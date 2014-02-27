#include "SoundEffect.h"
#include <cstring>

/**
 * Creates a new sound effect object by location
 * the sound file pointed to by filePath.
 */
SoundEffect::SoundEffect(char *filePath) {
    sound = Mix_LoadWAV(str(filePath));
} // constructor

/**
 * Plays the sound effect.
 */
void SoundEffect::play() {
    Mix_PlayChannel(-1, sound, 0);
} // play

void SoundEffect::free() {
    Mix_FreeChunk(this->sound);
}
