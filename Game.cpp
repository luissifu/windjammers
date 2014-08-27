#include "Game.h"

Game::Game() {}

int Game::execute() {
	if (!init())
		return -1;

	//TODO
	running = false;

	int ticks = 0;
	int loops;
	int fps = 0;
	std::string title = "Windjammers";

	while(running)
	{
		loops = 0;
		while (loops < MAX_SKIP)
		{
			update();

			ticks += SKIP_TICKS;
			loops++;
		}

		//window
		draw();
	}

	cleanUp();

	return 0;
}

void Game::cleanUp() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}