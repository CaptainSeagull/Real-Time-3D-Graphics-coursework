#include "ThirdPersonCamera.h"
#include <GLM\gtc\matrix_transform.hpp>

glm::mat4 ThirdPersonCamera::getViewMat(glm::vec3 subjectPos)
{
	glm::vec3 cameraPosition;
	//Get the position of the camera in local space.
	// x = radius x sin(inclination) x cos(azimuth)
	// y = radius x sin(inclination) x sin(azimuth)
	// z = radius x cos(inclination)
	cameraPosition = glm::vec3(radius*sin(inclination)*cos(azimuth), radius*sin(inclination)*sin(azimuth), radius*cos(inclination));
	//Translate the position to be relative to the subject's position
	cameraPosition += subjectPos;
	//Create a world-to-view matrix from the position of the camera, the position of the subject, and an up direction. 
	glm::mat4 viewMat = glm::lookAt(cameraPosition, subjectPos, glm::vec3(0, 1, 0));
	return viewMat;
}

ThirdPersonCamera::~ThirdPersonCamera()
{
}
