#ifndef _STATE_H_
#define _STATE_H_

#include <SDL2/SDL.h>
#include "../include/Sprite.h"
#include "../include/Music.h"

class State{
public:
	State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();

private:
	Sprite bg;
	Music music;
	bool quitRequested;
};

#endif
