#include "../include/Vec2.h"
#include <cmath>

Vec2::Vec2(float x, float y){
	this->x = x;
	this->y = y;
}

Vec2 Vec2::Sum(Vec2 v){
	Vec2 w;
	w.x = x + v.x;
	w.y = y + v.y;
	return w;
}

Vec2 Vec2::Sub(Vec2 v){
	Vec2 w;
	w.x = x - v.x;
	w.y = y - v.y;
	return w;
}

Vec2 Vec2::Mult(float e){
	Vec2 w;
	w.x = e*x;
	w.y = e*y;
	return w;
}

float Vec2::Module(){
	float module;
	module = sqrt(pow(x,2) + pow(y,2));
	return module;
}

Vec2 Vec2::Norm(){
	Vec2 w;
	w.x = x/Module();
	w.y = y/Module();
	return w;
}

float Vec2::Dist(Vec2 v){
	Vec2 w;
	w = this->Sub(v);
	return w.Module();
}

Vec2 Vec2::Rotate(float angle){
	Vec2 w;
	w.x = x*cos(angle) - y*sin(angle);
	w.y = y*cos(angle) + x*sin(angle);
	return w;
}
