#include "OctNode.h"

OctNode::OctNode() {
	leaf = true;
	dataNum = 0;
}

OctNode::OctNode(Region r) {
	leaf = true;
	dataNum = 0;
	region = r;
}

void OctNode::insert(SceneNode n) {
	if (!leaf)
	{
		if (dataNum < MAX_DATA)
		{
			data[dataNum] = std::make_shared<Node>();
			dataNum++;
		}
		else
		{
			leaf = false;
			std::vector<Region> regions = region.split();

			for (int i = 0; i < MAX_CHILDREN; i++)
			{
				children[i] = std::make_shared<OctNode>(regions[i]);
			}

			add(n);
		}
	}
	else
	{
		add(n);
	}
}

void add(SceneNode n) {
	for (int i = 0; i < MAX_CHILDREN; i++)
	{
		if (children[i]->inside(n.x, n.y, n.z))
		{
			children[i]->insert(n);
			break;	
		}
	}
}

void OctNode::setRegion(Region r) {
	region = r;
}
