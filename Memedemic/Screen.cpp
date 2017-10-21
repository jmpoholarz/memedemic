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
		std::cout << "Player " << gsm.getCurrentPlayerNumber()+1 << "\t" << gsm.getCurrentPlayer().getPlayerName() << " - "
			<< convertRole(gsm.getCurrentPlayer().getPlayerRole()) << "\n                                                          Actions left: " << gsm.getActionsRemaining() << "\n";

		// If there is an announcement, print it!!
		if (gsm.announcement != "")
			std::cout << gsm.announcement << std::endl;
		gsm.announcement = "";
		// Print response of output to user
		std::cout << response << std::endl;
		gsm.saveGame("autosave.txt");
		// Obtain the next user command
		std::getline(std::cin, command);
		response = sendCommand(command);

		if ("response = __main_menu")
			return;
	}
}

void Screen::showBoard() {
	gsm.getBoard().printBoard();
}

std::string Screen::sendCommand(std::string command) {
	return parser.parse(command);
}

std::string Screen::convertRole(int role) {
	if (role == 0)
		return "Professor";
	else if (role == 1)
		return "Hacker";
	else if (role == 2)
		return "Moderator";
	else if (role == 3)
		return "Router";
	else if (role == 4)
		return "Firewall";
	else if (role == 5)
		return "Millenial";
}