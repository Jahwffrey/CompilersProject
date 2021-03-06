#include "codegeneration.hpp"
#include <string>
#define cout cout<<padstr
using namespace std;
std::string padstr = "";
// CodeGenerator Visitor Functions: These are the functions
// you will complete to generate the x86 assembly code. Not
// all functions must have code, many may be left empty.


void CodeGenerator::visitProgramNode(ProgramNode* node) {
	cout << ".data\n";
	cout << "printstr: .asciz \"%d\\n\"\n";
	cout << ".text\n";
	cout << ".globl Main_main\n";
	cout << "# -- BEGIN THE THING\n";	
	node->visit_children(this);
}

void CodeGenerator::visitClassNode(ClassNode* node) {
	std::string tempstr = padstr;
	padstr+="   ";
	currentClassName = node->identifier_1->name;
	node->visit_children(this);
	padstr = tempstr;
}

void CodeGenerator::visitMethodNode(MethodNode* node) {
	currentMethodName = node->identifier->name;
	cout << "# -- Methodnode\n";
	std::string tempstr = padstr;
	padstr+="   ";
	//Label
	cout << currentClassName << "_" << node->identifier->name <<":     ## @" <<currentClassName << "_" << node->identifier->name <<"\n";
	///#######PROLOGUE
	cout << "PUSH %EBP\n";
	cout << "MOV %ESP,%EBP\n";
		//Allocate stack space for locals
	cout << "SUB $" << classTable->at(currentClassName).methods->at(currentMethodName).localsSize <<",%ESP\n";
	//Save callee saved registers?
	cout << "PUSH %EBX\n";
	cout << "PUSH %ESI\n";
	cout << "PUSH %EDI\n";
	node->visit_children(this);
	///#######EPILOGUE
	//Restore callee saved registers
	cout << "MOV %EBP,%ESP\n";
	cout << "SUB $" << classTable->at(currentClassName).methods->at(currentMethodName).localsSize <<",%ESP\n";
	cout << "SUB $16,%ESP\n";
	cout << "POP %EDI\n";
	cout << "POP %ESI\n";
	cout << "POP %EBX\n";
		//Deallocate
	cout << "MOV %EBP,%ESP\n";
	cout << "POP %EBP\n";
	cout << "RET\n";
	padstr = tempstr;
}

void CodeGenerator::visitMethodBodyNode(MethodBodyNode* node) {
	cout << "# -- Methodbodynode\n";
	node->visit_children(this);
}

void CodeGenerator::visitParameterNode(ParameterNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitDeclarationNode(DeclarationNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitReturnStatementNode(ReturnStatementNode* node) {
	cout << "# -- Returnstatementnode\n";
	node->visit_children(this);
	//Assuming that what we want to return is ontop of the stack
	cout << "POP %EAX\n";
}

void CodeGenerator::visitAssignmentNode(AssignmentNode* node) {
	cout << "# -- Assignmentnode\n";
	node->visit_children(this);
	if(node->identifier_2==NULL){
		if(classTable->at(currentClassName).methods->at(currentMethodName).variables->count(node->identifier_1->name)!=0){
		//Locals:
			int var = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).offset;
			cout << "POP "<< var << "(%EBP)\n";
		} else {
			//Members:
			cout << "MOV 8(%EBP),%EAX\n";
			int var = -1 * classTable->at(currentClassName).members->at(node->identifier_1->name).offset;
			cout << "POP " << var << "(%EAX)\n";
		}
	} else {
		if(classTable->at(currentClassName).methods->at(currentMethodName).variables->count(node->identifier_1->name)!=0){
		//Locals to the class:
			int var = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).offset;
			std::string className = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).type.objectClassName;
			cout << "MOV "<< var << "(%EBP),%EAX\n";
			int classesVar = -1 * classTable->at(className).members->at(node->identifier_2->name).offset;
			cout << "POP " << classesVar << "(%EAX)\n";
		} else {
			//Members:
			cout << "MOV 8(%EBP),%EAX\n";
			int var = -1 * classTable->at(currentClassName).members->at(node->identifier_1->name).offset;
			cout << "MOV " << var << "(%EAX),%EBX\n";
			std::string className = classTable->at(currentClassName).members->at(node->identifier_1->name).type.objectClassName;
			int memberMemberVar = -1 * classTable->at(className).members->at(node->identifier_2->name).offset;
			cout << "POP "<< memberMemberVar << "(%EBX)\n";
		}
	}
}

void CodeGenerator::visitCallNode(CallNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIfElseNode(IfElseNode* node) {
	cout << "# -- Ifelsenode\n";
	std::string tempstr = padstr;
	padstr+="   ";
	int tempLabel = nextLabel();
	//Want to visit children in a specific order.
	//First visit the expression, then t/f is on top of stack. 
	//If equal to true, jumpt to the true block. else continue into the false block and then skip past the true block
	node->expression->accept(this);
	cout << "POP %EAX\n";
	cout << "CMP $1,%EAX\n";
	cout << "JE trueblock_" << tempLabel << "\n";
	if (node->statement_list_2) {
		for(std::list<StatementNode*>::iterator iter = node->statement_list_2->begin();
		iter != node->statement_list_2->end(); iter++) {
			(*iter)->accept(this);
    		}
	}
	cout << "JMP endofif_" << tempLabel << "\n";
	cout << "trueblock_" << tempLabel << ":\n";
	if (node->statement_list_1) {
		for(std::list<StatementNode*>::iterator iter = node->statement_list_1->begin();
		iter != node->statement_list_1->end(); iter++) {
			(*iter)->accept(this);
    		}
	}
	cout << "endofif_" << tempLabel << ":\n";
	padstr = tempstr;
}

void CodeGenerator::visitWhileNode(WhileNode* node) {
	cout << "# -- Whilenode\n";
	std::string tempstr = padstr;
	padstr+="   ";
	int tempLabel = nextLabel();
	//Want to visit children in a specific order.
	//First visit the expression, then t/f is on top of stack. 
	//If false, skip everything
	//At the end, jump back to top and repeat
	cout << "beginofwhile_" << tempLabel << ":\n";
	node->expression->accept(this);
	cout << "POP %EAX\n";
	cout << "CMP $0,%EAX\n";
	cout << "JE outofwhile_" << tempLabel << "\n";
	if (node->statement_list) {
		for(std::list<StatementNode*>::iterator iter = node->statement_list->begin();
		iter != node->statement_list->end(); iter++) {
			(*iter)->accept(this);
    		}
	}
	cout << "JMP beginofwhile_" << tempLabel << "\n";
	cout << "outofwhile_" << tempLabel << ":\n";
	padstr = tempstr;
}

void CodeGenerator::visitPrintNode(PrintNode* node) {
	cout << "# -- Printnode\n";
	node->visit_children(this);
	cout << "PUSH $printstr\n";
	cout << "CALL printf\n";
	cout << "ADD $4,%ESP\n";
}

void CodeGenerator::visitPlusNode(PlusNode* node) {
	cout << "# -- Addnode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "ADD %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitMinusNode(MinusNode* node) {
	cout << "# -- Minusnode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "SUB %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitTimesNode(TimesNode* node) {
	cout << "# -- Timesnode\n";
	node->visit_children(this);
	cout << "POP %EBX\n";
	cout << "POP %EAX\n";
	cout << "IMUL %EBX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitDivideNode(DivideNode* node) {
	cout << "# -- Dividenode\n";
	node->visit_children(this);
	cout << "POP %EBX\n";
	cout << "POP %EAX\n";
	cout << "CDQ\n";
	cout << "IDIV %EBX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitLessNode(LessNode* node) {
	cout << "# -- Lessnode\n";
	node->visit_children(this);
	int label = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EDX,%EAX\n";
	cout << "JL pushtrueless_" << label << "\n";
	cout << "PUSH $0" << "\n";
	cout << "JMP afterless_" << label << "\n";
	cout << "pushtrueless_" << label << ":\n";
	cout << "PUSH $1\n";
	cout << "afterless_" <<label << ":\n";
}

void CodeGenerator::visitLessEqualNode(LessEqualNode* node) {
	cout << "# -- Lessequalnode\n";
	node->visit_children(this);
	int label = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EDX,%EAX\n";
	cout << "JLE pushtruelesseq_" << label << "\n";
	cout << "PUSH $0\n";
	cout << "JMP afterlesseq_" << label << "\n";
	cout << "pushtruelesseq_" << label << ":\n";
	cout << "PUSH $1\n";
	cout << "afterlesseq_" <<label << ":\n";
}

void CodeGenerator::visitEqualNode(EqualNode* node) {
	cout << "# -- Equalnode\n";
	node->visit_children(this);
	int label = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EAX,%EDX\n";
	cout << "JZ pushtrueeq_" << label << "\n";
	cout << "PUSH $0" << "\n";
	cout << "JMP aftereqblock_" << label << "\n";
	cout << "pushtrueeq_" << label << ":\n";
	cout << "PUSH $1\n";
	cout << "aftereqblock_" <<label << ":\n";
}

void CodeGenerator::visitAndNode(AndNode* node) {
	cout << "# -- Andnode\n"; 
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "AND %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitOrNode(OrNode* node) {
	cout << "# -- Ornode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "OR %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitNotNode(NotNode* node) {
	cout << "# -- Notnode\n";
	node->visit_children(this);
	//Flip the first bit of a boolean
	cout << "POP %EAX\n";
	cout << "XOR $1,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitNegationNode(NegationNode* node) {
	cout << "# -- Negationnode\n";
	node->visit_children(this);
	cout << "POP %EAX\n";	
	cout << "NEG %EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitMethodCallNode(MethodCallNode* node) {
	cout << "# -- Methodcall\n";
	std::string tempstr = padstr;
	padstr+="   ";
	cout << "# -- 							" << node->identifier_1->name << "\n";
	bool wasConstructor = false;
	///##########PRE-CALL
	//Save caller-saved registers
	cout << "PUSH %EAX\n";
	cout << "PUSH %ECX\n";
	cout << "PUSH %EDX\n";
	//push args in reverse	
	if (node->expression_list) {
		for(std::list<ExpressionNode*>::reverse_iterator iter = node->expression_list->rbegin();
		iter != node->expression_list->rend(); iter++) {
			(*iter)->accept(this);
    		}
	}
	//Jump to fxn
	if(node->identifier_2 == NULL){
		//Push self pointer
		cout << "PUSH 8(%EBP)\n";
		std::string callClass = currentClassName;
		while(classTable->at(callClass).methods->count(node->identifier_1->name)==0){
			callClass = classTable->at(callClass).superClassName;
		}
		if(callClass == node->identifier_1->name) wasConstructor = true;
		cout << "CALL " << callClass << "_" << node->identifier_1->name << "\n";
	} else {
		///////Push self pointer
		if(classTable->at(currentClassName).methods->at(currentMethodName).variables->count(node->identifier_1->name)!=0){
			//Locals:
			int var = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).offset;
			cout << "PUSH "<< var << "(%EBP)\n";
		} else {
			//Members:
			cout << "MOV 8(%EBP),%EAX\n";
			int var = -1 * classTable->at(currentClassName).members->at(node->identifier_1->name).offset;
			cout << "PUSH " << var << "(%EAX)\n";
		}
		std::string callClass = node->identifier_1->objectClassName;
		while(classTable->at(callClass).methods->count(node->identifier_2->name)==0){
			callClass = classTable->at(callClass).superClassName;
		}
		cout << "CALL " << callClass  << "_" << node->identifier_2->name << "\n";
	}
	///##########POST-RETURN
	//Deallocate params
	cout << "ADD $4,%ESP\n";
	if(node->expression_list!=NULL){
		cout << "ADD $" << node->expression_list->size()*4 << ",%ESP\n";
	}
	//restore caller-saved registers
	cout << "POP %EDX\n";
	cout << "POP %ECX\n";
	//Switch top of stack (return value) EAX
	if(!wasConstructor){
		cout << "POP %EBX\n";
		cout << "PUSH %EAX\n";
		cout << "MOV %EBX,%EAX\n";
	} else {
		cout << "POP %EAX\n";
	}
	padstr = tempstr;
}

void CodeGenerator::visitMemberAccessNode(MemberAccessNode* node) {
	node->visit_children(this);
	//Params/Locals:
	if(classTable->at(currentClassName).methods->at(currentMethodName).variables->count(node->identifier_1->name)!=0){
	//Locals:
		int var = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).offset;
		cout << "MOV "<< var << "(%EBP),%EAX\n";
		std::string className = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier_1->name).type.objectClassName;
		int classesVar = -1 * classTable->at(className).members->at(node->identifier_2->name).offset;
		cout << "PUSH " << classesVar << "(%EAX)\n";
	} else {
	//Members:
		cout << "MOV 8(%EBP),%EAX\n";
		int var = -1 * classTable->at(currentClassName).members->at(node->identifier_1->name).offset;
		cout << "MOV " << var << "(%EAX),%EBX\n";
		std::string className = classTable->at(currentClassName).members->at(node->identifier_1->name).type.objectClassName;
		int memberMemberVar = -1 * classTable->at(className).members->at(node->identifier_2->name).offset;
		cout << "PUSH "<< memberMemberVar << "(%EBX)\n";	
	}
}

void CodeGenerator::visitVariableNode(VariableNode* node) {
	cout << "# -- Variablenode\n";
	node->visit_children(this);
	//Params/Locals:
	if(classTable->at(currentClassName).methods->at(currentMethodName).variables->count(node->identifier->name)!=0){
	//Locals:
		int var = classTable->at(currentClassName).methods->at(currentMethodName).variables->at(node->identifier->name).offset;
		cout << "PUSH "<< var << "(%EBP)\n";
	} else {
	//Members:
		cout << "MOV 8(%EBP),%EAX\n";
		int var = -1 * classTable->at(currentClassName).members->at(node->identifier->name).offset;
		cout << "PUSH "<< var << "(%EAX)\n";		
	}
	
}

void CodeGenerator::visitIntegerLiteralNode(IntegerLiteralNode* node) {
	node->visit_children(this);
	cout << "PUSH $" << node->integer->value << "\n";
}

void CodeGenerator::visitBooleanLiteralNode(BooleanLiteralNode* node) {
	node->visit_children(this);
	cout << "PUSH $" << node->integer->value << "\n";
}

void CodeGenerator::visitNewNode(NewNode* node) {
	cout << "# -- Newnode\n";

	//visit children to get params on stack
	//node->visit_children(this);
	
	//create it
	cout << "PUSH $"<<classTable->at(node->identifier->name).membersSize << "\n";
	cout << "CALL malloc\n";
	cout << "ADD $4,%ESP\n";
	cout << "PUSH %EAX\n";
	
	//Save self in C, NOW MUST NEVER USE C IN EXPRESSIONS
	cout << "MOV %EAX,%ECX\n";

	if(classTable->at(node->identifier->name).methods->count(node->identifier->name)!=0){
		//Save caller-saved registers
		cout << "PUSH %EAX\n";
		cout << "PUSH %ECX\n";
		cout << "PUSH %EDX\n";
		//push args in reverse	
		if (node->expression_list) {
			for(std::list<ExpressionNode*>::reverse_iterator iter = node->expression_list->rbegin();
			iter != node->expression_list->rend(); iter++) {
				(*iter)->accept(this);
    			}
		}

		//Push self pointer, saved in ECX
		cout << "PUSH %ECX\n";

		cout << "CALL " << node->identifier->name << "_" << node->identifier->name << "\n";
	
		//restore caller-saved registers, deallocate params
		cout << "ADD $4,%ESP\n";
		if(node->expression_list!=NULL){
			cout << "ADD $" << node->expression_list->size()*4 << ",%ESP\n";
		}
		cout << "POP %EDX\n";
		cout << "POP %ECX\n";
		cout << "POP %EAX\n";
	}
}

void CodeGenerator::visitIntegerTypeNode(IntegerTypeNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitBooleanTypeNode(BooleanTypeNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitObjectTypeNode(ObjectTypeNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitNoneNode(NoneNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIdentifierNode(IdentifierNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIntegerNode(IntegerNode* node) {
	node->visit_children(this);
}
