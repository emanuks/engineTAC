#include "../include/Rect.h"

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rect Rect::SumVec2(Vec2 v){
	Rect auxRect;
	auxRect.x = x + v.x;
	auxRect.y = y + v.y;
	auxRect.w = w;
	auxRect.h = h;
	return auxRect;
}

Vec2 Rect::Center(){
	Vec2 v;
	v.x = x + w/2;
	v.y = y + h/2;
	return v;
}

float Rect::CentersDist(Rect r){
	Vec2 u, v;
	u = this->Center();
	v = r.Center();
	return u.Dist(v);
}

bool Rect::IsInside(Vec2 v){
	return ((v.x >= x && v.x <= x+w) && (v.y >= y && v.y <= y+h));
}
