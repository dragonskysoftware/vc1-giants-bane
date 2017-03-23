/*
 * TempFile.cpp
 * Implements a class that represents a temporary file
 * Created by Andrew Davis
 * Created on 3/22/2017
 * Open source (GPL license)
 */

//include header
#include "TempFile.h"

//init the static fileID member
unsigned long long TempFile::fileID = 0; //used to created unique file names

//constructor
TempFile::TempFile()
	: fileName("EvScriptFile") //init the field to the first part of the filename
{
	if(fileID == ULLONG_MAX) { //if the file ID counter has reached its max
		fileID = 0; //then reset it to 0
	}
	this->fileName += std::to_string(fileID++); //append the file ID to the file name
	this->fileName += ".evsc"; //append the file extension
	std::ofstream creator(this->fileName.c_str()); //create the file
	creator.close(); //finish the file creation
}

//destructor
TempFile::~TempFile() {
	this->free(); //deallocate and clean up the object
}

//copy constructor
TempFile::TempFile(const TempFile& tf)
	: fileName(tf.fileName) //copy the field
{
	//no code needed
}

//move constructor
TempFile::TempFile(TempFile&& tf)
	: fileName(tf.fileName) //move the field
{
	tf.free(); //deallocate the temporary
}

//assignment operator
TempFile& TempFile::operator=(const TempFile& src) {
	this->fileName = src.fileName; //assign the file name
	return *this; //return the object
}

//move operator
TempFile& TempFile::operator=(TempFile&& src) {
	this->fileName = src.fileName; //move the file name
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//insertion operator
std::ostream& operator<<(std::ostream& os, const TempFile& tf) {
	std::ofstream ofs(tf.fileName.c_str()); //get an output file stream
	os << ofs.rdbuf(); //stream out the file stream
	return os; //return the stream object
}

//extraction operator
std::istream& operator>>(std::istream& is, TempFile& tf) {
	std::ifstream ifs(tf.fileName.c_str()); //get an input file stream
	is >> ifs.rdbuf(); //stream into the file stream
	return is; //return the stream object
}

//getter method

//getFileName method - returns the filename of the TempFile
const std::string& TempFile::getFileName() const {
	return this->fileName; //return the filename field
}

//private method

//free method - deallocates and cleans up the object
void TempFile::free() {
	if(fileExistsAtPath(this->fileName)) { //if the temp file exists
		remove(this->fileName.c_str()); //delete the temporary file
	}
}

//end of implementation
