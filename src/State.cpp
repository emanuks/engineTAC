#include "../include/State.h"
#include "../include/Sprite.h"
#include <iostream>

State::State(){
	quitRequested = false;
	LoadAssets();
}

void State::LoadAssets(){
	bg.Open("assets/img/ocean.jpg");
	music.Open("assets/audio/stageState.ogg");
}

void State::Update(float dt){
	if(SDL_QuitRequested()){
		quitRequested = true;
	}
}

void State::Render(){
	bg.Render(0,0);
	music.Play();
}

bool State::QuitRequested(){
	return quitRequested;
}
