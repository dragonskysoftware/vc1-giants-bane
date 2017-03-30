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

//constructor 1 - constructs from a C string, an ImgComponent, and an HP value
Entity::Entity(const char* newName, const ImgComponent& newComponent, int newHP)
	: id(s_id++), name(newName), component(newComponent), hp(newHP) //init the fields
{
	//no code needed
}

//constructor 2 - constructs from an std::string, an ImgComponent, and an HP value
Entity::Entity(std::string newName, const ImgComponent& newComponent, int newHP)
	: Entity(newName.c_str(), newComponent, newHP) //call other constructor
{
	//no code needed
}

//destructor
Entity::~Entity() {
	//no code needed
}

//copy constructor
Entity::Entity(const Entity& e)
	: id(e.id), name(e.name), component(e.component), hp(e.hp) //copy the fields
{
	//no code needed
}

//move constructor
Entity::Entity(Entity&& e)
	: id(e.id), name(e.name), component(e.component), hp(e.hp) //move the fields
{
	//no code needed
}

//assignment operator
Entity& Entity::operator=(const Entity& src) {
	this->id = src.id; //assign the entity ID
	this->name = src.name; //assign the entity name
	this->component = src.component; //assign the entity's image
	this->hp = src.hp; //assign the entity's HP
	return *this; //return the object
}

//move operator
Entity& Entity::operator=(Entity&& src) {
	this->id = src.id; //move the entity ID
	this->name = src.name; //move the entity name
	this->component = src.component; //move the entity's image
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

//getImage method - returns the ImgComponent that holds the Entity's image
const ImgComponent& Entity::getImage() const {
	return this->component; //return the image component
}

//getHP method - returns the HP of the entity
int Entity::getHP() const {
	return this->hp; //return the HP field
}

//other methods are abstract

//end of implementation
