/*
 * EnumCall.h
 * Enumerates different game calls that can be made by EvScript scripts
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_CALL_H
#define ENUM_CALL_H

//enum definition
enum class EnumCall {
	SHUTDOWN, //shut down game
	SLEEP, //sleep x seconds
	USLEEP, //sleep x milliseconds
};

#endif
