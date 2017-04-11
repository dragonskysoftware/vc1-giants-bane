/*
 * StaticEntity.cpp
 * Implements a class that represents a static (non-living) entity for Giant's Bane
 * Created by Andrew Davis
 * Created on 4/5/2017
 * All rights reserved
 */

//include header
#include "StaticEntity.h"

//default constructor
StaticEntity::StaticEntity()
	: Entity() //call default superconstructor
{
	//no code needed
}

//first constructor - constructs from a C string
StaticEntity::StaticEntity(const char* newName)
	: Entity(newName) //call superconstructor
{
	//no code needed
}

//second constructor - constructs from an std::string
StaticEntity::StaticEntity(const std::string& newName)
	: Entity(newName) //call superconstructor
{
	//no code needed
}

//destructor
StaticEntity::~StaticEntity() {
	//no code needed
}

//copy constructor
StaticEntity::StaticEntity(const StaticEntity& se)
	: Entity(se) //call superclass copy constructor
{
	//no code needed
}

//move constructor
StaticEntity::StaticEntity(StaticEntity&& se)
	: Entity(se) //call superclass move constructor
{
	//no code needed
}

//assignment operator
StaticEntity& StaticEntity::operator=(const StaticEntity& src) {
	Entity::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
StaticEntity& StaticEntity::operator=(StaticEntity&& src) {
	Entity::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//serialization functions

//save function - writes the StaticEntity to a stream
std::ostream& operator<<(std::ostream& os, const StaticEntity& se) {
	const Entity& e(se); //get an Entity object from the StaticEntity parameter
	os << e; //write the Entity to a stream
	return os; //and return the stream
}

//load function - loads the StaticEntity from a stream
std::istream& operator>>(std::istream& is, StaticEntity& se) {
	Entity& e(se); //get an Entity object from the StaticEntity parameter
	is >> e; //read the Entity from the stream
	return is; //and return the stream
}

//health modification methods

//heal method - heals the StaticEntity by a given amount, returning the new health value
int StaticEntity::heal(int dhp) {
	return this->hp; //apply no modification and return the value
}

//hurt method - damages the StaticEntity by a given amount, returning the new health value
int StaticEntity::hurt(int dhp) {
	return this->hp; //apply no modification and return the value
}

//other methods

//shouldDespawn method - returns whether the StaticEntity should despawn
bool StaticEntity::shouldDespawn() {
	return false; //never despawn
}

//end of implementation
