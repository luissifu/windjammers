#pragma once
#include <SDL.h>
#include <string>

#include "Constants.h"

class Game {
	public:
		Game();
		//
		int execute();
	private:
		//
		bool init();
		void update();
		void draw();
		void cleanUp();
		//
		SDL_Window* window;
		bool running;
};