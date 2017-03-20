/*
 * Array.cpp
 * Implements a class that holds multiple values
 * Created by Andrew Davis
 * Created on 3/20/2017
 * Open source (GPL license)
 */

//include header
#include "Array.h"

//default constructor
Array::Array()
	: Array(1) //call other constructor
{
	//no code needed
}

//constructor
Array::Array(int newSize)
	: data(nullptr), arraySize(newSize) //init the fields
{
	if(this->arraySize <= 0) { //if the given array size is invalid
		throw InvalidStateException("Invalid size given in Array class constructor"); //then throw an exception
	}
	this->data = new Variant[this->arraySize]; //allocate the array
	for(int i = 0; i < this->arraySize; i++) { //loop through the array
		this->data[i] = Variant(); //and initialize each entry to 0
	}
}

//destructor
Array::~Array() {
	delete[] this->data; //deallocate the data field
	this->data = nullptr; //and zero it out
}

//copy constructor
Array::Array(const Array& a)
	: data(nullptr), arraySize(a.arraySize) //copy the fields
{
	if(a.data != nullptr) { //if the other data isn't null
		this->data = new Variant[this->arraySize]; //allocate the data
		for(int i = 0; i < this->arraySize; i++) { //loop through the array
			this->data[i] = a.data[i]; //and copy the values from the other array
		}
	}
}

//move constructor
Array::Array(Array&& a)
	: data(nullptr), arraySize(a.arraySize) //move the fields
{
	if(a.data != nullptr) { //if the other data isn't null
		this->data = new Variant[this->arraySize]; //allocate the data
		for(int i = 0; i < this->arraySize; i++) { //loop through the array
			this->data[i] = a.data[i]; //and move the values from the other array
		}
	}
	delete[] a.data; //deallocate the temporary's data field
	a.data = nullptr; //and zero it out
}

//assignment operator
Array& Array::operator=(const Array& src) {
	this->arraySize = src.arraySize; //assign the array size
	delete[] this->data; //deallocate this object's data field
	this->data = nullptr; //and zero it out
	if(src.data != nullptr) { //if the other data isn't null
		this->data = new Variant[this->arraySize]; //allocate the data
		for(int i = 0; i < this->arraySize; i++) { //loop through the array
			this->data[i] = src.data[i]; //and assign the values from the other array
		}
	}
	return *this; //return the object
}

//move operator
Array& Array::operator=(Array&& src) {
	this->arraySize = src.arraySize; //move the array size
	delete[] this->data; //deallocate this object's data field
	this->data = nullptr; //and zero it out
	if(src.data != nullptr) { //if the other data isn't null
		this->data = new Variant[this->arraySize]; //allocate the data
		for(int i = 0; i < this->arraySize; i++) { //loop through the array
			this->data[i] = src.data[i]; //and move the values from the other array
		}
	}
	delete[] src.data; //deallocate the temporary's data field
	src.data = nullptr; //and zero it out
	return *this; //return the object
}

//getter methods

//objectAtIndex method - returns a reference to the Variant object at the specified index
Variant& Array::objectAtIndex(int index) {
	if(index < 0 || index >= this->arraySize) { //if the index is out of range
		throw OutOfRangeException(index); //then throw an exception
	}
	return this->data[index]; //return the data value at the index
}

//size method - returns the size of the array
int Array::size() const {
	return this->arraySize; //return the array size field
}

//end of implementation
