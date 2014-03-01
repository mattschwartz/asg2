#include <memory>
#include <OgrePrerequisites.h>
#include <OgreMeshManager.h>
#include <OgrePlane.h>
#include <OgreVector3.h>
#include "Court.h"
using namespace std;
using namespace Ogre;

Court::Court(Ogre::SceneNode* node):_node{node}{
  Ogre::Plane plane;
  Ogre::SceneNode* planeNode;
  Ogre::Entity* entity;

  plane = Ogre::Plane(Vector3(1.0f,0.0f,0.0f),-_width/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("LeftWallMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_depth,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("LeftWallMesh");
  entity->setMaterialName("WallColor");
  planeNode->attachObject(entity);
 
  _leftWallShape = unique_ptr<btCollisionShape>(new btStaticPlaneShape(btVector3(1,0,0),-_width/2));
  _leftWallMotionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  btRigidBody::btRigidBodyConstructionInfo rigidBodyInfo(0,_leftWallMotionState.get(),_leftWallShape.get());
  _leftWallRigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _leftWallRigidBody->setRestitution(_coefficientOfRestitution);

  plane = Ogre::Plane(Vector3(-1.0f,0.0f,0.0f),-_width/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("RightWallMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_depth,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("RightWallMesh");
  entity->setMaterialName("WallColor");
  planeNode->attachObject(entity);

  _rightWallShape = unique_ptr<btCollisionShape>(new btStaticPlaneShape(btVector3(-1,0,0),-_width/2));
  _rightWallMotionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  rigidBodyInfo=btRigidBody::btRigidBodyConstructionInfo(0,_rightWallMotionState.get(),_rightWallShape.get());
  _rightWallRigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _rightWallRigidBody->setRestitution(_coefficientOfRestitution);

  plane = Ogre::Plane(Vector3(0.0f,-1.0f,0.0f),-_height/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("CeilingMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_depth,_width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = node->getCreator()->createEntity("CeilingMesh");
  entity->setMaterialName("WallColor");
  planeNode->attachObject(entity);

  _ceilingShape = unique_ptr<btCollisionShape>(new btStaticPlaneShape(btVector3(0,-1,0),-_height/2));
  _ceilingMotionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  rigidBodyInfo=btRigidBody::btRigidBodyConstructionInfo(0,_ceilingMotionState.get(),_ceilingShape.get());
  _ceilingRigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _ceilingRigidBody->setRestitution(_coefficientOfRestitution);

  plane = Ogre::Plane(Vector3(0.0f,1.0f,0.0f),-_height/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("FloorMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_depth,_width,1,1,true,1,1,1,Vector3::UNIT_X);
  entity = node->getCreator()->createEntity("FloorMesh");
  entity->setMaterialName("WallColor");
  planeNode->attachObject(entity);

  _floorShape = unique_ptr<btCollisionShape>(new btStaticPlaneShape(btVector3(0,1,0),-_height/2));
  _floorMotionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  rigidBodyInfo=btRigidBody::btRigidBodyConstructionInfo(0,_floorMotionState.get(),_floorShape.get());
  _floorRigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _floorRigidBody->setRestitution(_coefficientOfRestitution);

  plane = Ogre::Plane(Vector3(0.0f,0.0f,1.0f),-_depth/2);
  planeNode = node->createChildSceneNode();
  Ogre::MeshManager::getSingleton().createPlane("FarWallMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,plane,_width,_height,1,1,true,1,1,1,Vector3::UNIT_Y);
  entity = node->getCreator()->createEntity("FarWallMesh");
  entity->setMaterialName("WallColor");
  planeNode->attachObject(entity);

  _farWallShape = unique_ptr<btCollisionShape>(new btStaticPlaneShape(btVector3(0,0,1),-_depth/2));
  _farWallMotionState = unique_ptr<btDefaultMotionState>(new btDefaultMotionState());
  rigidBodyInfo=btRigidBody::btRigidBodyConstructionInfo(0,_farWallMotionState.get(),_farWallShape.get());
  _farWallRigidBody = unique_ptr<btRigidBody>{new btRigidBody(rigidBodyInfo)};
  _farWallRigidBody->setRestitution(_coefficientOfRestitution);
}
btRigidBody* Court::LeftWallRigidBody(){
  return _leftWallRigidBody.get();
}
btRigidBody* Court::RightWallRigidBody(){
  return _rightWallRigidBody.get();
}
btRigidBody* Court::CeilingRigidBody(){
  return _ceilingRigidBody.get();
}
btRigidBody* Court::FloorRigidBody(){
  return _floorRigidBody.get();
}
btRigidBody* Court::FarWallRigidBody(){
  return _farWallRigidBody.get();
}
btScalar Court::Width(){
  return _width;
}
btScalar Court::Height(){
  return _height;
}
btScalar Court::Depth(){
  return _depth;
}
const btScalar Court::_width{6.096f};
const btScalar Court::_height{6.096f};
const btScalar Court::_depth{12.192f};
const btScalar Court::_coefficientOfRestitution{1.0f};
