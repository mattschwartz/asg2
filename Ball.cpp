#include "Ball.h"
#include "Room.h"

Ball::Ball(int id, Room *room) {
	this->id = id;
	this->room = room;
	init();
} // constructor

Ball::Ball(int id, Room *room, float x, float y, float z) {
	this->id = id;
	this->room = room;
	pos.x = x;
	pos.y = y;
	pos.z = z;
	init();
} // constructor

Ball::Ball(int id, Room *room, struct Position p) {
	this->id = id;
	this->room = room;
	this->pos = p;
	init();
} // constructor

void Ball::init() {
	radius = 1.0f;
	// points in the center of the room... well close
	direction = Ogre::Vector3(0.1, 0.1, 0.1);
	direction.normalise();
	speed = 6;
} // init

/**
 * Creates and adds a spherical (Ball) object to the
 * Scene.
 */
void Ball::createObject(Ogre::SceneManager &sceneMgr) {
	std::stringstream ballName, nodename;
	ballName << "Sphere " << id;
	nodename << "SphereNode " << id;

	Ogre::Entity *ballEntity = sceneMgr.createEntity(ballName.str(), "sphere.mesh");
	ballNode = sceneMgr.getRootSceneNode()->createChildSceneNode(nodename.str());
	ballNode->setPosition(Ogre::Vector3(pos.x, pos.y, pos.z));
	ballNode->setScale(Ogre::Vector3(radius/100, radius/100, radius/100));
	ballEntity->setCastShadows(true);
	ballNode->attachObject(ballEntity);
} // createObject

void Ball::setSpeed(float speed) {
	this->speed = speed;
} // setSpeed

void Ball::setDirection(float x, float y, float z) {
	direction = Ogre::Vector3(x, y, z);
	direction.normalise();
} // setDirection

/**
 * Sets the current position of the Ball to the supplied
 * coordinates.
 */
void Ball::setPosition(float x, float y, float z) {
	pos.x = x;
	pos.y = y;
	pos.z = z;
} // setPosition

/**
 * Returns the current position of the Ball object
 */
struct Position Ball::getPosition() {
	return pos;
} // getPosition

/**
 * This method is invoked while the Ball is actually moving
 * within the game world and must have its position updated
 * constantly.
 */
void Ball::move(const Ogre::FrameEvent &evt) {
	if (pos.y < -room->getHeight()/2.0f + radius && direction.y < 0.0f) 
		direction.y = -direction.y;
	if (pos.y > room->getHeight()/2.0f - radius && direction.y > 0.0f) 
		direction.y = -direction.y;
	if (pos.z < -room->getDepth()/2.0f + radius && direction.z < 0.0f) 
		direction.z = -direction.z;
	if (pos.z > room->getDepth()/2.0f - radius && direction.z > 0.0f) 
		direction.z = -direction.z;
	if (pos.x < -room->getWidth()/2.0f + radius && direction.x < 0.0f) 
		direction.x = -direction.x;
	if (pos.x > room->getWidth()/2.0f - radius && direction.x > 0.0f) 
		direction.x = -direction.x;
	ballNode->translate(speed * evt.timeSinceLastFrame * direction);
	pos.x = ballNode->getPosition().x;
	pos.y = ballNode->getPosition().y;
	pos.z = ballNode->getPosition().z;
} // move

/**
 * This method is invoked when the Ball has hit the wall and is
 * to explode. An animation should play in addition to some kind
 * of sound effect. If an animation is too much trouble, then at
 * least a splat texture should be displayed for a moment or two.
 */
void Ball::splat() {
} // splat


/**
 * This function is invoked whenever the game must update its
 * components.  This particular level of update() is called from
 * its parent node, the Cannon.
 */
void Ball::update(const Ogre::FrameEvent &evt) {
	move(evt);
	// did the ball hit a target? then, 
	// splat();
} // update
