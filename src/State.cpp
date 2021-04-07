#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Face.h"
#include "../include/Vec2.h"
#include "../include/Sound.h"

State::State(){
	quitRequested = false;

	GameObject *gameObject = new GameObject();
	gameObject->box.x = 0;
	gameObject->box.y = 0;

	bg = new Sprite(*gameObject, "assets/img/ocean.jpg");
	gameObject->box.w = bg->GetHeight();
	gameObject->box.h = bg->GetHeight();
	gameObject->AddComponent(bg);
	objectArray.emplace_back(gameObject);

	LoadAssets();
	music.Play(-1);
}

State::~State(){
	objectArray.clear();
}

void State::LoadAssets(){
	music.Open("assets/audio/stageState.ogg");
}

void State::Update(float dt){
	Input();
	int size = objectArray.size();
	for (int i = 0; i < size; i++){
		objectArray[i]->Update(dt);
	}

	for (int i = 0; i < objectArray.size(); i++){
		if(objectArray[i]->IsDead()){
			objectArray.erase(objectArray.begin()+i);
			i--;
		}
	}
}

void State::Render(){
	int size = objectArray.size();
	for (int i = 0; i < size; i++){
		objectArray[i]->Render();
	}
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::Input(){
		SDL_Event event;
		int mouseX, mouseY;

		// Obtenha as coordenadas do mouse
		SDL_GetMouseState(&mouseX, &mouseY);

		// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
		while (SDL_PollEvent(&event)) {

			// Se o evento for quit, setar a flag para terminação
			if(event.type == SDL_QUIT) {
				quitRequested = true;
			}

			// Se o evento for clique...
			if(event.type == SDL_MOUSEBUTTONDOWN) {

				// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
				for(int i = objectArray.size() - 1; i >= 0; --i) {
					// Obtem o ponteiro e casta pra Face.
					GameObject* go = (GameObject*) objectArray[i].get();
					// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
					// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
					// ao usar get(), violamos esse princípio e estamos menos seguros.
					// Esse código, assim como a classe Face, é provisório. Futuramente, para
					// chamar funções de GameObjects, use objectArray[i]->função() direto.

					Vec2 v = Vec2((float)mouseX, (float)mouseY);
					if(go->box.IsInside(v)) {
						Face* face = (Face*)go->GetComponent( "Face" );
						if ( nullptr != face ) {
							// Aplica dano
							face->Damage(rand() % 10 + 10);
							// Sai do loop (só queremos acertar um)
							break;
						}
					}
				}
			}
			if( event.type == SDL_KEYDOWN ) {
				// Se a tecla for ESC, setar a flag de quit
				if( event.key.keysym.sym == SDLK_ESCAPE ) {
					quitRequested = true;
				}
				// Se não, crie um objeto
				else {
					Vec2 v = Vec2(mouseX, mouseY);
					Vec2 objPos =  Vec2( 200, 0 );
					objPos = objPos.Rotate(-M_PI + M_PI*(rand() % 1001)/500.0);
					objPos = objPos.Sum(v);
					AddObject((int)objPos.x, (int)objPos.y);
				}
			}
		}
}

void State::AddObject(int mouseX, int mouseY){
	GameObject *enemy = new GameObject();
	enemy->box.x = mouseX;
	enemy->box.y = mouseY;

	Sprite *penguin = new Sprite(*enemy, "assets/img/penguinface.png");
	enemy->box.w = penguin->GetWidth();
	enemy->box.h = penguin->GetHeight();
	enemy->AddComponent(penguin);

	Sound *sound = new Sound(*enemy, "assets/audio/boom.wav");
	enemy->AddComponent(sound);

	Face *face = new Face(*enemy);
	enemy->AddComponent(face);

	objectArray.emplace_back(enemy);
}
