#include "SoundManager.h"
#include <iostream>

using namespace std;

SoundManager::SoundManager()
{
	if(!BASS_Init(-1, 44100, 0, 0, NULL))
		cout << "Cant't initialise sound." << endl;

	sounds = new HSAMPLE[1]; //Best way to manipulater BASS is through use of arrays.
	sounds [0] = loadSample("01 Timber (feat. Ke$ha).wav");

	//cout << "Press P to pause music and R to resume music" << endl;

}


SoundManager::~SoundManager() //Deleted music to free up memory
{
	BASS_Stop();
	BASS_Free();
}

HSAMPLE SoundManager::loadSample(char * filename)
{
	HSAMPLE music;
	music = BASS_SampleLoad(FALSE, filename, 0, 0, 3, BASS_SAMPLE_LOOP);
	return music;
}
	
void SoundManager::playMusic()
{
	HCHANNEL song = BASS_SampleGetChannel(sounds[0], FALSE);
	BASS_ChannelSetAttributes(song, -1 , 50, (rand()%201)-100);
	BASS_ChannelPlay(song, TRUE);

	if(!BASS_ChannelPlay(song, FALSE))
		cout << "Can't play sample" <<endl;
}