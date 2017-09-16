#include "GameStateManager.h"


GameStateManager::GameStateManager() {
	board = new Board();
}

GameStateManager::~GameStateManager() {
	delete board;
}