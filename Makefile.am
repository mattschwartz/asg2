noinst_HEADERS = BaseApplication.h TutorialApplication.h Paddle.h PaddleController.h Room.h Cannon.h Ball.h SoundManager.h SoundEffect.h

bin_PROGRAMS = assignment2
assignment2_CPPFLAGS = -I$(top_srcdir)
assignment2_SOURCES = BaseApplication.cpp TutorialApplication.cpp Paddle.cpp PaddleController.cpp Room.cpp Cannon.cpp Ball.cpp SoundManager.cpp SoundEffect.cpp
assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(SDL_CFLAGS) $(CEGUI_CFLAGS) $(CEGUI_OGRE_CFLAGS) -std=c++0x -lSDL -lSDL_mixer
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(SDL_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS)

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
