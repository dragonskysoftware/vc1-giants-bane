/*
 * DieEquation.cpp
 * Implements a class that represents a die roll in equation form
 * Created by Andrew Davis
 * Created on 6/30/2017
 * Open source (GPL license)
 */

//include header
#include "DieEquation.h"

//default constructor - used for deserialization
DieEquation::DieEquation()
	: data() //default the data field
{
	//no code needed
}

//first constructor - constructs from a C string
DieEquation::DieEquation(const char* newData)
	: data(newData) //init the data field
{
	//no code needed
}

//second constructor - constructs from a std::string
DieEquation::DieEquation(const std::string& newData)
	: DieEquation(newData.c_str()) //call the first constructor
{
	//no code needed
}

//destructor
DieEquation::~DieEquation() {
	//no code needed
}

//copy constructor
DieEquation::DieEquation(const DieEquation& de)
	: data(de.data) //copy the data field
{
	//no code needed
}

//move constructor
DieEquation::DieEquation(DieEquation&& de)
	: data(de.data) //move the data field
{
	//no code needed
}

//assignment operator
DieEquation& DieEquation::operator=(const DieEquation& src) {
	this->data = src.data; //assign the data field
	return *this; //and return the object
}

//move operator
DieEquation& DieEquation::operator=(DieEquation&& src) {
	this->data = src.data; //move the data field
	return *this; //and return the object
}

//getter method

//getData method - returns the equation data
const std::string& DieEquation::getData() const {
	return this->data; //return the data field
}

//serialization code

//serialization function
std::ostream& operator<<(std::ostream& os, const DieEquation& de) {
	os << de.data << '\n'; //serialize the data field
	return os; //and return the stream
}

//deserialization function
std::istream& operator>>(std::istream& is, DieEquation& de) {
	is >> de.data; //deserialize the data field
	return is; //and return the stream
}

//end of implementation
