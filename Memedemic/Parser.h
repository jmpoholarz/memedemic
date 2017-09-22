#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include "GameStateManager.h"
#include "Enums.h"

class Parser {
public:
	Parser(GameStateManager& gsm);
	~Parser();
	std::string parse(std::string command);

	// returns the enum value of the card given by name
	int convertCard(std::string name);

	// provides a usage string for correct usage of a command
	std::string getUsage(std::string command);

private:
	GameStateManager& gsm;
};