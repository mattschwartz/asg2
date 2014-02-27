/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID)
{
    switch (buttonID)
    {
        case OIS::MB_Left:
            return CEGUI::LeftButton;
        
        case OIS::MB_Right:
            return CEGUI::RightButton;
            
        case OIS::MB_Middle:
            return CEGUI::MiddleButton;
            
        default:
            return CEGUI::LeftButton;
    }
}

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void){
    sm = new SoundManager();
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void){
}

//-------------------------------------------------------------------------------------
/*void Project2-GUI::createCamera(void)
{
    // create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");
    
    // set its position, direction
    mCamera->setPosition(Ogre::Vector3(0.0f,0.0f,-100.0f));
    mCamera->lookAt(Ogre::Vector3(0,0,0));
    
    // set the near clip distance
    mCamera->setNearClipDistance(5);
    
    // create a default camera controller
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

//-------------------------------------------------------------------------------------
void Project2-GUI::createViewports(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
    
    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}*/

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    
    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    
    CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
    CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
    CEGUI::MouseCursor::getSingleton().setPosition(CEGUI::Point(0,0));
    
    createMainMenu();

    Dimension roomDimensions{50.0f, 50.0f, 50.0f};
    rm = new Room(sm, roomDimensions);
    rm->createScene(*mSceneMgr);
    mCamera->setPosition(rm->getWidth() + 15, rm->getHeight() + 15, rm->getDepth() + 15);
    mCamera->lookAt(0, 0, 0);
    Paddle* paddle = new Paddle(mSceneMgr, 6.0f, 3.0f, 1.0f);
    mSceneMgr->getRootSceneNode()->addChild(paddle->getNode());
    paddleController = new PaddleController(paddle, roomDimensions.width, roomDimensions.height, roomDimensions.depth);
    paddleController->PositionPaddle(0.5f,0.5f,0.0f);
}
//-------------------------------------------------------------------------------------
void TutorialApplication::updateScene(const Ogre::FrameEvent &evt) {
	rm->update(evt);
} // updateScene

//-------------------------------------------------------------------------------------
void TutorialApplication::createFrameListener(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    mInputManager = OIS::InputManager::createInputSystem( pl );

    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);

    //Set initial mouse clipping size
    windowResized(mWindow);

    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

    mRoot->addFrameListener(this);
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& evt) 
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    //Need to inject timestamps to CEGUI System.
    CEGUI::System::getSingleton().injectTimePulse(evt.timeSinceLastFrame);

    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::keyPressed(const OIS::KeyEvent &arg)
{
    CEGUI::System &sys = CEGUI::System::getSingleton();
    sys.injectKeyDown(arg.key);
    sys.injectChar(arg.text);
    
    if (arg.key == OIS::KC_ESCAPE || arg.key == OIS::KC_Q) {
        createMainMenu();
    }
    
    else if (arg.key == OIS::KC_M) {
        sm->toggle();
    }
    
    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::keyReleased(const OIS::KeyEvent &arg)
{
    CEGUI::System::getSingleton().injectKeyUp(arg.key);
    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::mouseMoved(const OIS::MouseEvent &arg)
{
    CEGUI::System &sys = CEGUI::System::getSingleton();
    sys.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
    // Scroll wheel.
    if (arg.state.Z.rel)
        sys.injectMouseWheelChange(arg.state.Z.rel / 120.0f);
        
    float xPercent = 1.0f-((float)(arg.state.width-arg.state.X.abs))/((float)arg.state.width);
    float yPercent = ((float)(arg.state.height-arg.state.Y.abs))/((float)arg.state.height);
    paddleController->PositionPaddle(xPercent,yPercent,0.0f);
    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    CEGUI::System::getSingleton().injectMouseButtonDown(convertButton(id));
    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    CEGUI::System::getSingleton().injectMouseButtonUp(convertButton(id));
    return true;
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createMainMenu(void)
{
    CEGUI::MouseCursor::getSingleton().show();
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    wmgr.destroyAllWindows();
    CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "Project2-GUI/Sheet");
    
    CEGUI::Window *quit = wmgr.createWindow("TaharezLook/Button", "Project2-GUI/QuitButton");
    quit->setText("Quit Game");
    quit->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    
    CEGUI::Window *fp = wmgr.createWindow("TaharezLook/Button", "Project2-GUI/MainMenu/FreePlayButton");
    fp->setText("Free Play");
    fp->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    fp->setPosition(CEGUI::UVector2(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.5, 0)));
    
    sheet->addChildWindow(quit);
    sheet->addChildWindow(fp);
    CEGUI::System::getSingleton().setGUISheet(sheet);
    
    quit->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TutorialApplication::quit, this));
    fp->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TutorialApplication::startGame, this));
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::quit(const CEGUI::EventArgs &e)
{
    mShutDown = true;
    return true;
}

//-------------------------------------------------------------------------------------
bool TutorialApplication::startGame(const CEGUI::EventArgs &e)
{
        
    CEGUI::MouseCursor::getSingleton().hide();
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    wmgr.destroyAllWindows();
    
    CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "Project2-GUI/FreePlay/Sheet");
    
    CEGUI::Window *score = wmgr.createWindow("TaharezLook/Button", "Project2-GUI/FreePlay/Score");
    int scoreNum = 0;
    std::ostringstream s;
    s << scoreNum;
    score->setText(s.str());
    score->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    score->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));
    
    sheet->addChildWindow(score);
    
    CEGUI::System::getSingleton().setGUISheet(sheet);
    
    return true;
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
