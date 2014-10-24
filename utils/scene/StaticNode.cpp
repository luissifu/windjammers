#include "StaticNode.h"

StaticNode::StaticNode() {
	type = SCENE_NODE_STATIC;
}

void StaticNode::addMesh(Mesh m) {
	mesh = m;
}

Mesh StaticNode::getMesh() {
	return mesh;
}
