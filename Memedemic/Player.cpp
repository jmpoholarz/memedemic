#include "Player.h"
#include "Enums.h"
#include <string>
#include <vector>

Player::Player() : playerName(""), playerRole(UNASSIGNED), 
playerLocation(EMAIL) {

}

Player::player() {
}

Player::Player(std::string name, PlayerRoles role, CardNames location) {
    this -> playerName = name;
    this -> playerRole = role;
    this -> playerLocation = location;
}

Player::~Player() {

}

// Sets player's name
bool Player::setPlayerName(std::string name) {
    this -> playerName = name;
    return true;
}

// Returns player's name
std::string Player::getPlayerName() {
    return this -> playerName;
}

// Returns player's role
PlayerRoles Player::getPlayerRole() {
    return this -> playerRole;
}

// Returns player's hand
std::vector<CardNames> Player::getPlayerCards() {
    return this -> playerCards;
}

// Returns player's location
CardNames Player::getPlayerLocation() {
    return this -> playerLocation;
}

// Sets player's location
bool Player::setPlayerLocation(CardNames location) {
    this -> playerLocation = location;
    return true;
}

bool Player::setPlayerRold(PlayerRoles role) {
    this -> playerRole = role;
}

// Checks if player holds n instances of the specified card
bool Player::holdsNCards(CardNames card, int n) {
    int i;
    int count = 0;

    // Count instances of card in player's hand
    for (i = 0; i < this -> playerCards.size(); i++) {
        if (playerCards[i] == card) {
            count++;
        }
    }

    if (n != 0 && count >= n) { // If the player holds n or more of the card, return true
        return true;
    } else if (n == 0 && count == 0) { // If n is 0, ensure the player did not hold the card
        return true;
    }
    
    return false;
}

// Adds a card to the player's hand
bool Player::addCard(CardNames card) {
    try {
        this -> playerCards.push_back(card);
    } catch (std::bad_alloc) { // If push_back fails to allocate memory to expand the vector
        return false;
    }
    return true;
}

// Removes n instances of the specified card
bool Player::removeNCards(CardNames card, int n) {
    int i = 0;
    bool success = false;
    while (i < this -> playerCards.size() && n > 0) {
        if (this -> playerCards[i] == card) {
            success = true;
            // Remove card using erase so items are relocated
            playerCards.erase(playerCards.begin() + i);
            n--;
            i--;
        }
        i++;
    }

    return success;
}
