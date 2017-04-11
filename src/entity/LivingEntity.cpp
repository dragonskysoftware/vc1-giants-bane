/*
 * LivingEntity.cpp
 * Implements a class that represents a living entity for Giant's Bane
 * Created by Andrew Davis
 * Created on 4/5/2017
 * All rights reserved
 */

//include header
#include "LivingEntity.h"

//default constructor
LivingEntity::LivingEntity()
	: Entity() //call default superclass constructor
{
	//no code needed
}

//first constructor - constructs from a C string and an HP value
LivingEntity::LivingEntity(const char* newName, int newHP)
	: Entity(newName, newHP) //call superconstructor
{
	//no code needed
}

//second constructor - constructs from an std::string and an HP value
LivingEntity::LivingEntity(const std::string& newName, int newHP)
	: Entity(newName, newHP) //call superconstructor
{
	//no code needed
}

//destructor
LivingEntity::~LivingEntity() {
	//no code needed
}

//copy constructor
LivingEntity::LivingEntity(const LivingEntity& le)
	: Entity(le) //call superclass copy constructor
{
	//no code needed
}

//move constructor
LivingEntity::LivingEntity(LivingEntity&& le)
	: Entity(le) //call superclass move constructor
{
	//no code needed
}

//assignment operator
LivingEntity& LivingEntity::operator=(const LivingEntity& src) {
	Entity::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
LivingEntity& LivingEntity::operator=(LivingEntity&& src) {
	Entity::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//serialization functions

//save function - writes the LivingEntity to a stream
std::ostream& operator<<(std::ostream& os, const LivingEntity& le) {
	const Entity& e(le); //get an Entity object from the LivingEntity parameter
	os << e; //write the Entity to a stream
	return os; //and return the stream
}

//load function - loads the LivingEntity from a stream
std::istream& operator>>(std::istream& is, LivingEntity& le) {
	Entity& e(le); //get an Entity object from the LivingEntity parameter
	is >> e; //read the Entity from the stream
	return is; //and return the stream
}

//health modification methods

//heal method - heals the LivingEntity by a given amount, returning the new health value
int LivingEntity::heal(int dhp) {
	this->hp += dhp; //add the delta-hp value to the HP field
	return this->hp; //return the new HP value
}

//hurt method - damages the LivingEntity by a given amount, returning the new health value
int LivingEntity::hurt(int dhp) {
	return this->heal(-dhp); //heal the LivingEntity by a negative value, and return the new HP value
}

//end of implementation
