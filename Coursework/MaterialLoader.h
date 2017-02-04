#pragma once
#include "rt3d.h"

class MaterialLoader
{
private:
	MaterialLoader(void);
	~MaterialLoader(void);
public:
	static rt3d::materialStruct loadMaterial(const char* file);
};

