#include "GameStateManager.h"

GameStateManager::GameStateManager() {
	// Placeholder default constructor\

	// Add players to a vector
	for (int i = 0; i < 1; i++) {
		Player* p = new Player();
		players.push_back(p);
	}

	// Create a new board
	board = new Board(players[0]->getPlayerRole());
	// Create a new location
	locations = new Location();

	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}

GameStateManager::GameStateManager(int numPlayers) {
	// Add players to a vector
	for (int i = 0; i < numPlayers; i++) {
		Player* p = new Player();
		players.push_back(p);
	}

	// Create a new board.  Constructor depends on number of players and player roles.
	switch (numPlayers) {
	case 1 :
		board = new Board(players[0]->getPlayerRole());
		break;
	case 2 :
		board = new Board(players[0]->getPlayerRole(), players[1]->getPlayerRole());
		break;
	case 3 :
		board = new Board(players[0]->getPlayerRole(), players[1]->getPlayerRole(),
						  players[2]->getPlayerRole());
		break;
	default :
		board = new Board(players[0]->getPlayerRole(), players[1]->getPlayerRole(),
						  players[2]->getPlayerRole(), players[3]->getPlayerRole());
		break;
	}

	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}

GameStateManager::~GameStateManager() {
	delete board;
	while (players.size() > 0)
		delete players[0];
	}
}

int GameStateManager::movePlayer(int location) {
	// Check if location is a valid move for the player
	if (locations->isAdjacent(players[currentPlayer]->getPlayerLocation(), location)) {
		// Update player location in the Board class
		board->movePlayer(location, currentPlayer);
		return 1;
	}

	else return 0;
}

int GameStateManager::banMeme(int memeNumber) {


	// Update meme cube in the Board class
	board->removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);

	return 0;
}
int GameStateManager::developMemeFilter(int card1, int card2, int card3, 
	int card4, int card5) {
	// Note: card5 might be empty


	// Need memeNumber to update Board class
	int memeNumber = NULL;
	// Add cure to Board class
	board->addCure(memeNumber);

	return 0;
}
int GameStateManager::buildCMCServer() {



	// if six CMC stations already exist, set remove = true and removeLocation = location of CMC to remove
	bool removeCMC = false;
	int removeLocation = NULL;
	// Build CMC server at the player's current location in the Board class
	board->addCMC(players[currentPlayer]->getPlayerLocation());
	if (removeCMC) {
		board->removeCMC(removeLocation);
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



	// Reduce number of player cards in Board class by two
	board->removePlayerCard();
	board->removePlayerCard();

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


	// Perhaps print board with each new turn? board->printBoard();

	return 0;
}
int GameStateManager::initialInfection() {
	return 0;
}
int GameStateManager::infect(int location, int meme, int count) {


	// Add count number of meme cubes of the given meme to the given location in the Board class
	board->addMemeCubes(location, meme, count);
	// If outbreak occurs, use < board->addOutbreak(); >

	return 0;
}
int GameStateManager::getMemeStatus(int memeNumber) {
	return board->getCure(memeNumber);
}
int GameStateManager::getOutbreakTrack() {
	return outbreakTrack;
}
int GameStateManager::getViralQuotient() {
	return viralQuotient;
}
Board& GameStateManager::getBoard() {
	return *board;
}
int GameStateManager::getActionsRemaining() {
	return actionsRemaining;
}

int GameStateManager::setMemeStatus(int meme, bool filtered) {
	if (filtered)
		board->addCure(meme);
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