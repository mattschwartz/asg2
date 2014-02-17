#include <Ogre.h>
#include <OgrePrerequisites.h>
#include <OgreSceneManager.h>

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
