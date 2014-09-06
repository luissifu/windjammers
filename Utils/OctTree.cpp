#include "OctTree.h"

OctTree::OctTree() {
	size = 0;
	root = std::make_shared<OctNode>();
}

void OctTree::insert(Node n) {
	root->insert(n);
}

int OctTree::getSize() {
	return size;
}