#include "GameStateManager.h"


GameStateManager::GameStateManager() {
	board = new Board();
	//players = new Player[4]; wip
}

GameStateManager::~GameStateManager() {
	delete board;
}