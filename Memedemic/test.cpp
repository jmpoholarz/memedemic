#include <iostream>
#include "Enums.h"
#include "Player.h"

int main() {
    int i;
    Player *player = new Player("My Name", HACKER, VINE);
    std::cout << player -> getPlayerName() << std::endl;
    player -> setPlayerName("Jeff");
    player -> addCard(VINE);
    std::cout << player -> getPlayerName() << std::endl;
    player -> addCard(TWITTER);
    player -> addCard(FACEBOOK);
    player -> addCard(TWITTER);
    player -> addCard(TWITTER);
    player -> addCard(TWITTER);
    player -> addCard(TWITTER);
    for (i = 0; i < player -> getPlayerCards().size(); i++) {
        std::cout << player -> getPlayerCards()[i] << std::endl;
    }
    player -> removeNCards(TWITTER, 2);
    for (i = 0; i < player -> getPlayerCards().size(); i++) {
        std::cout << player -> getPlayerCards()[i] << std::endl;
    }
    delete player;
    std::cout << "Test" << std::endl;
    return 0;
}
