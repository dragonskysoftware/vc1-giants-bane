/*
 * Entity.h
 * Declares a class that represents an entity in Giant's Bane
 * Created by Andrew Davis
 * Created on 3/29/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENTITY_H_INC
#define ENTITY_H_INC

//includes
#include <string>
#include <iostream>
#include <climits>

//class declaration
class Entity {
	//public fields and methods
	public:
		//default constructor
		Entity();

		//constructor 1 - constructs from a C string and an HP value
		Entity(const char* newName, int newHP = -1);

		//constructor 2 - constructs from a std::string and an HP value
		Entity(std::string newName, int newHP = -1);

		//destructor
		virtual ~Entity();

		//copy constructor
		Entity(const Entity& e);

		//move constructor
		Entity(Entity&& e);

		//assignment operator
		Entity& operator=(const Entity& src);

		//move operator
		Entity& operator=(Entity&& src);

		//getter methods
		unsigned long long getID() const; //returns the ID of the entity
		const std::string& getName() const; //returns the name of the entity
		int getHP() const; //returns the hit points for the entity

		//save/load functions
		friend std::ostream& operator<<(std::ostream& os, const Entity& e); //save function
		friend std::istream& operator>>(std::istream& is, Entity& e); //load function

		//pure virtual methods
		virtual int heal(int dhp) = 0; //heals the entity and returns its new health
		virtual int hurt(int dhp) = 0; //hurts the entity and returns its new health
		virtual bool shouldDespawn() = 0; //returns whether or not the Entity should despawn

	//protected fields and methods
	protected:
		//static methods
		static void checkIDMax(); //checks if the ID creation value is too large, and resets it if it is
		//fields
		static unsigned long long s_id; //used to get the ID of the entity
		unsigned long long id; //the actual, per-entity, ID
		std::string name; //the name of the entity
		int hp; //the hit points for the Entity
};

#endif
