/*
 * MsgBox.h
 * Declares a class that represents an SDL message box
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MSG_BOX_H_INC
#define MSG_BOX_H_INC

//includes
#include <SDL2/SDL.h>
#include "MsgBoxData.h"
#include "MsgBoxColorScheme.h"
#include "MsgBoxButtonData.h"
#include "../except/MessageBoxException.h"

//class declaration
class MsgBox final {
	//public fields and methods
	public:
		//constructor
		explicit MsgBox(const MsgBoxData& newData);

		//destructor
		~MsgBox();

		//copy constructor
		MsgBox(const MsgBox& mb);

		//move constructor
		MsgBox(MsgBox&& mb);

		//assignment operator
		MsgBox& operator=(const MsgBox& src);

		//move operator
		MsgBox& operator=(MsgBox&& src);

		//other methods
		void show() const; //brings up the MsgBox and allows input

	//private fields and methods
	private:
		//field
		MsgBoxData data; //the data related to the message box
};

#endif
