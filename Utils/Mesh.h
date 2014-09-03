#pragma once
#include <string>

class Mesh {
	public:
		Mesh();
		std::string getFileName();
		std::string getName();
		int getPolygonsQty();
		int getVerticesQty();
		int getCoordsQty();
		//
		void setFileName(std::string name);
		void setName(std::string name);
		void setPolygonsQty(int qty);
		void setVerticesQty(int qty);
		void setCoordsQty(int qty);
	private:
		int polygons;
		int vertices;
		int coords;
		std::vector<polygon> polygons;
		std::vector<vertex> vertices;
		std::vector<coord> coords;
};