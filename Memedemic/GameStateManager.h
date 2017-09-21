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

	int movePlayer(int location);
	int banMeme(int memeNumber);
	int developMemeFilter(int memeNumber);
	int buildCMCServer();
	int playCard(int card);
	int shareCard(int card, std::string playerName);
	int drawCards();
	int printPlayerRoles();
	int printPlayerLocations();
	int printPlayerCards(int player);
	int printCMCLocations();
	int updateBoard();
	int autoSave();
	int nextTurn();
	int initialInfection();
	int infect(int location, int meme, int count);


private:
	Board* board;
	std::vector<Player*> players;
	int outbreakTrack;
	int viralQuotient;
	int currentPlayer;
	int actionsRemaining;
	std::vector<Card*> cards;
};