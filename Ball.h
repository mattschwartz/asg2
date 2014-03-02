#ifndef BALL_H
#define BALL_H
#include <memory>
#include <btBulletDynamicsCommon.h>
#include <Ogre.h>
using namespace std;

class Ball{
  public:
    Ball(Ogre::SceneNode* node);
    ~Ball();
    btRigidBody* RigidBody();
    btMotionState* MotionState();
    btScalar Radius();
  private:
    btVector3 _displacement;
    btVector3 _velocity;
    Ogre::SceneNode* _node;
    unique_ptr<btDefaultMotionState> _motionState;
    unique_ptr<btRigidBody> _rigidBody;
    unique_ptr<btSphereShape> _shape;
    static const btScalar _mass;
    static const btScalar _radius;
    static const btScalar _coefficientOfRestitution;
};
#endif
