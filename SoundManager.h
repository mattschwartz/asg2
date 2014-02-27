#ifndef _SOUND_H_
#define _SOUND_H_

class SoundEffect;

enum Sound {HIT, FIRE, SCORE, MENU};

class SoundManager {
private:
	bool toggleSound;

public:
	SoundEffect *BALL_HIT_SOUND;
	SoundEffect *BALL_FIRED_SOUND;
	SoundEffect *SCORE_INCREASE_SOUND;
	SoundEffect *MENU_SELECT_SOUND;
	SoundManager();
	~SoundManager();
<<<<<<< HEAD
	void playSoundEffect(SoundEffect *effect);
=======
	void playSoundEffect(Sound s);
>>>>>>> 9ef05bc017e6aa330e4a58b28c72fd6aaabfc9d5
	void toggle();
};

#endif
