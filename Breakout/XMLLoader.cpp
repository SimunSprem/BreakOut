#include "XMLLoader.hpp"

#include <iostream>

using namespace std;

XMLLoader::XMLLoader(const char* filePath) {

	path = filePath;
	
	//extractLevelInfo();
	//extractBricksInfo();
	//extractBrickFormation();

}

XMLLoader::~XMLLoader() {}

std::vector<std::string> XMLLoader::extractLevelInfo() {

	string rowCount;
	string columnCount;
	string rowSpacing;
	string columnSpacing;
	string bgTexture;


	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile(path);
	if (eResult != tinyxml2::XML_SUCCESS) return levelInfo;

	tinyxml2::XMLElement* level = xml_doc.FirstChildElement("Level");
	if (level == nullptr) return levelInfo;

	try {
		rowCount = level->Attribute("RowCount");
		columnCount = level->Attribute("ColumnCount");
		rowSpacing = level->Attribute("RowSpacing");
		columnSpacing = level->Attribute("ColumnSpacing");
		bgTexture = level->Attribute("BackgroundTexture");
	}
	catch (const std::exception&) {
		return levelInfo;
	}

	levelInfo.push_back(rowCount);
	levelInfo.push_back(columnCount);
	levelInfo.push_back(rowSpacing);
	levelInfo.push_back(columnSpacing);
	levelInfo.push_back(bgTexture);

	return levelInfo;
}

std::vector<std::vector<std::string>> XMLLoader::extractBricksInfo() {

	string id;
	string texture;
	string hitPoints;
	string hitSound;
	string breakSound;
	string breakScore;

	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile(path);
	if (eResult != tinyxml2::XML_SUCCESS) return bricksInfo;

	tinyxml2::XMLNode* level = xml_doc.FirstChildElement("Level");
	if (level == nullptr) return bricksInfo;

	tinyxml2::XMLNode* brickType = level->FirstChildElement("BrickTypes");
	if (brickType == nullptr) return bricksInfo;

	tinyxml2::XMLElement* brick = brickType->FirstChildElement("BrickType");
	for (int i = 0; i < 4; i++) {
		std::vector<string> temp;
		try
		{
			id = brick->Attribute("Id");
			texture = brick->Attribute("Texture");
			hitPoints = brick->Attribute("HitPoints");
			hitSound = brick->Attribute("HitSound");
			if (id != "I") {
				breakSound = brick->Attribute("BreakSound");
				breakScore = brick->Attribute("BreakScore");
			}
			brick = brick->NextSiblingElement("BrickType");
		}
		catch (const std::exception&)
		{
			return bricksInfo;
		}

		temp.push_back(id);
		temp.push_back(texture);
		temp.push_back(hitPoints);
		temp.push_back(hitSound);
		if (id != "I") {
			temp.push_back(breakSound);
			temp.push_back(breakScore);
		}

		bricksInfo.push_back(temp);
	}

	return bricksInfo;
}

std::string XMLLoader::extractBrickFormation() {

	tinyxml2::XMLDocument xml_doc;

	tinyxml2::XMLError eResult = xml_doc.LoadFile(path);
	if (eResult != tinyxml2::XML_SUCCESS) return bricksFormation;

	tinyxml2::XMLNode* level = xml_doc.FirstChildElement("Level");
	if (level == nullptr) return bricksFormation;

	tinyxml2::XMLElement* bricks = level->FirstChildElement("Bricks");
	if (bricks == nullptr) return bricksFormation;

	bricksFormation = bricks->GetText();

	return bricksFormation;

}
