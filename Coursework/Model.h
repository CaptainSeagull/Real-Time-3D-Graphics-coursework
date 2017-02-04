#pragma once
#include "GameContext.h"
#include "rt3d.h"
#include "md2model.h"
#include <istream>


	enum ModelType
	{
		OBJ,
		MD2
	};

class Model
{
private:
	GLuint mesh, texture, indexCount;
	int currentMD2Anim;
	int type;
	glm::vec3 pos, scaleFactor, rotation;
	rt3d::materialStruct material;
	md2model md2model;
	const int readInt(std::ifstream &stream) const;
	const float readFloat(std::ifstream &stream) const;
	void readVertex(std::vector<GLfloat> &verts, std::ifstream &stream);
	void loadObjModel(const char* filename, std::vector<GLfloat> &verts, std::vector<GLfloat> &texcoords, 
		std::vector<GLfloat> &norms, std::vector<GLuint> &indices);
public:
	Model(void);
	Model(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotation);
	bool init(int type, const char* file);
	void setMaterial (rt3d::materialStruct material) { this->material = material; }
	void setTexture(char* file);
	void setTexture(GLuint index) {texture = index;}
	void render(GameContext *gameContext);
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
	glm::vec3 getPos() {return pos;}
	glm::vec3 getScale() {return scaleFactor;}
	glm::vec3 getRotation() {return rotation;}
	~Model(void);


	float getXRotation() { return rotation.x; }
	float getYRotation() { return rotation.y; }
	float getZRotation() { return rotation.z; }
};

