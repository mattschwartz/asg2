#ifndef _ROOM_H_
#define _ROOM_H_
#include <Ogre.h>
#include "Common.h"

class Ball;

class Room {
private:
	Ball *ball;
    /* Room planes, 4 walls, a floor and a ceiling with 
        normals pointing inside */
    Ogre::Plane *floor;
    Ogre::Plane *ceiling;
    Ogre::Plane *wall1;
    Ogre::Plane *wall2;
    Ogre::Plane *wall3;
    Ogre::Plane *wall4;
	struct Dimension dimensions;
	void createLights(Ogre::SceneManager &sceneMgr);
    void createMeshes(Ogre::SceneManager &sceneMgr);
	void init();

public:
	Room();
	Room(float width, float depth, float height);
	Room(struct Dimension d);
	void createScene(Ogre::SceneManager &sceneMgr);
	bool intersects(struct Position point);
	float getWidth();
	float getHeight();
	float getDepth();
	void update(const Ogre::FrameEvent &evt);
};

#endif
