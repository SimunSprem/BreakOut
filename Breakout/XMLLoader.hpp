#pragma once

#include <vector>
#include "tinyxml2.h"
#include <map>
#include <string>

class XMLLoader {
public:
	XMLLoader(const char* filePath);
	~XMLLoader();
	std::vector<std::string> extractLevelInfo();
	std::vector<std::vector<std::string>> extractBricksInfo();
	std::string extractBrickFormation();

private:
	const char* path;
	//std::map<const char*, const char*> levelInfo;
	//std::map<const char*, std::map<const char*, const char*>> bricksInfo;
	std::vector<std::string> levelInfo;
	std::vector<std::vector<std::string>> bricksInfo;
	std::string bricksFormation;
	tinyxml2::XMLNode* brickTypes;
	tinyxml2::XMLElement* brick;
};