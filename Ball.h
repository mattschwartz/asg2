#ifndef _BALL_H_
#define _BALL_H_

#include <Ogre.h>
#include <sstream>
#include "Common.h"

class Room;
class SoundManager;

class Ball {
private:
	int id; // allows for many balls
	float radius;
	float speed;
	struct Position pos;
    SoundManager *soundMgr;
	Room *room;
	Ogre::Vector3 direction;
	Ogre::SceneNode *ballNode;
	void init();

public:
	Ball(int id, SoundManager *soundMgr, Room *room);
	Ball(int id, SoundManager *soundMgr, Room *room, float x, float y, float z);
	Ball(int id, SoundManager *soundMgr, Room *room, struct Position p);
	void createObject(Ogre::SceneManager &sceneMgr);
    void deleteObject(Ogre::SceneManager &sceneMgr);
	void setSpeed(float speed);
	void setDirection(float x, float y, float z);
	void setPosition(float x, float y, float z);
	struct Position getPosition();
	void move(const Ogre::FrameEvent &evt);
	void splat();
	void update(const Ogre::FrameEvent &evt);
};

#endif
