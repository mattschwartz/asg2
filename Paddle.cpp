#include <OgreMeshManager.h>
#include <OgrePlane.h>
#include <OgreVector3.h>
#include "Paddle.h"

using namespace Ogre;

void Paddle::Position(Real x, Real y, Real z){
  node->setPosition(x, y, z);
}

Paddle::Paddle(Ogre::SceneManager* scnMgr, float width, float height, float length):scnMgr(scnMgr),width(width),height(height),length(length){
  node = scnMgr->createSceneNode("Field");

  Ogre::SceneNode* planeNode;
  Ogre::Plane plane;
  Ogre::Entity* entity;

  plane = Ogre::Plane(Vector3(-1.0f,0.0f,0.0f),width/2);
  planeNode = node->createChildSceneNode("PaddleLeft");
  Ogre::MeshManager::getSingleton().createPlane("PaddleLeftMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,length,height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = scnMgr->createEntity("PaddleLeftMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(1.0f,0.0f,0.0f),width/2);
  planeNode = node->createChildSceneNode("PaddleRight");
  Ogre::MeshManager::getSingleton().createPlane("PaddleRightMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,length,height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = scnMgr->createEntity("PaddleRightMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);
  
  plane = Ogre::Plane(Vector3(0.0f,1.0f,0.0f),height/2);
  planeNode = node->createChildSceneNode("PaddleTop");
  Ogre::MeshManager::getSingleton().createPlane("PaddleTopMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,length,width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = scnMgr->createEntity("PaddleTopMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(0.0f,-1.0f,0.0f),height/2);
  planeNode = node->createChildSceneNode("PaddleBottom");
  Ogre::MeshManager::getSingleton().createPlane("PaddleBottomMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,length,width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = scnMgr->createEntity("PaddleBottomMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);
  
  plane = Ogre::Plane(Vector3(0.0f,0.0f,-1.0f),length/2);
  planeNode = node->createChildSceneNode("PaddleFront");
  Ogre::MeshManager::getSingleton().createPlane("PaddleFrontMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,width,height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = scnMgr->createEntity("PaddleFrontMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);
  
  plane = Ogre::Plane(Vector3(0.0f,0.0f,1.0f),length/2);
  planeNode = node->createChildSceneNode("PaddleBack");
  Ogre::MeshManager::getSingleton().createPlane("PaddleBackMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,width,height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = scnMgr->createEntity("PaddleBackMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);
}
void Paddle::addChild(Ogre::SceneNode* child){
  node->addChild(child);
}
Ogre::SceneNode* Paddle::getNode(){return node;}
float Paddle::getWidth(){return width;}
float Paddle::getHeight(){return height;}
float Paddle::getLength(){return length;}
