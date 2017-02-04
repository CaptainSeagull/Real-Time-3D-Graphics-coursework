#include "Cube.h"
#include <GLM\gtc\matrix_transform.hpp>
#include <GLM\gtc\type_ptr.hpp>

GLuint cubeVertCount = 8;
GLfloat cubeVerts[] = { -0.5, -0.5f, -0.5f,
						-0.5, 0.5f, -0.5f,
						0.5, 0.5f, -0.5f,
						0.5, -0.5f, -0.5f,
						-0.5, -0.5f, 0.5f,
						-0.5, 0.5f, 0.5f,
						0.5, 0.5f, 0.5f,
						0.5, -0.5f, 0.5f };
GLfloat cubeColours[] = {	0.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f,
							1.0f, 1.0f, 0.0f,
							1.0f, 0.0f, 0.0f,
							0.0f, 0.0f, 1.0f,
							0.0f, 1.0f, 1.0f,
							1.0f, 1.0f, 1.0f,
							1.0f, 0.0f, 1.0f };
GLfloat cubeTexCoords[] = { 0.0f, 0.0f,
							0.0f, 1.0f,
							1.0f, 1.0f,
							1.0f, 0.0f,
							1.0f, 1.0f,
							1.0f, 0.0f,
							0.0f, 0.0f, 
							0.0f, 1.0f  };

GLuint cubeIndexCount = 36;
GLuint cubeIndices[] = {	0,1,2, 0,2,3, // back 
							1,0,5, 0,4,5, // left
							6,3,2, 3,6,7, // right
							1,5,6, 1,6,2, // top
							0,3,4, 3,7,4, // bottom
							6,5,4, 7,6,4 }; // front

Cube::Cube(void)
{
}

Cube::Cube(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation)
{
	this->pos = pos;
	this->scaleFactor = scale;
	this->rotation = rotation;
}


bool Cube::init()
{
	mesh = rt3d::createMesh(cubeVertCount, cubeVerts, nullptr, cubeVerts, cubeTexCoords, cubeIndexCount, cubeIndices);
	return true;
}
	
void Cube::setTexture(char* file)
{
	texture = rt3d::loadBitmap(file);
}

void Cube::render(GLuint shaderProgram, glm::mat4 viewMat)
{
	rt3d::setMaterial(shaderProgram, material);
	glBindTexture(GL_TEXTURE_2D, texture);
	glm::mat4 model, modelView;
	model = glm::mat4(1.0f);
	model = glm::translate(model, pos);
	model = glm::scale(model, scaleFactor);
	model = glm::rotate(model, 1.0f, rotation);
	modelView = viewMat * model;
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(modelView));
	rt3d::drawIndexedMesh(mesh,cubeIndexCount,GL_TRIANGLES);
}

Cube::~Cube(void)
{
}
