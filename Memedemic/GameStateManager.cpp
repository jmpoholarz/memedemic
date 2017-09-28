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
int GameStateManager::developMemeFilter(int card1, int card2, int card3, 
	int card4, int card5) {
	// Note: card5 might be empty
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
int GameStateManager::discardCard(int card1, int card2) {

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
std::string GameStateManager::getMemeStatus() {
	return "";
}
std::string GameStateManager::getOutbreakTrack() {
	return "";
}
std::string GameStateManager::getViralQuotient() {
	return "";
}