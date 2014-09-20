#include "Game.h"

void Game::draw() {
	
	scene.drawAll();

	SDL_GL_SwapWindow(window);
}