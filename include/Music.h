#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

using namespace std;

class Music{
public:
	Music();
	Music(string file);
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
	void Open(string file);
	bool IsOpen();
	~Music();
private:
	Mix_Music* music;
};

#endif
