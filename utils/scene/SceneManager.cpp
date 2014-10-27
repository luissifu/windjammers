#include "SceneManager.h"

SceneManager::SceneManager() {
	//DELETE THIS AFTER
	rotation = 0.0f;
}

//DELETE THIS AFTER
void SceneManager::setRotation(float r) {
	rotation = r;
}

std::shared_ptr<SceneNode> SceneManager::createStaticNode(std::string filename, float x, float y, float z) {
	Mesh m = loader.getMesh(filename);

	if (m.empty())
	{
		printf("file not found\n");
		return nullptr;
	}

	std::shared_ptr<StaticNode> n = std::make_shared<StaticNode>();

	n->addMesh(m);
	n->setPosition(x, y, z);

	tree.insert(n);
	return n;
}

void SceneManager::drawAll() {
	glClear(GL_COLOR_BUFFER_BIT);

	std::vector<std::shared_ptr<SceneNode>> v;
	tree.getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		std::shared_ptr<SceneNode> node = v[i];

		switch(node->getType())
		{
			case SCENE_NODE_STATIC:
				drawStaticNode(std::dynamic_pointer_cast<StaticNode>(node));
			break;
		}
	}
}

void SceneManager::draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	std::vector<std::shared_ptr<SceneNode>> v;
	tree.getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		std::shared_ptr<SceneNode> node = v[i];

		switch(node->getType())
		{
			case SCENE_NODE_STATIC:
				drawStaticNode(std::dynamic_pointer_cast<StaticNode>(node));
			break;
		}
	}
}

void SceneManager::drawStaticNode(std::shared_ptr<StaticNode> n) {
	Mesh mesh = n->getMesh();

	glPushMatrix();
	glTranslatef(n->getX(), n->getY(), n->getZ());
	glRotatef(-90.0f, 1.0, 0.0, 0.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mesh.getPolygonsQty(); i++)
	{
		polygon p = mesh.getPolygon(i);
		vertex a = mesh.getVertex(p.a);
		vertex b = mesh.getVertex(p.b);
		vertex c = mesh.getVertex(p.c);

		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);
	}
	glEnd();
	glPopMatrix();
}
