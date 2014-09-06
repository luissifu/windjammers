#pragma once
#include <memory>
#include "OctNode.h"

class OctTree {
	public:
		OctTree();
		void insert(Node n);
		int getSize();
	private:
		std::shared_prt<OctNode> root;
		int size;
}