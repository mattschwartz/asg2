#ifndef _SOUND_H_
#define _SOUND_H_

class SoundEffect;

class SoundManager {
private:
	static SoundEffect *BALL_HIT_SOUND;
	static SoundEffect *BALL_FIRED_SOUND;
	static SoundEffect *SCORE_INCREASE_SOUND;

public:
	SoundManager();
	void playSoundEffect(SoundEffect *effect);

};

#endif
