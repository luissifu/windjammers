#include "Mesh.h"

Mesh::Mesh() {
	polygons = vertices = coords = 0;
	name = fileName = "";
}

std::string Mesh::getFileName() {
	return fileName;
}

std::string Mesh::getName() {
	return name;
}

int Mesh::getPolygonsQty() {
	return polygons;
}

int Mesh::getVerticesQty() {
	return vertices;
}

int Mesh::getCoordsQty() {
	return coords;
}

void Mesh::setFileName(std::string fn) {
	fileName = fn;
}

void Mesh::setName(std::string n) {
	name = n;
}

void Mesh::setPolygonsQty(int qty) {
	polygons = qty;
}

void Mesh::setVerticesQty(int qty) {
	vertices = qty;
}

void Mesh::setCoordsQty(int qty) {
	coords = qty;
}

void Mesh::addPolygon(polygon p) {
	polygon_list.push_back(p);
}

void Mesh::addVertex(vertex v) {
	vertex_list.push_back(v);
}

void Mesh::addCoord(coord c) {
	coord_list.push_back(c);
}
