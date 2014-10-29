#include "Game.h"

bool Game::init() {
	return initSDL() && initGL() && initTest();
}

bool Game::initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);

	window = SDL_CreateWindow(
		"Windjammers",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		DEFAULT_WIDTH,
		DEFAULT_HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	if (window == NULL)
	{
		return false;
	}

	context = SDL_GL_CreateContext(window);

	if (context == NULL)
	{
		return false;
	}

	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

bool Game::initGL() {
	GLenum error = GL_NO_ERROR;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf("Error setting projection: %s", gluErrorString(error));
		return false;
	}

	double hw = DEFAULT_WIDTH / GL_HALF_SCALE;
	double hh = DEFAULT_HEIGHT / GL_HALF_SCALE;
	double hd = DEFAULT_DEPTH / 2.0f;

	glOrtho(-hw, hw, -hh, hh, -hd, hd);

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error setting camera: %s", gluErrorString(error));
		return false;
	}

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glRotatef(35.264f, 1.0f, 0.0f, 0.0f);
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf("Error setting modelview: %s", gluErrorString(error));
		return false;
	}

	glClearColor( 0.f, 0.f, 0.f, 1.f );
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf("Error on clear color: %s", gluErrorString(error));
		return false;
	}

	return true;
}

bool Game::initTest() {
	rotation = 0.0f;

	std::shared_ptr<SceneNode> node = scene.createStaticNode("tank2", 0, 0, 0);
	//std::shared_ptr<SceneNode> node2 = scene.createStaticNode("hextile", 2, 0, 0);

	//std::shared_ptr<SceneNode> node = scene.createFlatNode("title", 0, 0, 12.8, 7.2);

	return node != nullptr;
}
