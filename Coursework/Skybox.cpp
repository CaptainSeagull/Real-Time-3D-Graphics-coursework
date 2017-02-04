#include "Skybox.h"
#include "rt3d.h"
#include <FreeImage.h>
#include <GLM\gtc\matrix_transform.hpp>
#include <GLM\gtc\type_ptr.hpp>
#include <iostream>

GLfloat vertsFront[] = {-1.0f, -1.0f, 1.0f,
						-1.0f, 1.0f, 1.0f,
						1.0f, 1.0f, 1.0f,
						1.0f, -1.0f, 1.0f};

GLfloat vertsBack[] = {-1.0f, -1.0f, -1.0f,
						-1.0f, 1.0f, -1.0f,
						1.0f, 1.0f, -1.0f,
						1.0f, -1.0f, -1.0f};

GLfloat vertsLeft[] = {-1.0f, -1.0f, -1.0f,
						-1.0f, 1.0f, -1.0f,
						1.0f, 1.0f, 1.0f,
						1.0f, -1.0f, 1.0f};

GLfloat vertsRight[] = {-1.0f, -1.0f, 1.0f,
						-1.0f, 1.0f, 1.0f,
						1.0f, 1.0f, -1.0f,
						1.0f, -1.0f, -1.0f};

GLfloat vertsTop[] = {-1.0f, 1.0f, -1.0f,
						1.0f, 1.0f, -1.0f,
						1.0f, 1.0f, 1.0f,
						-1.0f, 1.0f, 1.0f};

GLuint skyboxIndices[] = {0,1,2, 0,2,3}; //Back
						  /*1,0,5, 0,4,5, //Left
						  6,3,2, 3,6,7, //Right
						  1,5,6, 1,6,2, //Top
						  0,3,4, 3,7,4, //Bottom
						  6,5,4, 7,6,4 }; //Front*/

GLfloat skyboxTextCoords[] = {0.0f, 0.0f,
							  0.0f, 1.0f,
							  1.0f, 1.0f,
							  1.0f, 0.0f};

unsigned int loadTexture(char * filename) //Laods a texture using the FreeImage library 
{
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0); 

	FIBITMAP * bitmap = FreeImage_Load(format, filename);
	FIBITMAP * temp = FreeImage_ConvertTo32Bits(bitmap);

	unsigned int ID = 0;

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FreeImage_GetWidth(temp), FreeImage_GetHeight(temp), 0, GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(temp));
	
	GLenum err = glGetError();
	if ( err  != GL_NO_ERROR ) {
		std::cout << '\n' << "Skybox Error: " << err << std::endl;
	}

	//std::cout << FreeImage_GetWidth(temp) << std::endl; //Test for width of image
	//std::cout << FreeImage_GetHeight(temp) << std::endl; //Test for height of image

	FreeImage_Unload(bitmap);
	FreeImage_Unload(temp); //Unloads image.

	return ID;
}

Skybox::Skybox(void)
{
	texture = new GLuint[5]; //Textures for skybox
	mesh = new GLuint[5]; //Meshes for the skybox

	//Setting up 5 meshes for each face of the skybox
	mesh[0] = rt3d::createMesh(4, vertsFront, nullptr, vertsFront, skyboxTextCoords, 6, skyboxIndices);
	mesh[1] = rt3d::createMesh(4, vertsBack, nullptr, vertsBack, skyboxTextCoords, 6, skyboxIndices);
	mesh[2] = rt3d::createMesh(4, vertsLeft, nullptr, vertsLeft, skyboxTextCoords, 6, skyboxIndices);
	mesh[3] = rt3d::createMesh(4, vertsRight, nullptr, vertsRight, skyboxTextCoords, 6, skyboxIndices);
	mesh[4] = rt3d::createMesh(4, vertsTop, nullptr, vertsTop, skyboxTextCoords, 6, skyboxIndices);
}


Skybox::~Skybox(void)
{
	delete texture;
	delete mesh;
}

void Skybox::render(GameContext * gameContext)
{
	gameContext->switchShader(gameContext->skyboxShaderProgram);

	glm::mat3 rotationMatrix = glm::mat3(gameContext->viewMatrix);
	glm::mat4 modelView = glm::mat4(rotationMatrix);
	glm::mat4 model = glm::mat4(1.0f);
	
	glDepthMask(GL_FALSE); // make sure depth test is off
	for(int index=0; index<5; index++)
	{
		modelView = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		rt3d::setUniformMatrix4fv(gameContext->skyboxShaderProgram, "modelview", glm::value_ptr(modelView));
		glBindTexture(GL_TEXTURE_2D, texture[index]);
		rt3d::drawIndexedMesh(mesh[index], 6, GL_TRIANGLES);
	}
	glDepthMask(GL_TRUE); // make sure depth test is on
	gameContext->switchShader(gameContext->defaultShaderProgram);
}

void Skybox::loadFrontTexture(char *filename)
{
	texture[0] = loadTexture(filename);
	
}

void Skybox::loadBackTexture(char *filename)
{
	texture[1] = loadTexture(filename);
	
}

void Skybox::loadLeftTexture(char *filename)
{
	texture[2] = loadTexture(filename);
	
}

void Skybox::loadRightTexture(char *filename)
{
	texture[3] = loadTexture(filename);
	
}

void Skybox::loadTopTexture(char *filename)
{
	texture[4] = loadTexture(filename);
	
}
