#include "PaddleController.h"

PaddleController::PaddleController(Paddle* paddle, float rangeWidth, float rangeHeight, float rangeDepth):_paddle(paddle),_rangeWidth(rangeWidth),_rangeHeight(rangeHeight),_rangeDepth(rangeDepth){
  float paddleWidth = paddle->Width();
  float paddleHeight = paddle->Height();
  float paddleLength = paddle->Length();
  _minX = -rangeWidth/2 + paddleWidth/2;
  _maxX = rangeWidth/2 - paddleWidth/2;
  _minY = -rangeHeight/2 + paddleHeight/2;
  _maxY = rangeHeight/2 - paddleHeight/2;
  _minZ = -rangeDepth/2 + paddleLength/2;
  _maxZ = rangeDepth/2 - paddleLength/2;
}
void PaddleController::PositionPaddle(float percentX, float percentY, float percentZ){
  _paddle->Position(percentX*(_maxX-_minX)+_minX, percentY*(_maxY-_minY)+_minY, _maxZ-percentZ*(_maxZ-_minZ));
}
