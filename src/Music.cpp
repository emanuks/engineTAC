#include "../include/Music.h"
#include <iostream>

using namespace std;

Music::Music(){
	music = nullptr;
}

Music::Music(string file){
	music = nullptr;
	Open(file);
}

void Music::Play(int times){
	if(music){
		Mix_PlayMusic(music, times);
	} else {
		cout << "ERRO: " << SDL_GetError() << endl;
	}
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
	music = Mix_LoadMUS(file.c_str());
	if (!music){
		cout << "ERRO: " << SDL_GetError() << endl;
	}
}

bool Music::IsOpen(){
	if(music){
		return true;
	} else {
		return false;
	}
}

Music::~Music(){
	Stop();
	Mix_FreeMusic(music);
}
