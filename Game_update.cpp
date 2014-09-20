#include "Game.h"

void Game::update() {
	rotation += 1.0f;
	scene.setRotation(rotation);
}