#pragma once
#include <GLM\glm.hpp>
#include "rt3d.h"

class Cube
{
private:
	GLuint mesh, texture;
	glm::vec3 pos, scaleFactor, rotation;
	rt3d::materialStruct material;
public:
	Cube();
	Cube(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation);
	bool init();
	void setMaterial (rt3d::materialStruct material) { this->material = material; }
	void setTexture(char* file);
	void setTexture(GLuint index) {texture = index;}
	void render(GLuint shaderProgram, glm::mat4 viewMat);
	void rotate(float x, float y, float z) {rotation.x+=x; rotation.y+=y; rotation.z+=z;}
	void scale(float x, float y, float z) {scaleFactor.x+=x; scaleFactor.y+=y; scaleFactor.z+=z;}
	void translate(float x, float y, float z) {pos.x+=x; pos.y+=y; pos.z+=z;}
	void rotate(glm::vec3 vec) {rotation += vec;}
	void scale(glm::vec3 vec) {scaleFactor += vec;}
	void translate(glm::vec3 vec) {pos += vec;}
	void setRotate(float x, float y, float z) { rotation.x = x; rotation.y = y; rotation.z = z;}
	void setScale(float x, float y, float z) { scaleFactor.x = x; scaleFactor.y = y; scaleFactor.z = z;}
	void setPos(float x, float y, float z) { pos.x = x; pos.y = y; pos.z = z;}
	void setRotate(glm::vec3 vec) {rotation = vec;}
	void setScale(glm::vec3 vec) {scaleFactor = vec;}
	void setPos(glm::vec3 vec) {pos = vec;}
	~Cube(void);
};

