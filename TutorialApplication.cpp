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
    soundMgr = new SoundManager();
    menuOpen = true;
    paused = false;
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
}
//-------------------------------------------------------------------------------------

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
    
    if (!menuOpen)
	    rm->update(evt);

    return true;
}


//-------------------------------------------------------------------------------------
bool TutorialApplication::keyPressed(const OIS::KeyEvent &arg)
{
    CEGUI::System &sys = CEGUI::System::getSingleton();
    sys.injectKeyDown(arg.key);
    sys.injectChar(arg.text);
    
    if (arg.key == OIS::KC_ESCAPE || arg.key == OIS::KC_Q) {
        menuOpen = true;
        paused = true;
        createMainMenu();
    }
    
    else if (arg.key == OIS::KC_M) {
        soundMgr->toggle();
    }
    
    else {
        rm->keyHandler(arg);
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
        
    if (!menuOpen) {
        rm->mouseHandler(arg);
    }
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
    CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "assignment2/Sheet");
    
    CEGUI::Window *quit = wmgr.createWindow("TaharezLook/Button", "Project2-GUI/QuitButton");
    quit->setText("Quit Game");
    quit->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    
    CEGUI::Window *fp = wmgr.createWindow("TaharezLook/Button", "assignment2/MainMenu/FreePlayButton");
    fp->setText("Free Play");
    fp->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    fp->setPosition(CEGUI::UVector2(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.5, 0)));
    
    CEGUI::Window *title = wmgr.createWindow("TaharezLook/Titlebar", "assignment2/MainMenu/Title");
    title->setText("Paddler");
    title->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    title->setPosition(CEGUI::UVector2(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.0, 0)));
    
    sheet->addChildWindow(quit);
    sheet->addChildWindow(fp);
    sheet->addChildWindow(title);
    
    if (paused) {
        CEGUI::Window *resume = wmgr.createWindow("TaharezLook/Button", "assignment2/MainMenu/ResumeButton");
        resume->setText("Resume");
        resume->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
        resume->setPosition(CEGUI::UVector2(CEGUI::UDim(0.4, 0), CEGUI::UDim(0.6, 0)));
        sheet->addChildWindow(resume);
        resume->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TutorialApplication::resumeGame, this));
    }
    
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
    soundMgr->playSoundEffect(MENU);
    CEGUI::MouseCursor::getSingleton().hide();
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    wmgr.destroyAllWindows();

    static bool first = true;
    if (!first)
        rm->restart();
    
    else {    
        Dimension roomDimensions{25, 8.5, 25};
        rm = new Room(soundMgr, roomDimensions);
        rm->createScene(*mSceneMgr);
        first = false;
    }
    
    mCamera->setPosition(0, 0, rm->getDepth() / 2 + 20);
    mCamera->lookAt(0, 0, 0);
    
    CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "Project2-GUI/FreePlay/Sheet");
    
    CEGUI::Window *score = wmgr.createWindow("TaharezLook/StaticText", "Project2-GUI/FreePlay/Score");
    int scoreNum = 0;
    std::ostringstream s;
    s << scoreNum;
    score->setText(s.str());
    score->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    score->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));
    
    sheet->addChildWindow(score);
    
    CEGUI::System::getSingleton().setGUISheet(sheet);
    
    menuOpen = false;
    paused = false;
    
    return true;
}

//---------------------------------------------------------------------------------------
bool TutorialApplication::resumeGame(const CEGUI::EventArgs &e)
{
    soundMgr->playSoundEffect(MENU);
    CEGUI::MouseCursor::getSingleton().hide();
    CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
    wmgr.destroyAllWindows();
    
    CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "Project2-GUI/FreePlay/Sheet");
    
    CEGUI::Window *score = wmgr.createWindow("TaharezLook/StaticText", "Project2-GUI/FreePlay/Score");
    int scoreNum = 0;
    std::ostringstream s;
    s << scoreNum;
    score->setText(s.str());
    score->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
    score->setPosition(CEGUI::UVector2(CEGUI::UDim(0.85, 0), CEGUI::UDim(0.0, 0)));
    
    sheet->addChildWindow(score);
    
    CEGUI::System::getSingleton().setGUISheet(sheet);
    
    menuOpen = false;
    paused = false;
    
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
