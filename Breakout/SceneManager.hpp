#pragma once

#include "Level.hpp"
#include "Text.hpp"
#include <SDL.h>

class SceneManager {
public:
	SceneManager(const char* sID, SDL_Renderer* ren);
	~SceneManager();

	void nextLevel(string sID);
	void loadScene(const char* sID);
	void update();

	Text* levelText;
	static Text* levelNum;
	Text* livesText;
	static Text* livesNum;
	Text* scoreText;
	static Text* scoreNum;

	Level* level;
	const char* getSID();
	int getSelected();
	void setSelected(int s);
	Ball* mainMenuPointer;

private:
	const char* sceneID;
	int score;
	string lvl;
	SDL_Renderer* renderer;
	TTF_Font* mainMenuFont;
	Text* startText;
	Text* quitText;
	int selected;


};