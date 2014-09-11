#pragma once
#include <SDL.h>
#include <string>
#include "Utils/Mesh/Loader.h"
#include "Constants.h"

class Game {
	public:
		Game();
		//
		int execute();
	private:
		//
		bool init();
		void event(SDL_Event* e);
		void update();
		void draw();
		void cleanUp();
		//
		SDL_Window* window;
		SDL_Event ev;
		Loader loader;
		bool running;
};