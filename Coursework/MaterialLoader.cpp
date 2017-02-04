#include "MaterialLoader.h"
#include "Utils.h"
#include <fstream>

using namespace std;

MaterialLoader::MaterialLoader(void)
{
}

rt3d::materialStruct MaterialLoader::loadMaterial(const char* filename)
{
	GLfloat *ambient, *diffuse, *specular;
	GLfloat shininess;

	fstream stream (filename);
	string line;

	if(stream.is_open())
	{
		getline(stream, line);
		ambient = Utils::stringToArray(line, 4);

		getline(stream, line);
		diffuse = Utils::stringToArray(line, 4);

		getline(stream, line);
		specular = Utils::stringToArray(line, 4);

		getline(stream, line);
		shininess = stof(line);

		rt3d::materialStruct mat = 
		{ 
			{ambient[0], ambient[1], ambient[2], ambient[3]},
			{diffuse[0], diffuse[1], diffuse[2], diffuse[3]}, 
			{specular[0], specular[1], specular[2], specular[3]},
			shininess
		};

		return mat;
	}
	rt3d::materialStruct mat = {};
	return mat;
}

MaterialLoader::~MaterialLoader(void)
{
}
