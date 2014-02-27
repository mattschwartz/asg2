#include "SoundManager.h"


SoundManager::SoundManager() {
	BALL_HIT_SOUND = new SoundEffect("");
	BALL_FIRED_SOUND = new SoundEffect("");
	SCORE_INCREASE_SOUND = new SoundEffect("");
	soundEnabled = false;
} // constructor

void SoundManager::playSoundEffect(SoundEffect *effect) {
	if (soundEnabled) {
		effect->play();
	} // if
} // playSoundEffect

void SoundManager::toggleSound() {
	soundEnabled = !soundEnabled;
} // toggleSound
