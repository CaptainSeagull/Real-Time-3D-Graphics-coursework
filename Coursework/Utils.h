#pragma once
#include <GLM\glm.hpp>
#include <string>

class Utils
{
private:
	Utils(void);
	~Utils(void);
public:
	static glm::vec3 stringToVector(std::string str);
	static float* stringToArray(std::string str, int numValues);
};

