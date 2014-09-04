#include "Node.h"

Node::Node() {
	visible = collidable = false;
	x = y = z = 0.0f;
}

void Node::addMesh(Mesh m) {
	mesh = m;
}

void Node::setPosition(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Node::setX(float x) {
	this->x = x;
}

void Node::setY(float y) {
	this->y = y;
}

void Node::setZ(float z) {
	this->z = z;
}

float Node::getX() {
	return x;
}

float Node::getY() {
	return y;
}

float Node::getZ() {
	return z;
}

bool Node::isVisible() {
	return visible;
}

bool Node::isCollidable() {
	return collidable;
}

void Node::setVisible(bool v) {
	visible = v;
}

void Node::setCollidable(bool c) {
	collidable = c;
}
