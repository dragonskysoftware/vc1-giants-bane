/*
 * Variant.h
 * Defines a class that can hold any intrinsic type
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef VARIANT_H_INC
#define VARIANT_H_INC

//include
#include "../../util/strdup.h"
#include <string>
#include <sstream>
#include <cstdlib>

//enum definition for the tagged union
enum class VariantType {
	INT, //integer type
	BOOL, //boolean type
	CHAR, //character type
	DBL, //double type
	FLT, //float type
	STR //string type
};

//class definition
class Variant final {
	//public fields and methods
	public:
		//default constructor - constructs to a value of 0
		Variant();

		//constructor 1 - constructs from an integer
		Variant(int newInt);

		//constructor 2 - constructs from a boolean
		Variant(bool newBool);

		//constructor 3 - constructs from a character
		Variant(char newChar);

		//constructor 4 - constructs from a double
		Variant(double newDouble);

		//constructor 5 - constructs from a float
		Variant(float newFloat);

		//constructor 6 - constructs from a char string
		Variant(const char* newString);

		//constructor 7 - constructs from an std::string
		Variant(std::string newString);

		//destructor
		~Variant();

		//copy constructor
		Variant(const Variant& v);

		//move constructor
		Variant(Variant&& v);

		//assignment operator
		Variant& operator=(const Variant& src);

		//move operator
		Variant& operator=(Variant&& src);

		//overloaded assignment operators
		Variant& operator=(int newInt); //assigns to an int
		Variant& operator=(bool newBool); //assigns to a bool
		Variant& operator=(char newChar); //assigns to a character
		Variant& operator=(double newDouble); //assigns to a double
		Variant& operator=(float newFloat); //assigns to a float
		Variant& operator=(const char* newString); //assigns to a character string
		Variant& operator=(std::string newString); //assigns to an std::string

		//math operators
		Variant& operator+=(const Variant& other); //addition operator
		Variant& operator-=(const Variant& other); //subtraction operator
		Variant& operator*=(const Variant& other); //multiplication operator
		Variant& operator/=(const Variant& other); //division operator
		Variant& operator%=(const Variant& other); //modulus operator
		Variant& abs(); //absolute value operator
		Variant& neg(); //negation operator

		//logic operators
		bool operator!() const; //NOT operator
		bool operator&&(const Variant& other) const; //AND operator
		bool operator||(const Variant& other) const; //inclusive OR operator

		//comparison operators
		bool operator==(const Variant& other); //equality operator
		bool operator!=(const Variant& other); //inequality operator
		bool operator<(const Variant& other); //less-than operator
		bool operator>(const Variant& other); //greater-than operator
		bool operator<=(const Variant& other); //ltoe operator
		bool operator>=(const Variant& other); //gtoe operator

		//getter methods
		VariantType getType() const; //returns the type stored in the Variant
		int intValue() const; //returns the Variant as an integer
		bool boolValue() const; //returns the Variant as a boolean
		char charValue() const; //returns the Variant as a character
		double doubleValue() const; //returns the Variant as a double
		float floatValue() const; //returns the Variant as a float
		std::string stringValue() const; //returns the Variant as a string

	//private fields and methods
	private:
		//private method
		void free(); //deletes assets related to an object of type Variant

		//fields
		VariantType type; //the type stored in the union
		
		//define the union that holds the variant values
		union u_val {
			int i; //the integer in the Variant
			bool b; //the boolean in the Variant
			char c; //the character in the Variant
			double d; //the double in the Variant
			float f; //the float in the Variant
			char* s; //the string in the variant
		} value;

};


#endif
