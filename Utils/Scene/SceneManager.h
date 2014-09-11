#pragma once
#include "OctTree.h"
#include "SceneNode.h"

class SceneManager {
	public:
		SceneManager();
		std::shared_prt<SceneNode> createSceneNode();
		void drawAll();
	private:
		OctTree tree;
		//
		void drawNode(SceneNode n);
};