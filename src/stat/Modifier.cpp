/*
 * Modifier.cpp
 * Implements a class that represents a statistic or skill modifier
 * Created by Andrew Davis
 * Created on 3/14/2017
 * All rights reserved
 */

//include header
#include "Modifier.h"

//constructor
Modifier::Modifier(int score)
	: value(0) //init the value to 0
{
	this->calculateValue(score); //calculate the modifier value
}

//destructor
Modifier::~Modifier() {
	//no code needed
}

//copy constructor
Modifier::Modifier(const Modifier& m)
	: value(m.value) //copy the value field
{
	//no code needed
}

//move constructor
Modifier::Modifier(Modifier&& m)
	: value(m.value) //move the value field
{
	//no code needed
}

//assignment operator
Modifier& Modifier::operator=(const Modifier& src) {
	this->value = src.value; //assign the value field
	return *this; //return the object
}

//move operator
Modifier& Modifier::operator=(Modifier&& src) {
	this->value = src.value; //move the value field
	return *this; //return the object
}

//getter methods

//getValue method - returns the value of the Modifier
int Modifier::getValue() const {
	return this->value; //return the value field
}

//isPositive method - returns whether or not the Modifier is positive
bool Modifier::isPositive() const {
	return this->value >= 0; //return the sign of the Modifier
}

//other methods

//recalculate method - recalculates the value of the Modifier based on a new ability score
void Modifier::recalculate(int newScore) {
	this->calculateValue(newScore); //call the protected calculateValue method to calculate the modifier
}

//save and load code

//save operator
std::ostream& operator<<(std::ostream& os, const Modifier& m) {
	os << m.value; //save the value field
	return os; //return the stream
}

//load operator
std::istream& operator>>(std::istream& is, Modifier& m) {
	is >> m.value; //load the value field
	return is; //return the stream
}

//protected calculateValue method - calcuates the value of the Modifier based on an integer ability score
void Modifier::calculateValue(int score) {
	if(score < SCORE_MIN || score > SCORE_MAX) { //if the score is invalid
		throw InvalidAbilityScoreException(score); //then throw an exception
	}
	double doubleValue = floor((score - 10) / 2); //calculate the ability score as a double
	this->value = static_cast<int>(doubleValue); //and cast it to an int, assigning it to the value field of the Modifier
}

//end of implementation
