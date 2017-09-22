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
	std::vector<CardNames> getPlayerCards();
	CardNames getPlayerLocation();
    bool holdsNCards(CardNames card, int n);
    bool addCard(CardNames card);
    bool removeNCards(CardNames card, int n);
private:
	std::string playerName;
	PlayerRoles playerRole;
	CardNames playerLocation;
	std::vector<CardNames> playerCards;
};
