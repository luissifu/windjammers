#pragma once
#include "Loader.h"
#include "Mesh.h"

class Node {
	public:
		Node();
		void addMesh(Mesh m);
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