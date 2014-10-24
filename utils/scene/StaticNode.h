#pragma once
#include "SceneNode.h"
#include "../mesh/Mesh.h"

class StaticNode : public SceneNode {
	public:
		StaticNode();
		void addMesh(Mesh m);
		Mesh getMesh();
	private:
		Mesh mesh;
};
