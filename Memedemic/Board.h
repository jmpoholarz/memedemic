#pragma once
#include <vector>
#include <string>
#include "Enums.h"

class Board {

public:
	struct BoardLocation {
		bool players[4] = { false, false, false, false };
		int memes[4] = { 0, 0, 0, 0 };
		bool cmcServer = false;
	};

	Board(int players);
	~Board();

	void setupPlayers(int players);
	void printBoard();
	void addMemeCubes(int loc, int meme, int count);
	void removeMemeCube(int loc, int meme);
	void addCMC(int loc);
	void removeCMC(int loc);
	void movePlayer(int location, int player);
	void addOutbreak();
	void addCure(int meme);
	void eradicateMeme(int meme);
	void removePlayerCard();

	BoardLocation getLocation(int loc); // For testing purposes
	int getOutbreakCounter(); // For testing purposes
	bool getCure(int meme); // For testing purposes
	int getPlayerCards(); // For testing purposes
	std::vector<std::string> getPlayerRoles(); // For testing purposes

	void setMemes(int location, int values[]);
	void setPlayers(int location, int playerNumber, bool present);
	void setCMCServer(int location, bool exists);

private:
	std::vector<BoardLocation> locations;

	std::vector<std::string> playerRoles;

	int outbreakCounter;
	bool cures[4];
	int playerCards;

	void initializeLocations();
	std::string getRoleAbbreviation(PlayerRoles role);
	void printCounters(int loc);
	void printCMC(int loc);
	void printPlayers(int loc);
	void printOutbreaks();
	void printCures();
	void printPlayerCards();

};
