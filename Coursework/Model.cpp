#include "Model.h"
#include "rt3dObjLoader.h"
#include <GLM\gtc\type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <sstream>

using namespace std;

Model::Model(void)
{
	pos = glm::vec3(0.0f);
	scaleFactor = glm::vec3(1.0f);
	rotation = glm::vec3(0.0f);
	texture = 0;
}

Model::Model(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation)
{
	this->pos = pos;
	this->scaleFactor = scale;
	this->rotation = rotation;
	texture = 0;
}


bool Model::init(int type, const char* file)
{
	currentMD2Anim = 0;
	this->type = type;
	switch(type)
	{
	case ModelType::MD2:
		mesh = md2model.ReadMD2Model(file);
		break;
	case ModelType::OBJ:
		vector<GLfloat> verts;
		vector<GLfloat> norms;
		vector<GLfloat> tex_coords;
		vector<GLuint> indices;
		rt3d::loadObj(file, verts, norms, tex_coords, indices);
		GLuint size = indices.size();
		indexCount = size;
		mesh = rt3d::createMesh(verts.size()/3, verts.data(), nullptr, norms.data(), tex_coords.data(), size, indices.data());
		break;
	}
	return true;
}
	
void Model::setTexture(char* file)
{
	texture = rt3d::loadBitmap(file);
}

void Model::render(GameContext *gameContext)
{
	rt3d::setMaterial(gameContext->defaultShaderProgram, material);
	glBindTexture(GL_TEXTURE_2D, texture);
	glm::mat4 model, modelView;
	model = glm::mat4(1.0f);
	model = glm::translate(model, pos);
	model = glm::scale(model, scaleFactor);
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	modelView = gameContext->viewMatrix * model;
	rt3d::setUniformMatrix4fv(gameContext->defaultShaderProgram, "modelview", glm::value_ptr(modelView));
	switch(type)
	{
	case ModelType::OBJ:
		rt3d::drawIndexedMesh(mesh,indexCount,GL_TRIANGLES);
		break;
	case ModelType::MD2:
		int md2VertCount = md2model.getVertDataSize();
		/*md2model.Animate(currentMD2Anim, 0.1);
		rt3d::updateMesh(mesh, RT3D_VERTEX, md2model.getAnimVerts(), md2VertCount);*/
	
		glCullFace(GL_FRONT);
		rt3d::drawMesh(mesh, md2VertCount, GL_TRIANGLES);
		glCullFace(GL_BACK);
		break;
	}
}

const float Model::readFloat(ifstream &stream) const
{
	float value = 0.0f; //Float to hold our value, and return.
	stringstream ss; //stringstream to stream characters into the float.
	char character = stream.get(); //char to hold each character read.
	while(stream.good() && character != ' ') //Keep reading until no more file, or a space is found.
	{
		ss << character;
		character = stream.get();
	} 

	if(!(ss >> value))
	{
		//Converstion from string to float has failed. Boo. 
		cout << "Invalid input from file" << endl;
		return 0.0f;
	}
	else
		return value;
}

const int Model::readInt(ifstream &stream) const
{
	int value = 0; //int to hold our value, and return.
	stringstream ss; //stringstream to stream characters into the float.
	char character = stream.get(); //char to hold each character read.
	while(stream.good() && character != ' ' && character != '/n') //Keep reading until no more file, or a space or newline is found.
	{
		ss << character;
		character = stream.get();
	} 

	if(!(ss >> value))
	{
		//Converstion from string to int has failed. Boo. 
		cout << "Invalid input from file" << endl;
		return 0;
	}
	else
		return value;
}

void Model::readVertex (vector<GLfloat> &verts, ifstream &stream)
{
	char nextChar = stream.peek(); //Peek at the next character in the file.

	while(nextChar != '/n' && nextChar != '#' && nextChar != 'v') //While the next character isn't a new line, a comment, or a new vertex.
	{
		verts.push_back(readFloat(stream));//Add the float read from the file to the vertex list.
	}
}


void Model::loadObjModel(const char* filename, vector<GLfloat> &verts, vector<GLfloat> &texCoords, 
		vector<GLfloat> &norms, vector<GLuint> &indices)
{
	//Open .obj file.
	ifstream stream = ifstream(filename);
	//Check if file has been opened correctly
	if(stream.is_open())
	{
		//Keep reading file until it can't. 
		while(stream.good())
		{
			//Check what the next character is
			switch(stream.get())
			{
			case 'v': //'v' denotes it is a vertex of some kind. 
				switch(stream.get())
				{
				case ' ': //a lone 'v' means it is a postion vertex.
					readVertex(verts, stream);
					break;
				case 't': //a 'vt' means it is a texture coordinate.
					readVertex(texCoords, stream);
					break;
				case 'n': //a 'vn' means it is a normal.
					readVertex(norms, stream);
					break;
				}
				break;
			case '#': //Anything following this symbol can be ignored
				stream.getline(new char(), 256);
				break;
			case 'f': //a 'f' indicates a list of face indices follow. 
				//Read in indices somehow 
				break;
			}

		}
	}
}

Model::~Model(void)
{
}
