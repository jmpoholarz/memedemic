#pragma once
#include "Enums.h"
#include <string>
#include <vector>

class Player {
	
public:
	Player();
	Player(std::string name, PlayerRoles playerRole, CardNames location);
	~Player();

	bool setPlayerName(std::string name);
	std::string getPlayerName();
	PlayerRoles getPlayerRole();
	std::vector<int> getPlayerCards();
	int getPlayerLocation();
    bool setPlayerLocation(int location);
    bool setPlayerRole(PlayerRoles role);
    bool holdsNCards(int card, int n);
    bool addCard(int card);
    bool removeNCards(int card, int n);
private:
	std::string playerName;
	PlayerRoles playerRole;
	int playerLocation;
	std::vector<int> playerCards;
};
