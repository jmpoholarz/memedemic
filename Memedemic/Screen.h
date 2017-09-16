#pragma once
#include <string>
#include "Board.h"
class Screen {

public:
	Screen();
	~Screen();
	Board getBoard();
	void showBoard();
	void sendCommand(std::string command);
private:

};