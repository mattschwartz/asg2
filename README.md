I added plugins.cfg and resources.cfg to .gitignore since they'll be specific to our development environments.

Various configuration items for porting to the CS machines:

configure.ac:

PKG_CHECK_MODULES(SDL, [sdl >= 1.2])
AC_SUBST(SDL_CFLAGS)
AC_SUBST(SDL_LIBS)

Makefile.am:

assignment2_CXXFLAGS = $(OGRE_CFLAGS) $(OIS_CFLAGS) $(bullet_CFLAGS) $(SDL_CFLAGS) -std=c++0x
assignment2_LDADD = $(OGRE_LIBS) $(OIS_LIBS) $(bullet_LIBS) $(SDL_LIBS)
