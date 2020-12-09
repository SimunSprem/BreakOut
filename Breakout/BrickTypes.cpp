//#include "BrickTypes.hpp"
//
//
//BrickSoft::BrickSoft(SDL_Renderer* ren, int x, int y) : Brick(ren, 'S', x, y, false) {
//
//	id = 'S';
//	textureFile = "Assets/brickS.png";
//	hitPoints = "1";
//	hitSound = " ";
//	breakSound = " ";
//	breakScore = 50;
//
//	changeTextureFile(textureFile);
//
//	Brick::addToBricks(this);
//}
//
//BrickMedium::BrickMedium(SDL_Renderer* ren, int x, int y) : Brick(ren, 'M', x, y, false) {
//
//	id = 'M';
//	textureFile = "Assets/brickM.png";
//	hitPoints = "2";
//	hitSound = " ";
//	breakSound = " ";
//	breakScore = 100;
//
//	changeTextureFile(textureFile);
//
//	Brick::addToBricks(this);
//}
//
//BrickHard::BrickHard(SDL_Renderer* ren, int x, int y) : Brick(ren, 'H', x, y, false) {
//
//	id = 'H';
//	textureFile = "Assets/brickH.png";
//	hitPoints = "3";
//	hitSound = " ";
//	breakSound = " ";
//	breakScore = 150;
//
//	changeTextureFile(textureFile);
//
//	Brick::addToBricks(this);
//}
//
//BrickImpen::BrickImpen(SDL_Renderer* ren, int x, int y) : Brick(ren, 'I', x, y, false) {
//
//	id = 'I';
//	textureFile = "Assets/brickI.png";
//	hitPoints = "Infinite";
//	hitSound = " ";
//
//	changeTextureFile(textureFile);
//
//	Brick::addToBricks(this);
//}