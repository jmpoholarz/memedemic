#include "Main.h"


int main() {
	// Prompt player count
	int players = 0;
	std::string strPlayers = "";
	do {
		std::cout << "Enter players (1-4): ";
		std::getline(std::cin, strPlayers);
		if (strPlayers.size() == 1 && std::isdigit(strPlayers[0]))
			players = atoi(strPlayers.c_str());
	} while (!(players > 0 && players < 5));
	//std::string s = ""; // throwaway string to fix extra empty line error
	//std::getline(std::cin,s); // eat empty line
	// Create GameStateManager to setup game
	Board* board = new Board(players);
	Location* locations = new Location();

	GameStateManager* gsm = new GameStateManager(*board, *locations, players);
	Parser* parser = new Parser(*gsm);
	Screen* screen = new Screen(*gsm, *parser);
	screen->run();
}
