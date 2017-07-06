/*
 * NullASTException.cpp
 * Implements an exception that is thrown when a null AST node is found
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//include header
#include "NullASTException.h"

//overridden what method - called when the exception is thrown
const char* NullASTException::what() const throw() {
	return "Null AST node encountered"; //return the error message
}

//end of implementation
