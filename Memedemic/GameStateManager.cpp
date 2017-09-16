#include "GameStateManager.h"


GameStateManager::GameStateManager(int numPlayers) {
	// Create a new board
	board = new Board();
	// Add players to a vector
	for (int i = 0; i < numPlayers; i++) {
		Player* p = new Player();
		players.push_back(p);
	}
	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}

GameStateManager::~GameStateManager() {
	delete board;
	for each (Player* p in players) {
		delete p;
	}
}