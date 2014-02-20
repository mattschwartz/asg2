#include <Ogre.h>
#include <OgrePrerequisites.h>
#include <OgreSceneManager.h>

#ifndef _PADDLE_H_
#define _PADDLE_H_
class Paddle{
  protected:
    Ogre::SceneManager* scnMgr;
    Ogre::SceneNode* node;
    float width;
    float height;
    float length;
  public:
    Paddle(Ogre::SceneManager* scnMgr);
    ~Paddle();
    void addChild(Ogre::SceneNode* child);
    Ogre::SceneNode* getNode();
    float getWidth();
    float getHeight();
    float getLength();
};
#endif
