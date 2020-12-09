#include "Level.hpp"

//int Level::numOfBricks = 0;

Level::Level(const char * filePath, SDL_Renderer* renderer) {

	ren = renderer;

	XMLLoader xml = XMLLoader(filePath);

	levelInfo = xml.extractLevelInfo();
	bricksInfo = xml.extractBricksInfo();
	bricksFormation = xml.extractBrickFormation();

	if (levelInfo.empty() || bricksInfo.empty() || bricksFormation.empty()) {
		std::cout << "ERROR LOADING XML..." << std::endl;
		return;
	}
	bg = new Wall("", renderer, 0, 0);
	bg->setBoxColliderSize(0, 0);
	bg->setDestRectSize(800, 600);
	bg->changeTextureFile((levelInfo[4]).c_str());
	ball = new Ball("Assets/ball.dds", renderer, 396, 400);
	player = new Player("Assets/player.dds", renderer, 360, 580);
	wall1 = new Wall("Assets/wall.dds", renderer, 0, 0);
	wall2 = new Wall("Assets/wall.dds", renderer, 780, 0);

	loadBricks();
	
}

void Level::loadBricks() {
	int row = 0;
	int column = 0;
	int distX = 38;
	for (int i = 0; i < bricksFormation.size(); i++) {
		switch (bricksFormation[i]) {
		case 'S':
			bricks.push_back(new Brick(bricksInfo.at(0), ren, column * distX + 20 + stoi(levelInfo.at(3)), row * 25 + 40 + stoi(levelInfo.at(2))));
			numOfBricks++;
			column++;
			break;
		case 'M':
			bricks.push_back(new Brick(bricksInfo.at(1), ren, column * distX + 20 + stoi(levelInfo.at(3)), row * 25 + 40 + stoi(levelInfo.at(2))));
			numOfBricks++;
			column++;
			break;
		case 'H':
			bricks.push_back(new Brick(bricksInfo.at(2), ren, column * distX + 20 + stoi(levelInfo.at(3)), row * 25 + 40 + stoi(levelInfo.at(2))));
			numOfBricks++;
			column++;
			break;
		case 'I':
			bricks.push_back(new Brick(bricksInfo.at(3), ren, column * distX + 20 + stoi(levelInfo.at(3)), row * 25 + 40 + stoi(levelInfo.at(2))));
			column++;
			break;
		case '_':
			column++;
			break;
		case ' ':
			break;
		case '\n':
			column = 0;
			row++;
			break;
		default:
			break;
		}
	}
	backBrick = new Brick(bricksInfo.at(3), ren, 0, 0);
	backBrick->resizeBrick(800, 30);
	bricks.push_back(backBrick);
}

void Level::nextLevel() {
	delete this;
}

void Level::setBG(const char* filePath) {
	bg->changeTextureFile(filePath);
}

Level::~Level() {
	GameObject::gameObjects.clear();
	Ball::balls.clear();
	BoxCollider::boxColliders.clear();
	sounds.clear();

}

std::vector<std::string> Level::getLevelInfo() {
	return levelInfo;
}
