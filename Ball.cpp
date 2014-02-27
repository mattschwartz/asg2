#include "Ball.h"
using namespace std;

Ball::Ball(Ogre::SceneNode* node):_node{node}{
  Ogre::Entity* entity = node->getCreator()->createEntity("sphere.mesh");
  node->attachObject(entity);
  float scalingFactor = _radius/entity->getMesh()->getBoundingSphereRadius();
  node->setScale(scalingFactor,scalingFactor,scalingFactor);
  _motionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(_mass,_motionState.get(),_shape.get());
  _rigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _rigidBody->setRestitution(_coefficientOfRestitution);
}

btRigidBody* Ball::RigidBody(){
  return _rigidBody.get();
}
const btScalar Ball::_radius{0.127f};
const btScalar Ball::_mass{0.623689f};
const unique_ptr<btSphereShape> Ball::_shape{new btSphereShape(Ball::_radius)};
const btScalar Ball::_coefficientOfRestitution{0.92f};
