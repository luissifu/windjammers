#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "Mesh.h"

const int max_vertices = 8000;
const int max_polygons = 8000;

const enum 3ds_data_names {
	3DS_UNKNOWN = 					0x0000,
	3DS_MAIN_CHUNK = 				0x4D4D,
	3DS_EDITOR_CHUNK = 				0x3D3D,
	3DS_OBJECT_BLOCK = 				0x4000,
	3DS_TRIANGULAR_MESH = 			0x4100,
	3DS_VERTICES_LIST = 			0x4110,
	3DS_FACES_DESCRIPTION = 		0x4120,
	3DS_MAPPING_COORDINATES_LIST = 	0x4140
};

class Loader {
	public:
		Loader();
		void getMesh(std::string filename);
	private:
		bool loadMesh(Mesh& mesh, std::string filename);
		std::vector<Mesh> meshes;
}