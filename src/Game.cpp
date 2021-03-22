#include "SDL_image.h"
#include "SDL_mixer.h"
#include "../include/Game.h"
#include <iostream>

using namespace std;

Game* Game::instance;

Game& Game::GetInstance() {
	if(instance == nullptr){
		instance = new Game("Emanuel Silva - 170009360", 1024, 600);
	}
	return *instance;
}

Game::Game(string title, int width, int height){
	if(instance != nullptr){
		exit(EXIT_FAILURE);
	} else {
		instance = this;
	}

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
		cout << "ERRO: " << SDL_GetError() << endl;
	} else {
		if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
			cout << "ERRO: " << SDL_GetError() << endl;
		} else {
			Mix_Init(MIX_INIT_MP3);
			Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
			Mix_AllocateChannels(32);
			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

			if(window == nullptr){
				cout << "ERRO: " << SDL_GetError() << endl;
			} else {
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

				if(renderer == nullptr){
					cout << "ERRO: " << SDL_GetError() << endl;
				} else {
					state = new State();
				}
			}
		}
	}
}

Game::~Game(){
	state = nullptr;
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

State& Game::GetState(){
	return *state;
}

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}

void Game::Run(){
	while(!state->QuitRequested()){
		state->Update(0);
		state->Render();

		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
