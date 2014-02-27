#include "SoundEffect.h"
#include <cstring>

/**
 * Creates a new sound effect object by location
 * the sound file pointed to by filePath.
 */
SoundEffect::SoundEffect(const char* filePath) {
    sound = Mix_LoadWAV(filePath);
} // constructor

SoundEffect::~SoundEffect() {

}

/**
 * Plays the sound effect.
 */
void SoundEffect::play() {
    Mix_PlayChannel(-1, sound, 0);
} // play

void SoundEffect::freeSound() {
    Mix_FreeChunk(this->sound);
}
