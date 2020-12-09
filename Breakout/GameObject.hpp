#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"
#include "BoxCollider.hpp"
//#include "Level.hpp"
#include <vector>
#include <string>

using namespace std;


class GameObject {

public:
	GameObject(const char* textureFile, SDL_Renderer* ren, int x, int y);
	~GameObject();

	virtual void update() = 0;
	virtual void move(int x, int y) = 0;
	virtual vector<string> getBrickDetails() = 0;
	virtual void setBrickDetails(vector<string> details) = 0;
	virtual void playBreakSound() = 0;
	virtual void playHitSound() = 0;

	void render();

	//const char* getTexturePath();
	//SDL_Renderer* getRenderer();
	void setDestRectCoordinates(int x, int y);
	void setDestRectSize(int w, int h);
	void changeTextureFile(const char* textureFile);
	void setBoxColliderSize(int x, int y);
	SDL_Rect getDestRect();

	static bool checkForDeletion(BoxCollider* boxCollider);

	static vector<GameObject*> gameObjects;

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;

protected:
	SDL_Rect srcRect, destRect;
	BoxCollider* boxCollider;
	SDL_Renderer* renderer;

};
