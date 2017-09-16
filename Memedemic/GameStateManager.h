#pragma once
#include "Board.h"
#include "Player.h"


// Handles most game actions and state changes
class GameStateManager {
	
public:
	// Sets up initial game starting conditions
	GameStateManager();
	
	// Frees all objects and readies the game for closing
	~GameStateManager();

private:
	Board* board;
	Player* players[];
};