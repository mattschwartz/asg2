#include "Paddle.h"

class PaddleController{
  public:
    void PositionPaddle(float percentX, float percentY, float percentZ);
    PaddleController(Paddle* paddle, float rangeWidth, float rangeHeight, float rangeDepth);
    ~PaddleController();
  private:
    Paddle* _paddle;
    float _rangeWidth;
    float _rangeHeight;
    float _rangeDepth;
    float _minX;
    float _maxX;
    float _minY;
    float _maxY;
    float _minZ;
    float _maxZ;
};
