/*
 * GameDB.cpp
 * Implements a singleton class that holds the important game data for Giant's Bane
 * Created by Andrew Davis
 * Created on 3/12/2017
 * Open source (GPL license)
 */

//include header
#include "GameDB.h"

//private ructor
GameDB::GameDB()
	: intDB(), floatDB(), charDB(), boolDB(), stringDB() //init the database maps
{
	//add the proper fields to the databases
	this->initDB();
}

//destructor
GameDB::~GameDB() {
	//no code needed
}

//getInstance method - returns the instance of the singleton class
GameDB& GameDB::getInstance() {
	static GameDB instance; //the instance of the database
	return instance; //return the created instance
}

//initDB method - wipes initializes the database
//EDIT THIS TO ADD NEW DATABASE FIELDS
void GameDB::initDB() {
	this->intDB[std::string(OP_KEY)] = STARTING; //create the operation state entry
	//TODO: Create more entries
}

//getter methods for the database

//first getInt method - returns an integer value from the database
int GameDB::getInt(const char* key) {
	std::string newKey = key; //get a new key as an std::string
	return this->getInt(newKey); //return a call to the other getInt method
}

//second getInt method - returns an integer value from the database
int GameDB::getInt(std::string key) {
	if(this->intDB.find(key) == this->intDB.end()) { //if the key is not found in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	return this->intDB[key]; //return the correct entry
}

//first getFloat method - returns a float value from the database
float GameDB::getFloat(const char* key) {
	std::string newKey = key; //get a new key as an std::string
	return this->getFloat(newKey); //return a call to the other getFloat method
}

//second getFloat method - returns a float value from the database
float GameDB::getFloat(std::string key)  {
	if(this->floatDB.find(key) == this->floatDB.end()) { //if the key is not found in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	return this->floatDB[key]; //return the correct entry
}

//first getChar method - returns a character value from the database
char GameDB::getChar(const char* key)  {
	std::string newKey = key; //get a new key as an std::string
	return this->getChar(newKey); //return a call to the other getChar method
}

//second getChar method - returns a character value from the database
char GameDB::getChar(std::string key)  {
	if(this->charDB.find(key) == this->charDB.end()) { //if the key is not found in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	return this->charDB[key]; //return the correct entry
}

//first getBool method - returns a boolean value from the database
bool GameDB::getBool(const char* key)  {
	std::string newKey = key; //get a new key as an std::string
	return this->getBool(newKey); //return a call to the other getBool method
}

//second getBool method - returns a boolean value from the database
bool GameDB::getBool(std::string key)  {
	if(this->boolDB.find(key) == this->boolDB.end()) { //if the key is not found in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	return this->boolDB[key]; //return the correct entry
}

//first getString method - returns a string value from the database
std::string GameDB::getString(const char* key)  {
	std::string newKey = key; //get a new key as an std::string
	return this->getString(newKey); //return a call to the other getString method
}

//second getString method - returns a string value from the database
std::string GameDB::getString(std::string key)  {
	if(this->stringDB.find(key) == this->stringDB.end()) { //if the key is not found in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	return this->stringDB[key]; //return the correct entry
}

//setter methods

//first setInt method - sets an integer in the database
void GameDB::setInt(const char* key, int newValue) {
	std::string newKey = key; //get a new key as a std::string
	this->setInt(newKey, newValue);
}

//second setInt method - sets an integer in the database
void GameDB::setInt(std::string key, int newValue) {
	if(this->intDB.find(key) == this->intDB.end()) { //if the key is not in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	this->intDB[key] = newValue; //assign the new value field
}

//first setFloat method - sets a float in the database
void GameDB::setFloat(const char* key, float newValue) {
	std::string newKey = key; //get a new key as a std::string
	this->setFloat(newKey, newValue);
}

//second setFloat method - sets a float in the database
void GameDB::setFloat(std::string key, float newValue) {
	if(this->floatDB.find(key) == this->floatDB.end()) { //if the key is not in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	this->floatDB[key] = newValue; //assign the new value field
}

//first setChar method - sets a character in the database
void GameDB::setChar(const char* key, char newValue) {
	std::string newKey = key; //get a new key as a std::string
	this->setChar(newKey, newValue);
}

//second setChar method - sets a character in the database
void GameDB::setChar(std::string key, char newValue) {
	if(this->charDB.find(key) == this->charDB.end()) { //if the key is not in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	this->charDB[key] = newValue; //assign the new value field
}

//first setBool method - sets a boolean in the database
void GameDB::setBool(const char* key, bool newValue) {
	std::string newKey = key; //get a new key as a std::string
	this->setBool(newKey, newValue);
}

//second setBool method - sets a boolean in the database
void GameDB::setBool(std::string key, bool newValue) {
	if(this->boolDB.find(key) == this->boolDB.end()) { //if the key is not in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	this->boolDB[key] = newValue; //assign the new value field
}

//first setString method - sets a string in the database
void GameDB::setString(const char* key, std::string newValue) {
	std::string newKey = key; //get a new key as a std::string
	this->setString(newKey, newValue);
}

//second setString method - sets a string in the database
void GameDB::setString(std::string key, std::string newValue) {
	if(this->stringDB.find(key) == this->stringDB.end()) { //if the key is not in the database
		throw InvalidDictEntryException(key.c_str()); //then throw an exception
	}
	this->stringDB[key] = newValue; //assign the new value field
}

//end of implementation
