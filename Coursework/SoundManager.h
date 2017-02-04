#pragma once

#include <bass.h>

using namespace std;

class SoundManager
{
private:
	HSAMPLE *sounds;
public:
	SoundManager(void);
	~SoundManager(); //Deletes music from application to free memory space
	HSAMPLE loadSample(char * filename);
	void playMusic();
	//Need to update user input class.
};

