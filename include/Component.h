#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>

using namespace std;

class GameObject;

class Component{
public:
	Component(GameObject& associated);
	virtual ~Component();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual bool Is(string type) = 0;
protected:
	GameObject& associated;
};

#endif
