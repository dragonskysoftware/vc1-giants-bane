/*
 * EVSContext.cpp
 * Implements a class that acts as a context for the EvScript interpreter
 * Created by Andrew Davis
 * Created on 3/27/2017
 * Open source (GPL license)
 */

//include header
#include "EVSContext.h"

//constructor
EVSContext::EVSContext()
	: ast(nullptr), symtab(nullptr) //null the fields
{
	this->symtab = new Symbol[NHASH]; //initialize the symbol table
}

//destructor
EVSContext::~EVSContext() {
	this->free(); //deallocate the object
}

//copy constructor
EVSContext::EVSContext(const EVSContext& evsc)
	: ast(nullptr), symtab(nullptr) //null the fields
{
	if(evsc.ast != nullptr) { //if the other AST isn't null
		this->ast = new ASTNode(*evsc.ast); //then copy it in
	}
	this->symtab = new Symbol[NHASH]; //allocate the symbol table
	for(int i = 0; i < NHASH; i++) { //loop through the symbol table
		this->symtab[i] = Symbol(evsc.symtab[i]); //and copy each symbol over
	}
}

//move constructor
EVSContext::EVSContext(EVSContext&& evsc)
	: ast(nullptr), symtab(nullptr) //null the fields
{
	if(evsc.ast != nullptr) { //if the other AST isn't null
		this->ast = new ASTNode(*evsc.ast); //then move it in
	}
	this->symtab = new Symbol[NHASH]; //allocate the symbol table
	for(int i = 0; i < NHASH; i++) { //loop through the symbol table
		this->symtab[i] = Symbol(evsc.symtab[i]); //and move each symbol over
	}
	evsc.free(); //deallocate the temporary
}

//assignment operator
EVSContext& EVSContext::operator=(const EVSContext& src) {
	delete this->ast; //deallocate the AST
	this->ast = nullptr; //and zero it out
	if(src.ast != nullptr) { //if the other AST isn't null
		this->ast = new ASTNode(*src.ast); //then assign it
	}
	for(int i = 0; i < NHASH; i++) { //loop through the symbol table
		this->symtab[i] = src.symtab[i]; //and assign the symbols
	}
	return *this; //return the object
}

//move operator
EVSContext& EVSContext::operator=(EVSContext&& src) {
	delete this->ast; //deallocate the AST
	this->ast = nullptr; //and zero it out
	if(src.ast != nullptr) { //if the other AST isn't null
		this->ast = new ASTNode(*src.ast); //then move it
	}
	for(int i = 0; i < NHASH; i++) { //loop through the symbol table
		this->symtab[i] = src.symtab[i]; //and move the symbols
	}
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//setter method

//setAST method - sets the AST to be interpreted
void EVSContext::setAST(const ASTNode* newAST) {
	delete this->ast; //deallocate the current AST
	this->ast = nullptr; //and zero it out
	this->ast = new ASTNode(*newAST); //copy the provided AST node into the AST field
}

//public interpreter methods

//lookup method - accesses the symbol table
Symbol* EVSContext::lookup(char* symName) {
	Symbol* sym = &symtab[this->symhash(symName)%NHASH]; //get a symbol from the table
	int symCount = NHASH; //how many symbols have been examined
	while(--symCount >= 0) { //loop through the table
		std::string temp = symName; //get a temporary string
		if(!sym->name().empty() && sym->name() == temp) { //if the name matches
			return sym; //then return the symbol
		}
		if(sym->name().empty()) { //new entry
			sym->name() = symName; //init the name field
			sym->value() = 0; //init the value field
			sym->array() = Array(); //init the array field
			sym->function() = nullptr; //null the function field
			sym->functionArgs() = nullptr; //null the function arguments field
			return sym; //return the symbol
		}
		if(++sym >= this->symtab+NHASH) { //try the next entry
			sym = this->symtab; //assign the symbol pointer
		}
	}
	throw SymbolTableException("Symbol table overflow"); //the end of the table was reached, so we throw an error
}

//dummy eval method - interprets an AST
void EVSContext::eval() {
	this->eval(this->ast); //evaluate the AST using the private eval method
}

//defineFunc method - defines a function in the symbol table
void EVSContext::defineFunc(Symbol*& name, SymbolList* syms, ASTNode* func) {
	delete name->functionArgs(); //deallocate the name's function args
	name->functionArgs() = nullptr; //and zero them out
	delete name->function(); //deallocate the name's function
	name->function() = nullptr; //and zero it out
	name->functionArgs() = new SymbolList(*syms); //assign the symbol list
	name->function() = new ASTNode(*func); //assign the function AST node
}

//defineArray method - defines an array in the symbol table
void EVSContext::defineArray(Symbol*& name, ASTNode* size) {
	Variant newSize = eval(size); //get the size of the new Array
	name->array() = Array(newSize.intValue()); //assign the new array
}

//defineArray method 2 - defines an array in the symbol table
void EVSContext::defineArray(Symbol*& name, int size) {
	name->array() = Array(size); //assign the new array
}

//private method

//free method - deallocates the EVSContext
void EVSContext::free() {
	delete this->ast; //deallocate the AST
	this->ast = nullptr; //and zero it out
	delete[] this->symtab; //deallocate the symbol table
	this->symtab = nullptr; //and zero it out
}

//private interpreter methods

//symhash method - hashes a symbol name
unsigned EVSContext::symhash(char* symName) {
	unsigned int hash = 0; //the hash
	unsigned c; //used in the hash algorithm
	while((c = *symName++)) { //loop through the symbol name
		hash = hash * 9 ^ c; //calculate the hash
	}
	return hash; //return the hash value
}

//real eval method - evaluates the AST for the context
Variant EVSContext::eval(ASTNode* node) {
	Variant v; //the value used to evaluate the tree
	if(node == nullptr) { //if the node is invalid
		throw InvalidASTException("AST is null in eval method"); //then throw an exception
	}
	switch(node->getNodeType()) { //switch on the node's type
		case EnumNodeType::MATH: //math node found
			{
				MathNode* mNode = dynamic_cast<MathNode*>(node); //get a MathNode instance from the AST node
				switch(mNode->getOperation()) { //switch on the math operation
					case EnumMathOps::ADD: //addition node
						{
							//calculate the addition
							v = eval(node->getLeftBranch()); //eval the left branch
							v += eval(node->getRightBranch());
							break;
						}
					case EnumMathOps::SUB: //subtraction node
						{
							//calculate the subtraction
							v = eval(node->getLeftBranch()); //eval the left branch
							v -= eval(node->getRightBranch());
							break;
						}
					case EnumMathOps::MPY: //multiplication node
						{
							//calculate the multiplication
							v = eval(node->getLeftBranch()); //eval the left branch
							v *= eval(node->getRightBranch());
							break;
						}
					case EnumMathOps::DIV: //division node
						{
							//calculate the division
							v = eval(node->getLeftBranch()); //eval the left branch
							v /= eval(node->getRightBranch());
							break;
						}
					case EnumMathOps::MOD: //modulus node
						{
							//calculate the modulus
							v = eval(node->getLeftBranch()); //eval the left branch
							v %= eval(node->getRightBranch());
							break;
						}
					case EnumMathOps::ABS: //absolute value node
						{
							//calculate the absolute value
							v = eval(node->getLeftBranch()); //eval and assign the left branch
							v.abs(); //apply the absolute value operation
							break;
						}
					case EnumMathOps::NEG: //negation node
						{
							//calculate the negation
							v = eval(node->getLeftBranch()); //eval and assign the left branch
							v.neg(); //apply the negation
							break;
						}
					default: //unknown type
						{
							//throw an exception
							throw InvalidASTException("Unknown math node type");
						}
				}
				break;
			}
		case EnumNodeType::LOGIC: //logic node found
			{
				LogicNode* lNode = dynamic_cast<LogicNode*>(node); //get a LogicNode instance from the ASTNode
				switch(lNode->getOperation()) { //switch on the logical operation
					case EnumLogicOps::AND: //logical AND node
						{
							//evaluate the AND
							v = eval(node->getLeftBranch()) && eval(node->getRightBranch());
							break;
						}
					case EnumLogicOps::OR: //logical OR node
						{
							//evaluate the OR
							v = eval(node->getLeftBranch()) || eval(node->getRightBranch());
							break;
						}
					case EnumLogicOps::NOT: //logical NOT node
						{
							//evaluate the NOT
							Variant temp = eval(node->getLeftBranch()); //eval and assign the branch
							v = !temp; //negate the assigned Variant and assign it
							break;
						}
					case EnumLogicOps::XOR: //logical XOR node
						{
							//evaluate the XOR
							Variant x = eval(node->getLeftBranch()); //eval and assign the left branch
							Variant y = eval(node->getRightBranch()); //eval and assign the right
							v = (x.boolValue() && !y) || (!x && y.boolValue()); //get the XOR value
							break;
						}
					default: //unknown operation
						{
							//throw an exception
							throw InvalidASTException("Unknown logic node type");
						}
				}
				break;
			}
		case EnumNodeType::COMP: //comparison node found
			{
				CompNode* cNode = dynamic_cast<CompNode*>(node); //get a CompNode instance from the ASTNode
				switch(cNode->getComparisonType()) { //switch on the comparison type
					case EnumCompType::EQUAL: //equality operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) == eval(node->getRightBranch());
							break;
						}
					case EnumCompType::NEQUAL: //inequality operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) != eval(node->getRightBranch());
							break;
						}
					case EnumCompType::LTHAN: //less-than operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) < eval(node->getRightBranch());
							break;
						}
					case EnumCompType::GTHAN: //greater-than operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) > eval(node->getRightBranch());
							break;
						}

					case EnumCompType::LTOE: //less-than-or-equal-to operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) <= eval(node->getRightBranch());
							break;
						}
					case EnumCompType::GTOE: //greater-than-or-equal-to operator
						{
							//evaluate the comparison
							v = eval(node->getLeftBranch()) >= eval(node->getRightBranch());
							break;
						}
					default: //unknown operation
						{
							//throw an exception
							throw InvalidASTException("Unknown comparison node type");
						}
				}
				break;
			}
		case EnumNodeType::LIST: //expression list
			{
				eval(node->getLeftBranch()); //evaluate the left branch
				v = eval(node->getRightBranch()); //evaluate and assign the right branch
				break;
			}
		case EnumNodeType::IF: //if statement
			{
				FlowNode* fNode = dynamic_cast<FlowNode*>(node); //get a FlowNode instance
				Variant test = eval(fNode->getCondition()); //evaluate the condition
				if(test.boolValue()) { //if the condition evaluates to true
					v = eval(fNode->getThenBranch()); //then evaluate the then branch
				} else { //if the condition evaluates to false
					if(fNode->getElseBranch() != nullptr) { //if the else branch exists
						v = eval(fNode->getElseBranch()); //then evaluate it
					} else { //if it doesn't
						v = 0; //then zero the return value
					}
				}
				break;
			}
		case EnumNodeType::WHL: //while statement
			{
				FlowNode* fNode = dynamic_cast<FlowNode*>(node); //get a FlowNode instance
				while(eval(fNode->getCondition()) != false) { //execute the while loop
					v = eval(fNode->getThenBranch()); //evaluate the statements
				}
				//the value of the last statement is the value of the loop
				break;
			}
		case EnumNodeType::REF: //symbol reference
			{
				SymbolRef* rNode = dynamic_cast<SymbolRef*>(node); //get a symbol reference
				v = rNode->getSymbol()->value(); //assign the value of the reference to the return value
				break;
			}
		case EnumNodeType::EQU: //assignment
			{
				GenAsgnNode* aNode = dynamic_cast<GenAsgnNode*>(node); //get a general assignment node
				switch(aNode->getAssignType()) { //switch on the assignment type of the node
					case EnumAsgnType::VTV: //value-to-value assignment
						{
							VTVAsgnNode* vNode = dynamic_cast<VTVAsgnNode*>(aNode); //cast the node
							//assign the value
							vNode->symbol()->value() = eval(vNode->getValueNode());
							v = true;
							break;
						}
					case EnumAsgnType::VTIA: //value-to-array-dereference assignment
						{
							VTIAAsgnNode* vNode = dynamic_cast<VTIAAsgnNode*>(aNode); //cast the node
							//assign the value
							Variant index = eval(vNode->getArrayRef()->getIndexNode()); //get index
							Array arr = vNode->getArrayRef()->array(); //get the array
							vNode->symbol()->value() = arr.objectAtIndex(index.intValue());
							v = true;
							break;
						}
					case EnumAsgnType::ATA: //array-to-array assignment
						{
							ATAAsgnNode* vNode = dynamic_cast<ATAAsgnNode*>(aNode); //cast the node
							//assign the array
							Array arr = vNode->getRval()->array(); //get the rvalue array
							vNode->lval()->array() = arr; //assign the rval to the lval
							v = true;
							break;
						}
					case EnumAsgnType::AITIA: //array-dereference-to-array-dereference assignment
						{
							//cast the node
							AITIAAsgnNode* vNode = dynamic_cast<AITIAAsgnNode*>(aNode); 
							//get the value to assign
							Variant rindex = eval(vNode->getRval()->getIndexNode()); //get the r index
							Array rarr = vNode->getRval()->array(); //get the right array
							Variant rval = rarr.objectAtIndex(rindex.intValue()); //get the rval
							Variant lindex = eval(vNode->lval()->getIndexNode()); //get the l index
							//assign the value
							vNode->lval()->array().objectAtIndex(lindex.intValue()) = rval;
							v = true;
							break;
						}
					case EnumAsgnType::AITV: //array-dereference-to-value assignment
						{
							//cast the node
							AITVAsgnNode* vNode = dynamic_cast<AITVAsgnNode*>(aNode);
							//get the value to assign
							Variant rval = eval(vNode->getRval()); //evaluate the right-hand value
							//get the index of the target array
							Variant index = eval(vNode->lval()->getIndexNode());
							//assign the array
							vNode->lval()->array().objectAtIndex(index.intValue()) = rval;
							v = true;
							break;
						}
					default: //unknown type
						{
							//throw an exception
							throw InvalidASTException("Unknown assignment node type");
						}
				}
				break;
			}
		case EnumNodeType::GAME: //game call
			{
				GameCall* gCall = dynamic_cast<GameCall*>(node); //get a game call pointer
				v = this->callGame(gCall); //execute the game call
				break;
			}
		case EnumNodeType::FUNC: //built-in function call
			{
				FnCall* fCall = dynamic_cast<FnCall*>(node); //get a function call pointer
				v = this->callBuiltIn(fCall); //call the built-in function
				break;
			}
		case EnumNodeType::CALL: //user-defined function call
			{
				UserFnCall* ufCall = dynamic_cast<UserFnCall*>(node); //get a user function call pointer
				v = this->callUser(ufCall); //call the user-defined function
				break;
			}
		case EnumNodeType::CONST: //constant value
			{
				ConstNode* cNode = dynamic_cast<ConstNode*>(node); //get a constant node pointer
				v = cNode->getValue(); //assign the value
				break;
			}
		case EnumNodeType::ARRAY: //array dereference
			{
				ArrayRef* aNode = dynamic_cast<ArrayRef*>(node); //get an array reference pointer
				Variant index = eval(aNode->getIndexNode()); //get the index to access the array with
				v = aNode->array().objectAtIndex(index.intValue()); //assign the return value
				break;
			}
		default: //unknown node
			{
				//throw an exception
				throw InvalidASTException("Unknown AST node encountered");
			}
	}
	return v;
}

//callBuiltIn method - calls a built in function
Variant EVSContext::callBuiltIn(FnCall* func) {
	EnumFunc funcType = func->getFunctionID(); //get the function ID for the function
	Variant v = eval(func->getLeftBranch()); //evaluate the left AST branch of the function to obtain the function argument

	switch(funcType) { //switch on the function type
		case EnumFunc::SQRT: //square root function
			{
				return Variant(sqrt(v.doubleValue())); //return the square root of the Variant
			}
		case EnumFunc::EXP: //exponentiation
			{
				return Variant(exp(v.doubleValue())); //return e to the power of the Variant
			}
		case EnumFunc::LOG: //logarithm
			{
				return Variant(log(v.doubleValue())); //return the base ten log of the Variant
			}
		default: //unknown function
			{
				//throw an exception
				throw InvalidASTException("Unknown function found");
			}
	}
}

//callGame method - executes a game call
Variant EVSContext::callGame(GameCall* call) {
	EnumCall callType = call->getCallID();
	if(call->getLeftBranch() != nullptr) { //if the left branch exists, meaning the call has an argument
		Variant arg = eval(call->getLeftBranch()); //obtain the argument
		switch(callType) { //switch on the call type
			case EnumCall::SLEEP: //sleep game call
				{
					call_sleep(arg.intValue()); //sleep for the given time
					return Variant(0); //return a zeroed Variant
					break;
				}
			case EnumCall::USLEEP: //alternative sleep game call
				{
					call_usleep(arg.intValue()); //sleep for the given time
					return Variant(0); //return a zeroed Variant
					break;
				}
			default: //unknown call
				{
					//throw an exception
					throw InvalidASTException("Unknown game call found");
				}
		}
	} else { //if there is no argument to the call
		switch(callType) { //switch on the call type
			case EnumCall::SHUTDOWN:
				{
					call_shutdownGame(); //begin the game shutdown process
					return Variant(0); //return a zeroed Variant
				}
			default: //unknown call
				{
					//throw an exception
					throw InvalidASTException("Unknown game call found");
				}
		}
	}
}

//callUser method - calls a user-defined function
Variant EVSContext::callUser(UserFnCall* ufunc) {
	Symbol* fn = new Symbol(*(ufunc->getSymbol())); //the function name
	SymbolList* symlist = nullptr; //dummy arguments 
	ASTNode* args = nullptr; //the actual args
	if(ufunc->getLeftBranch() != nullptr) { //if arguments are supplied
		args = new ASTNode(*(ufunc->getLeftBranch())); //then assign the actual args
	}
	Variant* oldValues; //the saved old arguments
	Variant* newValues; //the saved new arguments
	Variant v; //the return value of the method
	int nArgs; //the number of arguments
	int i; //a loop counter


	//verify the function pointer
	if(fn->function() == nullptr) { //if the function is null
		//throw an exception
		throw InvalidASTException("Call to null function");
	}

	symlist = new SymbolList(*(fn->functionArgs())); //copy the symbol list
	
	//count the arguments
	for(nArgs = 0; symlist; symlist = symlist->nextNode()) {
		nArgs++; //increment the argument counter
	}

	//allocate memory for saving values
	oldValues = new Variant[nArgs]; //allocate memory for the old values
	newValues = new Variant[nArgs]; //allocate memory for the new values

	//evaluate the arguments
	for(i = 0; i < nArgs; i++) { //loop through the arguments
		if(args != nullptr) { //if arguments exist for the function
			if(args->getNodeType() == EnumNodeType::LIST) { //if this is a list node
				newValues[i] = eval(args->getLeftBranch()); //then evaluate and assign the left branch
				*args = *args->getRightBranch(); //assign the argument AST node
			} else { //end of list
				newValues[i] = eval(args); //evaluate and assign the argument AST node
				delete args; //deallocate the argument
				args = nullptr; //and zero it out
			}
		}
	}

	//save the old dummy values and assign new ones
	delete symlist; //deallocate the symbol list
	symlist = nullptr; //and zero it out
	symlist = new SymbolList(*(fn->functionArgs())); //copy in another symbol list
	for(i = 0; i < nArgs; i++) {
		Symbol* s = symlist->getSymbol(); //get the symbol pointer
		oldValues[i] = s->value(); //save the value
		s->value() = newValues[i]; //load in the new value
		symlist = symlist->nextNode(); //move along the symbol list
	}

	//deallocate the new values
	delete[] newValues;
	newValues = nullptr;

	//evaluate the function
	v = eval(fn->function()); 

	//put the real dummy values back
	delete symlist; //deallocate the symbol list
	symlist = nullptr; //and zero it out
	symlist = new SymbolList(*(fn->functionArgs())); //copy in another symbol list
	for(i = 0; i < nArgs; i++) {
		Symbol* s = symlist->getSymbol(); //get the symbol pointer
		s->value() = oldValues[i]; //assign back the dummy value
		symlist = symlist->nextNode(); //move along the symbol list
	}

	//deallocate the remaining memory
	delete symlist; //deallocate the symbol list
	symlist = nullptr; //and zero it out
	delete fn; //deallocate the symbol pointer
	fn = nullptr; //and zero it out
	delete args; //deallocate the argument node
	args = nullptr; //and zero it out
	delete[] oldValues; //deallocate the old dummy values
	oldValues = nullptr; //and zero them out

	//finish
	return v; //return the result of the function evaluation 
}

//end of implementation
