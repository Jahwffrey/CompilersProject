%{
    #include <cstdlib>
    #include <cstdio>
    #include <iostream>
    #include "ast.hpp"
    
    #define YYDEBUG 1
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;
%}

%error-verbose
// %glr-parser
/* NOTE: You may use the %glr-parser directive, which may allow your parser to
         work even with some shift/reduce conflicts remianing. */

/* WRITEME: Copy your token and precedence specifiers from Project 3 here */
%token T_PLUS
%token T_MINUS
%token T_MULTI
%token T_DIVID
%token T_EQ
%token T_LESSTHAN
%token T_LESSTHANOREQ
%token T_OPENCURLYBRACE
%token T_CLOSECURLYBRACE
%token T_OPENPAREN
%token T_CLOSEPAREN
%token T_DOT
%token T_NUM
%token T_IF
%token T_OR
%token T_NEW
%token T_AND
%token T_NOT
%token T_ELSE
%token T_COLON
%token T_COMMA
%token T_NONE
%token T_TRUE
%token T_FALSE
%token T_PRINT
%token T_WHILE
%token T_RETURN
%token T_EQUALS
%token T_BOOL
%token T_INT
%token T_EXTENDS
%token T_ARROW
%token T_ID

%left T_OR
%left T_AND
%left T_LESSTHAN T_LESSTHANOREQ T_EQUALS
%left T_MINUS T_PLUS
%left T_MULTI T_DIVID
%right T_NOT
%right then T_ELSE


/* WRITEME: Specify types for all nonterminals and necessary terminals here */

%type <program_ptr> Start
%type <class_list_ptr> Classes
%type <class_ptr> Class InsideClass Members
%type <identifier_ptr> T_ID Extension Id
%type <method_list_ptr> Methods
%type <method_ptr> Method
%type <parameter_list_ptr> Params MoreParams
%type <expression_list_ptr> MethodCallParams MoreMethodCallParams
%type <type_ptr> Type ReturnType
%type <methodbody_ptr> MethodBody Declarations
%type <statement_list_ptr> Statements
%type <statement_ptr> Statement
%type <returnstatement_ptr> MaybeReturn
%type <parameter_ptr> Param
%type <declaration_ptr> Declaration Member
%type <identifier_list_ptr> InlineDeclarations
%type <expression_ptr> Expression
%type <assignment_ptr> Assigner
%type <ifelse_ptr> IfStatement
%type <while_ptr> WhileStatement
%type <print_ptr> PrintStatement
%type <integertype_ptr> T_INT
%type <integer_ptr> T_NUM
%type <none_ptr> T_NONE
%type <booltype_ptr> T_BOOL
%type <new_ptr> T_NEW
%type <methodcall_ptr> MethodCall

%%

/* WRITEME: This rule is a placeholder. Replace it with your grammar
            rules from Project 3 */
Start :Classes 						{ astRoot = new ProgramNode($1);}
      ;

Id: T_ID						{ $$ = new IdentifierNode(yylval.base_char_ptr);}

Classes:Class Classes					{ $2->push_front($1); $$ = $2;}
	|Class						{ $$ = new std::list<ClassNode*>(); $$->push_front($1);}
	;

Type: T_INT						{ $$ = new IntegerTypeNode();}
    | T_BOOL 						{ $$ = new BooleanTypeNode();}
    | Id						{ $$ = new ObjectTypeNode($1);}
    ;

ReturnType: T_INT 					{ $$ = new IntegerTypeNode();}
	  | T_BOOL 					{ $$ = new BooleanTypeNode();}
	  | Id						{ $$ = new ObjectTypeNode($1);}
	  | T_NONE					{ $$ = new NoneNode();}
	  ;

Class:Id Extension T_OPENCURLYBRACE InsideClass  T_CLOSECURLYBRACE { $4->identifier_1 = $1; $4->identifier_2 = $2; $$ = $4;}
	;

Extension:T_EXTENDS Id/*CLASSNAME*/			{ $$ = $2;}
	|						{ $$ = NULL;}
	;

InsideClass:Members					{$$ = $1;}
	;

Members:Member Members					{ $2->declaration_list->push_front($1); $$ = $2;}
	|Methods					{ $$ = new ClassNode(NULL,NULL,new std::list<DeclarationNode*>(),$1);}
	;

Member: Type Id						{ $$ = new DeclarationNode($1,new std::list<IdentifierNode*>()); $$->identifier_list->push_front($2);}
      ;

Methods: Method Methods					{ $2->push_front($1); $$ = $2;}
	|						{ $$ = new std::list<MethodNode*>();}
	;

Method:Id T_OPENPAREN Params T_CLOSEPAREN T_ARROW ReturnType T_OPENCURLYBRACE MethodBody T_CLOSECURLYBRACE { $$ = new MethodNode($1,$3,$6,$8);}
	;

Params:Param MoreParams					{ $2->push_front($1); $$ = $2;}
	|						{ $$ = NULL;}
	;

MoreParams:T_COMMA Param MoreParams			{ $3->push_front($2); $$ = $3;}
	|						{ $$ = new std::list<ParameterNode*>();}
	;

Param: Id T_COLON Type					{ $$ = new ParameterNode($3,$1); }
     ;
							// This is a bit weird but the way im doing things requires me to build the method body in this way

MethodBody: Declarations MaybeReturn			{ $1->returnstatement = $2; $$ = $1;}
	  ;

Declarations: Declaration Declarations			{ $2->declaration_list->push_front($1); $$ = $2;}
		|Statements				{ $$ = new MethodBodyNode(new std::list<DeclarationNode*>(),$1,NULL);}
		;

Declaration: Type Id InlineDeclarations			{ $3->push_front($2); $$ = new DeclarationNode($1,$3);}
	   ;

InlineDeclarations:T_COMMA Id InlineDeclarations	{ $3->push_front($2); $$ = $3; }
		|					{ $$ = new std::list<IdentifierNode*>(); }
		;

Statements: Statement Statements			{ $2->push_front($1); $$ = $2; }
		|					{ $$ = new std::list<StatementNode*>(); }
		;

Assigner: Id T_EQ Expression				{ $$ = new AssignmentNode($1,NULL,$3);}
	| Id T_DOT Id T_EQ Expression			{ $$ = new AssignmentNode($1,$3,$5);}
	;

Statement: Assigner					{ $$ = $1;}
	  |MethodCall					{ $$ = new CallNode($1);}
	  |WhileStatement				{ $$ = $1;}
	  |PrintStatement				{ $$ = $1;}
	  |IfStatement					{ $$ = $1;}
	  ;

PrintStatement: T_PRINT Expression			{ $$ = new PrintNode($2); }
	      ;

WhileStatement: T_WHILE Expression T_OPENCURLYBRACE Statements T_CLOSECURLYBRACE { $$ = new WhileNode($2,$4); }
	      ;
IfStatement:T_IF Expression T_OPENCURLYBRACE Statements T_CLOSECURLYBRACE   { $$ = new IfElseNode($2,$4,NULL);}							%prec then
	   |T_IF Expression T_OPENCURLYBRACE Statements T_CLOSECURLYBRACE T_ELSE T_OPENCURLYBRACE Statements T_CLOSECURLYBRACE {$$ = new IfElseNode($2,$4,$8);}
	   ;

MaybeReturn: T_RETURN Expression			{ $$ = new ReturnStatementNode($2); }
		|					{ $$ = NULL; }
		;

Expression:Expression T_PLUS Expression					     { $$ = new PlusNode($1,$3);}
	  |Expression T_MINUS Expression				     { $$ = new MinusNode($1,$3);}
	  |Expression T_MULTI Expression				     { $$ = new TimesNode($1,$3);}
	  |Expression T_DIVID Expression				     { $$ = new DivideNode($1,$3);}
	  |Expression T_LESSTHAN Expression				     { $$ = new LessNode($1,$3);}
	  |Expression T_LESSTHANOREQ Expression				     { $$ = new LessEqualNode($1,$3);}
	  |Expression T_EQUALS Expression				     { $$ = new EqualNode($1,$3);}
	  |Expression T_AND Expression					     { $$ = new AndNode($1,$3);}
	  |Expression T_OR Expression					     { $$ = new OrNode($1,$3);}
	  |T_NOT Expression						     { $$ = new NotNode($2); }
	  |T_MINUS Expression 				%prec T_NOT	     { $$ = new NegationNode($2); }
	  |Id								     { $$ = new VariableNode($1); }
	  |Id T_DOT Id							     { $$ = new MemberAccessNode($1,$3);}
	  |MethodCall							     { $$ = $1; }
	  |T_OPENPAREN Expression T_CLOSEPAREN				     { $$ = $2; }
	  |T_NUM							     { $$ = new IntegerLiteralNode(new IntegerNode(yylval.base_int));}
	  |T_TRUE							     { $$ = new BooleanLiteralNode(new IntegerNode(1)); }
	  |T_FALSE							     { $$ = new BooleanLiteralNode(new IntegerNode(0)); }
	  |T_NEW Id						  	     { $$ = new NewNode($2,NULL);}
	  |T_NEW Id T_OPENPAREN MethodCallParams T_CLOSEPAREN		     { $$ = new NewNode($2,$4);}	  	   
	  ;

MethodCall:Id T_OPENPAREN MethodCallParams T_CLOSEPAREN	     		{ $$ = new MethodCallNode($1,NULL,$3);}
	  |Id T_DOT Id T_OPENPAREN MethodCallParams T_CLOSEPAREN 	{ $$ = new MethodCallNode($1,$3,$5);}
	  ;

MethodCallParams:Expression MoreMethodCallParams {$2->push_front($1); $$ = $2;}
		|				 {$$ = NULL;}
		;

MoreMethodCallParams:T_COMMA Expression MoreMethodCallParams { $3->push_front($2); $$ = $3;}
		    |				 	     { $$ = new std::list<ExpressionNode*>();} 
		    ;

%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(1);
}
