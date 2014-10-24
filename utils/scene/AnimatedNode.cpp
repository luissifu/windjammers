#include "AnimatedNode.h"

AnimatedNode::AnimatedNode() {
	type = SCENE_NODE_ANIMATED;
}

void AnimatedNode::addMesh(AnimatedMesh m) {
	mesh = m;
}

AnimatedMesh AnimatedNode::getMesh() {
	return mesh;
}
