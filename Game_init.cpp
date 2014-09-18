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

	return true;
}

bool Game::initTest() {
	mesh = loader.getMesh("disk.3ds");
	
	if (mesh.getName().empty())
	{
		printf("Mesh not found");
		return false;
	}

	printf("Mesh data = %s", mesh.getName().c_str());

	return true;
}