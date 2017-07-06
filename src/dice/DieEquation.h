/*
 * DieEquation.h
 * Declares a class that represents a die roll in equation form
 * Created by Andrew Davis
 * Created on 6/30/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_CLS_H
#define DIE_EQN_CLS_H

//includes
#include <iostream>
#include <string>

//class declaration
class DieEquation final {
	//public fields and methods
	public:
		//default constructor - used for deserialization
		DieEquation();

		//constructor 1 - constructs from a C string
		DieEquation(const char* newData);

		//constructor 2 - constructs from a std::string
		explicit DieEquation(const std::string& newData);

		//destructor
		~DieEquation();

		//copy constructor
		DieEquation(const DieEquation& de);

		//move constructor
		DieEquation(DieEquation&& de);

		//assignment operator
		DieEquation& operator=(const DieEquation& src);

		//move operator
		DieEquation& operator=(DieEquation&& src);

		//getter method

		const std::string& getData() const; //returns the equation

		//serialization code

		//serialization operator
		friend std::ostream& operator<<(std::ostream& os, const DieEquation& de);

		//deserialization operator
		friend std::istream& operator>>(std::istream& is, DieEquation& de);

	//private fields and methods
	private:
		//field
		std::string data; //the equation data

};

#endif
