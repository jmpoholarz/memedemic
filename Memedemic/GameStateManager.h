#pragma once
#include <vector>
#include "Board.h"
#include "Card.h"
#include "Player.h"


// Handles most game actions and state changes
class GameStateManager {
	
public:
	GameStateManager();

	// Sets up initial game starting conditions
	GameStateManager(int numPlayers);
	
	// Frees all objects and readies the game for closing
	~GameStateManager();

	bool movePlayer(int location);
	bool banMeme(int location);
	bool developMemeFilter(int location, int meme);
	bool buildCMCServer(int location);
	bool playCard(int card);
	bool shareCard(int player);
	bool drawCards(int player);
	void printPlayerRoles();
	void printPlayerLocations();
	void printPlayerCards(int player);
	void printCMCLocations();
	bool updateBoard();
	bool autoSave();
	bool nextTurn();
	bool initialInfection();
	bool infect(int location, int meme, int count);


private:
	Board* board;
	std::vector<Player*> players;
	int outbreakTrack;
	int viralQuotient;
	int currentPlayer;
	int actionsRemaining;
	std::vector<Card*> cards;
};