#pragma once

#include "XMLLoader.hpp"
#include "Sound.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Wall.hpp"


class Level {

public:
	Level(const char* filePath, SDL_Renderer* renderer);
	~Level();
	void loadBricks();
	int numOfBricks;

	void nextLevel();
	void setBG(const char* filePath);
	std::vector<std::string> getLevelInfo();

private:
	std::vector<std::string> levelInfo;
	std::vector<std::vector<std::string>> bricksInfo;
	std::string bricksFormation;
	std::vector<Sound*> sounds;

	SDL_Renderer* ren;

	Ball* ball;
	Player* player;
	Brick* backBrick;
	std::vector<Brick*> bricks;
	Wall* wall1;
	Wall* wall2;
	Wall* bg;

};