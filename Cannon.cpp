#include <ctime>
#include <chrono>
#include "Cannon.h"
#include "Room.h"
#include "Ball.h"
#include "SoundManager.h"

Cannon::Cannon(Room *rm, SoundManager *soundMgr, Ogre::SceneManager *sceneMgr) {
	this->rm = rm;
	this->soundMgr = soundMgr;
	this->sceneMgr = sceneMgr;
	init(0, 0, 0);
} // constructor

Cannon::Cannon(Room *rm, SoundManager *soundMgr, Ogre::SceneManager *sceneMgr, float x, float y, float z) {
	this->rm = rm;
	this->soundMgr = soundMgr;
	this->sceneMgr = sceneMgr;
	init(x, y, z);
} // constructor

void Cannon::init(float x, float y, float z) {
	numBalls = 0;
	pos.x = x;
	pos.y = y;
	pos.z = z;
	// used for spewing out new balls - temporary
	last = time_now();
	rate = 3;
} // init

ull Cannon::time_now() {
	return std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
} // now

void Cannon::fire() {
	Ball *ball = new Ball(numBalls++, soundMgr, rm, pos);
	srand(time(0));
	ball->setDirection(rand() % 50, rand() % (int)rm->getHeight(), rand() % 50);
	ball->setSpeed(max(15, (rand() % 30)));
	ball->createObject(*sceneMgr);
	balls.push_back(ball);

	// Play sound effect
	soundMgr->playSoundEffect(FIRE);
} // fire

void Cannon::update(const Ogre::FrameEvent &evt) {
    int i = 0;
	now = time_now();

	if (now - last > rate * 1000) {
		fire();
		last = time_now();
	} // if

	// Go through active balls, updating their positions
	for (Ball *b : balls) {
		if (!b->update(evt)) {
            b->deleteObject(*sceneMgr);
            balls.erase(balls.begin()+i);
            i--;
        }
        i++;
	} // for
} // update

void Cannon::restart() {
    for (Ball *b : balls) {
        b->deleteObject(*sceneMgr);
    }
    balls.clear();
} // restart
