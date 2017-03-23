/*
 * TempFile.h
 * Declares a class that represents a temporary file
 * Created by Andrew Davis
 * Created on 3/22/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef TEMP_FILE_H
#define TEMP_FILE_H

//includes
#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include "functions.h"

//class declaration
class TempFile final {
	//public fields and methods
	public:
		//constructor
		TempFile();

		//destructor
		~TempFile();

		//copy constructor
		TempFile(const TempFile& tf);

		//move constructor
		TempFile(TempFile&& tf);

		//assignment operator
		TempFile& operator=(const TempFile& src);

		//move operator
		TempFile& operator=(TempFile&& src);

		//friendly insertion and extraction operators
		friend std::ostream& operator<<(std::ostream& os, const TempFile& tf); //insertion operator
		friend std::istream& operator>>(std::istream& is, TempFile& tf); //extraction operator

		//getter method
		const std::string& getFileName() const; //returns the filename of the TempFile

	//private fields and methods
	private:
		//private method
		void free(); //deallocates and closes down an instance of a TempFile

		//fields
		static unsigned long long fileID; //the ID of the temporary file (starts at 0 and increments for each file)
		std::string fileName; //the name of the file
};

#endif
