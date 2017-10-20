#include "Player.h"
#include "Enums.h"
#include <string>
#include <vector>
#include <iostream>

// Test 1: Initialize Player
bool testInitialize(Player *&player) {
    player = new Player("Player 1", HACKER, VINE);
    if (player -> getPlayerName().compare("Player 1") != 0) {
        return false;
    } else if (player -> getPlayerRole() != HACKER) {
        return false;
    } else if (player -> getPlayerLocation() != VINE) {
        return false;
    }

    std::cout << "PASS 1" << std::endl;
    return true;
}

// Test 2: Change player's name
bool testChangeName(Player *&player) {
    player -> setPlayerName("Player 2");
    if (player -> getPlayerName().compare("Player 2") != 0) {
        return false;
    }

    player -> setPlayerName("Player 1");
    if (player -> getPlayerName().compare("Player 1") != 0) {
        return false;
    }

    std::cout << "PASS 2" << std::endl;
    return true;
}

// Test 3: Change player's location
bool testChangeLocation(Player *&player) {
    player -> setPlayerLocation(VK);
    if (player -> getPlayerLocation() != VK) {
        return false;
    }


    player -> setPlayerLocation(VINE);
    if (player -> getPlayerLocation() != VINE) {
        return false;
    }

    std::cout << "PASS 3" << std::endl;
    return true;
}

// Test 4: Add cards to player's hand
bool testAddCards(Player *&player) {
    player -> addCard(WEIBO);
    player -> addCard(FACEBOOK);
    player -> addCard(WECHAT);

    std::vector<int> playerCards = player -> getPlayerCards();
    if (playerCards[0] != WEIBO || playerCards[1] != FACEBOOK || playerCards[2] != WECHAT) {
        return false;
    }

    std::cout << "PASS 4" << std::endl;
    return true;
}

// Test 5: Remove cards from player's hand
bool testRemoveCards(Player *&player) {
    player -> removeNCards(WEIBO, 1);
    player -> removeNCards(FACEBOOK, 1);
    player -> removeNCards(WECHAT, 1);

    if (player -> getPlayerCards().size() != 0) {
        return false;
    }

    std::cout << "PASS 5" << std::endl;
    return true;
}

// Test 6: Check if player holds n cards
bool testHoldsNCards(Player *&player) {
    player -> addCard(WHATSAPP);
    player -> addCard(WHATSAPP);
    player -> addCard(WHATSAPP);
    player -> addCard(WHATSAPP);
    player -> addCard(EMAIL);
    player -> addCard(EMAIL);
    player -> addCard(MYSPACE);

    if (!player -> holdsNCards(WHATSAPP, 4) || !player -> holdsNCards(EMAIL, 2) || !player -> holdsNCards(MYSPACE, 1)) {
        return false;
    }

    std::cout << "PASS 6" << std::endl;
    return true;
}

// Test 7: Remove n cards from player's hand
bool testRemoveNCards(Player *&player) {
    player -> removeNCards(WHATSAPP, 3);
    player -> removeNCards(EMAIL, 1);

    std::vector<int> playerCards = player -> getPlayerCards();
    if (playerCards[0] != WHATSAPP || playerCards[1] != EMAIL || playerCards[2] != MYSPACE) {
        return false;
    }

    player -> removeNCards(WHATSAPP, 1);
    player -> removeNCards(EMAIL, 1);
    player -> removeNCards(MYSPACE, 1);

    if (player -> getPlayerCards().size() != 0) {
        return false;
    }

    std::cout << "PASS 7" << std::endl;
    return true;
}


// Main function
int main() {
    Player *player;
    testInitialize(player);
    testChangeName(player);
    testChangeLocation(player);
    testAddCards(player);
    testRemoveCards(player);
    testHoldsNCards(player);
    testRemoveNCards(player);

    return 0;
}
