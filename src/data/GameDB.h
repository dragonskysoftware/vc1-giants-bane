/*
 * GameDB.h
 * Declares a singleton class that holds the important game data for Giant's Bane
 * Created by Andrew Davis
 * Created on 3/12/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef GAME_DB_H
#define GAME_DB_H

//include
#include <map>
#include <string>
#include "../util/constants.h"
#include "../except/InvalidDictEntryException.h"

//class declaration
class GameDB final {
	//public fields and methods
	public:
		//constructor is private

		//destructor
		~GameDB();
		
		//declare copy constructor, etc. as deleted
		GameDB(const GameDB& gdb) = delete;
		GameDB(GameDB&& gdb) = delete;
		GameDB& operator=(const GameDB& src) = delete;
		GameDB& operator=(GameDB&& src) = delete;

		//getInstance method - returns the instance of the game database
		static GameDB& getInstance();

		//getter methods for the database
		int getInt(const char* key); //retrieves an integer from the database
		int getInt(std::string key); //retrieves an integer from the database
		float getFloat(const char* key); //retrieves a floating-point number from the database
		float getFloat(std::string key); //retrieves a floating-point number from the database
		char getChar(const char* key); //retrieves a character from the database
		char getChar(std::string key); //retrieves a character from the database
		bool getBool(const char* key); //retrieves a boolean from the database
		bool getBool(std::string key); //retrieves a boolean from the database
		std::string getString(const char* key); //retrieves a string from the database
		std::string getString(std::string key); //retrieves a string from the database

		//setter methods for the database
		void setInt(const char* key, int newValue); //sets an integer in the database
		void setInt(std::string key, int newValue); //sets an integer in the database
		void setFloat(const char* key, float newValue); //sets a float in the database
		void setFloat(std::string key, float newValue); //sets a float in the database
		void setChar(const char* key, char newValue); //sets a char in the database
		void setChar(std::string key, char newValue); //sets a char in the database
		void setBool(const char* key, bool newValue); //sets a boolean in the database
		void setBool(std::string key, bool newValue); //sets a boolean in the database
		void setString(const char* key, std::string newValue); //sets a string in the database
		void setString(std::string key, std::string newValue); //sets a string in the database
	
	//private fields and methods
	private:
		//constructor
		GameDB();

		//private methods
		void initDB(); //initializes the databases with the proper entries

		//dictionary fields
		std::map<std::string, int> intDB; //the integer database
		std::map<std::string, float> floatDB; //the float database
		std::map<std::string, char> charDB; //the character database
		std::map<std::string, bool> boolDB; //the boolean database
		std::map<std::string, std::string> stringDB; //the string database

};

#endif
