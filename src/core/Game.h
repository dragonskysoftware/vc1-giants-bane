/*
 * Game.h
 * Declares a static class that runs the Giant's Bane game
 * Created by Andrew Davis
 * Created on 3/12/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef GAME_H_INC
#define GAME_H_INC

//includes
#include "../data/GameDB.h"
#include "../event/EventRegulator.h"
#include "../component/ImgComponent.h"
#include "../component/TextComponent.h"
#include "../util/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

//static class declaration
class Game final {
	//public fields and methods
	public:
		//delete the constructor
		Game() = delete;

		//delete the destructor
		~Game() = delete;

		//delete the copy constructor and other such methods
		Game(const Game& g) = delete;
		Game(Game&& g) = delete;
		Game& operator=(const Game& src) = delete;
		Game& operator=(Game&& src) = delete;

		//other methods
		static bool start(); //starts the game
		static void run(); //runs the game
		static void shutdown(); //shuts down the game

	//private fields and methods
	private:
		//SDL fields
		static SDL_Window* window; //the window the game runs in
		static SDL_Renderer* renderer; //the graphics renderer for the game

		//game object fields
		static TextComponent* message; //a temporary message displayed while the game is being developed
		static ImgComponent* image; //an image used to test graphics rendering

};


#endif
