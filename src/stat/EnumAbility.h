/*
 * EnumAbility.h
 * Enumerates the different abilities in Giant's Bane
 * Created by Andrew Davis
 * Created on 3/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_ABIL_H
#define ENUM_ABIL_H

//enum definition
enum class EnumAbility {
	STR, //strength, or how far you can throw a rock
	DEX, //dexterity, or how accurately you can throw a rock
	CON, //constitution, or how well you can take a rock to the head
	TGT, //thought, or how much you know about rocks
	SOC, //social, or how well you can talk about rocks
	ARC, //arcana, or how easily you can turn a rock into a frog
};

#endif
