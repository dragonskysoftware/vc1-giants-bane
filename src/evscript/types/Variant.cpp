/*
 * Variant.cpp
 * Implements a class that can hold any intrinsic type
 * Created by Andrew Davis
 * Created on 3/18/2017
 * Open source (GPL license)
 */

//include header
#include "Variant.h"

//default constructor - constructs to a value of 0
Variant::Variant()
	: Variant(0) //call integer constructor
{
	//no code needed
}

//constructor 1 - constructs from an integer
Variant::Variant(int newInt)
	: type(VariantType::INT) //init the type field
{
	this->value.i = newInt; //init the int field of the value union
}

//constructor 2 - constructs from a boolean
Variant::Variant(bool newBool)
	: type(VariantType::BOOL) //init the type field
{
	this->value.b = newBool; //init the bool field of the value union
}

//constructor 3 - constructs from a character
Variant::Variant(char newChar)
	: type(VariantType::CHAR) //init the type field
{
	this->value.c = newChar; //init the char field of the value union
}

//constructor 4 - constructs from a double
Variant::Variant(double newDouble)
	: type(VariantType::DBL) //init the type field
{
	this->value.d = newDouble; //init the double field of the value union
}

//constructor 5 - constructs from a float
Variant::Variant(float newFloat)
	: type(VariantType::FLT) //init the type field
{
	this->value.f = newFloat; //init the float field of the value union
}

//constructor 6 - constructs from a char string
Variant::Variant(const char* newString)
	: type(VariantType::STR) //init the type field
{
	this->value.s = strdup(newString); //init the string field of the value union
}

//constructor 7 - constructs from an std::string
Variant::Variant(std::string newString)
	: Variant(newString.c_str()) //call constructor 6
{
	//no code needed
}

//destructor
Variant::~Variant() {
	this->free(); //free the allocated assets (if any)
}

//copy constructor
Variant::Variant(const Variant& v)
	: type(v.type), value(v.value) //copy the fields
{
	//no code needed
}

//move constructor
Variant::Variant(Variant&& v)
	: type(v.type), value(v.value) //move the fields
{
	v.free(); //free the temporary
}

//assignment operator
Variant& Variant::operator=(const Variant& src) {
	this->type = src.type; //assign the type field
	this->value = src.value; //assign the value union
	return *this; //return the object
}

//move operator
Variant& Variant::operator=(Variant&& src) {
	this->type = src.type; //move the type field
	this->value = src.value; //move the value union
	src.free(); //free the temporary
	return *this; //return the object
}

//overloaded assignment operators

//assigns to an int
Variant& Variant::operator=(int newInt) {
	this->free(); //free the string value if it exists
	this->type = VariantType::INT; //assign the type
	this->value.i = newInt; //assign the value
	return *this; //and return the object
}

//assigns to a bool
Variant& Variant::operator=(bool newBool) {
	this->free(); //free the string value if it exists
	this->type = VariantType::BOOL; //assign the type
	this->value.b = newBool; //assign the value
	return *this; //and return the object
}

//assigns to a char
Variant& Variant::operator=(char newChar) {
	this->free(); //free the string value if it exists
	this->type = VariantType::CHAR; //assign the type
	this->value.c = newChar; //assign the value
	return *this; //and return the object
}

//assigns to a double
Variant& Variant::operator=(double newDouble) {
	this->free(); //free the string value if it exists
	this->type = VariantType::DBL; //assign the type
	this->value.d = newDouble; //assign the value
	return *this; //and return the object
}

//assigns to a float
Variant& Variant::operator=(float newFloat) {
	this->free(); //free the string value if it exists
	this->type = VariantType::FLT; //assign the type
	this->value.f = newFloat; //assign the value
	return *this; //and return the object
}

//assigns to a char string
Variant& Variant::operator=(const char* newString) {
	this->free(); //free the string value if it exists
	this->type = VariantType::STR; //assign the type
	this->value.s = strdup(newString); //assign the value
	return *this; //and return the object
}

//assigns to a std::string
Variant& Variant::operator=(std::string newString) {
	Variant::operator=(newString.c_str()); //call char string operator
	return *this; //and return the object
}

//getter methods

//getType method - returns the type stored in the Variant
VariantType Variant::getType() const {
	return this->type; //return the type field
}

//intValue method - returns the Variant as an int
int Variant::intValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				return this->value.i; //return the value field
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				return this->value.b ? 1 : 0; //return the bool as an int
			}
		//character is stored
		case VariantType::CHAR:
			{
				return (int)(this->value.c); //return the char as an int
			}
		//double is stored
		case VariantType::DBL:
			{
				return (int)(this->value.d); //return the double as an int
			}
		//float is stored
		case VariantType::FLT:
			{
				return (int)(this->value.f); //return the float as an int
			}
		//string is stored
		case VariantType::STR:
			{
				return atoi(this->value.s); //return the string as an int
			}
		default:
			{
				return 0; //return nothing
			}
	}
}

//boolValue method - returns the Variant as a bool
bool Variant::boolValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				return this->value.i != 0; //return the int as a bool
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				return this->value.b; //return the bool
			}
		//character is stored
		case VariantType::CHAR:
			{
				return this->value.c != 0; //return the char as a bool
			}
		//double is stored
		case VariantType::DBL:
			{
				return this->value.d != 0.0; //return the double as a bool
			}
		//float is stored
		case VariantType::FLT:
			{
				return this->value.f != 0.0; //return the float as a bool
			}
		//string is stored
		case VariantType::STR:
			{
				return this->value.s[0] != '\0'; //return the string as a bool
			}
		default:
			{
				return false; //return nothing
			}
	}
}

//charValue method - returns the Variant as a character
char Variant::charValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				return static_cast<char>(this->value.i); //return the int as a char
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				return this->value.b ? 1 : 0; //return the bool as a char
			}
		//character is stored
		case VariantType::CHAR:
			{
				return this->value.c; //return the char
			}
		//double is stored
		case VariantType::DBL:
			{
				return static_cast<char>(this->value.d); //return the double as a char
			}
		//float is stored
		case VariantType::FLT:
			{
				return static_cast<char>(this->value.f); //return the float as a char
			}
		//string is stored
		case VariantType::STR:
			{
				return this->value.s[0]; //return the string's first character
			}
		default:
			{
				return 0; //return nothing
			}
	}
}

//doubleValue method - returns the Variant as a double
double Variant::doubleValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				return static_cast<double>(this->value.i); //return the int as a double
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				return this->value.b ? 1.0 : 0.0; //return the bool as a double
			}
		//character is stored
		case VariantType::CHAR:
			{
				return static_cast<double>(this->value.c); //return the char as a double
			}
		//double is stored
		case VariantType::DBL:
			{
				return this->value.d; //return the double
			}
		//float is stored
		case VariantType::FLT:
			{
				return static_cast<double>(this->value.f); //return the float as a double
			}
		//string is stored
		case VariantType::STR:
			{
				return atof(this->value.s); //return the string as a double
			}
		default:
			{
				return 0.0; //return nothing
			}
	}
}

//floatValue method - returns the Variant as a float
float Variant::floatValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				return static_cast<float>(this->value.i); //return the int as a float
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				return this->value.b ? 1.0 : 0.0; //return the bool as a double
			}
		//character is stored
		case VariantType::CHAR:
			{
				return static_cast<float>(this->value.c); //return the char as a float
			}
		//double is stored
		case VariantType::DBL:
			{
				return static_cast<float>(this->value.d); //return the double as a float
			}
		//float is stored
		case VariantType::FLT:
			{
				return this->value.f; //return the float
			}
		//string is stored
		case VariantType::STR:
			{
				double dbl = atof(this->value.s); //get the string as a double
				return static_cast<float>(dbl); //and return the double as a float
			}
		default:
			{
				return 0.0; //return nothing
			}
	}
}

//stringValue method - returns the Variant as a string
std::string Variant::stringValue() const {
	//handle different types
	switch(this->type) {
		//integer is stored
		case VariantType::INT:
			{
				std::stringstream ss; //get a stream to make a string
				ss << this->value.i; //add the value
				return ss.str(); //return the string
			}
		//boolean is stored
		case VariantType::BOOL:
			{
				std::stringstream ss; //get a stream to make a string
				ss << this->value.b; //add the value
				return ss.str(); //return the string
			}
		//character is stored
		case VariantType::CHAR:
			{
				std::stringstream ss; //get a stream to make a string
				ss << this->value.c; //add the value
				return ss.str(); //return the string
			}
		//double is stored
		case VariantType::DBL:
			{
				std::stringstream ss; //get a stream to make a string
				ss << this->value.d; //add the value
				return ss.str(); //return the string
			}
		//float is stored
		case VariantType::FLT:
			{
				std::stringstream ss; //get a stream to make a string
				ss << this->value.f; //add the value
				return ss.str(); //return the string
			}
		//string is stored
		case VariantType::STR:
			{
				return std::string(this->value.s); //return the string
			}
		default:
			{
				return ""; //return nothing
			}
	}
}

//private free method - frees the string memory if it's allocated
void Variant::free() {
	if(this->type == VariantType::STR) { //if the Variant holds a string
		delete[] this->value.s; //deallocate the string value
		this->value.s = nullptr; //and zero it out
	}
}

//end of implementation

