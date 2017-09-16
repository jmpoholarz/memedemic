#include "Main.h"

int main() {
	// Prompt player count
	std::cout << "Enter players 1-4" << std::endl;
	int players;
	std::cin >> players;
	// Create GameStateManager to setup game
	GameStateManager* gsm = new GameStateManager(players);
	Screen* screen = new Screen(*gsm);
	screen->run();
}