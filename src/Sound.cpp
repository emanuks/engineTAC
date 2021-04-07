#include "../include/Sound.h"
#include <iostream>

using namespace std;

Sound::Sound(GameObject& associated) : Component(associated){
	chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Component(associated){
	Open(file);
}

void Sound::Play(int times){
	channel = Mix_PlayChannel(-1, chunk, times);
}

bool Sound::IsOpen(){
	if(chunk){
		return true;
	} else {
		return false;
	}
}

void Sound::Stop(){
	if(IsOpen()){
		Mix_HaltChannel(channel);
	} else {
		cout << "ERRO: " << SDL_GetError() << endl;
	}
}

void Sound::Open(string file){
	chunk = Mix_LoadWAV(file.c_str());

	if(!IsOpen()){
		cout << "ERRO: " << SDL_GetError() << endl;
	}
}

Sound::~Sound(){
	if(IsOpen()){
		Mix_HaltChannel(channel);
	}
	Mix_FreeChunk(chunk);
}

bool Sound::Is(string type){
	if(type == "Sound"){
		return true;
	} else {
		return false;
	}
}

void Sound::Update(float dt){}

void Sound::Render(){}
