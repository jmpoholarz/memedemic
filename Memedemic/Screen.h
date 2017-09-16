#pragma once
#include <string>
#include "GameStateManager.h"

class Screen {

public:
	Screen(GameStateManager& gsm);
	~Screen();
	void showBoard();
	std::string sendCommand(std::string command);
	void run();
private:
	GameStateManager gsm;
};