#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <btBulletDynamicsCommon.h>
#include "Ball.h"
class Launcher{
  public:
    void Launch(Ball* ball, btVector3 origin);
  private:
    btVector3 _position;
    btVector3 randomizeDirection();
    btScalar randomizeSpeed();
    btVector3 randomizeVelocity();
  protected:
    static const btScalar _minimumSpeed;
    static const btScalar _maximumSpeed;
};
#endif
