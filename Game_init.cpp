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

	return true;
}

bool Game::initGL() {
	GLenum error = GL_NO_ERROR; 
	
	glMatrixMode( GL_PROJECTION ); 
	glLoadIdentity(); 
	error = glGetError(); 
	if( error != GL_NO_ERROR ) 
	{ 
		return false;
	} 
	
	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity();
	error = glGetError(); 
	if( error != GL_NO_ERROR ) 
	{ 
		return false;
	}

	glClearColor( 0.f, 0.f, 0.f, 1.f );  
	error = glGetError(); 
	if( error != GL_NO_ERROR ) 
	{ 
		return false;
	}

	double hw = 12.8 / 2.0f;
	double hh = 7.2 / 2.0f;
	double hd = DEFAULT_DEPTH / 2.0f;

	glOrtho(-hw, hw, -hh, hh, -hd, hd);
	glShadeModel(GL_SMOOTH);

	return true;
}

bool Game::initTest() {
	rotation = 0.0f;
	
	std::shared_ptr<SceneNode> node = scene.createSceneNode("disk.3ds", -2, 0, 0);
	std::shared_ptr<SceneNode> node2 = scene.createSceneNode("disk.3ds", 2, 0, 0);

	return node != nullptr;
}