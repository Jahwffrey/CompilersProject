#include "codegeneration.hpp"
using namespace std;

// CodeGenerator Visitor Functions: These are the functions
// you will complete to generate the x86 assembly code. Not
// all functions must have code, many may be left empty.

void CodeGenerator::visitProgramNode(ProgramNode* node) {
	
	node->visit_children(this);
}

void CodeGenerator::visitClassNode(ClassNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitMethodNode(MethodNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitMethodBodyNode(MethodBodyNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitParameterNode(ParameterNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitDeclarationNode(DeclarationNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitReturnStatementNode(ReturnStatementNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitAssignmentNode(AssignmentNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitCallNode(CallNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIfElseNode(IfElseNode* node) {
	cout << "#-- Ifelsenode";
	int tempLabel = nextLabel();
	int tempLabel2 = nextLabel();
	//Want to visit children in a specific order. First visit the expression, then t/f is on top of stack. If equal to true, jumpt to the true block. else continue into
	//the false block and then skip past the true block
	node->expression->accept(this);
	cout << "POP %EAX\n";
	cout << "CMP %EAX,$1\n";
	cout << "JE label_" << tempLabel << "\n";
	if (node->statement_list_2) {
		for(std::list<StatementNode*>::iterator iter = node->statement_list_2->begin();
		iter != node->statement_list_2->end(); iter++) {
			(*iter)->accept(this);
    		}
	}
	cout << "JMP label_" << tempLabel2 << "\n";
	cout << "label_" << tempLabel << ":\n";
	if (node->statement_list_1) {
		for(std::list<StatementNode*>::iterator iter = node->statement_list_1->begin();
		iter != node->statement_list_1->end(); iter++) {
			(*iter)->accept(this);
    		}
	}
	cout << "label_" << tempLabel2 << ":\n";
}

void CodeGenerator::visitWhileNode(WhileNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitPrintNode(PrintNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitPlusNode(PlusNode* node) {
	cout << "#-- Addnode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "ADD %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitMinusNode(MinusNode* node) {
	cout << "#-- Minusnode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "SUB %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitTimesNode(TimesNode* node) {
	cout << "#-- Timesnode\n";
	node->visit_children(this);
	cout << "POP %EBX\n";
	cout << "POP %EAX\n";
	cout << "CDQ\n";
	cout << "IMUL %EBX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitDivideNode(DivideNode* node) {
	cout << "#-- Dividenode\n";
	node->visit_children(this);
	cout << "POP %EBX\n";
	cout << "POP %EAX\n";
	cout << "CDQ\n";
	cout << "IDIV %EBX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitLessNode(LessNode* node) {
	cout << "#-- Lessnode\n";
	node->visit_children(this);
	int label1 = nextLabel();
	int label2 = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EAX,%EDX\n";
	cout << "JL label_" << label1 << "\n";
	cout << "PUSH $0" << "\n";
	cout << "JMP label_" << label2 << "\n";
	cout << "label_" << label1 << ":\n";
	cout << "PUSH $1\n";
	cout << "label_" <<label2 << "\n";
}

void CodeGenerator::visitLessEqualNode(LessEqualNode* node) {
	cout << "#-- Lessequalnode\n";
	node->visit_children(this);
	int label1 = nextLabel();
	int label2 = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EAX,%EDX\n";
	cout << "JEL label_" << label1 << "\n";
	cout << "PUSH $0\n";
	cout << "JMP label_" << label2 << "\n";
	cout << "label_" << label1 << ":\n";
	cout << "PUSH $1\n";
	cout << "label_" <<label2 << "\n";
}

void CodeGenerator::visitEqualNode(EqualNode* node) {
	cout << "#-- Equalnode\n";
	node->visit_children(this);
	int label1 = nextLabel();
	int label2 = nextLabel();
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "CMP %EAX,%EDX\n";
	cout << "JZ label_" << label1 << "\n";
	cout << "PUSH $0" << "\n";
	cout << "JMP label_" << label2 << "\n";
	cout << "label_" << label1 << ":\n";
	cout << "PUSH $1\n";
	cout << "label_" <<label2 << "\n";
}

void CodeGenerator::visitAndNode(AndNode* node) {
	cout << "#-- Andnode\n"; 
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "AND %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitOrNode(OrNode* node) {
	cout << "#-- Ornode\n";
	node->visit_children(this);
	cout << "POP %EDX\n";
	cout << "POP %EAX\n";
	cout << "OR %EDX,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitNotNode(NotNode* node) {
	cout << "#-- Notnode\n";
	node->visit_children(this);
	//Flip the first bit of a boolean
	cout << "POP %EAX\n";
	cout << "XOR $1,%EAX\n";
	cout << "PUSH %EAX\n";
}

void CodeGenerator::visitNegationNode(NegationNode* node) {
	cout << "#-- Negationnode\n";
	node->visit_children(this);
	cout << "NEG %ESP\n";
}

void CodeGenerator::visitMethodCallNode(MethodCallNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitMemberAccessNode(MemberAccessNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitVariableNode(VariableNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIntegerLiteralNode(IntegerLiteralNode* node) {
	node->visit_children(this);
	cout << "PUSH $" << node->integer->value << "\n";
}

void CodeGenerator::visitBooleanLiteralNode(BooleanLiteralNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitNewNode(NewNode* node) {
	node->visit_children(this);
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
