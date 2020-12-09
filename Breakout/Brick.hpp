#pragma once

#include "GameObject.hpp"
#include "Sound.hpp"
#include <vector>
#include <string>

class Brick : public GameObject {

public:
	Brick(SDL_Renderer* ren, char id, int x, int y, bool firstPass);
	Brick(const char* textureFile, SDL_Renderer* ren, int x, int y);
	Brick(std::vector<std::string> &info, SDL_Renderer* renderer, int x, int y);
	~Brick();
	SDL_Renderer* ren;

	void resizeBrick(int w, int h);
	void reduceHP();

	static vector<Brick*> bricks;

	void addToBricks(Brick* brick);
	static Brick* createBrick(SDL_Renderer* ren, char id, int x, int y);
	static int numOfBricks;
	static int numOfImpenetrableBricks;

	virtual void move(int x, int y);
	virtual void update();
	virtual vector<string> getBrickDetails();
	virtual void setBrickDetails(vector<string> details);
	virtual void playBreakSound();
	virtual void playHitSound();

	//BoxCollider* boxCollider;

private:
	std::string id;
	std::string textureFile;
	std::string hitPoints;
	std::string hitSound;
	std::string breakSound;
	std::string breakScore;

	Sound* hitSFX;
	Sound* breakSFX;
};
