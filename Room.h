#ifndef _ROOM_H_
#define _ROOM_H_
#include <Ogre.h>

struct Dimension {
	int width;
	int height;
	int depth;
};

class Room {
private:
	struct Dimension dimensions;

public:
	Room();
	Room(int width, int height, int depth);
	Room(struct Dimension d);
	void createScene(Ogre::SceneManager &sceneMgr);
	int getWidth();
	int getHeight();
	int getDepth();
};

#endif
