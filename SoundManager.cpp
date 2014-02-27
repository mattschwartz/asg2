#include "SoundManager.h"
#include "SoundEffect.h"

SoundManager::SoundManager() {
	BALL_HIT_SOUND = new SoundEffect("./media/sounds/ballHit.wav");
	BALL_FIRED_SOUND = new SoundEffect("./media/sounds/launch.wav");
	SCORE_INCREASE_SOUND = new SoundEffect("./media/sounds/scoreChime.wav");
	MENU_SELECT_SOUND = new SoundEffect("./media/sounds/menuSelect.wav");
	toggleSound = true;
} // constructor

SoundManager::~SoundManager() {
    BALL_HIT_SOUND->free();
    BALL_FIRED_SOUND->free();
    SCORE_INCREASE_SOUND->free();
    MENU_SELECT_SOUND->free();
    Mix_CloseAudio();
    SDL_Quit();
} // destructor

void SoundManager::playSoundEffect(SoundEffect *effect) {
	if (toggleSound) {
	    effect->play();
	} // if
} // playSoundEffect

void SoundManager::toggle() {
    toggleSound = !toggleSound;
} // toggle
