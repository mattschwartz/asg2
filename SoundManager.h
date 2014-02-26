#ifndef _SOUND_H_
#define _SOUND_H_

class SoundEffect;

class SoundManager {
private:
	SoundEffect *BALL_HIT_SOUND;
	SoundEffect *BALL_FIRED_SOUND;
	SoundEffect *SCORE_INCREASE_SOUND;

public:
	SoundManager();
	void playSoundEffect(SoundEffect *effect);

};

#endif
