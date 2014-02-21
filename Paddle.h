#include <Ogre.h>
#include <OgrePrerequisites.h>
#include <OgreMatrix3.h>
#include <OgreSceneManager.h>
#ifndef _PADDLE_H_
#define _PADDLE_H_
using namespace Ogre;
class Paddle{
  protected:
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
    void Position(Real x, Real y, Real z);
};
#endif
