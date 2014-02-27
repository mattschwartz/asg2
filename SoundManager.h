#ifndef _SOUND_H_
#define _SOUND_H_

class SoundEffect;

enum Sound {HIT, FIRE, SCORE, MENU};

class SoundManager {
private:
	SoundEffect *BALL_HIT_SOUND;
	SoundEffect *BALL_FIRED_SOUND;
	SoundEffect *SCORE_INCREASE_SOUND;
	SoundEffect *MENU_SELECT_SOUND;
	bool toggleSound;

public:
	SoundManager();
	~SoundManager();
	void playSoundEffect(Sound s);
	void toggle();
};

#endif
