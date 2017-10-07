#pragma once
#include "Enums.h"
#include "Card.h"
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
	std::vector<Card> getPlayerCards();
	CardNames getPlayerLocation();
    bool setPlayerLocation(CardNames location);
    bool setPlayerRole(PlayerRoles role);
    bool holdsNCards(CardNames card, int n);
    bool addCard(CardNames card);
    bool removeNCards(CardNames card, int n);
private:
	std::string playerName;
	PlayerRoles playerRole;
	CardNames playerLocation;
	std::vector<Card> playerCards;
};
