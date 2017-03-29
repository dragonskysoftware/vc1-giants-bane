/*
 * ASTNode.cpp
 * Implements a class that represents an Abstract Syntax Tree node
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//include header
#include "ASTNode.h"

//constructor
ASTNode::ASTNode(EnumNodeType newType, const ASTNode* newLeft, const ASTNode* newRight)
	: nodeType(newType), left(nullptr), right(nullptr) //init the node type field and zero the branches
{
	if(newLeft != nullptr) { //if the supplied left node isn't null
		this->left = new ASTNode(*newLeft); //then copy it into this node's left branch field
	}
	if(newRight != nullptr) { //if the supplied right node isn't null
		this->right = new ASTNode(*newRight); //then copy it into this node's right branch field
	}
}

//destructor
ASTNode::~ASTNode() {
	delete this->left; //deallocate the left branch, causing a chain reaction that deallocates everything down that branch
	this->left = nullptr; //and zero the left branch
	delete this->right; //deallocate the right branch, causing a similar chain reaction
	this->right = nullptr; //and zero the right branch
}

//copy constructor
ASTNode::ASTNode(const ASTNode& ast)
	: nodeType(ast.nodeType), left(nullptr), right(nullptr) //copy the node type and zero the left and right branches
{
	if(ast.left != nullptr) { //if the other left node isn't null
		this->left = new ASTNode(*ast.left); //then copy it into this node's left branch field
	}
	if(ast.right != nullptr) { //if the other right node isn't null
		this->right = new ASTNode(*ast.right); //then copy it into this node's right branch field
	}
}

//move constructor
ASTNode::ASTNode(ASTNode&& ast)
	: nodeType(ast.nodeType), left(nullptr), right(nullptr) //move the node type and zero the left and right branches
{
	if(ast.left != nullptr) { //if the other left node isn't null
		this->left = new ASTNode(*ast.left); //then copy it into this node's left branch field
	}
	if(ast.right != nullptr) { //if the other right node isn't null
		this->right = new ASTNode(*ast.right); //then copy it into this node's right branch field
	}
	delete ast.left; //deallocate the temporary's left branch (see the destructor for details)
	ast.left = nullptr; //and zero it out
	delete ast.right; //deallocate the temporary's right branch (see the destructor)
	ast.right = nullptr; //and zero it out
}

//assignment operator
ASTNode& ASTNode::operator=(const ASTNode& src) {
	this->nodeType = src.nodeType; //assign the node type
	if(src.left != nullptr) { //if the other left node isn't null
		if(this->left == nullptr) { //if this left node is null
			this->left = new ASTNode(*src.left); //then initialize it
		} else { //if it isn't
			*this->left = *src.left; //then assign the left node
		}
	} else { //if it is
		delete this->left; //deallocate the left node
		this->left = nullptr; //and zero it out
	}
	if(src.right != nullptr) { //if the other right node isn't null
		if(this->right == nullptr) { //if this right node is null
			this->right = new ASTNode(*src.right); //then initialize it
		} else { //if it isn't
			*this->right = *src.right; //then assign the right node
		}
	} else { //if it is
		delete this->right; //deallocate the right node
		this->right = nullptr; //and zero it out
	}
	return *this; //return the object
}

//move operator
ASTNode& ASTNode::operator=(ASTNode&& src) {
	this->nodeType = src.nodeType; //move the node type
	if(src.left != nullptr) { //if the other left node isn't null
		if(this->left == nullptr) { //if this left node is null
			this->left = new ASTNode(*src.left); //then initialize it
		} else { //if it isn't
			*this->left = *src.left; //then move the left node
		}
	} else { //if it is
		delete this->left; //deallocate the left node
		this->left = nullptr; //and zero it out
	}
	if(src.right != nullptr) { //if the other right node isn't null
		if(this->right == nullptr) { //if this right node is null
			this->right = new ASTNode(*src.right); //then initialize it
		} else { //if it isn't
			*this->right = *src.right; //then move the right node
		}
	} else { //if it is
		delete this->right; //deallocate the right node
		this->right = nullptr; //and zero it out
	}
	delete src.left; //deallocate the temporary's left branch (see the destructor for details)
	src.left = nullptr; //and zero it out
	delete src.right; //deallocate the temporary's right branch (see the destructor)
	src.right = nullptr; //and zero it out
	return *this; //return the object
}

//getter methods

//getNodeType method - returns the node type of the ASTNode
EnumNodeType ASTNode::getNodeType() const {
	return this->nodeType; //return the node type field
}

//getLeftBranch method - returns the left branch of the ASTNode
ASTNode* ASTNode::getLeftBranch() {
	return this->left; //return the left branch pointer
}

//getRightBranch method - returns the right branch of the ASTNode
ASTNode* ASTNode::getRightBranch() {
	return this->right; //return the right branch pointer
}

//end of implementation
