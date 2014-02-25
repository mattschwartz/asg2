#include "SoundManager.h"
#include "SoundEffect.h"

SoundManager::SoundManager() {
	BALL_HIT_SOUND = new SoundEffect("");
	BALL_FIRED_SOUND = new SoundEffect("");
	SCORE_INCREASE_SOUND = new SoundEffect("");
} // constructor

void SoundManager::playSoundEffect(SoundEffect *effect) {
	effect->play();
} // playSoundEffect
