#include "Mesh.h"

Mesh::Mesh() {
	polygons = vertices = coords = 0;
	name = fileName = "";
}

std::string getFileName() {
	return fileName;
}

std::string getName() {
	return name;
}

int getPolygonsQty() {
	return polygons;
}

int getVerticesQty() {
	return vertices;
}

int getCoordsQty() {
	return coords;
}

void setFileName(std::string name) {
	this->fileName = fileName;
}

void setName(std::string name) {
	this->name = name;
}

void setPolygonsQty(int qty) {
	polygons = qty;
}

void setVerticesQty(int qty) {
	vertices = qty;
}

void setCoordsQty(int qty) {
	coords = qty;
}

void addPolygon(polygon p) {
	polygon_list.push_back(p);
}

void addVertex(vertex v) {
	vertex_list.push_back(v);
}

void addCoord(coord c) {
	coord_list.push_back(c);
}
