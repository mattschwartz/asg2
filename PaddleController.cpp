#include "PaddleController.h"

PaddleController::PaddleController(Paddle* paddle, Ogre::Camera *camera, float rangeWidth, float rangeHeight, float rangeDepth):_paddle(paddle),_rangeWidth(rangeWidth),_rangeHeight(rangeHeight),_rangeDepth(rangeDepth){
	this->camera = camera;
  float paddleWidth = paddle->getWidth();
  float paddleHeight = paddle->getHeight();
  float paddleLength = paddle->getLength();
  _minX = -rangeWidth/2 + paddleWidth/2;
  _maxX = rangeWidth/2 - paddleWidth/2;
  _minY = -rangeHeight/2 + paddleHeight/2;
  _maxY = rangeHeight/2 - paddleHeight/2;
  _minZ = -rangeDepth/2 + paddleLength/2;
  _maxZ = rangeDepth/2 - paddleLength/2;
}
void PaddleController::PositionPaddle(float percentX, float percentY, float percentZ){
  _paddle->Position(percentX*(_maxX-_minX)+_minX, percentY*(_maxY-_minY)+_minY, _maxZ-percentZ*(_maxZ-_minZ));
  // Move the camera in some way
  camera->setPosition(percentX*(_maxX-_minX)+_minX, percentY*(_maxY-_minY)+_minY, _maxZ-percentZ*(_maxZ-_minZ));
  camera->lookAt(0, 0, 0);
}
