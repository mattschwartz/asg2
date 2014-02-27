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

<<<<<<< HEAD
void SoundEffect::free() {
=======
void SoundEffect::freeSound() {
>>>>>>> 9ef05bc017e6aa330e4a58b28c72fd6aaabfc9d5
    Mix_FreeChunk(this->sound);
}
