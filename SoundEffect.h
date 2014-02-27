#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_
#include <Ogre.h>

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

class SoundEffect {
private:
    Mix_Chunk *sound;
public:
	SoundEffect(const char* filePath);
	~SoundEffect();
	void play();
	void freeSound();
};

#endif
