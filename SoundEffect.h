#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_
#include <Ogre.h>

class SoundEffect {
private:
public:
	SoundEffect(char *filePath);
	void play();
};

#endif