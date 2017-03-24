/*
 * EnumAsgnType.h
 * Enumerates different types of assignments in EvScript
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_ASGN_H
#define ENUM_ASGN_H

//enum definition
enum class EnumAsgnType {
	VTV, //value assigned to a value
	VTIA, //array dereference assigned to a value
	ATA, //array assigned to another array
	AITA, //array dereference assigned to an array
	AITIA //array dereference assigned to another array dereference
};

#endif
