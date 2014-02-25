#ifndef _BALL_H_
#define _BALL_H_

#include <Ogre.h>
#include <sstream>
#include "Common.h"

class Room;

class Ball {
private:
	int id; // allows for many balls
	float radius;
	float speed;
	struct Position pos;
	Room *room;
	Ogre::Vector3 direction;
	Ogre::SceneNode *ballNode;

public:
	Ball(int id, Room *room);
	Ball(int id, Room *room, float x, float y, float z);
	Ball(int id, Room *room, struct Position p);
	void createObject(Ogre::SceneManager &sceneMgr);
	void setPosition(float x, float y, float z);
	struct Position getPosition();
	void fire();
	void move(const Ogre::FrameEvent &evt);
	void splat();
};

#endif
