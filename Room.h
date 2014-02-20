#ifndef _ROOM_H_
#define _ROOM_H_
#include <Ogre.h>

struct Dimension {
	float width;
	float height;
	float depth;
};

class Room {
private:
	struct Dimension dimensions;

public:
	Room();
	Room(float width, float height, float depth);
	Room(struct Dimension d);
	void createScene(Ogre::SceneManager &sceneMgr);
	float getWidth();
	float getHeight();
        float getDepth();
};

#endif
