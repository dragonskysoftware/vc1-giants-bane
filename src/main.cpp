/*
 * main.cpp
 * Runs main code for Validian Chronicles 1: Giant's Bane
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "util/constants.h"
#include "component/TextComponent.h"
#include "component/ImgComponent.h"
#include <iostream>
#include <cstdlib>

//function prototypes
bool init(SDL_Window*& parWindow, SDL_Renderer*& parRenderer); //initializes the window and the renderer
void close(SDL_Window*& parWindow, SDL_Renderer*& parRenderer); //returns memory and shuts down SDL

//main function - main entry point for program
int main(int argc, char* argv[]) {
	SDL_Window* window = nullptr; //a pointer to a window object that manages the game window
	SDL_Renderer* renderer = nullptr; //a pointer to a graphics renderer
	TextComponent* message = nullptr; //the message to display
	ImgComponent* image = nullptr; //the image to display
	//start by calling init()
	if(!init(window, renderer)) { //if the init failed
		std::cerr << "FATAL: Failed to initialize resources." << std::endl; //display an error message
		return EXIT_FAILURE; //and exit with an error
	} else { //if the init succeeded
		//prepare for the main loop
		bool shouldQuit = false; //should the main loop be exited?
			
		//event code
		SDL_Event eventHandler; //the event handler for keyboard events
		message = new TextComponent(SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, std::string(DEV_MSG), "../assets/Roboto-Light.ttf", 28, 0, 0, 0, renderer); 
		image = new ImgComponent(0, 0, "../assets/test.png", renderer);
		//start the loop
		while(!shouldQuit) { //loop until the user wants to quit
			while(SDL_PollEvent(&eventHandler) != 0) { //handle the event queue
				if(eventHandler.type == SDL_QUIT) { //if the user wants to quit
					shouldQuit = true; //then set the quit flag to true
				}
			}

			//draw a blank screen
			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); //set the draw color to white
			SDL_RenderClear(renderer); //fill the screen with white
			message->render(); //render the message
			image->render(); //render the image
			SDL_RenderPresent(renderer); //update the draw screen
		}
	}
	delete message; //deallocate the message
	message = nullptr; //zero it out
	close(window, renderer); //close down the program
	return EXIT_SUCCESS; //and exit with no errors
}

//init function implementation
bool init(SDL_Window*& parWindow, SDL_Renderer*& parRenderer) {
	//set flags
	bool success = true; //init success flag

	//start initialization
	if(SDL_Init(SDL_INIT_VIDEO) < 0) { //if preliminary initialization fails
		std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl; //display an error message
		success = false; //and reset the success flag
	} else {
		//set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) { //if the texture filtering setting failed
			std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl; //display a warning
		}
		//create the window
		parWindow = SDL_CreateWindow(WIN_HEADER, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if(parWindow == nullptr) { //if the creation failed
			std::cerr << "Fatal: Window could not be created. SDL Error: " << SDL_GetError() << std::endl; //display an error message
			success = false; //and reset the success flag
		} else { 
			//create the renderer
			parRenderer = SDL_CreateRenderer(parWindow, -1, SDL_RENDERER_ACCELERATED);
			if(parRenderer == nullptr) { //if the creation failed
				//display an error message
				std::cerr << "Fatal: Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
				success = false; //and reset the success flag
			} else {
				SDL_SetRenderDrawColor(parRenderer, 0xff, 0xff, 0xff, 0xff); //init the draw colors
			}
		}
	}
	//Initialize SDL_ttf
	if( TTF_Init() == -1 ) {	
		std::cerr << "Could not initialize SDL_TTF. Error: " << TTF_GetError() << std::endl;			
		success = false;
	}

	return success; //return the success flag
}

//close function implementation
void close(SDL_Window*& parWindow, SDL_Renderer*& parRenderer) {
	//destroy the renderer
	SDL_DestroyRenderer(parRenderer); 
	parRenderer = nullptr;

	//destroy the window
	SDL_DestroyWindow(parWindow);
	parWindow = nullptr;

	//quit TTF
	TTF_Quit();

	//Quit SDL
	SDL_Quit();
}

//end of program
