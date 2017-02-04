#pragma once
#include "GameContext.h"

class Skybox
{
private:
	GLuint *texture;
	GLuint *mesh;

public:
	Skybox(void);
	~Skybox(void);
	void render(GameContext * gameContext);
	void loadFrontTexture(char * filename); //Loads front texture for skybox
	void loadBackTexture(char * filename); //Loads back texture for skybox
	void loadLeftTexture(char * filename); //Loads left texture for skybox
	void loadRightTexture(char * filename); //Loads right texture for skybox
	void loadTopTexture(char * filename); //Loads top texture for skybox
};

