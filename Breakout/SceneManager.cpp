#include "SceneManager.hpp"

Text* SceneManager::scoreNum;
Text* SceneManager::livesNum;
Text* SceneManager::levelNum;

SceneManager::SceneManager(const char* sID, SDL_Renderer* ren) {

	sceneID = sID;
	renderer = ren;
	lvl = sceneID;
	lvl = lvl.back();
	selected = 0;
	loadScene(sceneID);

}

SceneManager::~SceneManager() {
}

void SceneManager::loadScene(const char* sID) {

	if (sID == "Level1")
		level = new Level("./Levels/Level1.xml", renderer);
	else if (sID == "Level2")
		level = new Level("Levels/Level2.xml", renderer);
	else if (sID == "Level3")
		level = new Level("Levels/Level3.xml", renderer);
	else if (sID == "MainMenu") {
		mainMenuFont = TTF_OpenFont("./Fonts/arial.ttf", 35);
		startText = new Text("Start", mainMenuFont, renderer, 300, 200);
		quitText = new Text("Quit", mainMenuFont, renderer, 300, 400);
		mainMenuPointer = new Ball("Assets/ball.dds", renderer, 400, 220);
		mainMenuPointer->speed = 0;
		return;
	}

	level->setBG((level->getLevelInfo()[4]).c_str());

	scoreText = new Text("Score ", Game::font, renderer, 0, 0);
	levelText = new Text("Level ", Game::font, renderer, 350, 0);
	livesText = new Text("Lives ", Game::font, renderer, 600, 0);

	scoreNum = new Text(to_string(Game::score).c_str(), Game::font, renderer, 75, 0);
	levelNum = new Text(lvl.c_str(), Game::font, renderer, 420, 0);
	livesNum = new Text(to_string(Game::lives).c_str(), Game::font, renderer, 670, 0);


}

void SceneManager::update() {
	//cout << GameObject::gameObjects.size() << endl;
	// kada je broj elemenata na levelu jednak zbroju neprobojnih cigli i ostalih objekata (zidovi, pozadina, igrač), znači da više nema cigli
		if (GameObject::gameObjects.size() == 4 + Brick::numOfImpenetrableBricks) { 
			//cout << "NextLevel" << endl;
			//lvl = to_string(stoi(lvl) + 1);
			string newLvlId = to_string(stoi(lvl) + 1).c_str();
			newLvlId = "Level" + newLvlId;
			nextLevel(newLvlId);
		}
}

void SceneManager::nextLevel(string sID) {
	
	startText = nullptr;
	quitText = nullptr;
	Text::texts.clear();
	GameObject::gameObjects.clear();
	Ball::balls.clear();
	sceneID = sID.c_str();
	
	SDL_Delay(2000);
	delete level;
	if (sID == "Level1")
		level = new Level("Levels/Level1.xml", renderer);
	else if (sID == "Level2")
		level = new Level("Levels/Level2.xml", renderer);
	else if (sID == "Level3")
		level = new Level("Levels/Level3.xml", renderer);

	lvl = sID;
	lvl = lvl.back();

	scoreText = new Text("Score ", Game::font, renderer, 0, 0);
	levelText = new Text("Level ", Game::font, renderer, 350, 0);
	livesText = new Text("Lives ", Game::font, renderer, 600, 0);

	scoreNum = new Text(to_string(Game::score).c_str(), Game::font, renderer, 75, 0);
	levelNum = new Text(lvl.c_str(), Game::font, renderer, 420, 0);
	livesNum = new Text(to_string(Game::lives).c_str(), Game::font, renderer, 670, 0);

	SceneManager::levelNum->updateText(lvl.c_str());

}

const char* SceneManager::getSID() {
	return sceneID;
}

int SceneManager::getSelected() {
	return selected;
}

void SceneManager::setSelected(int s) {
	selected = s;
}
