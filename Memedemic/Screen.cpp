#include <iostream>
#include "Screen.h"

Screen::Screen(GameStateManager& g, Parser& p) : gsm(g), parser(p) {

}

Screen::~Screen() {

}

void Screen::run() {
	std::string command;
	std::string response;
	while (1) {
		// WINDOWS SPECIFIC CLEAR SCREEN
		system("cls||clear");
		// Display the current board
		showBoard();

		// If there is an announcement, print it!!
		if (gsm.announcement != "")
			std::cout << gsm.announcement << std::endl;
		// Print response of output to user
		std::cout << response << std::endl;
		gsm.saveGame("autosave.txt");
		// Obtain the next user command
		std::getline(std::cin, command);
		response = sendCommand(command);

	}
}

void Screen::showBoard() {
	gsm.getBoard().printBoard();
}

std::string Screen::sendCommand(std::string command) {
	return parser.parse(command);
}
