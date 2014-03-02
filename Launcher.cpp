#include <math.h>
#include "Launcher.h"

void Launcher::Launch(Ball* ball, btVector3 origin){
  btTransform t;
  t.setIdentity();
  t.setOrigin(origin);
  ball->RigidBody()->getMotionState()->setWorldTransform(t);
  ball->RigidBody()->setLinearVelocity(randomizeVelocity());
}
btVector3 Launcher::randomizeDirection(){
  btScalar phi=M_PI*2/3*(float)rand()/RAND_MAX + M_PI/6;
  btScalar theta=M_PI*2/3*(float)rand()/RAND_MAX + M_PI/6;
  return btVector3{sin(phi)*cos(theta),cos(phi),sin(phi)*sin(theta)};
}
btVector3 Launcher::randomizeVelocity(){
  return randomizeSpeed()*randomizeDirection();
}
btScalar Launcher::randomizeSpeed(){
  return (_maximumSpeed-_minimumSpeed)*(float)rand()/RAND_MAX + _minimumSpeed;
}
const btScalar Launcher::_minimumSpeed{15.0f};
const btScalar Launcher::_maximumSpeed{25.0f};
