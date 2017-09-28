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
	int developMemeFilter(int card1, int card2, int card3, int card4, int card5);
	int buildCMCServer();
	int playCard(int card);
	int discardCard(int card1, int card2);
	int shareCard(int card, std::string playerName);
	int drawCards();
	std::string printPlayerRoles();
	std::string printPlayerLocations();
	std::string printPlayerCards(std::string playerName);
	std::string printCMCLocations();
	int updateBoard();
	int autoSave();
	int nextTurn();
	int initialInfection();
	int infect(int location, int meme, int count);
	std::string getOutbreakTrack();
	std::string getViralQuotient();
	std::string getMemeStatus();


private:
	Board* board;
	std::vector<Player*> players;
	int outbreakTrack;
	int viralQuotient;
	int currentPlayer;
	int actionsRemaining;
	std::vector<Card*> cards;
};