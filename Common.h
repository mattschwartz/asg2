#ifndef _COMMON_H_
#define _COMMON_H_


struct Dimension {
	float width;
	float height;
	float depth;
};

struct Position {
	float x;
	float y;
	float z;
};

static float max(float a, float b) {
    return a > b ? a : b;
}

#endif
