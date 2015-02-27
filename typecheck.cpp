#include "typecheck.hpp"

// Defines the function used to throw type errors. The possible
// type errors are defined as an enumeration in the header file.
void typeError(TypeErrorCode code) {
  switch (code) {
    case undefined_variable:
      std::cerr << "Undefined variable." << std::endl;
      break;
    case undefined_method:
      std::cerr << "Method does not exist." << std::endl;
      break;
    case undefined_class:
      std::cerr << "Class does not exist." << std::endl;
      break;
    case undefined_member:
      std::cerr << "Class member does not exist." << std::endl;
      break;
    case not_object:
      std::cerr << "Variable is not an object." << std::endl;
      break;
    case expression_type_mismatch:
      std::cerr << "Expression types do not match." << std::endl;
      break;
    case argument_number_mismatch:
      std::cerr << "Method called with incorrect number of arguments." << std::endl;
      break;
    case argument_type_mismatch:
      std::cerr << "Method called with argument of incorrect type." << std::endl;
      break;
    case while_predicate_type_mismatch:
      std::cerr << "Predicate of while loop is not boolean." << std::endl;
      break;
    case if_predicate_type_mismatch:
      std::cerr << "Predicate of if statement is not boolean." << std::endl;
      break;
    case assignment_type_mismatch:
      std::cerr << "Left and right hand sides of assignment types mismatch." << std::endl;
      break;
    case return_type_mismatch:
      std::cerr << "Return statement type does not match declared return type." << std::endl;
      break;
    case constructor_returns_type:
      std::cerr << "Class constructor returns a value." << std::endl;
      break;
    case no_main_class:
      std::cerr << "The \"Main\" class was not found." << std::endl;
      break;
    case main_class_members_present:
      std::cerr << "The \"Main\" class has members." << std::endl;
      break;
    case no_main_method:
      std::cerr << "The \"Main\" class does not have a \"main\" method." << std::endl;
      break;
    case main_method_incorrect_signature:
      std::cerr << "The \"main\" method of the \"Main\" class has an incorrect signature." << std::endl;
      break;
  }
  exit(1);
}

// TypeCheck Visitor Functions: These are the functions you will
// complete to build the symbol table and type check the program.
// Not all functions must have code, many may be left empty.

ClassInfo* currentClass;
MethodInfo* currentMethod;

void TypeCheck::visitProgramNode(ProgramNode* node) {
	classTable = new ClassTable;
	currentLocalOffset = 0;
	currentMemberOffset = 0;
	currentParameterOffset = 0;
	node->visit_children(this);
}

void TypeCheck::visitClassNode(ClassNode* node) {
  	currentMemberOffset = 0;
	ClassInfo* newInfo = new ClassInfo;
	currentClass = newInfo;
	(node->identifier_2!=NULL)?	
		newInfo->superClassName = node->identifier_2->name :
		newInfo->superClassName = "";
	newInfo->methods = new MethodTable;
	currentMethodTable = newInfo->methods;
	newInfo->members = new VariableTable;
	currentVariableTable = newInfo->members;
	newInfo->membersSize = node->declaration_list->size()*4;
	classTable->insert(std::pair<std::string,ClassInfo>(node->identifier_1->name,*newInfo));
	node->visit_children(this);
}

BaseType checkType(TypeNode* type){
	if(dynamic_cast<IntegerTypeNode*>(type)!=NULL){
		return bt_integer;
	}else if(dynamic_cast<BooleanTypeNode*>(type)!=NULL){
		return bt_boolean;
	}else if(dynamic_cast<NoneNode*>(type)!=NULL){
		return bt_none;
	}else if(dynamic_cast<ObjectTypeNode*>(type)!=NULL){
		return bt_object;
	}else{
		std::cerr << "There is a type that is not of any type :|";
		exit(0);
	}
}

void TypeCheck::visitMethodNode(MethodNode* node) {
	currentLocalOffset = -4;
	currentParameterOffset = 8;
	currentMemberOffset = -1;
	VariableTable* temp = currentVariableTable;
	MethodInfo* newMethod = new MethodInfo;
	currentMethod = newMethod;
	newMethod->variables = new VariableTable;
	currentVariableTable = newMethod->variables;
	newMethod->returnType.baseType = checkType(node->type);
	if(newMethod->returnType.baseType == bt_object) newMethod->returnType.objectClassName = ((ObjectTypeNode*)node->type)->identifier->name;
	node->visit_children(this);
	newMethod->localsSize =  -(currentLocalOffset+4);
	currentMethodTable->insert(std::pair<std::string,MethodInfo>(node->identifier->name,*newMethod)); 	
	currentVariableTable = temp;
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
	node->visit_children(this);
}

void TypeCheck::visitParameterNode(ParameterNode* node) {
	currentParameterOffset+=4;
	CompoundType* newParam = new CompoundType;
	if((newParam->baseType = checkType(node->type)) == bt_object) newParam->objectClassName = ((ObjectTypeNode*) node->type)->identifier->name;
	VariableInfo* newVar = new VariableInfo;
	newVar->type = *newParam;
	newVar->offset = currentParameterOffset;
	newVar->size = 4;
	currentVariableTable->insert(std::pair<std::string,VariableInfo>(node->identifier->name,*newVar));
}

void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
	for(std::list<IdentifierNode*>::iterator it = node->identifier_list->begin(); it!=node->identifier_list->end();it++){
 		CompoundType* newParam = new CompoundType;
		if((newParam->baseType = checkType(node->type)) == bt_object) newParam->objectClassName = ((ObjectTypeNode*) node->type)->identifier->name;
		VariableInfo* newVar = new VariableInfo;
		newVar->type = *newParam;
		//class members always come before methods, so i will set currentMemberOffset to -1 once get to methods so as to distiguish var types
		if(currentMemberOffset==-1){
			newVar->offset = currentLocalOffset;
			currentLocalOffset-=4;
		} else {
			newVar->offset = currentMemberOffset;
			currentMemberOffset+=4;
		}
		newVar->size = 4;
		currentVariableTable->insert(std::pair<std::string,VariableInfo>((*it)->name,*newVar));
	}
}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
	node->visit_children(this);
	if(currentMethod->returnType.baseType!=node->expression->basetype) typeError(return_type_mismatch);
}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
	//The first identifier should be a class or a member of the current variable table
	//If the second identifier is not blank, it should be a member of the class of the first identifier or any of its super classes
	node->visit_children(this);
	if(node->identifier_2==NULL){
		if(node->identifier_1->basetype == bt_none){
			typeError(undefined_variable);
		} else {
			node->basetype = node->identifier_1->basetype;
			node->objectClassName = node->identifier_1->objectClassName;
		}	
	} else {
		if(node->identifier_1->basetype==bt_object){
			if(classTable->at(node->identifier_1->objectClassName).members->count(node->identifier_2->name)!=0){
				CompoundType temp = classTable->at(node->identifier_1->objectClassName).members->at(node->identifier_2->name).type;
				node->basetype = temp.baseType;
				node->objectClassName = temp.objectClassName;
			} else {
				bool foundmember = false;
				std::string supername =  classTable->at(node->identifier_1->objectClassName).superClassName;
				while(supername!="" && foundmember == false){
					if(classTable->at(supername).members->count(node->identifier_2->name)!=0){
						CompoundType temp = classTable->at(supername).members->at(node->identifier_2->name).type;
						node->basetype = temp.baseType;
						node->objectClassName = temp.objectClassName;
						foundmember = true;
					} else {
						supername = classTable->at(supername).superClassName;
					}
				}
			}
		} else {
			typeError(not_object);
		}
	}
	//Check if equal:
	if(node->basetype!=node->expression->basetype){
		typeError(assignment_type_mismatch);
	}
}

void TypeCheck::visitCallNode(CallNode* node) {
	//Do nothing?
	node->visit_children(this);
	node->basetype = node->methodcall->basetype;
	node->objectClassName = node->methodcall->objectClassName;
}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
	node->visit_children(this);
	if(node->expression->basetype!=bt_boolean){
		typeError(if_predicate_type_mismatch);
	}
}

void TypeCheck::visitWhileNode(WhileNode* node) {
	node->visit_children(this);
	if(node->expression->basetype!=bt_boolean){
		typeError(while_predicate_type_mismatch);
	}
}

void TypeCheck::visitPrintNode(PrintNode* node) {
	node->visit_children(this);
	node->basetype = node->expression->basetype;
}

void TypeCheck::visitPlusNode(PlusNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_integer;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitMinusNode(MinusNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_integer;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitTimesNode(TimesNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_integer;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitDivideNode(DivideNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_integer;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitLessNode(LessNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitLessEqualNode(LessEqualNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitEqualNode(EqualNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_boolean && node->expression_2->basetype==bt_boolean){
		node->basetype = bt_boolean;
	} else if (node->expression_1->basetype==bt_integer && node->expression_2->basetype==bt_integer){ 
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitAndNode(AndNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_boolean && node->expression_2->basetype==bt_boolean){
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitOrNode(OrNode* node) {
	node->visit_children(this);
	if(node->expression_1->basetype==bt_boolean && node->expression_2->basetype==bt_boolean){
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitNotNode(NotNode* node) {
	node->visit_children(this);
	if(node->expression->basetype==bt_boolean){
		node->basetype = bt_boolean;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitNegationNode(NegationNode* node) {
	node->visit_children(this);
	if(node->expression->basetype==bt_integer){
		node->basetype = bt_integer;
	} else {
		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
	//If the second indentifier is blank, the first identifier should be a method in the current class
	//If it is not, the first identifier should be a class and the second a method in that class.
	//The expression list are the aparameters.They should have the same type as the parameters for this method
	node->visit_children(this);
	MethodInfo thisMethod; //Will use this to check parameters
	//Check that the method exists
	if(node->identifier_2==NULL){
		if(currentClass->methods->count(node->identifier_1->name)!=0){
			thisMethod = currentClass->methods->at(node->identifier_1->name);
			CompoundType temp = thisMethod.returnType;
			node->basetype = temp.baseType;
			node->objectClassName = temp.objectClassName;
		} else {
			typeError(undefined_method);
		}
	} else if(node->identifier_1->basetype == bt_object){
		if(classTable->at(node->identifier_1->objectClassName).methods->count(node->identifier_2->name)!=0){
			thisMethod = classTable->at(node->identifier_1->objectClassName).methods->at(node->identifier_2->name);
			CompoundType temp = thisMethod.returnType;
			node->basetype = temp.baseType;
			node->objectClassName = temp.objectClassName;
		} else {
			//check that the method might exist in the superclass
			bool foundmethod = false;
			std::string supername =  classTable->at(node->identifier_1->objectClassName).superClassName;
			while(supername!="" && foundmethod == false){
				if(classTable->at(supername).methods->count(node->identifier_2->name)!=0){
					thisMethod = classTable->at(supername).methods->at(node->identifier_2->name);
					CompoundType temp = thisMethod.returnType;
					node->basetype = temp.baseType;
					node->objectClassName = temp.objectClassName;
					foundmethod = true;
				} else {
					supername = classTable->at(supername).superClassName;
				}
			}
		}
	} else {
		typeError(not_object);
	}
	//check that the paramerters are correct
	if(node->expression_list->size() == thisMethod.parameters->size()){
		std::list<CompoundType>::iterator mIt = thisMethod.parameters->begin();
		std::list<ExpressionNode*>::iterator eIt = (*node->expression_list).begin();
		while(eIt!=(*node->expression_list).end()){
			if((*eIt)->basetype!=(*mIt).baseType){
				typeError(argument_type_mismatch);
			} else if ((*eIt)->basetype==bt_object){
				if((*eIt)->objectClassName!=(*mIt).objectClassName){
					typeError(argument_type_mismatch);
				}
			}
			eIt++;
			mIt++;
		}	
	} else {
		typeError(argument_number_mismatch);
	}
	
}

void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
	//The first identifier should be a class instance
	//The second identifier should be a member of that class
	node->visit_children(this);
	if(node->identifier_1->basetype == bt_object){
		if(classTable->at(node->identifier_1->objectClassName).members->count(node->identifier_2->name)!=0){
			CompoundType temp = classTable->at(node->identifier_1->objectClassName).members->at(node->identifier_2->name).type;
			node->basetype = temp.baseType;
			node->objectClassName = temp.objectClassName;
		}
	} else {
		typeError(not_object);
	}
}

void TypeCheck::visitVariableNode(VariableNode* node) {
	node->visit_children(this);
	node->basetype = node->identifier->basetype;
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
	node->visit_children(this);
	node->basetype = bt_integer;
}


void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
	node->visit_children(this);
	node->basetype = bt_boolean;
}

void TypeCheck::visitNewNode(NewNode* node) {
	node->visit_children(this);
	if(classTable->count(node->identifier->name)!=0){
		if(node->expression_list->size()==0){
			node->basetype = bt_object;
			node->objectClassName = node->identifier->name;
		} else {
			if(node->expression_list->size() == classTable->at(node->identifier->name).members->size() && node->expression_list->size()!=0){
				std::map<std::string,VariableInfo>::iterator mIt = classTable->at(node->identifier->name).members->begin();
				std::list<ExpressionNode*>::iterator eIt = (*node->expression_list).begin();
				while(eIt!=(*node->expression_list).end()){
					if((*eIt)->basetype!=(*mIt).second.type.baseType){
						typeError(argument_type_mismatch);
					} else if ((*eIt)->basetype==bt_object){
						if((*eIt)->objectClassName!=(*mIt).second.type.objectClassName){
							typeError(argument_type_mismatch);
						}
					}
					eIt++;
					mIt++;
				}	
			} else {
				typeError(argument_number_mismatch);
			}
		}
	} else {
		typeError(undefined_class);
	}
	//Im going to have to iterate over the expression list, checking to make sure arguments are correct. Dont forget to account for giving no params!
}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
	node->visit_children(this);
}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
	node->visit_children(this);
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
	node->visit_children(this);
}

void TypeCheck::visitNoneNode(NoneNode* node) {
	node->visit_children(this);
}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
	if(currentVariableTable->count(node->name)==0){
		if(currentClass->members->count(node->name)==0){
			//I dunno?
			//account for inheritance!!
			node->basetype = bt_none;
		} else {
			node->basetype=(*currentClass->members).at(node->name).type.baseType;
			if(node->basetype == bt_object) node->objectClassName = (*currentClass->members).at(node->name).type.objectClassName;
		}
	} else {
		node->basetype=(*currentVariableTable).at(node->name).type.baseType;
		if(node->basetype == bt_object) node->objectClassName = (*currentVariableTable).at(node->name).type.objectClassName;	
	}
}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
	node->visit_children(this);
}


// The following functions are used to print the Symbol Table.
// They do not need to be modified at all.

std::string genIndent(int indent) {
  std::string string = std::string("");
  for (int i = 0; i < indent; i++)
    string += std::string(" ");
  return string;
}

std::string string(CompoundType type) {
  switch (type.baseType) {
    case bt_integer:
      return std::string("Integer");
    case bt_boolean:
      return std::string("Boolean");
    case bt_none:
      return std::string("None");
    case bt_object:
      return std::string("Object(") + type.objectClassName + std::string(")");
    default:
      return std::string("");
  }
}


void print(VariableTable variableTable, int indent) {
  std::cout << genIndent(indent) << "VariableTable {";
  if (variableTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (VariableTable::iterator it = variableTable.begin(); it != variableTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << string(it->second.type);
    std::cout << ", " << it->second.offset << ", " << it->second.size << "}";
    if (it != --variableTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(MethodTable methodTable, int indent) {
  std::cout << genIndent(indent) << "MethodTable {";
  if (methodTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (MethodTable::iterator it = methodTable.begin(); it != methodTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    std::cout << genIndent(indent + 4) << string(it->second.returnType) << "," << std::endl;
    std::cout << genIndent(indent + 4) << it->second.localsSize << "," << std::endl;
    print(*it->second.variables, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --methodTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(ClassTable classTable, int indent) {
  std::cout << genIndent(indent) << "ClassTable {" << std::endl;
  for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    if (it->second.superClassName != "")
      std::cout << genIndent(indent + 4) << it->second.superClassName << "," << std::endl;
    print(*it->second.members, indent + 4);
    std::cout << "," << std::endl;
    print(*it->second.methods, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --classTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}" << std::endl;
}

void print(ClassTable classTable) {
  print(classTable, 0);
}
