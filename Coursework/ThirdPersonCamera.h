#pragma once
#include <GLM\glm.hpp>

//Camera which returns a world-to-view matrix given a specific subject to follow. 
class ThirdPersonCamera
{
private:
	/**Controls where the camera is placed, relative to the subject. 
	**Radius is how far from the subject it is placed
	**Inclination and azimuth are the longitudanel and latitudanel angles of the desired position in a sphere around the subject. **/
	float radius, inclination, azimuth;
public:
	ThirdPersonCamera() : radius(1), inclination(0), azimuth(0){}
	void setRadius(float radius) {this->radius = radius;}
	void setInclination(float inclination) {this->inclination = inclination;}
	void setAzimuth(float azimuth) {this->azimuth = azimuth;}
	glm::mat4 getViewMat(glm::vec3 subjectPos);
	~ThirdPersonCamera();
};

