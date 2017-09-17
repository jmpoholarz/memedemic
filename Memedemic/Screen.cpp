#include <iostream>
#include "Screen.h"

Screen::Screen(GameStateManager& g, Parser& p) : gsm(g), parser(p) {

}

Screen::~Screen() {

}

void Screen::run() {
	while (1) {
		// Obtain the next user command
		std::string command;
		std::getline(std::cin, command);
		std::string response = sendCommand(command);
		// Print response of output to user
		std::cout << response << std::endl;
		// Display the current board
		showBoard();
	}
}