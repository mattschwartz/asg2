#ifndef COURT_H
#define COURT_H

#include <memory>
#include <btBulletDynamicsCommon.h>
#include <Ogre.h>
using namespace std;

class Court{
  public:
    Court(Ogre::SceneNode* node);
    ~Court();
    btScalar Width();
    btScalar Height();
    btScalar Depth();
    btRigidBody* LeftWallRigidBody();
    btRigidBody* RightWallRigidBody();
    btRigidBody* CeilingRigidBody();
    btRigidBody* FloorRigidBody();
    btRigidBody* FarWallRigidBody();
  private:
    Ogre::SceneNode* _node;
    static const btScalar _width;
    static const btScalar _height;
    static const btScalar _depth;
    static const btScalar _coefficientOfRestitution;
    unique_ptr<btCollisionShape> _leftWallShape;
    unique_ptr<btDefaultMotionState> _leftWallMotionState;
    unique_ptr<btRigidBody> _leftWallRigidBody;
    unique_ptr<btCollisionShape> _rightWallShape;
    unique_ptr<btDefaultMotionState> _rightWallMotionState;
    unique_ptr<btRigidBody> _rightWallRigidBody;
    unique_ptr<btCollisionShape> _ceilingShape;
    unique_ptr<btDefaultMotionState> _ceilingMotionState;
    unique_ptr<btRigidBody> _ceilingRigidBody;
    unique_ptr<btCollisionShape> _floorShape;
    unique_ptr<btDefaultMotionState> _floorMotionState;
    unique_ptr<btRigidBody> _floorRigidBody;
    unique_ptr<btCollisionShape> _farWallShape;
    unique_ptr<btDefaultMotionState> _farWallMotionState;
    unique_ptr<btRigidBody> _farWallRigidBody;
};

#endif
