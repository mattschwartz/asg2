#include "SoundManager.h"
#include "SoundEffect.h"

SoundManager::SoundManager() {
    if (SDL_Init(SDL_INIT_AUDIO) == -1)
        mShutDown = true;
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
        mShutDown = true;
        
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
}

void SoundManager::playSoundEffect(SoundEffect *effect) {
	if (toggleSound)
	    effect->play();
} // playSoundEffect

void SoundManager::toggle() {
    toggleSound = !toggleSound;
} // toggle
