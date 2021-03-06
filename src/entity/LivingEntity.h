/*
 * LivingEntity.h
 * Declares a class that represents a living entity for Giant's Bane
 * Created by Andrew Davis
 * Created on 3/30/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef LIVING_ENTITY_H
#define LIVING_ENTITY_H

//includes
#include "Entity.h"

//class declaration
class LivingEntity : public Entity
{
	//public fields and methods
	public:
		//default constructor
		LivingEntity();

		//first constructor - constructs from a C string and a health value
		LivingEntity(const char* newName, int newHP);
		
		//second constructor - constructs from an std::string and a health value
		LivingEntity(const std::string& newName, int newHP);

		//destructor
		virtual ~LivingEntity();

		//copy constructor
		LivingEntity(const LivingEntity& le);

		//move constructor
		LivingEntity(LivingEntity&& le);

		//assignment operator
		LivingEntity& operator=(const LivingEntity& src);

		//move operator
		LivingEntity& operator=(LivingEntity&& src);

		//serialization code
		friend std::ostream& operator<<(std::ostream& os, const LivingEntity& le); //save function
		friend std::istream& operator>>(std::istream& is, LivingEntity& le); //load function
		
		//overridden PV methods
		int heal(int dhp) override; //heals the LivingEntity and returns its new HP
		int hurt(int dhp) override; //hurts the LivingEntity and returns its new HP

		//abstract method
		virtual bool shouldDespawn() const = 0; //returns whether or not the LivingEntity should despawn

	//protected fields and methods
	protected:
		//using declarations
		using Entity::shouldDespawn; //use the PV method from the Entity class
	
};

#endif
