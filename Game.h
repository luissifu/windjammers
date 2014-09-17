#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/glu.h>
#include <string>
#include "Utils/Scene/SceneManager.h"
#include "Constants.h"

class Game {
	public:
		Game();
		//
		int execute();
	private:
		//
		bool init();
		bool initSDL();
		bool initGL();
		//
		void event(SDL_Event* e);
		void update();
		void draw();
		void cleanUp();
		//
		SDL_Window* window;
		SDL_Event ev;
		SDL_GLContext context;
		SceneManager scene;
		bool running;
};