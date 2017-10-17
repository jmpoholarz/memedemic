#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Location.h"
#include "Player.h"


// Handles most game actions and state changes
class GameStateManager {
	
public:
	//GameStateManager();

	// Sets up initial game starting conditions
	GameStateManager(Board& b, Location& l);
	void setupPlayers(int numPlayers);
    void setupDeck();
	
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
	
	int getOutbreakTrack();
	int getViralQuotient();
	int getMemeStatus(int memeNumber);
	int getActionsRemaining();
	Board& getBoard();
	Player& getPlayer(int index);
	//std::vector<Card*> getCards();
	
	int setOutbreakTrack(int value);
	int setViralQuotient(int value);
	int setMemeStatus(int meme, int filtered);
	int setActionsRemaining(int value);

	int saveGame();

	int endGame();
	bool gameEnd;

private:
    std::string convertIntToCard(int);
	Board& board;
	Location& locations;
	std::vector<Player*> players;
	int outbreakTrack;
	int viralQuotient;
	int currentPlayer;
	int actionsRemaining;

	//TODO tracks how many cubes of each meme is left, losing condition if any is < 0
	int cubesLeft[4];
    int playerHasDrawn;
	std::vector<int> cards;
    std::vector<int> discardPile;
};
