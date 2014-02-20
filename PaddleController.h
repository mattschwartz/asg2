#include "Paddle.h"

class PaddleController{
  public:
    void PositionPaddle(float percentX, float percentY);
    PaddleController(Paddle* paddle, float rangeWidth, float rangeHeight);
    ~PaddleController();
  private:
    Paddle* _paddle;
    float _rangeWidth;
    float _rangeHeight;
    float _minX;
    float _maxX;
    float _minY;
    float _maxY;
};
