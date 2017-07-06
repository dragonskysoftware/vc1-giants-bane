/*
 * Die.cpp
 * Implements a class that represents a die with an arbitrary side count
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "Die.h"

//constructor
Die::Die(int numSides)
	: sides(numSides), value(1) //init the fields
{
	//validate the side count (has to be 2 or more)
	if(this->sides <= 1) { //if the side count is invalid
		//then throw an exception
		throw BadDieException("Invalid side count given");
	}
	this->seedRNG(); //seed the RNG
	this->roll(); //and randomize the value field
}

//destructor
Die::~Die() {
	//no code needed
}

//copy constructor
Die::Die(const Die& d)
	: sides(d.sides), value(d.value) //copy the fields
{
	this->seedRNG(); //and seed the RNG
}

//move constructor
Die::Die(Die&& d)
	: sides(d.sides), value(d.value) //move the fields
{
	this->seedRNG(); //and seed the RNG
}

//assignment operator
Die& Die::operator=(const Die& src) {
	this->sides = src.sides; //assign the side count field
	this->value = src.value; //assign the value field
	return *this; //and return the object
}

//move operator
Die& Die::operator=(Die&& src) {
	this->sides = src.sides; //move the side count field
	this->value = src.value; //move the value field
	return *this; //and return the object
}

//getter methods

//getSideCount method - returns the number of sides on the Die
int Die::getSideCount() const {
	return this->sides; //return the side count field
}

//getValue method - returns the value last rolled
int Die::getValue() const {
	return this->value; //return the value field
}

//other methods

//roll method - rolls the Die
void Die::roll() {
	this->value = (rand() % this->sides) + 1; //randomize the value
}

//protected seedRNG method - seeds the RNG
void Die::seedRNG() {
	srand(time(NULL)); //seed the RNG
}

//end of implementation
