#include <ctime>
#include <chrono>
#include "Cannon.h"
#include "Room.h"
#include "Ball.h"

Cannon::Cannon(Room *rm, Ogre::SceneManager *sceneMgr) {
	this->rm = rm;
	this->sceneMgr = sceneMgr;
	init(0, 0, 0);
} // constructor

Cannon::Cannon(Room *rm, Ogre::SceneManager *sceneMgr, float x, float y, float z) {
	this->rm = rm;
	this->sceneMgr = sceneMgr;
	init(x, y, z);
} // constructor

void Cannon::init(float x, float y, float z) {
	numBalls = 0;
	pos.x = x;
	pos.y = y;
	pos.z = z;
	fire();
	// used for spewing out new balls - temporary
	last = time_now();
	rate = 3;
} // init

ull Cannon::time_now() {
	return std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
} // now

void Cannon::fire() {
	Ball *ball = new Ball(numBalls++, rm, pos);
	srand(time(0));
	ball->setDirection(rand() % 50, rand() % 50, rand() % 50);
	ball->setSpeed((rand() % 100) / 10.0);
	ball->createObject(*sceneMgr);
	balls.push_back(ball);
} // fire

void Cannon::update(const Ogre::FrameEvent &evt) {
	now = time_now();

	if (now - last > rate * 1000) {
		fire();
		last = time_now();
	} // if

	// Go through active balls, updating their positions
	for (Ball *b : balls) {
		b->update(evt);
	} // for
} // updage
