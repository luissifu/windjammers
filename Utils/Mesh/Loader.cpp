#include "Loader.h"

Loader::Loader() {}

Mesh Loader::getMesh(std::string filename) {
	for (int i = 0; i < mesh_list.size(); i++)
	{
		if (mesh_list[i].getFileName().compare(filename) == 0)
		{
			return mesh_list[i];
		}
	}

	Mesh new_mesh;
	
	if (loadMesh(new_mesh, filename))
	{
		mesh_list.push_back(new_mesh);
		return new_mesh;
	}
	else //panic!
	{
		return new_mesh;
	}
}

bool Loader::loadMesh(Mesh& mesh, std::string filename) {
	int i;

	FILE* file;

	unsigned short chunkId;
	unsigned int chunkLength;
	unsigned char chr;
	unsigned short qty;
	unsigned short faceFlags;

	file = fopen(filename.c_str(), "rb");

	if (file == NULL)
	{
		printf("failed to open file\n");
		return false;
	}

	mesh.setFileName(filename);

	fseek(file, 0, SEEK_END);
	int end = ftell(file);
	fseek(file, 0, SEEK_SET);

	while (ftell(file) < end)
	{
		fread(&chunkId, 2, 1, file);
		fread(&chunkLength, 4, 1, file);

		switch(chunkId)
		{
			case M3DS_MAIN_CHUNK:
			break;

			case M3DS_EDITOR_CHUNK:
			break;

			case M3DS_OBJECT_BLOCK:
			{
				char name[20];
				i = 0;

				do
				{
					fread(&chr, 1, 1, file);
					name[i] = chr;
					i++;
				}
				while (chr != '\0' && i < 20);

				mesh.setName(std::string(name));
			}
			break;

			case M3DS_TRIANGULAR_MESH:
			break;

			case M3DS_VERTICES_LIST:
			{
				fread (&qty, sizeof (unsigned short), 1, file);
				mesh.setVerticesQty(qty);

				for (i = 0; i < qty; i++)
				{
					vertex v;
					
					fread(&v.x, sizeof(float), 1, file);
					fread(&v.y, sizeof(float), 1, file);
					fread(&v.z, sizeof(float), 1, file);

					mesh.addVertex(v);
				}

			}
			break;

			case M3DS_FACES_DESCRIPTION:
			{
				fread(&qty, sizeof (unsigned short), 1, file);
				mesh.setPolygonsQty(qty);
				
				for (i = 0; i < qty; i++)
				{
					polygon p;
					
					fread(&p.a, sizeof (unsigned short), 1, file);
					fread(&p.b, sizeof (unsigned short), 1, file);
					fread(&p.c, sizeof (unsigned short), 1, file);
					fread(&faceFlags, sizeof (unsigned short), 1, file);

					mesh.addPolygon(p);
				}

			}
			break;

			case M3DS_MAPPING_COORDINATES_LIST:
			{
				fread(&qty, sizeof (unsigned short), 1, file);
				mesh.setCoordsQty(qty);

				for (i = 0; i < qty; i++)
				{
					coord c;
					
					fread(&c.u, sizeof (float), 1, file);
					fread(&c.v, sizeof (float), 1, file);

					mesh.addCoord(c);
				}
			}
			break;

			default:
				fseek(file, chunkLength - 6, SEEK_CUR);
		}
	}

	fclose(file);
	return true;
}