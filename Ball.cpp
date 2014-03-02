#include "Ball.h"
using namespace std;

Ball::Ball(Ogre::SceneNode* node):_node{node}{
  Ogre::Entity* entity = node->getCreator()->createEntity("sphere.mesh");
  entity->setMaterialName("BallColor");
  node->attachObject(entity);
  float scalingFactor = _radius/entity->getMesh()->getBoundingSphereRadius();
  node->setScale(scalingFactor,scalingFactor,scalingFactor);
  _shape = unique_ptr<btSphereShape>(new btSphereShape(_radius));
  _motionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(_mass,_motionState.get(),_shape.get());
  _rigidBody = unique_ptr<btRigidBody>(new btRigidBody(rigidBodyInfo));
  _rigidBody->setRestitution(_coefficientOfRestitution);
  _rigidBody->setUserPointer(this);
  _rigidBody->setLinearVelocity(btVector3{0,0,-10});
}

btScalar Ball::Radius(){
  return _radius;
}
btRigidBody* Ball::RigidBody(){
  return _rigidBody.get();
}
btMotionState* Ball::MotionState(){
  return _motionState.get();
};

const btScalar Ball::_radius{0.127f};
const btScalar Ball::_mass{0.623689f};
const btScalar Ball::_coefficientOfRestitution{0.92f};
