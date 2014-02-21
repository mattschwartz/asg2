#include "Room.h"

Room::Room() {
	initPlanes();
}

Room::Room(float width, float depth, float height) {
	initPlanes();
	dimensions.width = width;
	dimensions.depth = depth;
	dimensions.height = height;
}

Room::Room(struct Dimension d) {
	initPlanes();
	this->dimensions = d;
}

void Room::initPlanes() {
	floor = new Ogre::Plane(Ogre::Vector3::UNIT_Y, 0);
	ceiling = new Ogre::Plane(-Ogre::Vector3::UNIT_Y, 0);
	wall1 = new Ogre::Plane(Ogre::Vector3::UNIT_X, 0);
	wall2 = new Ogre::Plane(-Ogre::Vector3::UNIT_X, 0);
	wall3 = new Ogre::Plane(Ogre::Vector3::UNIT_Z, 0);
	wall4 = new Ogre::Plane(-Ogre::Vector3::UNIT_Z, 0);
}

void Room::createScene(Ogre::SceneManager &sceneMgr) {
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
	floorEntity->setMaterialName("Examples/Rockwall");
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
} // createScene

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
}

float Room::getHeight() {
	return dimensions.height;
}

float Room::getDepth() {
	return dimensions.depth;
}
