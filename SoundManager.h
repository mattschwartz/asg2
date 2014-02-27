#ifndef _SOUND_H_
#define _SOUND_H_
#include "SoundEffect.h"

class SoundManager {
private:
	bool soundEnabled;

public:
	SoundEffect *BALL_HIT_SOUND;
	SoundEffect *BALL_FIRED_SOUND;
	SoundEffect *SCORE_INCREASE_SOUND;
	
	SoundManager::SoundManager();
	void playSoundEffect(SoundEffect *effect);
	void toggleSound();
};

#endif
