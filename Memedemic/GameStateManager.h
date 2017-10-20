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
	void setupPlayers(int numPlayers, bool loadingGame = false);
    void setupDeck();
	
	// Frees all objects and readies the game for closing
	~GameStateManager();

	int movePlayer(int location);
	int moveOtherPlayer(int playerToMove, int location);
	int banMeme(int memeNumber);
	int developMemeFilter(int card1, int card2, int card3, int card4, int card5);
	int buildCMCServer();
	int playCard(int card);
	int discardCard(int card1, int card2);
	int shareCard(int direction, int card, std::string playerName);
	int drawCards();
	std::string printPlayerRoles();
	std::string printPlayerLocations();
	std::string printPlayerCards(std::string playerName);
	std::string printCMCLocations();
	int updateBoard();
	int autoSave(std::string filename);
	int incrementInfect(int loca, std::vector<int> track, int meme);
	int nextTurn();
	int initialInfection();
	int infect(int location, int meme, int count);
	
	int getOutbreakTrack();
	int getViralQuotient();
	int getMemeStatus(int memeNumber);
	int getActionsRemaining();
	Board& getBoard();
	Player& getPlayer(int index);
    std::vector<Player*> getPlayers();
	//std::vector<Card*> getCards();
	
	int setOutbreakTrack(int value);
	int setViralQuotient(int value);
	int setMemeStatus(int meme, int filtered);
	int setActionsRemaining(int value);
	void queueCardInDeck(int value);

	int saveGame(std::string filename = "autosave.txt");
	int loadGame(std::string filename = "autosave.txt");

	int endGame();
	bool gameEnd;

private:
    std::string convertIntToCard(int);
    std::string returnLocSection(int);
    bool locationHasPlayer(int);
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
