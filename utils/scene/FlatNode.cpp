#include "FlatNode.h"

FlatNode::FlatNode() {
	type = SCENE_NODE_FLAT;
}

void FlatNode::setTexture(Texture t) {
	texture = t;
}

Texture FlatNode::getTexture() {
	return texture;
}

void FlatNode::setSize(int w, int h) {
	width = w;
	height = h;
}

int FlatNode::getWidth() {
	return width;
}

int FlatNode::getHeight() {
	return height;
}
