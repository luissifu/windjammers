#pragma once
#include "../Mesh/Loader.h"
#include "../Mesh/Mesh.h"

class SceneNode {
	public:
		SceneNode();
		void addMesh(Mesh m);
		Mesh getMesh();
		void setPosition(int x, int y, int z);
		void setX(float x);
		void setY(float y);
		void setZ(float z);
		float getX();
		float getY();
		float getZ();
		bool isVisible();
		bool isCollidable();
		void setVisible(bool v);
		void setCollidable(bool c);
	private:
		bool visible;
		bool collidable;
		Mesh mesh;
		int x;
		int y;
		int z;
};