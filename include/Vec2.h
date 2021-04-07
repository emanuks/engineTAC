#ifndef _VEC2_H_
#define _VEC2_H_

class Vec2 {
public:
	float x;
	float y;
	Vec2(float x = 0, float y = 0);
	Vec2 Sum(Vec2 v);
	Vec2 Sub(Vec2 v);
	Vec2 Mult(float e);
	float Module();
	Vec2 Norm();
	float Dist(Vec2 v);
	Vec2 Rotate(float angle);
};

#endif
