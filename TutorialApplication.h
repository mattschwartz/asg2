/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include <btBulletDynamicsCommon.h>

#include "BaseApplication.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "SoundManager.h"
#include "Paddle.h"
#include "PaddleController.h"
#include "Court.h"
#include "Ball.h"
#include "Launcher.h"

class TutorialApplication:public BaseApplication{
private:
    SoundManager* soundMgr;
    bool menuOpen;
    bool paused;
    bool scoreCreated;
    CEGUI::Window *score;

public:
    bool soundOn;
    TutorialApplication(void);
    virtual ~TutorialApplication(void);
    virtual void handleStep(btDynamicsWorld*,btScalar);
protected:
    Court* court;
    Ogre::SceneNode* courtNode;
    PaddleController* paddleController;
    Ball* ball;
    Launcher* launcher;
    Ogre::SceneNode* ballNode; 
    CEGUI::OgreRenderer* mRenderer;
    int _score;

    virtual void createScene(void);
    virtual void createCamera(void);
    virtual void createViewports(void);
    virtual void createFrameListener(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);  // Ogre::FrameListener
    
    // OIS::KeyListener
    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    
    // OIS::MouseListener
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    
    void createMainMenu();
    bool quit(const CEGUI::EventArgs &e);
    bool startGame(const CEGUI::EventArgs &e);
    bool resumeGame(const CEGUI::EventArgs &e);
};

#endif // #ifndef _Project2_GUI_h_
