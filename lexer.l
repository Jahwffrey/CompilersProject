%option yylineno
%pointer

%{
    #include <cstdlib>
    #include <cerrno>
    #include <climits>
    #include <limits>
    #include "ast.hpp"
    #include "parser.hpp"
    
	void yyerror(const char *);
%}

%x COMMENT
DIGIT [0-9]
ID    [a-zA-Z][a-zA-Z0-9]*

%%

  /* WRITEME: Write your Flex token rules here */

<COMMENT><<EOF>> { yyerror("Dangling comment"); }  
<COMMENT>[\n]     ;
<COMMENT>.        ;
<COMMENT>"!--"    BEGIN(INITIAL);
"--!"		  BEGIN(COMMENT);
":"		  { return T_COLON; }
"+"		  { return T_PLUS; }
"-"		  { return T_MINUS; }
"="		  { return T_EQ; }
"*"		  { return T_MULTI; }
"/"		  { return T_DIVID; }
"<"		  { return T_LESSTHAN; }
"<="		  { return T_LESSTHANOREQ; }
"->"		  {  return T_ARROW; }
"{"		  { return T_OPENCURLYBRACE; }
"}"		  { return T_CLOSECURLYBRACE; }
"("		  {  return T_OPENPAREN; }
")"		  { return T_CLOSEPAREN; }
"."		  { return T_DOT; }
","		  { return T_COMMA; }
"0"|[1-9]{DIGIT}* { yylval.base_int = atoi(yytext); return T_NUM; }
"if"		  { return T_IF; }
"or"		  { return T_OR; }
"new" 		  { return T_NEW; }
"and"		  { return T_AND; }
"not"		  { return T_NOT; }
"else" 		  { return T_ELSE; }
"none" 		  { return T_NONE; }
"true"		  { return T_TRUE; }
"false"		  { return T_FALSE; }
"print"		  { return T_PRINT; }
"while"		  { return T_WHILE; }
"return"	  { return T_RETURN; }
"equals"	  { return T_EQUALS; }
"boolean"         { return T_BOOL; }
"integer"         { return T_INT; }
"extends"         { return T_EXTENDS; }
{ID}		  { yylval.base_char_ptr = yytext; return T_ID; }
[ \t\n]	  	  ;
.                 { yyerror("invalid character"); }

%%

int yywrap(void) {
  return 1;
}
