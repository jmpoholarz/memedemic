#include "GameStateManager.h"

GameStateManager::GameStateManager() {
	// Placeholder default constructor\

	// Create a new board
	board = new Board();
	// Add players to a vector
	for (int i = 0; i < 1; i++) {
		Player* p = new Player();
		players.push_back(p);
	}
	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}

GameStateManager::GameStateManager(int numPlayers) {
	// Create a new board
	board = new Board();
	// Add players to a vector
	for (int i = 0; i < numPlayers; i++) {
		Player* p = new Player();
		players.push_back(p);
	}
	// Initialize variables 
	outbreakTrack = 8;
	viralQuotient = 8;
	currentPlayer = 0;
}

GameStateManager::~GameStateManager() {
	delete board;
	for each (Player* p in players) {
		delete p;
	}
}

int GameStateManager::movePlayer(int location) {
	// Check if location is a valid move for the player
	
	return 0;
}

int GameStateManager::banMeme(int memeNumber) {
	return 0;
}
int GameStateManager::developMemeFilter(int memeNumber) {
	return 0;
}
int GameStateManager::buildCMCServer() {
	return 0;
}
int GameStateManager::playCard(int card) {
	return 0;
}
int GameStateManager::shareCard(int card, std::string playerName) {
	return 0;
}
int GameStateManager::drawCards() {
	return 0;
}
int GameStateManager::printPlayerRoles() {
	return 0;
}
int GameStateManager::printPlayerLocations() {
	return 0;
}
int GameStateManager::printPlayerCards(int player) {
	return 0;
}
int GameStateManager::printCMCLocations() {
	return 0;
}
int GameStateManager::updateBoard() {
	return 0;
}
int GameStateManager::autoSave() {
	return 0;
}
int GameStateManager::nextTurn() {
	return 0;
}
int GameStateManager::initialInfection() {
	return 0;
}
int GameStateManager::infect(int location, int meme, int count) {
	return 0;
}