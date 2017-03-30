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
#include "../component/ImgComponent.h"
#include <string>

//class declaration
class Entity {
	//public fields and methods
	public:
		//constructor 1 - constructs from a C string, a component, and an HP value
		Entity(const char* newName, const ImgComponent& newComponent, int newHP = -1);

		//constructor 2 - constructs from a std::string, a component, and an HP value
		Entity(std::string newName, const ImgComponent& newComponent, int newHP = -1);

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
		const ImgComponent& getImage() const; //returns the image that represents the entity
		int getHP() const; //returns the hit points for the entity

		//pure virtual methods
		virtual int heal(int hp) = 0; //heals the entity and returns its new health
		virtual int hurt(int hp) = 0; //hurts the entity and returns its new health

	//protected fields and methods
	protected:
		//fields
		static unsigned long long s_id; //used to get the ID of the entity
		unsigned long long id; //the actual, per-entity, ID
		std::string name; //the name of the entity
		ImgComponent component; //the image that depicts the Entity
		int hp; //the hit points for the Entity
};

#endif
