#pragma once
#include "../Data/OctTree.h"
#include "SceneNode.h"
#include <memory>

class SceneManager {
	public:
		SceneManager();
		std::shared_ptr<SceneNode> createSceneNode();
		void drawAll();
		void draw();
	private:
		OctTree tree;
		//
		void drawNode(SceneNode n);
};