#include "Utils.h"

using namespace std;

Utils::Utils(void)
{
}

glm::vec3 Utils::stringToVector(string str)
{
	//NEEDS FIXED!!!! 
	string numbers[3];

	for(int i=0; i<3; i++)
	{
		numbers[i] = str.substr((str.find_first_of(' ')+1)*i, str.find_first_of(' ')*(i+1));
	}
	
	glm::vec3 vector (stof(numbers[0], nullptr), stof(numbers[1], nullptr), stof(numbers[2], nullptr));

	return vector;
}
float* Utils::stringToArray(string str, int numValues)
{
	//NEEDS FIXED!!!! 
	float *array = new float[numValues];
	

	for(int i=0; i<numValues; i++)
	{
		string number = str.substr((str.find_first_of(' ')+1)*i, str.find_first_of(' ')*(i+1));
		array[i] = stof(number, nullptr);
	}

	return array;
}



Utils::~Utils(void)
{
}
