#include "Ball.h"
#include "Room.h"

Ball::Ball(int id, Room *room) {
	this->id = id;
	this->room = room;
} // constructor

Ball::Ball(int id, Room *room, float x, float y, float z) {
	this->id = id;
	this->room = room;
	pos.x = x;
	pos.y = y;
	pos.z = z;
} // constructor

Ball::Ball(int id, Room *room, struct Position p) {
	this->id = id;
	this->room = room;
	this->pos = p;
} // constructor

/**
 * Creates and adds a spherical (Ball) object to the
 * Scene.
 */
void Ball::createObject(Ogre::SceneManager &sceneMgr) {
	std::stringstream ballName, nodename;
	ballName << "Sphere " << id;
	nodename << "SphereNode " << id;
	radius = 1.0f;

	Ogre::Entity *ballEntity = sceneMgr.createEntity(ballName.str(), "sphere.mesh");
	ballNode = sceneMgr.getRootSceneNode()->createChildSceneNode(nodename.str());
	ballNode->setPosition(Ogre::Vector3(pos.x, pos.y, pos.z));
	ballNode->setScale(Ogre::Vector3(radius/100, radius/100, radius/100));
	ballEntity->setCastShadows(true);
	ballNode->attachObject(ballEntity);

	srand(time(NULL) + id);

	direction = Ogre::Vector3(rand() % 50, rand() % 50, rand() % 50);
	direction.normalise();
	speed = 100.0f;
} // createObject

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
} // move

/**
 * This method is invoked when the Ball has hit the wall and is
 * to explode. An animation should play in addition to some kind
 * of sound effect. If an animation is too much trouble, then at
 * least a splat texture should be displayed for a moment or two.
 */
void Ball::splat() {
} // splat
