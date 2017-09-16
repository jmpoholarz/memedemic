#include "GameStateManager.h"


GameStateManager::GameStateManager(int numPlayers) {
	board = new Board(numPlayers);
}

GameStateManager::~GameStateManager() {
	delete board;
}