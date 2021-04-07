#include "../include/GameObject.h"

GameObject::GameObject(){
	isDead = false;
}

GameObject::~GameObject(){
	int size = components.size() - 1;
	for (int i = size; i >= 0; i--){
		components.erase(components.begin()+i);
	}
	components.clear();
}

void GameObject::Update(float dt){
	int size = components.size();
	for (int i = 0; i < size; i++){
		components[i]->Update(dt);
	}
}

void GameObject::Render(){
	int size = components.size();
	for (int i = 0; i < size; i++){
		components[i]->Render();
	}
}

bool GameObject::IsDead(){
	return isDead;
}

void GameObject::RequestDelete(){
	isDead = true;
}

void GameObject::AddComponent(Component* cpt){
	components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
	int size = components.size();
	for (int i = 0; i < size; i++){
		if(cpt == components[i].get()) {
			components.erase(components.begin()+i);
		}
	}
}

Component* GameObject::GetComponent(string type){
	int size = components.size();
	for (int i = 0; i < size; i++){
		if(components[i]->Is(type)) {
			return components[i].get();
		}
	}
	return nullptr;
}
