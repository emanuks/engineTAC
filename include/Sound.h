#ifndef _SOUND_H_
#define _SOUND_H_

#include <string>
#include <SDL2/SDL_mixer.h>
#include "GameObject.h"

using namespace std;

class Sound : public Component{
public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, string file);
	~Sound();
	void Play(int times = 1);
	void Stop();
	void Open(string file);
	bool IsOpen();
	void Update(float dt);
	void Render();
	bool Is(string type);
private:
	Mix_Chunk* chunk;
	int channel;
};

#endif
