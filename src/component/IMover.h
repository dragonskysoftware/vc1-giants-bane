/*
 * IMover.h
 * Provides an interface to objects that can move
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef IMOVER_H_INC
#define IMOVER_H_INC

//interface declaration
class IMover {
	//public fields and methods
	public:
		//destructor
		virtual ~IMover() {} //no code needed

		//PV methods
		virtual void setX(int newX) = 0; //sets the X-coord of the IMover
		virtual void setY(int newY) = 0; //sets the Y-coord of the IMover
		virtual void moveX(int deltaX) = 0; //adds deltaX to the X-coord of the IMover
		virtual void moveY(int deltaY) = 0; //adds deltaY to the Y-coord ot the IMover
};

#endif
