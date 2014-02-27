#include "SoundManager.h"
#include "SoundEffect.h"

SoundManager::SoundManager() {
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Volume(-1, MIX_MAX_VOLUME);
        
	BALL_HIT_SOUND = new SoundEffect("./media/sounds/ballHit.wav");
	BALL_FIRED_SOUND = new SoundEffect("./media/sounds/launch.wav");
	SCORE_INCREASE_SOUND = new SoundEffect("./media/sounds/scoreChime.wav");
	MENU_SELECT_SOUND = new SoundEffect("./media/sounds/menuSelect.wav");
	toggleSound = true;
} // constructor

SoundManager::~SoundManager() {
    BALL_HIT_SOUND->freeSound();
    BALL_FIRED_SOUND->freeSound();
    SCORE_INCREASE_SOUND->freeSound();
    MENU_SELECT_SOUND->freeSound();
    Mix_CloseAudio();
    SDL_Quit();
} // destructor

void SoundManager::playSoundEffect(Sound s) {
	if (toggleSound) {
	    if (s == HIT)
	        BALL_HIT_SOUND->play();
	    else if (s == FIRE)
	        BALL_FIRED_SOUND->play();
        else if (s == SCORE)
	        SCORE_INCREASE_SOUND->play();
        else if (s == MENU)
	        MENU_SELECT_SOUND->play();
    }
} // playSoundEffect

void SoundManager::toggle() {
    toggleSound = !toggleSound;
} // toggle
