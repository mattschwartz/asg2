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

#include "BaseApplication.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "Paddle.h"
#include "PaddleController.h"
#include "Room.h"
#include "SoundManager.h"

class TutorialApplication:public BaseApplication{
private:
    bool soundToggle;

public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

protected:
    PaddleController* paddleController;
    CEGUI::OgreRenderer* mRenderer;

    virtual void createScene(void);
    //virtual void createCamera(void);
    //virtual void createViewports(void);
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
};

#endif // #ifndef _Project2_GUI_h_
