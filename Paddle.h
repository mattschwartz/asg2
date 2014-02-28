#ifndef _PADDLE_H_
#define _PADDLE_H_
#include <Ogre.h>
#include <OgrePrerequisites.h>
#include <OgreMatrix3.h>
#include <OgreSceneManager.h>

#include "Common.h"

class Paddle {
protected:
    struct Position pos;
    Ogre::SceneManager* scnMgr;
    Ogre::SceneNode* node;
    float width;
    float height;
    float length;
public:
    Paddle(Ogre::SceneManager* scnMgr, float width, float height, float length);
    ~Paddle();
    void addChild(Ogre::SceneNode* child);
    Ogre::SceneNode* getNode();
    float getWidth();
    float getHeight();
    float getLength();
    struct Position getPosition();
    void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
    
};

#endif
