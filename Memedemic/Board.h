#pragma once
#include <vector>
#include "Enums.h"
#include "string"

class Board {

public:
	struct BoardLocation {
		bool players[4] = { false, false, false, false };
		int memes[4] = { 0, 0, 0, 0 };
		bool cmcServer = false;
	};

	Board();
	~Board();

	void setupPlayers(int players);
	void printBoard();
	void addMemeCubes(int loc, int meme, int count);
	void removeMemeCube(int loc, int meme);
	void addCMC(int loc);
	void removeCMC(int loc);
	void movePlayer(int location, int player);
	void addOutbreak();
	void increaseViralQuotient();
	void addCure(int meme);
	void eradicateMeme(int meme);
	void updatePlayerCardCount(int playerCardCount);

	BoardLocation getLocation(int loc);
	int getOutbreakCounter();
	int getCure(int meme);
	void setCure(int meme, int value);
	int getPlayerCards();
	std::vector<std::string> getPlayerRoles();

	void setMemes(int location, int values[]);
	void setPlayers(int location, int playerNumber, bool present);
	void setCMCServer(int location, bool exists);

private:
	std::vector<BoardLocation> locations;

	std::vector<std::string> playerRoles;

	int outbreakCounter;
	int viralQuotientCounter;
	int cures[4]; // 0 = not cured, 1 = cured, 2 = eradicated
	int playerCards;

	void initializeLocations();
	std::string getRoleAbbreviation(PlayerRoles role);
	void printCounters(int loc);
	void printCMC(int loc);
	void printPlayers(int loc);
	void printOutbreaks();
	void printViralQuotient();
	void printCures();
	void printPlayerCards();

};
