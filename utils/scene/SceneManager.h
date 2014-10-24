#pragma once
#include "../../Constants.h"
#include "../data/OctTree.h"
#include "../mesh/Loader.h"
#include "SceneNode.h"
#include "StaticNode.h"
#include "FlatNode.h"
#include "AnimatedNode.h"
#include <memory>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

class SceneManager {
	public:
		SceneManager();
		std::shared_ptr<SceneNode> createStaticNode(std::string filename, float x, float y, float z);
		void drawAll();
		void draw();
		void setRotation(float r);
	private:
		OctTree tree;
		Loader loader;
		//
		void drawStaticNode(std::shared_ptr<StaticNode> n);
		float rotation;
};
