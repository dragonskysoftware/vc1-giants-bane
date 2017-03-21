/*
 * EnumCompType.h
 * Enumerates different types of comparison operations
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_COMP_TYPE
#define ENUM_COMP_TYPE

//enum definition
enum class EnumCompType {
	EQUAL, //==
	NEQUAL, //!=
	LTHEN, //<
	GTHEN, //>
	LTOE, //<=
	GTOE //>=
};

#endif
