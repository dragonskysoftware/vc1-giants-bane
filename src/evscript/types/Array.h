/*
 * Array.h
 * Declares a class that holds multiple values
 * Created by Andrew Davis
 * Created on 3/20/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ARRAY_H_INC
#define ARRAY_H_INC

//includes
#include "Variant.h"
#include "../../except/OutOfRangeException.h"
#include "../../except/InvalidStateException.h"

//class declaration
class Array final {
	//public fields and methods
	public:
		//default constructor
		Array();

		//constructor
		explicit Array(int newSize);

		//destructor
		~Array();

		//copy constructor
		Array(const Array& a);

		//move constructor
		Array(Array&& a);

		//assignment operator
		Array& operator=(const Array& src);

		//move operator
		Array& operator=(Array&& src);
	
		//getter methods
		Variant& objectAtIndex(int index); //returns a reference to the Variant object at the specified index
		int size() const; //returns the size of the Array

	//private fields and methods
	private:
		//fields
		Variant* data; //the actual array
		int arraySize; //the size of the array
};

#endif
