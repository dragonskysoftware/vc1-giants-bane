/*
 * Entity.cpp
 * Implements a class that represents an entity in Giant's Bane
 * Created by Andrew Davis
 * Created on 3/30/2017
 * Open source (GPL license)
 */

//include header
#include "Entity.h"

//init static member
unsigned long long Entity::s_id = 0; //used to create entity IDs

//default constructor
Entity::Entity()
	: Entity("") //call other constructor
{
	//no code needed
}

//constructor 1 - constructs from a C string and an HP value
Entity::Entity(const char* newName, int newHP)
	: id(s_id++), name(newName), hp(newHP) //init the fields
{
	checkIDMax(); //check the ID maker
}

//constructor 2 - constructs from an std::string and an HP value
Entity::Entity(std::string newName, int newHP)
	: Entity(newName.c_str(), newHP) //call first constructor
{
	//no code needed
}

//destructor
Entity::~Entity() {
	//no code needed
}

//copy constructor
Entity::Entity(const Entity& e)
	: id(s_id++), name(e.name), hp(e.hp) //copy the fields
{
	checkIDMax(); //check the ID maker
}

//move constructor
Entity::Entity(Entity&& e)
	: id(s_id++), name(e.name), hp(e.hp) //move the fields
{
	checkIDMax(); //check the ID maker
}

//assignment operator
Entity& Entity::operator=(const Entity& src) {
	this->name = src.name; //assign the entity name
	this->hp = src.hp; //assign the entity's HP
	return *this; //return the object
}

//move operator
Entity& Entity::operator=(Entity&& src) {
	this->name = src.name; //move the entity name
	this->hp = src.hp; //move the entity's HP
	return *this; //return the object
}

//getter methods

//getID method - returns the ID of the entity
unsigned long long Entity::getID() const {
	return this->id; //return the entity ID field
}

//getName method - returns the name of the entity
const std::string& Entity::getName() const {
	return this->name; //return the name field
}

//getHP method - returns the HP of the entity
int Entity::getHP() const {
	return this->hp; //return the HP field
}

//save function
std::ostream& operator<<(std::ostream& os, const Entity& e) {
	os << e.id; //save the entity's ID
	os << e.name; //save the entity's name
	os << e.hp; //save the entity's hp
	return os; //return the stream
}

//load function
std::istream& operator>>(std::istream& is, Entity& e) {
	is >> e.id; //load the ID field
	is >> e.name; //load the name field
	is >> e.hp; //load the HP field
	return is; //return the stream
}

//static checkIDMax method - regulates the ID maker value
void Entity::checkIDMax() {
	if(s_id >= ULLONG_MAX) { //if the ID maker is too big
		s_id = 0; //then reset it to 0
	}
}

//other methods are abstract

//end of implementation
