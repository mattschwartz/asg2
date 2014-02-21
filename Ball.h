#ifndef _BALL_H_
#define _BALL_H_

#include "Common.h"

class Ball {
private:
	float radius;
	struct Position pos;

public:
	Ball();
	struct Position getPosition();
	void fire();
	void move();
	void splat();
};

#endif
