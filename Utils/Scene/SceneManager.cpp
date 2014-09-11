#include "SceneManager.h"

SceneManager::SceneManager() {}

std::shared_prt<SceneNode> createSceneNode() {
	std::shared_prt<SceneNode> n = std::make_shared<SceneNode>();

	//TODO init node

	tree->insert(n);
	return n;
}

void SceneManager::drawAll() {
	std::vector<Node> v;
	tree->getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		drawNode(v[i]);
	}
}

void SceneManager::draw() {
	std::vector<Node> v;
	tree->getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		drawNode(v[i]);
	}
}

void SceneManager::drawNode(SceneNode n) {
	Mesh m = n.getMesh();

	glBegin(GL_POLYGON);
		for (int i = 0; i < n.getVertexQty(); i++)
		{
			vertex v = m.getVertex(i);
			glVertex3f(v.x, v.y, v.z));
		}
	glEnd();
}