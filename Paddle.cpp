#include <OgreMeshManager.h>
#include <OgrePlane.h>
#include <OgreVector3.h>
#include "Paddle.h"

using namespace Ogre;

void Paddle::Position(Real x, Real y, Real z){
  _node->setPosition(x, y, z);
  btVector3 p{x,y,z};
  btTransform t;
  t.setIdentity();
  t.setOrigin(p);
  _rigidBody->getMotionState()->setWorldTransform(t);
}

Paddle::Paddle(Ogre::SceneNode* node, float width, float height, float length):_node(node),_width(width),_height(height),_length(length){
  Ogre::Plane plane;
  Ogre::SceneNode* planeNode;
  Ogre::Entity* entity;

  plane = Ogre::Plane(Vector3(-1.0f,0.0f,0.0f),_width/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("LeftPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_length,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("LeftPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(1.0f,0.0f,0.0f),_width/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("RightPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_length,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("RightPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(0.0f,1.0f,0.0f),_height/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("TopPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_length,_width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = node->getCreator()->createEntity("TopPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(0.0f,-1.0f,0.0f),_height/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("BottomPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_length,_width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = node->getCreator()->createEntity("BottomPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(0.0f,0.0f,-1.0f),_length/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("FrontPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_width,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("FrontPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  plane = Ogre::Plane(Vector3(0.0f,0.0f,1.0f),_length/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("BackPaddleMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_width,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("BackPaddleMesh");
  entity->setMaterialName("PaddleColor");
  planeNode->attachObject(entity);

  _shape = unique_ptr<btCollisionShape>(new btBoxShape(btVector3{_width/2,_height/2,_length/2}));
  _motionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(0,_motionState.get(),_shape.get());
  _rigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _rigidBody->setRestitution(_coefficientOfRestitution);
  _rigidBody->setUserPointer(this);
  _rigidBody->setCollisionFlags(_rigidBody->getCollisionFlags()|btCollisionObject::CF_KINEMATIC_OBJECT);
  _rigidBody->setActivationState(DISABLE_DEACTIVATION);
}
btRigidBody* Paddle::RigidBody(){
  return _rigidBody.get();
}
btMotionState* Paddle::MotionState(){
  return _motionState.get();
};
float Paddle::Width(){return _width;}
float Paddle::Height(){return _height;}
float Paddle::Length(){return _length;}
const btScalar Paddle::_coefficientOfRestitution{1.0f};
