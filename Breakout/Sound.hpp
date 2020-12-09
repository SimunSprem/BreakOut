#pragma once

#include "SDL_mixer.h"

class Sound {
public:
	Sound(const char* filePath);
	void playSound();

private:
	const char* soundPath;
	Mix_Chunk* sound;
};