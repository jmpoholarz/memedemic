#pragma once
#include <vector>

class Board {

public:
	Board(char p1Role[3], char p2Role[3]);
	Board(char p1Role[3], char p2Role[3], char p3Role[3]);
	Board(char p1Role[3], char p2Role[3], char p3Role[3], char p4Role[3]);
	~Board();

	void printBoard();
	void addMemeCube(int loc, int meme);
	void removeMemeCube(int loc, int meme);
	void addCMC(int loc);
	void removeCMC(int loc);
	void movePlayer(int location, int player);
	void addOutbreak();
	void addCure(int meme);
	void removePlayerCard();

private:
	struct BoardLocation {
		bool players[4] = { false, false, false, false };
		int memes[4] = { 0, 0, 0, 0 };
		bool cmcServer = false;
	};

	std::vector<BoardLocation> locations;

	std::string playerRoles[4] = { NULL };

	int outbreakCounter;
	bool cures[4];
	int playerCards;

	void initializeLocations();
	void printCounters(int loc);
	void printCMC(int loc);
	void printPlayers(int loc);
	void printOutbreaks();
	void printCures();
	void printPlayerCards();

};