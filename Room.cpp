#include "Room.h"
#include "Ball.h"
#include "Cannon.h"
#include "SoundManager.h"

Room::Room(SoundManager *soundMgr) {
	this->soundMgr = soundMgr;
	dimensions.width = 15;
	dimensions.depth = 15;
	dimensions.height = 15;
	init();
} // constructor

Room::Room(SoundManager *soundMgr, float width, float depth, float height) {
	this->soundMgr = soundMgr;
	dimensions.width = width;
	dimensions.depth = depth;
	dimensions.height = height;
	init();
} // constructor

Room::Room(SoundManager *soundMgr, struct Dimension d) {
	this->soundMgr = soundMgr;
	this->dimensions = d;
	init();
} // constructor

/** 
 * Performs the tasks that all constructors have in common
 * in one, convenient function.
 */
void Room::init() {

	// Initialize planes that make up the room
	floor = new Ogre::Plane(Ogre::Vector3::UNIT_Y, 0);
	ceiling = new Ogre::Plane(-Ogre::Vector3::UNIT_Y, 0);
	wall1 = new Ogre::Plane(Ogre::Vector3::UNIT_X, 0);
	wall2 = new Ogre::Plane(-Ogre::Vector3::UNIT_X, 0);
	wall3 = new Ogre::Plane(Ogre::Vector3::UNIT_Z, 0);
	wall4 = new Ogre::Plane(-Ogre::Vector3::UNIT_Z, 0);
} // init

/**
 * Creates the scene, which is composed of 6 planes that enclose upon a
 * single point (i.e., it creates a room).
 */
void Room::createScene(Ogre::SceneManager &sceneMgr) {
	// Let there be lights
	createLights(sceneMgr);

	// manage meshes for planes
    createMeshes(sceneMgr);

	// Create plane entities
	Ogre::Entity *floorEntity = sceneMgr.createEntity("FloorEntity", "floor");
	Ogre::Entity *ceilingEntity = sceneMgr.createEntity("CeilingEntity", "ceiling");
	Ogre::Entity *wall1Entity = sceneMgr.createEntity("Wall1Entity", "wall1");
	Ogre::Entity *wall2Entity = sceneMgr.createEntity("Wall2Entity", "wall2");
	Ogre::Entity *wall3Entity = sceneMgr.createEntity("Wall3Entity", "wall3");
	Ogre::Entity *wall4Entity = sceneMgr.createEntity("Wall4Entity", "wall4");
	Ogre::SceneNode *floorNode = sceneMgr.getRootSceneNode()->createChildSceneNode("FloorNode");
	Ogre::SceneNode *ceilingNode = sceneMgr.getRootSceneNode()->createChildSceneNode("CeilingNode");
	Ogre::SceneNode *wall1Node = sceneMgr.getRootSceneNode()->createChildSceneNode("Wall1Node");
	Ogre::SceneNode *wall2Node = sceneMgr.getRootSceneNode()->createChildSceneNode("Wall2Node");
	Ogre::SceneNode *wall3Node = sceneMgr.getRootSceneNode()->createChildSceneNode("Wall3Node");
	Ogre::SceneNode *wall4Node = sceneMgr.getRootSceneNode()->createChildSceneNode("Wall4Node");

	// Meshes
	floorEntity->setMaterialName("E:/users/matt/desktop/appdirectory/media/materials/textures/dirtFloorTexture.jpeg");
	ceilingEntity->setMaterialName("Examples/Rockwall");
	wall1Entity->setMaterialName("Examples/Rockwall");
	wall2Entity->setMaterialName("Examples/Rockwall");
	wall3Entity->setMaterialName("Examples/Rockwall");
	wall4Entity->setMaterialName("Examples/Rockwall");

	// Cast no shadows
	floorEntity->setCastShadows(false);
	ceilingEntity->setCastShadows(false);
	wall1Entity->setCastShadows(false);
	wall2Entity->setCastShadows(false);
	wall3Entity->setCastShadows(false);
	wall4Entity->setCastShadows(false);
	
	floorNode->setPosition(0, -dimensions.height / 2, 0);
	ceilingNode->setPosition(0, dimensions.height / 2, 0);

	wall1Node->setPosition(-dimensions.width / 2, 0, 0);
	wall2Node->setPosition(dimensions.width / 2, 0, 0);
	wall3Node->setPosition(0, 0, -dimensions.depth / 2);
	wall4Node->setPosition(0, 0, dimensions.depth / 2);

	// Attach them to nodes
	floorNode->attachObject(floorEntity);
	ceilingNode->attachObject(ceilingEntity);
	wall1Node->attachObject(wall1Entity);
	wall2Node->attachObject(wall2Entity);
	wall3Node->attachObject(wall3Entity);
	wall4Node->attachObject(wall4Entity);
	
	cannon = new Cannon(this, soundMgr, &sceneMgr, 0, -getHeight() / 2 + 1, 0);
} // createScene

/**
 * Sets up the lights for the room.
 */
void Room::createLights(Ogre::SceneManager &sceneMgr) {
	sceneMgr.setAmbientLight(Ogre::ColourValue(251, 242, 183));
	Ogre::Light *light = sceneMgr.createLight("MainLight");
	light->setPosition(0, getHeight() / 2 - 5, 0);
	//Ogre::Light *light2 = sceneMgr.createLight("MainLight2");
	//light2->setType(Ogre::Light::LT_SPOTLIGHT);
	//light2->setPosition(Ogre::Vector3(251, 242, 183));
	//light2->setSpecularColour(1.0, 1.0, 1.0);
	sceneMgr.setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_ADDITIVE);
} // createLights

/**
 * Create the meshes for the 6 planes of the room
 */
void Room::createMeshes(Ogre::SceneManager &sceneMgr) {
	Ogre::MeshManager::getSingleton().createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *floor, dimensions.width, dimensions.depth, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Z);
	Ogre::MeshManager::getSingleton().createPlane("ceiling", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *ceiling, dimensions.width, dimensions.depth, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Z);
    
	Ogre::MeshManager::getSingleton().createPlane("wall1", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *wall1, dimensions.height, dimensions.depth, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Z);
	Ogre::MeshManager::getSingleton().createPlane("wall2", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *wall2, dimensions.height, dimensions.depth, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Z);
	Ogre::MeshManager::getSingleton().createPlane("wall3", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *wall3, dimensions.width, dimensions.height, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Y);
	Ogre::MeshManager::getSingleton().createPlane("wall4", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *wall4, dimensions.width, dimensions.height, 20, 20, true, 1, 50, 50, Ogre::Vector3::UNIT_Y);
} // createMeshes

float Room::getWidth() {
	return dimensions.width;
} // getWidth

float Room::getHeight() {
	return dimensions.height;
} // getHeight

float Room::getDepth() {
	return dimensions.depth;
} // getDepth

/**
 * This function is invoked whenever the game needs to update all
 * of its objects.
 */
void Room::update(const Ogre::FrameEvent &evt) {
	cannon->update(evt);
} // update

void Room::input(KeyCode keyPressed) {
	// Check if input was directed at paddle and if it was
	// pass the keyPressed object down to it
	// paddle.input(keyPressed);
	// otherwise, ignore the input
} // input
