#ifndef _ROOM_H_
#define _ROOM_H_
#include <Ogre.h>
#include <OISMouse.h>
#include <OISKeyboard.h>
#include "Common.h"
#include "KeyMap.h"

class Ball;
class Cannon;
class SoundManager;
class Paddle;
class PaddleController;

class Room {
private:
	int score;
	Cannon *cannon;
	SoundManager *soundMgr;
    Paddle *paddle;
    PaddleController *paddleController;
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
    void createMeshes();
	void init();

public:
	Room(SoundManager *soundMgr);
	Room(SoundManager *soundMgr, float width, float depth, float height);
	Room(SoundManager *soundMgr, struct Dimension d);
	void createScene(Ogre::SceneManager &sceneMgr, Ogre::Camera *camera);
	bool intersects(struct Position point);
	float getWidth();
	float getHeight();
	float getDepth();
    void restart();
	void update(const Ogre::FrameEvent &evt);
	void keyHandler(const OIS::KeyEvent &keyEvt);
    void mouseHandler(const OIS::MouseEvent &mouseEvt);
	bool paddleCollision(Ball &ball);
	void incrementScore();
	int getPlayerScore();
};

#endif
