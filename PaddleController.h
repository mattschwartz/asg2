#include "Paddle.h"

class PaddleController{
  private:
    Paddle* _paddle;
	Ogre::Camera *camera;
    float _rangeWidth;
    float _rangeHeight;
    float _rangeDepth;
    float _minX;
    float _maxX;
    float _minY;
    float _maxY;
    float _minZ;
    float _maxZ;
  public:
    void PositionPaddle(float percentX, float percentY, float percentZ);
    PaddleController(Paddle* paddle, Ogre::Camera *camera, float rangeWidth, float rangeHeight, float rangeDepth);
    ~PaddleController();
};
