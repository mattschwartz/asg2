#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_

#ifdef _WIN32 
	#include <SDL.h>
	#include <SDL_mixer.h>
#else
	#include "SDL/SDL.h"
	#include "SDL/SDL_mixer.h"
#endif

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
