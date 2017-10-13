#include "GameStateManager.h"
#include <cstdlib>
#include <iostream>
#include <random>

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
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
    actionsRemaining = 4;
    setupDeck();
	initialInfection();
}
void GameStateManager::setupPlayers(int numPlayers) {
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
        for (int j = 0; j < numCardsToDraw; j++) {
            p -> addCard(cards.back());
            cards.pop_back();
        }

		players.push_back(p);
	}

    // Insert Epidemic cards
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, cards.size());
    for (int i = 0; i < 6; i++) {
        cards.insert(cards.begin() + distr(eng), 29);
    }
    board.updatePlayerCardCount(cards.size());
}

void GameStateManager::setupDeck() {
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
	delete &board;
	while (players.size() > 0)
		delete players[0];
	
}

int GameStateManager::movePlayer(int location) {
	// Make sure player has actions left in their turn
	if (actionsRemaining <= 0) {
		return 0;
	}
	// Check if adjacent location
	if (locations.isAdjacent(players[currentPlayer]->getPlayerLocation(), location)) {
		// Update player location in the Board class
		board.movePlayer(location, currentPlayer);
		players[currentPlayer]->setPlayerLocation((CardNames)location);
		std::cout << players[currentPlayer]->getPlayerLocation() << std::endl;
		actionsRemaining--;
		return 1;
	}
	// Or if player holding the card for the destination
	else if (players[currentPlayer]->holdsNCards(location, 1)) {
		players[currentPlayer]->removeNCards(location, 1);
		players[currentPlayer]->setPlayerLocation(location);
		board.movePlayer(location, currentPlayer);
		actionsRemaining--;
		return 1;
	}
	// Or if the player is holding the current location
	else if (players[currentPlayer]->holdsNCards(players[currentPlayer]->getPlayerLocation(), 1)) {
		players[currentPlayer]->removeNCards(players[currentPlayer]->getPlayerLocation(), 1);
		players[currentPlayer]->setPlayerLocation(location);
		board.movePlayer(location, currentPlayer);
		actionsRemaining--;
		return 1;
	}
	// Or if at a CMC server and moving to a CMC server
	else if (board.getLocation(location).cmcServer == true &&
		board.getLocation(players[currentPlayer]->getPlayerLocation()).cmcServer == true) {
		board.movePlayer(location, currentPlayer);
		players[currentPlayer]->setPlayerLocation(location);
		actionsRemaining--;
		return 1;
	}
	else return -1;
}

int GameStateManager::banMeme(int memeNumber) {
	if (board.getCure(memeNumber == 2)) {
		return 0;
	}
	else if (board.getCure(memeNumber) == 1) {
		int numberOfRemainingCubes = board.getLocation(players[currentPlayer]->getPlayerLocation()).memes[memeNumber];
		if (numberOfRemainingCubes == 0) {
			return 0;
		}
		else {
			for (int i = 0; i < numberOfRemainingCubes; i++) {
				board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
			}
			locations.setMemeStatus(players[currentPlayer]->getPlayerLocation(), memeNumber, 0);

			for (int i = 0; i < 24; i++) {
				if (locations.getMemeStatus(players[currentPlayer]->getPlayerLocation())[memeNumber] != 0) {
					break;
				}
				if (i == 23) {
					board.eradicateMeme(memeNumber);
				}
			}

			return 1;
		}
	}
	else {
		int numberOfRemainingCubes = board.getLocation(players[currentPlayer]->getPlayerLocation()).memes[memeNumber];
		if (numberOfRemainingCubes == 0) {
			return 0;
		}
		else {
			board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
			locations.setMemeStatus(players[currentPlayer]->getPlayerLocation(), memeNumber, locations.getMemeStatus(players[currentPlayer]->getPlayerLocation())[memeNumber] - 1);
			return 1;
		}
	}
}
int GameStateManager::developMemeFilter(int card1, int card2, int card3, 
	int card4, int card5) {
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

	// Need memeNumber to update Board class
	int memeNumber = NULL;
	// Add cure to Board class
	board.addCure(memeNumber);

	return 0;
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
	if (!(players[currentPlayer]->holdsNCards(players[currentPlayer]->getPlayerLocation(), 1))) {
		return -3;
	}
	// Otherwise player can build a CMC!
	board.addCMC(players[currentPlayer]->getPlayerLocation());
	players[currentPlayer]->removeNCards(players[currentPlayer]->getPlayerLocation(), 1);
	actionsRemaining--;
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
int GameStateManager::shareCard(int card, std::string playerName) {
	return 0;
}
int GameStateManager::drawCards() {
    int playerHandSize = players[currentPlayer] -> getPlayerCards().size();
    if (playerHandSize == 7) {
        return -1;
    } else if (playerHandSize >= 8) {
        return -2;
    } else if (cards.size() <= 0) {
        std::cout << "Error: no cards remaining" << std::endl;
        return -1;
    } else if (cards.size() == 1 || playerHandSize == 6) { // Add one card to player's deck
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        board.updatePlayerCardCount(cards.size());
		return 2;
    } else { // Add two cards to player's deck
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        board.updatePlayerCardCount(cards.size());
        return 1;
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
        int i;
        for (i = 0; i < players[currentPlayer] -> getPlayerCards().size(); i++) {
            output.append("Card " + std::to_string(i + 1) + ": " +
                    convertIntToCard(players[currentPlayer] -> getPlayerCards()[i]) + '\n');
        }
    } else { // View specified player's cards
        // TODO
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
int GameStateManager::autoSave() {
	if (saveGame() == 0)
		return 0;
	else return -1;
}
int GameStateManager::nextTurn() {
    actionsRemaining = 4;
	currentPlayer++;
	currentPlayer %= players.size();

	// Perhaps print board with each new turn? board->printBoard();

	return 1;
}
int GameStateManager::initialInfection() {
	//create each spawning area
	int area1[5] = {TUMBLR, IFUNNY, NINEGAG, IMGUR, FOURCHAN};
	int area2[6] = {BUZZFEED, YOUTUBE, TWITCH, REDDIT, STEAM, DISCORD};
	int area3[7] = {MYSPACE, FACEBOOK, VINE, TWITTER, PINTEREST, SNAPCHAT, INSTAGRAM};
	int area4[6] = {EMAIL, WECHAT, WHATSAPP, WEIBO, QQ, VK};

	//place level 3 meme infections in each area
	int randomNum = (rand() % 5);
	infect(area1[randomNum], 0, 3);
	//remove chosen value, ignore final value;
	area1[randomNum] = area1[4];

	//place level 2 meme
	randomNum = (rand() % 4);
	infect(area1[randomNum], 0, 2);
	//remove value, ignore final 2
	area1[randomNum] = area1[3];
	
	//place level 1 meme
	randomNum = (rand() % 3);
	infect(area1[randomNum], 0, 1);
	
	//move on to infecting area 2
	randomNum = (rand() % 6);
	infect(area2[randomNum], 1, 3);
	//remove value, ignore final value
	area2[randomNum] = area2[5];

	//place level 2 meme
	randomNum = (rand() % 5);
	infect(area2[randomNum], 1, 2);
	//remove value, ignore final 2 values
	area2[randomNum] = area2[4];

	//place level 1 meme
	randomNum = (rand() % 4);
	infect(area2[randomNum], 1, 1);

	//move on to infecting area3
	randomNum = (rand() % 7);
	infect(area3[randomNum], 2, 3);
	//remove value, ignore final value
	area3[randomNum] = area3[6];

	//place level 2 meme
	randomNum = (rand() % 6);
	infect(area3[randomNum], 2, 2);
	//remove value, ignore final 2 values
	area3[randomNum] = area3[5];

	//place level 1 meme
	randomNum = (rand() % 5);
	infect(area3[randomNum], 2, 1);
	
	//move on to infection of area4
	randomNum = (rand() % 6);
	infect(area4[randomNum], 3, 3);
	//remove value, ignore final value
	area4[randomNum] = area4[5];

	//place level 2 meme
	randomNum = (rand() % 5);
	infect(area4[randomNum], 3, 2);
	//remove value, ignore final 2 values
	area4[randomNum] = area4[4];
	
	//place level 1 meme
	randomNum = (rand() % 5);
	infect(area4[randomNum], 3, 1);
}
int GameStateManager::infect(int location, int meme, int count) {


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
Player& GameStateManager::getPlayer(int index) {
	return *(players[index]);
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
	return 0;
}
int GameStateManager::setViralQuotient(int value) {
	viralQuotient = value;
	return 0;
}
int GameStateManager::setActionsRemaining(int value) {
	actionsRemaining = value;
	return 0;
}

int GameStateManager::saveGame() {
	std::string filename = "save.txt";
	std::fstream fs(filename);
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
	fs << std::endl;
	// MemeDeckCardsRemaining,Card,Card,Card,...
	fs << std::endl;
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
			"," << std::endl;
	}
	// currentPlayer,actionsRemaining
	fs << currentPlayer << "," << actionsRemaining << "," << std::endl;
	
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
