#include "Loader.h"

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

Loader::Loader() {}

Mesh Loader::getMesh(std::string filename) {
	for (int i = 0; i < mesh_list.size(); i++)
	{
		if (mesh_list[i].getFileName() == filename)
		{
			return mesh_list[i];
		}
	}

	Mesh new_mesh;

	if (load3ds(new_mesh, filename))
	{
		return new_mesh;
	}
	else //panic!
	{
		return new_mesh;
	}
}

bool Loader::load3ds(Mesh& mesh, std::string filename) {
	int i;
	std::ifstream file;
	file.open(filename.c_str(), std::ios::binary);

	unsigned short chunkId;
	unsigned int chunkLength;
	unsigned char chr;
	unsigned short qty;
	unsigned short faceFlags;

	if (!file.is_open())
		return false;

	mesh.setFileName(filename);

	while (!file.eof())
	{
		file >> chunkId;
		file >> chunkLength;

		switch(chunkId)
		{
			case 3DS_MAIN_CHUNK:
			break;

			case 3DS_EDITOR_CHUNK:
			break;

			case 3DS_OBJECT_BLOCK:
			{
				char[20] name;
				i = 0;

				do
				{
					file >> chr;
					name[i] = chr;
					i++;
				}
				while (chr != '\0' && i < 20);

				mesh.setName(std::string(name));
			}
			break;

			case 3DS_TRIANGULAR_MESH:
			break;

			case 3DS_VERTICES_LIST:
			{
				file >> qty;
				mesh.setVertices(qty);

				for (i = 0; i < qty; i++)
				{
					vertex v;
					
					file >> v.x;
					file >> v.y;
					file >> v.z;

					mesh.addVertex(v);
				}

			}
			break;

			case 3DS_FACES_DESCRIPTION:
			{
				file >> qty;
				mesh.setPolygons(qty);
				
				for (i = 0; i < qty; i++)
				{
					polygon p;
					
					file >> p.a;
					file >> p.b;
					file >> p.c;
					file >> faceFlags;

					mesh.addPolygon(p);
				}

			}
			break;

			case 3DS_MAPPING_COORDINATES_LIST:
			{
				file >> qty;
				mesh.setCoords(qty);

				for (i = 0; i < qty; i++)
				{
					coord c;
					
					file >> c.u;
					file >> c.v;

					mesh.addCoord(c);
				}
			}
			break;

			default:
				file.ignore(chunkLength-6);

		}
	}

	file.close();
	return mesh;
}