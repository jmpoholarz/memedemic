#pragma once
#include <string>
#include "GameStateManager.h"
#include "Parser.h"

class Screen {

public:
	Screen(GameStateManager& gsm, Parser& parser);
	~Screen();
	void showBoard();
	std::string convertRole(int role);
	std::string sendCommand(std::string command);
	void run();
private:
	GameStateManager& gsm;
	Parser& parser;
};