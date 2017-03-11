/*
 * Die.cpp
 * Implements a class that acts as a superclass for more specific die classes
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "Die.h"

//first constructor - creates a Die with a given number of sides and a random value
Die::Die(int newSides)
	: sides(newSides), value(0) //init the fields
{
	if(this->sides <= 1) { //if the side number is invalid
		throw InvalidStateException("Side count for a Die object is invalid (less than 2)"); //then throw an exception
	}
	this->seedRandomGenerator(); //start the RNG
	this->roll(); //set the value field to a random value
}

//second constructor - creates a Die with a given number of sides and a set value
Die::Die(int newSides, int newValue)
	: Die(newSides) //call other constructor
{
	if(newValue > 0 && newValue <= newSides) { //if the new value is valid
		this->value = newValue; //then assign it to the value field
	}
}

//destructor
Die::~Die() {
	//no code needed
}

//copy constructor
Die::Die(const Die& d)
	: sides(d.sides), value(d.value) //copy the fields
{
	this->seedRandomGenerator(); //start the RNG
}

//move constructor
Die::Die(Die&& d)
	: sides(d.sides), value(d.value) //move the fields
{
	this->seedRandomGenerator(); //start the RNG
}

//assignment operator
Die& Die::operator=(const Die& src) {
	this->sides = src.sides; //assign the sides field
	this->value = src.value; //assign the value field
	return *this; //return the object
}

//move operator
Die& Die::operator=(Die&& src) {
	this->sides = src.sides; //move the sides field
	this->value = src.value; //move the value field
	return *this; //return the object
}

//getter methods

//getSideCount method - returns the number of sides on the Die
int Die::getSideCount() const {
	return this->sides; //return the sides field
}

//getValue method - returns the value showing on the Die
int Die::getValue() const {
	return this->value; //return the value field
}

//other methods

//roll method - rolls the Die
void Die::roll() {
	this->value = rand() % this->sides + 1; //get a new random value using the sides field
}

//protected seedRandomGenerator method - sets up the RNG
void Die::seedRandomGenerator() const {
	std::srand(std::time(NULL)); //seed the RNG using the current time
}

//end of implementation
