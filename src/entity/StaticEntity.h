/*
 * StaticEntity.h
 * Declares a class that represents a static (non-living) entity for Giant's Bane
 * Created by Andrew Davis
 * Created on 4/5/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

//includes
#include "Entity.h"

//class declaration
class StaticEntity : public Entity
{
	//public fields and methods
	public:
		//default constructor
		StaticEntity();

		//first constructor - constructs from a C string
		explicit StaticEntity(const char* newName);
		
		//second constructor - constructs from an std::string
		explicit StaticEntity(const std::string& newName);

		//destructor
		virtual ~StaticEntity();

		//copy constructor
		StaticEntity(const StaticEntity& se);

		//move constructor
		StaticEntity(StaticEntity&& se);

		//assignment operator
		StaticEntity& operator=(const StaticEntity& src);

		//move operator
		StaticEntity& operator=(StaticEntity&& src);

		//serialization code
		friend std::ostream& operator<<(std::ostream& os, const StaticEntity& se); //save function
		friend std::istream& operator>>(std::istream& is, StaticEntity& se); //load function
		
		//overridden PV methods
		int heal(int dhp) override; //heals the StaticEntity and returns its new HP
		int hurt(int dhp) override; //hurts the StaticEntity and returns its new HP
		bool shouldDespawn() override; //returns whether or not the StaticEntity should despawn

	//no protected data
	
};

#endif
