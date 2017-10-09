#include "GameStateManager.h"
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
}
void GameStateManager::setupPlayers(int numPlayers) {
	// Handle setup for players in the board
	board.setupPlayers(numPlayers);
	// Add players to a vector
	for (int i = 0; i < numPlayers; i++) {
		Player* p = new Player("testman", UNASSIGNED, EMAIL);
		players.push_back(p);
	}
	// Add role setup here based on the players roles
	/// TODO
}

void GameStateManager::setupDeck() {
    std::vector<int> values(24, 0);
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 23);
    int i = 0;
    while (i < 24) {
        int randomValue = distr(eng);
        if (values[randomValue] == 1) {
            continue;
        } else {
            cards.push_back(randomValue);
            values[randomValue] = 1;
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
	// Check if location is a valid move for the player
	if (locations.isAdjacent(players[currentPlayer]->getPlayerLocation(), location)) {
        // Make sure player has actions left in their turn
        if (actionsRemaining <= 0) {
            return 0;
        }
		// Update player location in the Board class
		board.movePlayer(location, currentPlayer);
        players[currentPlayer]->setPlayerLocation((CardNames) location);
        std::cout << players[currentPlayer] -> getPlayerLocation() << std::endl;
        actionsRemaining--;
		return 1;
	}

	else return 0;
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



	// if six CMC stations already exist, set remove = true and removeLocation = location of CMC to remove
	bool removeCMC = false;
	int removeLocation = NULL;
	// Build CMC server at the player's current location in the Board class
	board.addCMC(players[currentPlayer]->getPlayerLocation());
	if (removeCMC) {
		board.removeCMC(removeLocation);
	}

	return 0;
}
int GameStateManager::playCard(int card) {
	return 0;
}
int GameStateManager::shareCard(int card, std::string playerName) {
	return 0;
}
int GameStateManager::drawCards() {
    if (cards.size() <= 0) {
        std::cout << "Error: no cards remaining" << std::endl;
        return 1;
    } else if (cards.size() == 1) { // Add one card to player's deck
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        board.removePlayerCard();
    } else { // Add two cards to player's deck
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        board.removePlayerCard();
        board.removePlayerCard();
    }
	return 0;
}
int GameStateManager::discardCard(int card1, int card2) {
	return 0;
}
std::string GameStateManager::printPlayerRoles() {
	return "";
}
std::string GameStateManager::printPlayerLocations() {
	return "";
}
std::string GameStateManager::printPlayerCards(std::string playerName) {
	return "";
}
std::string GameStateManager::printCMCLocations() {
	return "";
}
int GameStateManager::updateBoard() {

	// updateBoard() not needed by Board class

	return 0;
}
int GameStateManager::autoSave() {
	return 0;
}
int GameStateManager::nextTurn() {
    actionsRemaining = 4;
	currentPlayer++;
	currentPlayer %= players.size();

	// Perhaps print board with each new turn? board->printBoard();

	return 1;
}
int GameStateManager::initialInfection() {
	return 0;
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
