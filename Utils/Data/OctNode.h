#pragma once
#include "../Scene/SceneNode.h"
#include "Region.h"

const int MAX_CHILDREN = 8;
const int MAX_DATA = 8;

class OctNode {
	public:
		OctNode();
		OctNode(Region r);
		void insert(SceneNode n);
		void setRegion(Region r);
	private:
		bool leaf;
		int dataNum;
		Region region;
		std::shared_ptr<SceneNode> data[MAX_DATA]
		std::shared_ptr<SceneNode> children[MAX_CHILDREN];
};