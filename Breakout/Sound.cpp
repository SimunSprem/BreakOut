#include "Sound.hpp"

Sound::Sound(const char* filePath) {
	soundPath = filePath;
	sound = Mix_LoadWAV(soundPath);
}

void Sound::playSound() {
	Mix_PlayChannel(-1, sound, 0);
}