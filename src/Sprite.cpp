#include "../include/Sprite.h"
#include "../include/Game.h"
#include <iostream>

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated){
	texture = nullptr;
}

Sprite::Sprite(GameObject& associated, string file) : Component(associated){
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite(){
	if(texture){
		SDL_DestroyTexture(texture);
	}
}

void Sprite::Open(string file){
	if(texture){
		SDL_DestroyTexture(texture);
	}

	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

	texture = IMG_LoadTexture(renderer, file.c_str());

	if(!texture){
		cout << "ERRO: " << SDL_GetError() << endl;
	} else {
		if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)){
			cout << "ERRO: " << SDL_GetError() << endl;
		} else {
			SetClip(0, 0, width, height);
		}
	}
}

void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(){
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

    SDL_Rect dst;
    dst.x= associated.box.x;
    dst.y= associated.box.y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;

	if(SDL_RenderCopy(renderer, texture, &clipRect, &dst)){
		cout << "ERRO: " << SDL_GetError() << endl;
	}
}

int Sprite::GetWidth(){
	return width;
}

int Sprite::GetHeight(){
	return height;
}

bool Sprite::IsOpen(){
	if(texture){
		return true;
	} else{
		return false;
	}
}

void Sprite::Update(float dt){}

bool Sprite::Is(string type){
	if(type == "Sprite"){
		return true;
	} else {
		return false;
	}
}
