#pragma once
#include "Node.h"
#include "Region.h"

const int MAX_CHILDREN = 8;
const int MAX_DATA = 8;

class OctNode {
	public:
		OctNode();
		OctNode(Region r);
		void insert(Node n);
		void setRegion(Region r);
	private:
		bool leaf;
		int dataNum;
		Region region;
		std::shared_ptr<Node> data[MAX_DATA]
		std::shared_ptr<Node> children[MAX_CHILDREN];
};