#include "Ball.h"

Ball::Ball() {
} // constructor

/**
 * Returns the current position of the Ball object
 */
struct Position Ball::getPosition() {
	return pos;
} // getPosition

/**
 * This method is invoked when the 'cannon' or some such
 * object 'fires' the Ball (when the Ball is initially 
 * shown within the game world.
  */
void Ball::fire() {
} // fire

/**
 * This method is invoked while the Ball is actually moving
 * within the game world and must have its position updated
 * constantly.
 */
void Ball::move() {
} // move

/**
 * This method is invoked when the Ball has hit the wall and is
 * to explode. An animation should play in addition to some kind
 * of sound effect. If an animation is too much trouble, then at
 * least a splat texture should be displayed for a moment or two.
 */
void Ball::splat() {
} // splat
