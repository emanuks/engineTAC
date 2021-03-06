#ifndef _FACE_H_
#define _FACE_H_

#include <string>
#include "GameObject.h"

using namespace std;

class Face : public Component{
public:
	Face(GameObject& associated);
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(string type);
private:
	int hitpoints;
};

#endif
