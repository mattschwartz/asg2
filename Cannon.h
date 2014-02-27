#ifndef _CANNON_H_
#define _CANNON_H_
#include <Ogre.h>
#include <vector>
#include "Common.h"

#define ull unsigned long long

// Forward declarations
class Room;
class Ball;
class SoundManager;

class Cannon {
private:
	int numBalls;
	struct Position pos;
	Room *rm;
	SoundManager *soundMgr;
	Ogre::SceneManager *sceneMgr;
	std::vector<Ball *> balls;
	void init(float x, float y, float z);

	// used for spewing out new balls - temporary
	ull time_now();
	ull last;
	ull now;
	int rate; // in seconds

public:
	Cannon(Room *rm, SoundManager *soundMgr, Ogre::SceneManager *sceneMgr);
	Cannon(Room *rm, SoundManager *soundMgr, Ogre::SceneManager *sceneMgr, float x, float y, float z);
	void fire();
	void update(const Ogre::FrameEvent &evt);
};

#endif
