#include "Game.h"

bool Game::init() {
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Windjammers",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		DEFAULT_WIDTH,
		DEFAULT_HEIGHT,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL) 
	{
		return false;
	}

	return true;
}