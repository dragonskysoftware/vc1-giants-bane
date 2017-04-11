/*
 * Game.cpp
 * Implements a static class that runs the Giant's Bane game
 * Created by Andrew Davis
 * Created on 3/13/2017
 * All rights reserved
 */

//include header
#include "Game.h"

//init the static variables

//first the SDL variables
SDL_Window* Game::window = nullptr; //initialize the window to nullptr
SDL_Renderer* Game::renderer = nullptr; //initialize the renderer to nullptr

//then the game variables
TextComponent* Game::message = nullptr; //initialize the message to nullptr
ImgComponent* Game::image = nullptr; //initialize the image to nullptr
ImgComponent* Game::splash = nullptr; //initialize the splash to nullptr

//end of variable initializations

//static method implementations

//start method - starts up the game and sets up the window and renderer
bool Game::start() {
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
		window = SDL_CreateWindow(WIN_HEADER, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if(window == nullptr) { //if the creation failed
			std::cerr << "Fatal: Window could not be created. SDL Error: " << SDL_GetError() << std::endl; //display an error message
			success = false; //and reset the success flag
		} else { 
			//create the renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == nullptr) { //if the creation failed
				//display an error message
				std::cerr << "Fatal: Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
				success = false; //and reset the success flag
			} else {
				SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); //init the draw colors
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

//run method - runs the game
void Game::run() {
	message = new TextComponent(SCREEN_WIDTH / 7, SCREEN_HEIGHT / 2, std::string(DEV_MSG), "../assets/Roboto-Light.ttf", 28, 0, 0, 0, renderer); 
	image = new ImgComponent(0, 0, "../assets/test.png", renderer);
	splash = new ImgComponent(0, 0, "../assets/Splash.png", renderer);
	displaySplash(); //show the splash screen
	//start the loop
	while(true) { //loop forever, or until a quit event is detected by the event regulator
		EventRegulator::getInstance().nextEvent(); //poll the next event
		//draw a blank screen
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); //set the draw color to white
		SDL_RenderClear(renderer); //fill the screen with white
		message->render(); //render the message
		image->render(); //render the image
		SDL_RenderPresent(renderer); //update the draw screen
		if(GameDB::getInstance().getInt(OP_KEY) == SHUTDOWN) { //if a shutdown event was detected
			break; //then exit the loop
		}
	}

}

//shutdown method - shuts down the game
void Game::shutdown() {
	delete message; //deallocate the message field
	message = nullptr; //and zero it out
	delete image; //deallocate the image field
	image = nullptr; //and zero it out
	delete splash; //deallocate the splash field
	splash = nullptr; //and zero it out

	//destroy the renderer
	SDL_DestroyRenderer(renderer); 
	renderer = nullptr;

	//destroy the window
	SDL_DestroyWindow(window);
	window = nullptr;

	//quit TTF
	TTF_Quit();

	//quit IMG
	IMG_Quit();

	//Quit SDL
	SDL_Quit();
}

//displaySplash method - fades in the splash, waits a second, and fades it out
void Game::displaySplash() {
	if(splash == nullptr) { //if the splash is not initialized
		return; //then exit the method
	}
	//draw a black screen
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); //set the draw color to black
	SDL_RenderClear(renderer); //fill the screen with black

	//fade in the splash screen
	int alpha = 0; //the alpha value for the splash screen
	splash->setAlpha(alpha); //make the splash image transparent
	while(alpha < 0xff) { //loop while the alpha value isn't maxed out
		//draw a black screen
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); //set the draw color to black
		SDL_RenderClear(renderer); //fill the screen with black
		splash->render(); //render the splash screen
		SDL_RenderPresent(renderer); //update the draw screen
		alpha += 10; //increment the alpha value
		splash->setAlpha(alpha); //set the new alpha value
		uwait(50); //wait 50/1000 of a second
	}

	//allow the user to view the logo
	uwait(2500); //wait 2.5 seconds

	//fade out the splash screen
	while(alpha > 0x00) { //loop while the alpha value isn't zero
		splash->render(); //render the splash screen
		SDL_RenderPresent(renderer); //update the draw screen
		alpha -= 10; //decrement the alpha value
		splash->setAlpha(alpha); //set the new alpha value
		//draw a black screen
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); //set the draw color to black
		SDL_RenderClear(renderer); //fill the screen with black
		uwait(50); //wait 50/1000 of a second
	}
	//draw a black screen
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff); //set the draw color to black
	SDL_RenderClear(renderer); //fill the screen with black
}


//end of implementation
