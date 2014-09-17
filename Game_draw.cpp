#include "Game.h"

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); 
		glVertex2f(-0.5f, -0.5f); 
		glVertex2f(0.5f, -0.5f); 
		glVertex2f(0.5f, 0.5f); 
		glVertex2f(-0.5f, 0.5f); 
	glEnd();

	SDL_GL_SwapWindow(window);
}