#include "GameStateManager.h"
#include "Main.h"
#include <iostream>
#include <random>
#include <algorithm>

/*GameStateManager::GameStateManager() : board(Board(1)), locations(Location()) {

	// Add players to a vector
	for (int i = 0; i < 1; i++) {
		Player* p = new Player();
		players.push_back(p);
	}

	// Create a new board
	//board = new Board(players[0]->getPlayerRole());
	// Create a new location

	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}*/

GameStateManager::GameStateManager(Board& b, Location& l) : board(b), locations(l) {
	// Initialize variables
	//outbreakTrack = 8;
	outbreakTrack = 0;
	viralQuotient = 0;
	currentPlayer = 0;
    actionsRemaining = 4;
    playerHasDrawn = 0; // may need to be stored in save file
    gameEnd = false;
    // Each meme is allocated 12 cubes
    cubesLeft[0] = 18;
    cubesLeft[1] = 18;
    cubesLeft[2] = 18;
    cubesLeft[3] = 18;
	//initialInfection(); // called in Main's game setup to not break loading
    //setupDeck(); // called in Main's game setup to not break loading
}
void GameStateManager::setupPlayers(int numPlayers, bool loadingGame) {
	// Handle setup for players in the board
	board.setupPlayers(numPlayers);
	// Add players to a vector
	for (int i = 0; i < numPlayers; i++) {
		Player* p = new Player("testman", UNASSIGNED, EMAIL);
        // Draw starting 2 cards
        int numCardsToDraw = 0;
        if (numPlayers <= 2) {
            numCardsToDraw = 4;
        } else if (numPlayers == 3) {
            numCardsToDraw = 3;
        } else if (numPlayers == 4) {
            numCardsToDraw = 2;
        }
		if (loadingGame == false) {
			for (int j = 0; j < numCardsToDraw; j++) {
				p->addCard(cards.back());
				cards.pop_back();
			}
		}

		players.push_back(p);
	}
	if (loadingGame == false) {
		// Insert Epidemic cards
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, cards.size() - 1);
		for (int i = 0; i < 6; i++) {
			cards.insert(cards.begin() + distr(eng), 29);
		}
		board.updatePlayerCardCount(cards.size());
	}

}

void GameStateManager::setupDeck() {
    /*std::vector<int> values(24, 0);
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 23);
    int i = 0;
    while (i < 5) {
        int randomValue = distr(eng);
        if (values[randomValue] == 2) {
            continue;
        } else {
            cards.push_back(randomValue);
            values[randomValue] += 1;
        }
        i++;
    }
    i = 0;
    while (i < 24) {
        infectionCards.push_back(i);
        i++;
    }
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(infectionCards), std::end(infectionCards), rng);*/
    std::vector<int> values(24, 0);
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 23);
    int i = 0;
    while (i < 48) {
        int randomValue = distr(eng);
        if (values[randomValue] == 2) {
            continue;
        } else {
            cards.push_back(randomValue);
            values[randomValue] += 1;
        }
        i++;
    }
}

GameStateManager::~GameStateManager() {
	while (players.size() > 0) {
		delete players[players.size() - 1];
		players.pop_back();
	}
}

int GameStateManager::movePlayer(int location) {
	// Make sure player has actions left in their turn
	if (actionsRemaining <= 0) {
		return 0;
	}
	// Check if accessing the same location as current location
	if (players[currentPlayer]->getPlayerLocation() == location)
		return -2;
	// Check if adjacent location
	if (locations.isAdjacent(players[currentPlayer]->getPlayerLocation(), location)) {
		// Update player location in the Board class
		board.movePlayer(location, currentPlayer);
		players[currentPlayer]->setPlayerLocation((CardNames)location);
		std::cout << players[currentPlayer]->getPlayerLocation() << std::endl;
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if player holding the card for the destination
	else if (players[currentPlayer]->holdsNCards(location, 1)) {
		players[currentPlayer]->removeNCards(location, 1);
		players[currentPlayer]->setPlayerLocation(location);
		board.movePlayer(location, currentPlayer);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if the player is holding the current location
	else if (players[currentPlayer]->holdsNCards(players[currentPlayer]->getPlayerLocation(), 1)) {
		players[currentPlayer]->removeNCards(players[currentPlayer]->getPlayerLocation(), 1);
		players[currentPlayer]->setPlayerLocation(location);
		board.movePlayer(location, currentPlayer);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if at a CMC server and moving to a CMC server
	else if (board.getLocation(location).cmcServer == true &&
		board.getLocation(players[currentPlayer]->getPlayerLocation()).cmcServer == true) {
		board.movePlayer(location, currentPlayer);
		players[currentPlayer]->setPlayerLocation(location);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// If player has Professor role
    else if (players[currentPlayer]->getPlayerRole() == MEMESTUDIESPROFESSOR) {
        bool shouldMove = false;
        std::cout << "Since you are a Meme Studies Professor, you may discard a card to move to your desired location.\n\n";
        for (int i = 0; i < players[currentPlayer] -> getPlayerCards().size(); i++) {
            std::cout << "Card " + std::to_string(i + 1) + ": " +
					convertIntToCard(players[currentPlayer] -> getPlayerCards()[i]) + " - " +
                    returnLocSection(players[currentPlayer] -> getPlayerCards()[i]) + '\n';
        }
        std::cout << "Enter the number of the card you would like to discard. Enter 'CANCEL' to cancel: ";
        std::string cardToDiscardString;
        int cardToDiscard = -1;
        int playerHandSize = players[currentPlayer]->getPlayerCards().size();
        do {
            std::getline(std::cin, cardToDiscardString);
            if (cardToDiscardString == "CANCEL") {
                shouldMove = false;
                break;
            }
            if (cardToDiscardString.size() == 1 && std::isdigit(cardToDiscardString[0]))
                cardToDiscard = atoi(cardToDiscardString.c_str());
        } while (cardToDiscard < 1 || cardToDiscard > playerHandSize);

        if (cardToDiscard > 0 && cardToDiscard <= playerHandSize) {
            this -> discardCard(cardToDiscard, -1);
            shouldMove = true;
        }

        if (shouldMove) {
            board.movePlayer(location, currentPlayer);
            players[currentPlayer]->setPlayerLocation(location);
            setActionsRemaining(--actionsRemaining);
            return 1;
        } else {
            return -1;
        }
    }
	else return -1;
}

int GameStateManager::moveOtherPlayer(int playerToMove, int location) {
    // Make sure player has role of Router
    if (players[currentPlayer] -> getPlayerRole() != ROUTER) {
        return -4;
    }
    // Make sure playerToMove is not current player
    if (currentPlayer == playerToMove) {
        return -3;
    }
	// Make sure player has actions left in their turn
	if (actionsRemaining <= 0) {
		return 0;
	}
	// Check if accessing the same location as current location
	if (players[playerToMove]->getPlayerLocation() == location)
		return -2;
	// Check if adjacent location
	if (locations.isAdjacent(players[playerToMove]->getPlayerLocation(), location)) {
		// Update player location in the Board class
		board.movePlayer(location, playerToMove);
		players[playerToMove]->setPlayerLocation((CardNames)location);
		std::cout << players[playerToMove]->getPlayerLocation() << std::endl;
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if player holding the card for the destination
	else if (players[currentPlayer]->holdsNCards(location, 1)) {
		players[currentPlayer]->removeNCards(location, 1);
		players[playerToMove]->setPlayerLocation(location);
		board.movePlayer(location, playerToMove);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if the player is holding the current location
	else if (players[currentPlayer]->holdsNCards(players[playerToMove]->getPlayerLocation(), 1)) {
		players[currentPlayer]->removeNCards(players[playerToMove]->getPlayerLocation(), 1);
		players[playerToMove]->setPlayerLocation(location);
		board.movePlayer(location, playerToMove);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if at a CMC server and moving to a CMC server
	else if (board.getLocation(location).cmcServer == true &&
		board.getLocation(players[playerToMove]->getPlayerLocation()).cmcServer == true) {
		board.movePlayer(location, playerToMove);
		players[playerToMove]->setPlayerLocation(location);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	// Or if another player is at the desired location 
	else if (locationHasPlayer(location)) {
		board.movePlayer(location, playerToMove);
		players[playerToMove]->setPlayerLocation(location);
		setActionsRemaining(--actionsRemaining);
		return 1;
	}
	else return -1;
}

int GameStateManager::banMeme(int memeNumber) {
    // Make sure player has actions remaining
    if (actionsRemaining <= 0) {
        return 0;
    }
	// Meme already eradicated
	if (board.getCure(memeNumber == 2)) {
		return -1;
	}
	// If meme is cured but not eradicated
	else if (board.getCure(memeNumber) == 1) {
		int numberOfRemainingCubes = board.getLocation(players[currentPlayer]->getPlayerLocation()).memes[memeNumber];
		// No meme present
		if (numberOfRemainingCubes == 0) {
			return -2;
		}
		else {
			for (int i = 0; i < numberOfRemainingCubes; i++) {
				board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
				cubesLeft[memeNumber]++;
			}
			//locations.setMemeStatus(memeNumber, 0, players[currentPlayer]->getPlayerLocation());
            board.locations[players[currentPlayer]->getPlayerLocation()].memes[memeNumber] = 0;

			for (int i = 0; i < 24; i++) {
                if (board.locations[players[currentPlayer]->getPlayerLocation()].memes[memeNumber] != 0) {
                    break;
                }
				if (i == 23) {
					board.eradicateMeme(memeNumber);
				}
			}
			setActionsRemaining(--actionsRemaining);
			return 1;
		}
	}
	else {
		int numberOfRemainingCubes = board.getLocation(players[currentPlayer]->getPlayerLocation()).memes[memeNumber];
		// No meme present
		if (numberOfRemainingCubes == 0) {
			return -2;
		}
		else {
			if (players[currentPlayer]->getPlayerRole() == MODERATOR) {
				int numMemes = board.getLocation(players[currentPlayer]->getPlayerLocation()).memes[memeNumber];
				for (int count = 0; count < numMemes; count++) {
					board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
					cubesLeft[memeNumber]++;
				}
			}
			else {
				board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
				cubesLeft[memeNumber]++;
				//locations.setMemeStatus(memeNumber, numberOfRemainingCubes - 1,
				//	players[currentPlayer]->getPlayerLocation());
			}
			setActionsRemaining(--actionsRemaining);
			return 1;
		}
	}
}
int GameStateManager::developMemeFilter(int card1, int card2, int card3,
	int card4, int card5) {
    // Check if player has actions remaining
    if (actionsRemaining == 0) {
        return 0;
    }

    // Check that user is at a CMC server
    if (board.getLocation(players[currentPlayer]->getPlayerLocation()).cmcServer == false) {
        return -5;
    }
	// Note: card5 might be empty
	//check if the current player is allowed to make a filter without a 5th card
	if(players[currentPlayer]->getPlayerRole() != HACKER && card5 == -1)
	{
		//invalid number of cards for role
		return -2;
	}
	//check the usual requirement on number of cards
	if(card1 == -1 || card2 == -1 || card3 == -1 || card4 == -1)
	{
		//invalid cards for any role
		return -2;
	}

    // Check for duplicates of the same card
    if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5) {
        return -6;
    } else if (card2 == card3 || card2 == card4 || card2 == card5) {
        return -6;
    } else if (card3 == card4 || card3 == card5) {
        return -6;
    } else if (card4 == card5) {
        return -6;
    }


    // Convert hand numbers to card numbers
    int card1Card, card2Card, card3Card, card4Card, card5Card;
    if (players[currentPlayer]->getPlayerRole() == HACKER) {
        if (card1 < 1 || card1 > players[currentPlayer]->getPlayerCards().size() ||
            card2 < 1 || card2 > players[currentPlayer]->getPlayerCards().size() ||
            card3 < 1 || card3 > players[currentPlayer]->getPlayerCards().size() ||
            card4 < 1 || card4 > players[currentPlayer]->getPlayerCards().size()) {
            return -4;
        }
        card1Card = players[currentPlayer]->getPlayerCards()[card1 - 1];
        card2Card = players[currentPlayer]->getPlayerCards()[card2 - 1];
        card3Card = players[currentPlayer]->getPlayerCards()[card3 - 1];
        card4Card = players[currentPlayer]->getPlayerCards()[card4 - 1];
    } else {
        if (card1 < 1 || card1 > players[currentPlayer]->getPlayerCards().size() ||
            card2 < 1 || card2 > players[currentPlayer]->getPlayerCards().size() ||
            card3 < 1 || card3 > players[currentPlayer]->getPlayerCards().size() ||
            card4 < 1 || card4 > players[currentPlayer]->getPlayerCards().size() ||
            card5 < 1 || card5 > players[currentPlayer]->getPlayerCards().size()) {
            return -4;
        }
        card1Card = players[currentPlayer]->getPlayerCards()[card1 - 1];
        card2Card = players[currentPlayer]->getPlayerCards()[card2 - 1];
        card3Card = players[currentPlayer]->getPlayerCards()[card3 - 1];
        card4Card = players[currentPlayer]->getPlayerCards()[card4 - 1];
        card5Card = players[currentPlayer]->getPlayerCards()[card5 - 1];
    }

	// Need memeNumber to update Board class
    int memeNumber = -1;

    std::string card1Section, card2Section, card3Section, card4Section, card5Section;
    card1Section = returnLocSection(card1Card);
    card2Section = returnLocSection(card2Card);
    card3Section = returnLocSection(card3Card);
    card4Section = returnLocSection(card4Card);
    card5Section = returnLocSection(card5Card);

    if (players[currentPlayer]->getPlayerRole() == HACKER) {
    	// Check that player has the specified cards in their hand
	    if (!players[currentPlayer]->holdsNCards(card1Card, 1) ||
	    	!players[currentPlayer]->holdsNCards(card2Card, 1) ||
	    	!players[currentPlayer]->holdsNCards(card3Card, 1) ||
	    	!players[currentPlayer]->holdsNCards(card4Card, 1)) {
            return -4;
        }

	    // Check that all specified cards are from the same section
        if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == "&") {
            memeNumber = 0;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == "$") {
            memeNumber = 1;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == "#") {
            memeNumber = 2;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == "@") {
            memeNumber = 3;
        } else {
            return -1;
        }
    } else {
        // Check that player has the specified cards in their hand
        if (!players[currentPlayer]->holdsNCards(card1Card, 1) ||
            !players[currentPlayer]->holdsNCards(card2Card, 1) ||
            !players[currentPlayer]->holdsNCards(card3Card, 1) ||
            !players[currentPlayer]->holdsNCards(card4Card, 1) ||
            !players[currentPlayer]->holdsNCards(card5Card, 1)) {
            return -4;
        }

    	// Check that all specified cards are from the same section
        if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == card5Section &&
            card5Section == "&") {
            memeNumber = 0;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == card5Section &&
            card5Section == "$") {
            memeNumber = 1;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == card5Section &&
            card5Section == "#") {
            memeNumber = 2;
        } else if (card1Section == card2Section && card2Section == card3Section &&
            card3Section == card4Section && card4Section == card5Section &&
            card5Section == "@") {
            memeNumber = 3;
        } else {
            return -1;
        }
    }

	// Add cure to Board class
    if (board.getCure(memeNumber)) {
        return -3;
    }

    // Discard cards and add filter for meme
    if (players[currentPlayer]->getPlayerRole() == HACKER) {
        players[currentPlayer]->removeNCards(card1Card, 1);
        players[currentPlayer]->removeNCards(card2Card, 1);
        players[currentPlayer]->removeNCards(card3Card, 1);
        players[currentPlayer]->removeNCards(card4Card, 1);
        discardPile.push_back(card1Card);
        discardPile.push_back(card2Card);
        discardPile.push_back(card3Card);
        discardPile.push_back(card4Card);
    } else {
        players[currentPlayer]->removeNCards(card1Card, 1);
        players[currentPlayer]->removeNCards(card2Card, 1);
        players[currentPlayer]->removeNCards(card3Card, 1);
        players[currentPlayer]->removeNCards(card4Card, 1);
        players[currentPlayer]->removeNCards(card5Card, 1);
        discardPile.push_back(card1Card);
        discardPile.push_back(card2Card);
        discardPile.push_back(card3Card);
        discardPile.push_back(card4Card);
        discardPile.push_back(card5Card);
    }
	board.addCure(memeNumber);
    setActionsRemaining(--actionsRemaining);
	return 1;
}
int GameStateManager::buildCMCServer() {
	// Check if player has actions remaining
	if (actionsRemaining <= 0)
		return 0;
	// Check if CMC exists at the location
	if (board.getLocation(players[currentPlayer]->getPlayerLocation()).cmcServer == true) {
		return -1;
	}
	// Check if max CMCs already exist
	int CMCCount = 0;
	for (int i = 0; i < 24; i++) {
		if (board.getLocation(i).cmcServer == true)
			CMCCount++;
	}
	if (CMCCount >= 6)
		return -2;
	// Check if player holding the current location card
	if (!(players[currentPlayer]->holdsNCards(players[currentPlayer]->getPlayerLocation(), 1))
            && players[currentPlayer]->getPlayerRole() != MEMESTUDIESPROFESSOR) {
		return -3;
	}
	// Otherwise player can build a CMC!
	board.addCMC(players[currentPlayer]->getPlayerLocation());
    if (players[currentPlayer]->getPlayerRole() != MEMESTUDIESPROFESSOR) {
        players[currentPlayer]->removeNCards(players[currentPlayer]->getPlayerLocation(), 1);
    }
	setActionsRemaining(--actionsRemaining);
	return 1;


	/*
	// if six CMC stations already exist, set remove = true and removeLocation = location of CMC to remove
	bool removeCMC = false;
	int removeLocation = NULL;
	// Build CMC server at the player's current location in the Board class
	board.addCMC(players[currentPlayer]->getPlayerLocation());
	if (removeCMC) {
		board.removeCMC(removeLocation);
	}

	return 0;
	*/
}
int GameStateManager::playCard(int card) {
	return 0;
}
int GameStateManager::shareCard(int direction, int card, int otherPlayer) {
	// Check for actions
	if (actionsRemaining <= 0) return 0;

	// If could not find player referenced in trade request
	if (otherPlayer == currentPlayer || otherPlayer < 0 || otherPlayer >= players.size())
		return -1;
	// If location differs
	if (players[currentPlayer]->getPlayerLocation() !=
		players[otherPlayer]->getPlayerLocation()) {
		return -3;
	}

	// Giving
	if (direction == 1) {
		// Check for valid card
		if (card < 0 || card >= players[currentPlayer]->getPlayerCards().size()) {
			return -2;
		}

        // If player is not a millenial, ensure the card being shared is
        // for the current location
        if (players[currentPlayer]->getPlayerRole() != MILLENIAL &&
            players[currentPlayer]->getPlayerCards()[card] !=
            players[currentPlayer]->getPlayerLocation()) {
            return -5;
        }

		// Transfer card ownership to otherPlayer
        if (players[otherPlayer]->getPlayerCards().size() < 7) {
    		players[otherPlayer]->addCard(players[currentPlayer]->getPlayerCards()[card]);
    		players[currentPlayer]->removeCardAtIndex(card);
            setActionsRemaining(--actionsRemaining);
            return 1;
        } else {
            return -4;
        }
	}
	// Taking
	else if (direction == -1) {
		// Check for valid card
		if (card < 0 || card >= players[otherPlayer]->getPlayerCards().size()) {
			return -2;
		}

        // If player is not a millenial, ensure the card being shared is
        // for the current location
        if (players[currentPlayer]->getPlayerRole() != MILLENIAL &&
            players[otherPlayer]->getPlayerCards()[card] !=
            players[otherPlayer]->getPlayerLocation()) {
            return -5;
        }

		// Transfer card ownership to currentPlayer
        if (players[currentPlayer]->getPlayerCards().size() < 7) {
    		players[currentPlayer]->addCard(players[otherPlayer]->getPlayerCards()[card]);
    		players[otherPlayer]->removeCardAtIndex(card);
            setActionsRemaining(--actionsRemaining);
    		return 1;
        } else {
            return -4;
        }
	}

	return -100;
}
int GameStateManager::drawCards() {
    int playerHandSize = players[currentPlayer] -> getPlayerCards().size();

	if (playerHasDrawn) {
		return -3;
	//} else if (playerHandSize == 7) {
	//    return -1;
	//} else if (playerHandSize >= 8) {
	//	  return -2;
	} else if (playerHandSize == 6) {
		return -1;
	} else if (playerHandSize >= 7) {
		return -2;
    } else if (cards.size() < 2) {
        endGame();
    } else if (cards.size() <= 0) {
        std::cout << "Error: no cards remaining" << std::endl;
        return -1;
    /*} else if (cards.size() == 1 || playerHandSize == 7) { // Add one card to player's deck
        playerHasDrawn = 1;
        int card = cards.back();
        if (card != 29) {
            players[currentPlayer] -> addCard(card);
        } else {
            epidemicCard();
        }
        cards.pop_back();
        board.updatePlayerCardCount(cards.size());
		return 2;*/
    } else { // Add two cards to player's deck
        playerHasDrawn = 1;
        int card = cards.back();
        if (card != 29) {
            players[currentPlayer] -> addCard(card);
        } else {
            epidemicCard();
        }
        cards.pop_back();
        card = cards.back();
        if (card != 29) {
            players[currentPlayer] -> addCard(card);
        } else {
            epidemicCard();
        }
        cards.pop_back();
        board.updatePlayerCardCount(cards.size());
        return 1;
    }
	return 0;
}
int GameStateManager::epidemicCard() {
	std::cout << "\nYou drew an epidemic card!" << std::endl;

	setViralQuotient(++viralQuotient);

	//int card = infectionCards.back();
	//infectionCards.pop_back();
	//std::string color = returnLocSection(card);
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 23);
	int infectionLoc = distr(eng);
	std::string color = returnLocSection(infectionLoc);
	int meme;

	std::cout << "The epidemic will infect " + convertIntToCard(infectionLoc) + "!\n";
	std::cout << "Type any command to continue..." << std::endl;

	std::cin.ignore();
	std::cin.ignore();

	if (color == "&") {
		meme = 0;
	} else if (color == "$") {
		meme = 1;
	} else if (color == "#") {
     	meme = 2;
    } else if (color == "@") {
		meme = 3;
    }
	if (board.getCure(meme) != 2) {
		infect(infectionLoc, meme, 3);
		std::vector<int> vec = {infectionLoc};
		incrementInfect(infectionLoc, vec, meme, 0);
		auto rng = std::default_random_engine {};
        std::shuffle(std::begin(infectionCards), std::end(infectionCards), rng);
	}
	return 0;
}
int GameStateManager::discardCard(int card1, int card2) {
    int maxSize = players[currentPlayer] -> getPlayerCards().size();
    if (card1 < 1 || (card2 != -1 && card2 < 1) || card1 > maxSize || card2 > maxSize) {
        // Out of bounds
        return -1;
    }
    if (card2 == -1) { // Only 1 card to discard
        discardPile.push_back(players[currentPlayer] -> removeCardAtIndex(card1 - 1));
    } else if (card1 > card2) { // Discard card with greater index first
        discardPile.push_back(players[currentPlayer] -> removeCardAtIndex(card1 - 1));
        discardPile.push_back(players[currentPlayer] -> removeCardAtIndex(card2 - 1));
    } else {
        discardPile.push_back(players[currentPlayer] -> removeCardAtIndex(card2 - 1));
        discardPile.push_back(players[currentPlayer] -> removeCardAtIndex(card1 - 1));
    }
	return 1;
}
std::string GameStateManager::printPlayerRoles() {
	return "";
}
std::string GameStateManager::printPlayerLocations() {
	return "";
}
std::string GameStateManager::printPlayerCards(std::string playerName) {
	std::string output;
	if (playerName == "") { // If no player is specified, view current player's cards
		for (int i = 0; i < players[currentPlayer] -> getPlayerCards().size(); i++) {
			output.append("Card " + std::to_string(i + 1) + ": " +
					convertIntToCard(players[currentPlayer] -> getPlayerCards()[i]) + " - " +
                    returnLocSection(players[currentPlayer] -> getPlayerCards()[i]) + '\n');
		}
	} else { // View specified player's cards
        int playerNum = atoi(playerName.c_str()) - 1;
        if (playerNum < 0 || playerNum > players.size() - 1) {
            return "INVALIDPLAYER";
        }
		for (int i = 0; i < players[playerNum] -> getPlayerCards().size(); i++) {
			output.append("Card " + std::to_string(i + 1) + ": " +
					convertIntToCard(players[playerNum] -> getPlayerCards()[i]) + " - " +
                    returnLocSection(players[playerNum] -> getPlayerCards()[i]) + '\n');
		}
	}

	return output;
}
std::string GameStateManager::printCMCLocations() {
	return "";
}
int GameStateManager::updateBoard() {

	// updateBoard() not needed by Board class

	return 0;
}
int GameStateManager::autoSave(std::string filename = "autosave.txt") {
	if (saveGame(filename) == 0)
		return 0;
	else return -1;
}

int GameStateManager::incrementInfect(int loca, std::vector<int> &track, int meme, int outbreakTrackIncremented) {
	//returns 1 if the track counter has been incremented this turn, 0 if not
	//check if the location has already been infected this cycle
	for(int i = 0; i < track.size()-1; i++)
	{
		if(loca == track[i] && track.size() != 1)
			return 1;
	}
	std::vector<int> firewallLocations;
	for (Player * player : players) {
		if (player->getPlayerRole() == FIREWALL) {
			std::vector<int> newLocations = locations.getAdjacentLocations(player->getPlayerLocation());
			for (int loc : newLocations) {
				firewallLocations.push_back(loc);
			}
			firewallLocations.push_back(player->getPlayerLocation());
		}
	}
	for (int loc : firewallLocations) {
		if (loca == loc) {
			return 0;
		}
	}
	//determine which meme to use based on the origin of this infection cycle
	switch(track[0]){
		case TUMBLR:
		case IFUNNY:
		case NINEGAG:
		case IMGUR:
		case FOURCHAN:
			meme = 0;
			break;
		case BUZZFEED:
		case YOUTUBE:
		case TWITCH:
		case REDDIT:
		case STEAM:
		case DISCORD:
			meme = 1;
			break;
		case MYSPACE:
		case FACEBOOK:
		case VINE:
		case TWITTER:
		case PINTEREST:
		case SNAPCHAT:
		case INSTAGRAM:
			meme = 2;
			break;
		case EMAIL:
		case WECHAT:
		case WHATSAPP:
		case WEIBO:
		case QQ:
		case VK:
			meme = 3;
			break;
		default:
			break;	
	}
	//if the current location's meme count is below 3, add 1 to the location's counter
	if(board.getLocation(loca).memes[meme] < 3)
	{
		infect(loca, meme, 1);
	}
	else
	{
		//if the location is at 3, then recursively call this function on the adjacent locations
		std::vector<int> adja = locations.getAdjacentLocations(loca);
		if(outbreakTrackIncremented == 0){
			setOutbreakTrack(getOutbreakTrack() + 1);
		}
		for(int i = 0; i < adja.size(); i++)
		{
			track.push_back(adja[i]);
			incrementInfect(adja[i], track, meme, 1);
		}
		return 1;
	}
	return 0;
}

// At the end of a player's turn, the current player must draw two cards
// i they have not already drawn, and if necessary, must discard one
// or two cards
int GameStateManager::endTurn() {
	if (playerHasDrawn == 0) {
        int result = drawCards();
        if (result == 1) {
            announcement = "Drew 2 cards.\n";
        }
		return result;
	}
	return 0;
}

int GameStateManager::nextTurn() {
    playerHasDrawn = 0;
    actionsRemaining = 4;
	setActionsRemaining(4);
	currentPlayer++;
	currentPlayer %= players.size();

	// Perhaps print board with each new turn? board->printBoard();

	//spread memes number of viral quotient
	//create the random device engine and stuff
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0,23);
	int outbroke = 0;
	int quotients[7] = {2,2,2,3,3,4,4};
	for(int x = 0; x < quotients[viralQuotient]; x++)
	{
		//choose the location
		int loca = distr(eng);

		bool message = true;
		std::vector<int> firewallLocations;
		for (Player * player : players) {
			if (player->getPlayerRole() == FIREWALL) {
				std::vector<int> newLocations = locations.getAdjacentLocations(player->getPlayerLocation());
				for (int loc : newLocations) {
					firewallLocations.push_back(loc);
				}
				firewallLocations.push_back(player->getPlayerLocation());
			}
		}
		for (int loc : firewallLocations) {
			if (loca == loc) {
				message = false;
			}
		}
		if (message == true) {
			announcement += "Initial infection location: " + convertIntToCard(loca) + "\n";
		}

		std::vector<int> locas;
		locas.push_back(loca);
		int meme = 0;
		outbroke = incrementInfect(loca, locas, meme, outbroke);
	}
	return 1;
}
int GameStateManager::initialInfection() {
	//create each spawning area
	int area1[5] = {TUMBLR, IFUNNY, NINEGAG, IMGUR, FOURCHAN};
	int area2[6] = {BUZZFEED, YOUTUBE, TWITCH, REDDIT, STEAM, DISCORD};
	int area3[7] = {MYSPACE, FACEBOOK, VINE, TWITTER, PINTEREST, SNAPCHAT, INSTAGRAM};
	int area4[6] = {EMAIL, WECHAT, WHATSAPP, WEIBO, QQ, VK};

	//setup randomization
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 1000000);
	//place level 3 meme infections in each area
	int randomNum = (distr(eng) % 5);
	infect(area1[randomNum], 0, 3);
	//remove chosen value, ignore final value;
	area1[randomNum] = area1[4];

	//place level 2 meme
	randomNum = (distr(eng) % 4);
	infect(area1[randomNum], 0, 2);
	//remove value, ignore final 2
	area1[randomNum] = area1[3];

	//place level 1 meme
	randomNum = (distr(eng) % 3);
	infect(area1[randomNum], 0, 1);

	//move on to infecting area 2
	randomNum = (distr(eng) % 6);
	infect(area2[randomNum], 1, 3);
	//remove value, ignore final value
	area2[randomNum] = area2[5];

	//place level 2 meme
	randomNum = (distr(eng) % 5);
	infect(area2[randomNum], 1, 2);
	//remove value, ignore final 2 values
	area2[randomNum] = area2[4];

	//place level 1 meme
	randomNum = (distr(eng) % 4);
	infect(area2[randomNum], 1, 1);

	//move on to infecting area3
	randomNum = (distr(eng) % 7);
	infect(area3[randomNum], 2, 3);
	//remove value, ignore final value
	area3[randomNum] = area3[6];

	//place level 2 meme
	randomNum = (distr(eng) % 6);
	infect(area3[randomNum], 2, 2);
	//remove value, ignore final 2 values
	area3[randomNum] = area3[5];

	//place level 1 meme
	randomNum = (distr(eng) % 5);
	infect(area3[randomNum], 2, 1);

	//move on to infection of area4
	randomNum = (distr(eng) % 6);
	infect(area4[randomNum], 3, 3);
	//remove value, ignore final value
	area4[randomNum] = area4[5];

	//place level 2 meme
	randomNum = (distr(eng) % 5);
	infect(area4[randomNum], 3, 2);
	//remove value, ignore final 2 values
	area4[randomNum] = area4[4];

	//place level 1 meme
	randomNum = (distr(eng) % 5);
	infect(area4[randomNum], 3, 1);
	return 0;
}
int GameStateManager::infect(int location, int meme, int count) {
	std::vector<int> firewallLocations;
	for (Player * player : players) {
		if (player->getPlayerRole() == FIREWALL) {
			std::vector<int> newLocations = locations.getAdjacentLocations(player->getPlayerLocation());
			for (int loc : newLocations) {
				firewallLocations.push_back(loc);
			}
			firewallLocations.push_back(player->getPlayerLocation());
		}
	}
	for (int loc : firewallLocations) {
		if (location == loc) {
			return 0;
		}
	}
	// Decrements number of cubes available for that meme
	// If it's less than 0 than game lost
	cubesLeft[meme] = cubesLeft[meme] - count;
	if (cubesLeft[meme] < 4) { 
		std::string warning = "Warning: Meme ";
		warning += meme + 49;
		warning += " is spreading dangerously!\n";
		announcement += warning;
	}
	if (cubesLeft[meme] < 0) {
		endGame();
	}
	// Add count number of meme cubes of the given meme to the given location in the Board class
	board.addMemeCubes(location, meme, count);
	// If outbreak occurs, use < board->addOutbreak(); >

	return 0;
}
int GameStateManager::getMemeStatus(int memeNumber) {
	return board.getCure(memeNumber);
}
int GameStateManager::getOutbreakTrack() {
	return outbreakTrack;
}
int GameStateManager::getViralQuotient() {
	return viralQuotient;
}
Board& GameStateManager::getBoard() {
	return board;
}

Player& GameStateManager::getCurrentPlayer() {
	return getPlayer(currentPlayer);
}

int GameStateManager::getCurrentPlayerNumber() {
	return currentPlayer;
}

Player& GameStateManager::getPlayer(int index) {
	return *(players[index]);
}
std::vector<Player*> GameStateManager::getPlayers() {
    return players;
}
int GameStateManager::getActionsRemaining() {
	return actionsRemaining;
}

int GameStateManager::setMemeStatus(int meme, int filtered) {
	if (filtered == 1)
		board.addCure(meme);
	else if (filtered == 2)
		board.setCure(meme, filtered);
	return 0;
}
int GameStateManager::setOutbreakTrack(int value) {
	outbreakTrack = value;
	board.setOutbreakTrack(value);
	endGame();
	return 0;
}
int GameStateManager::setViralQuotient(int value) {
	viralQuotient = value;
	board.setViralQuotient(value);
	return 0;
}
int GameStateManager::setActionsRemaining(int value) {
	actionsRemaining = value;
	board.setActionsRemaining(value);
	return 0;
}

void GameStateManager::queueCardInDeck(int value) {
	cards.push_back(value);
}

int GameStateManager::saveGame(std::string filename) {
	std::fstream fs(filename, std::fstream::out);
	// totalPlayers
	fs << players.size() << std::endl;
	// Location,memeLevel,memeLevel,memeLevel,memeLevel,hasCMC x24
	for (int i = 0; i < 24; i++) {
		fs << i << "," << board.getLocation(i).memes[0] << "," <<
			board.getLocation(i).memes[1] << "," <<
			board.getLocation(i).memes[2] << "," <<
			board.getLocation(i).memes[3] << "," <<
			board.getLocation(i).cmcServer << std::endl;
	}
	// PlayerDeckCardsRemaining,Card,Card,Card,...
	fs << cards.size() << ",";
	for (int i = 0; cards.size() != 0 && i < cards.size()-1; i++) {
		fs << cards[i] << ",";
	}
	fs << cards[cards.size() - 1] << std::endl;

	// outbreakTrack
	fs << outbreakTrack << std::endl;
	// viralQuotient
	fs << viralQuotient << std::endl;
	// memeStatus,memeStatus,memeStatus,memeStatus
	fs << board.getCure(0) << "," << board.getCure(1) << "," <<
		board.getCure(2) << "," << board.getCure(3) << std::endl;
	// playerNumber,name,role,currentLocation,totalCardsHeld,card,... xPlayers
	for (int i = 0; i < players.size(); i++) {
		fs << i << "," << players[i]->getPlayerName() << "," <<
			players[i]->getPlayerRole() << "," << players[i]->getPlayerLocation() <<
			"," << players[i]->getPlayerCards().size();
		if (players[i]->getPlayerCards().size() != 0)
			fs << ",";
		for (int j = 0; players[i]->getPlayerCards().size() != 0 && j < players[i]->getPlayerCards().size() - 1; j++) {
			fs << players[i]->getPlayerCards()[j] << ",";
		}
        if (players[i]->getPlayerCards().size() != 0) {
            fs << players[i]->getPlayerCards()[players[i]->getPlayerCards().size() - 1];
        }
		fs << std::endl;
	}
	// currentPlayer,actionsRemaining
	fs << currentPlayer << "," << actionsRemaining << std::endl;
	
	fs.flush();
	fs.close();
	std::cout << "Game saved.\n";
	return 1;
}
int GameStateManager::loadGame(std::string filename) {
	// Begin loading from chosen file
	std::fstream fs(filename, std::fstream::in);
	std::string line; // current line in save file
	std::string elem; // current comma separated item
	std::vector<std::string> tokens;

	// First line is the number of players
	int numberOfPlayers = 0;
	std::getline(fs, line);
	if (line.length() != 1)
		return -1;
	numberOfPlayers = atoi(line.c_str());
	if (numberOfPlayers < 1 || numberOfPlayers > 4)
		return -1;

	setupPlayers(numberOfPlayers, true);

	// Next 24 lines are each location
	for (int i = 0; i < 24; i++) {
		std::getline(fs, line);
		std::stringstream ss(line);
		// Split line by commas
		while (getline(ss, elem, ',')) {
			tokens.push_back(elem);
		}
		// Set the meme serverity of the site
		if (tokens.size() != 6)
			return -1;
		int levels[4] = {
			atoi(tokens[1].c_str()), atoi(tokens[2].c_str()),
			atoi(tokens[3].c_str()), atoi(tokens[4].c_str())
		};
		getBoard().setMemes(atoi(tokens[0].c_str()), levels);
		getBoard().setCMCServer(atoi(tokens[0].c_str()),
			atoi(tokens[5].c_str()));
		tokens.clear();
	}
	// Next line is player deck
	//gsm.d
	std::getline(fs, line);
	std::stringstream ss(line);
	while (getline(ss, elem, ',')) {
		tokens.push_back(elem);
	}
	for (int i = 1; i < atoi(tokens[0].c_str()) + 1; i++) {
		queueCardInDeck(atoi(tokens[i].c_str()));
	}
	tokens.clear();

	// Next two lines are outbreak track and viral quotient
	std::getline(fs, line);
	if (line.length() != 1)
		return -1;
	else {
		int outbreak = atoi(line.c_str());
		if (outbreak < 0 || outbreak > 8)
			return -1;
		setOutbreakTrack(outbreak);
	}
	std::getline(fs, line);
	if (line.length() != 1)
		return -1;
	else {
		int viralQuotient = atoi(line.c_str());
		if (viralQuotient < 0 || viralQuotient > 8)
			return -1;
		setViralQuotient(viralQuotient);
	}

	// Next line is the 4 meme statuses
	std::getline(fs, line);
	std::stringstream ss2(line);
	// Split line by commas
	while (getline(ss2, elem, ',')) {
		tokens.push_back(elem);
	}
	if (tokens.size() != 4)
		return -1;
	for (int i = 0; i < 4; i++) {
		setMemeStatus(i, atoi(tokens[i].c_str()));
	}
	tokens.clear();
	// Last player# of lines details things about the players
	for (int i = 0; i < numberOfPlayers; i++) {
		std::getline(fs, line);
		std::stringstream ss3(line);
		// Split line by commas
		while (getline(ss3, elem, ',')) {
			tokens.push_back(elem);
		}
		Player& p = getPlayer(atoi(tokens[0].c_str()));
		p.setPlayerName(tokens[1]);
		p.setPlayerRole((PlayerRoles)atoi(tokens[2].c_str()));
		p.setPlayerLocation(atoi(tokens[3].c_str()));
		for (int j = 0; j < atoi(tokens[4].c_str()); j++) {
			p.addCard(atoi(tokens[5 + j].c_str()));
		}
		tokens.clear();
	}



	fs.close();
	return 1;
}


int GameStateManager::endGame() {
	std::cout << "in end game" << std::endl;
	bool won = false;
	for (int i = 0; i < 4; i++) {
		if (board.getCure(i) == 0) {
			won = false;
			break;
		}
		won = true;
	}
	if (won) {
		system("cls||clear");
		board.printBoard();
		std::cout << "You Win!" << std::endl;
		std::cout << "Type any command to return to the main menu..." << std::endl;
		std::cin.ignore();
		mainMenu();
		return 0;
	}

	if (outbreakTrack == 8) {
		system("cls||clear");
		board.printBoard();
		std::cout << "The outbreak tracker reached 8! You Lose!" << std::endl;
		gameEnd = true;
	} else if (cards.size() < 2) {
		system("cls||clear");
		board.printBoard();
		std::cout << "The player card pile reached 0! You lose!" << std::endl;
		gameEnd = true;
	} else {
		//checks cubesLeft array to see if there are any cubes left for a meme
		//if not then the game is lost
		for (int i = 0; i < 4; i++) {
			if (cubesLeft[i] < 0) {
				system("cls||clear");
				board.printBoard();
				std::cout << "Meme cubes for meme " << i + 1 << " ran out! You lose!" << std::endl;
				gameEnd = true;
                break;
			}
		}
	}

	if (gameEnd) {
		std::cout << "Type any command to return to the main menu..." << std::endl;
		std::cin.ignore();
		mainMenu();
	}
	return 0;
}

std::string GameStateManager::convertIntToCard(int intCard) {
	switch (intCard) {
		case 0:
			return "9GAG";
		case 1:
			return "iFunny";
		case 2:
			return "Imgur";
		case 3:
			return "4chan";
		case 4:
			return "Reddit";
		case 5:
			return "Discord";
		case 6:
			return "Steam";
		case 7:
			return "Twitch";
		case 8:
			return "YouTube";
		case 9:
			return "Vine";
		case 10:
			return "Snapchat";
		case 11:
			return "Instagram";
		case 12:
			return "Pinterest";
		case 13:
			return "Twitter";
		case 14:
			return "Facebook";
		case 15:
			return "Buzzfeed";
		case 16:
			return "Tumblr";
		case 17:
			return "Myspace";
		case 18:
			return "Email";
		case 19:
			return "WhatsApp";
		case 20:
			return "WeChat";
		case 21:
			return "Weibo";
		case 22:
			return "QQ";
		case 23:
			return "VK";
		case 24:
			return "Serious Discussion";
		case 25:
			return "Power Outage";
		case 26:
			return "Meme Forecast";
		case 27:
			return "VPN";
		case 28:
			return "Government Grant";
		case 29:
			return "Epidemic";
		default:
			return "";
	}
}

std::string GameStateManager::returnLocSection(int loc) {
    if (loc == 16 || loc == 1 || loc == 0 || loc == 2 || loc == 3) {
        return "&";
    } else if (loc == 15 || loc == 8 || loc == 7 || loc == 4 || loc == 6 || loc == 5) {
        return "$";
    } else if (loc == 17 || loc == 14 || loc == 9 || loc == 13 || loc == 12 || loc == 10 || loc == 11) {
        return "#";
    } else if (loc == 18 || loc == 20 || loc == 19 || loc == 21 || loc == 22 || loc == 23) {
        return "@";
    } else {
        return "";
    }
}

bool GameStateManager::locationHasPlayer(int loc) {
    for (int i = 0; i < players.size(); i++) {
        if (players[i] -> getPlayerLocation() == loc) {
            return true;
        }
    }
    return false;
}