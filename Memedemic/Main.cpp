#include "Main.h"


int main() {
	// Prompt player count
	int players = 0;
	do {
		std::cout << "Enter players 1-4:" << std::endl;
		try
		{
			std::cin >> players;
		}
		catch (const std::exception&)
		{
			continue;
		}
	} while (!(players > 0 && players < 5));
	std::string s = ""; // throwaway string to fix extra empty line error
	std::getline(std::cin,s); // eat empty line
	// Create GameStateManager to setup game
	GameStateManager* gsm = new GameStateManager(players);
	Parser* parser = new Parser(*gsm);
	Screen* screen = new Screen(*gsm, *parser);
	screen->run();
}
