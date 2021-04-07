#ifndef _STATE_H_
#define _STATE_H_

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State{
public:
	State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
	~State();

private:
	Sprite *bg;
	Music music;
	bool quitRequested;
	void Input();
	void AddObject(int mouseX, int mouseY);
	vector<unique_ptr<GameObject>> objectArray;
};

#endif
