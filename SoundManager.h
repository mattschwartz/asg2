#ifndef _SOUND_H_
#define _SOUND_H_

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

class SoundEffect;

class SoundManager {
private:
	SoundEffect *BALL_HIT_SOUND;
	SoundEffect *BALL_FIRED_SOUND;
	SoundEffect *SCORE_INCREASE_SOUND;
	SoundEffect *MENU_SELECT_SOUND;
	bool toggleSound;

public:
	SoundManager();
	void playSoundEffect(SoundEffect *effect);
	void toggle();
};

#endif
