#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include "State.h"
#include <string>
using namespace std;

class Game{
private:
	string title;
	int width;
	int height;
	SDL_Renderer* renderer;
	SDL_Window* window;
	State* state;
	Game(string title, int width, int height);
	static Game* instance;

public:
	~Game();
	void Run();
	static Game& GetInstance();
	State& GetState();
	SDL_Renderer* GetRenderer();
};

#endif
