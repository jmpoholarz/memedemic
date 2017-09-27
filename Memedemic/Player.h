#pragma once
#include "Enums.h"
#include "Card.h"
#include <string>
#include <vector>

class Player {
	
public:
	Player(std::string name, PlayerRoles playerRole, CardNames location);
	~Player();

	bool setPlayerName(std::string name);
	std::string getPlayerName();
	PlayerRoles getPlayerRole();
	std::vector<Card> getPlayerCards();
	CardNames getPlayerLocation();
    bool setPlayerLocation(CardNames location);
    bool holdsNCards(Card card, int n);
    bool addCard(Card card);
    bool removeNCards(Card card, int n);
private:
	std::string playerName;
	PlayerRoles playerRole;
	CardNames playerLocation;
	std::vector<Card> playerCards;
};
