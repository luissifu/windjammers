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
	Mesh m = loader.getMesh(filename + ".3ds");

	if (m.empty())
	{
		printf("file not found\n");
		return nullptr;
	}

	Texture t = loader.getTexture(filename + ".png");
	
	if (t.empty())
	{
		printf("model has no texture");
		return nullptr;
	}

	m.setTexture(t);

	std::shared_ptr<StaticNode> n = std::make_shared<StaticNode>();

	n->addMesh(m);
	n->setPosition(x, y, z);

	tree.insert(n);
	return n;
}

std::shared_ptr<SceneNode> SceneManager::createFlatNode(std::string filename, float x, float y, float w, float h) {
	std::shared_ptr<FlatNode> n = std::make_shared<FlatNode>();

	n->setPosition(x, y, 0);
	n->setSize(w, h);

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

			case SCENE_NODE_FLAT:
				drawFlatNode(std::dynamic_pointer_cast<FlatNode>(node));
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

			case SCENE_NODE_FLAT:
				drawFlatNode(std::dynamic_pointer_cast<FlatNode>(node));
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
	glScalef(0.5, 0.5, 0.5);
	//glColor3f(0.0, 0.0, 1.0);
	
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mesh.getPolygonsQty(); i++)
	{
		polygon p = mesh.getPolygon(i);
		vertex a = mesh.getVertex(p.a);
		vertex b = mesh.getVertex(p.b);
		vertex c = mesh.getVertex(p.c);
		coord aa = mesh.getCoord(p.a);
		coord bb = mesh.getCoord(p.b);
		coord cc = mesh.getCoord(p.c);

		glTexCoord2f(aa.u, aa.v);
		glVertex3f(a.x, a.y, a.z);
		glTexCoord2f(bb.u, bb.v);
		glVertex3f(b.x, b.y, b.z);
		glTexCoord2f(cc.u, cc.v);
		glVertex3f(c.x, c.y, c.z);
	}
	glEnd();
	
	glPopMatrix();
}

void SceneManager::drawFlatNode(std::shared_ptr<FlatNode> n) {
	glPushMatrix();
	
	//unrotate
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-35.264f, 1.0f, 0.0f, 0.0f);

	glTranslatef(n->getX() - DEFAULT_WIDTH / GL_HALF_SCALE, n->getY() - DEFAULT_HEIGHT / GL_HALF_SCALE, n->getZ());

	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, n->getHeight(), 0);
		glVertex3f(n->getWidth(), n->getHeight(), 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(n->getWidth(), 0, 0);
		glVertex3f(n->getWidth(), n->getHeight(), 0);
	glEnd();
	
	glPopMatrix();
}