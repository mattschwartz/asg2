noinst_HEADERS = MinimalOgre.h Paddle.h PaddleController.h Room.h

bin_PROGRAMS = assignment2
assignment2_CPPFLAGS = -I$(top_srcdir)
assignment2_SOURCES = MinimalOgre.cpp Paddle.cpp PaddleController.cpp Room.cpp
assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(SDL_CFLAGS) -std=c++0x
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(SDL_LIBS)

EXTRA_DIST = buildit makeit
AUTOMAKE_OPTIONS = foreign
