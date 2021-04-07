#ifndef _RECT_H_
#define _RECT_H_

#include "Vec2.h"

class Rect{
public:
	float x;
	float y;
	float w;
	float h;
	Rect(float x = 0, float y = 0, float w = 0, float h = 0);
	Rect SumVec2(Vec2 v);
	Vec2 Center();
	float CentersDist(Rect r);
	bool IsInside(Vec2 v);
};

#endif
