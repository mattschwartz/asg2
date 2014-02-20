#include "PaddleController.h"

PaddleController::PaddleController(Paddle* paddle, float rangeWidth, float rangeHeight):_paddle(paddle),_rangeWidth(rangeWidth),_rangeHeight(rangeHeight){
  float paddleWidth = paddle->getWidth();
  float paddleHeight = paddle->getHeight();
  _minX = -rangeWidth/2 + paddleWidth/2;
  _maxX = rangeWidth/2 - paddleWidth/2;
  _minY = -rangeHeight/2 + paddleHeight/2;
  _maxY = rangeHeight/2 - paddleHeight/2;
}
PaddleController::~PaddleController()=default;
void PaddleController::PositionPaddle(float percentX, float percentY){
}
