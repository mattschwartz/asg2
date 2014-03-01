#ifndef PADDLE_H
#define PADDLE_H

#include <memory>
#include <btBulletDynamicsCommon.h>
#include <Ogre.h>
#include <OgrePrerequisites.h>
#include <OgreMatrix3.h>
#include <OgreSceneManager.h>

using namespace std;
using namespace Ogre;

class Paddle{
  public:
    Paddle(Ogre::SceneNode* node, float width, float height, float length);
    ~Paddle();
    float Width();
    float Height();
    float Length();
    void Position(Real x, Real y, Real z);
    btRigidBody* RigidBody();
    btMotionState* MotionState();
  private:
    Ogre::SceneNode* _node;
    btScalar _width;
    btScalar _height;
    btScalar _length;
    static const btScalar _coefficientOfRestitution;
    unique_ptr<btCollisionShape> _shape;
    unique_ptr<btDefaultMotionState> _motionState;
    unique_ptr<btRigidBody> _rigidBody;
};
#endif
