﻿#include "Board.h"
#include <string>
#include <iostream>
#include <vector>

/**
	Two Player Constructor
*/
Board::Board(char p1Role[3], char p2Role[3]) {
	outbreakCounter = 2;
	cures[4] = { false };
	playerCards = 59;

	playerRoles[0] = p1Role;
	playerRoles[1] = p2Role;

	initializeLocations();

	locations[18].players[0] = true;
	locations[18].players[1] = true;

	locations[18].cmcServer = true;
}

/**
	Three Player Constructor
*/
Board::Board(char p1Role[3], char p2Role[3], char p3Role[3]) {
	outbreakCounter = 2;
	cures[4] = { false };
	playerCards = 59;

	playerRoles[0] = p1Role;
	playerRoles[1] = p2Role;
	playerRoles[2] = p3Role;

	initializeLocations();

	locations[18].players[0] = true;
	locations[18].players[1] = true;
	locations[18].players[2] = true;

	locations[18].cmcServer = true;
}

/**
	Four Player Constructor
*/
Board::Board(char p1Role[3], char p2Role[3], char p3Role[3], char p4Role[3]) {
	outbreakCounter = 2;
	cures[4] = { false };
	playerCards = 59;

	playerRoles[0] = p1Role;
	playerRoles[1] = p2Role;
	playerRoles[2] = p3Role;
	playerRoles[3] = p4Role;

	initializeLocations();

	locations[18].players[0] = true;
	locations[18].players[1] = true;
	locations[18].players[2] = true;
	locations[18].players[3] = true;

	locations[18].cmcServer = true;
}

/**
	TODO: Destructor
*/
Board::~Board() {
	
}

/**
	Initializes the vector of locations
*/
void Board::initializeLocations() {
	for (int i = 0; i < 24; i++) {
		locations.push_back(BoardLocation());
	}
}

/**
	Adds a meme cube to the given location
*/
void Board::addMemeCube(int loc, int meme) {
	locations[loc].memes[meme] = locations[loc].memes[meme] + 1;
}

/**
	Removes a meme cube from the given location
*/
void Board::removeMemeCube(int loc, int meme) {
	locations[loc].memes[meme] = locations[loc].memes[meme] - 1;
}

/**
	Creates a CMC Server at the given location
*/
void Board::addCMC(int loc) {
	locations[loc].cmcServer = true;
}

/**
	Removes the CMC Server from the given location
*/
void Board::removeCMC(int loc) {
	locations[loc].cmcServer = false;
}

/**
	Changes the boolean for whether a player is at a given location from true to false at the
	old location, and from false to true at the new location
*/
void Board::movePlayer(int loc, int player) {
	for (int i = 0; i < 24; i++) {
		if (locations[i].players[player]) {
			locations[i].players[player] = false;
		}
	}
	locations[loc].players[player] = true;
}

/**
	Increases the outbreak counter by one
*/
void Board::addOutbreak() {
	outbreakCounter++;
}

/**
	Sets the boolean for the given cure to true
*/
void Board::addCure(int meme) {
	cures[meme] = true;
}

/**
	Reduces the player cards counter by one
*/
void Board::removePlayerCard() {
	playerCards--;
}

/**
	Main function for printing the contents of the board to the command line
*/
void Board::printBoard() {
	/*
	Example print out of the game board:

	std::cout << "┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐\n";
	std::cout << "│  Tumbler  │  │  iFunny   │  │   9GAG    │  │   Imgur   │  │   4chan   │\n";
	std::cout << "│1 2 3 4 CMC│  │           ├--┤           ├--┤           ├--┤           │\n";
	std::cout << "│HA RO FI ME│  │           │  │           │  │           │  │           │\n";
	std::cout << "└─────┬─────┘\ └─────┬─────┘ /└───────────┘  └───────────┘\ └─────┬─────┘\n";
	std::cout << "      |      \\      |      //                            \\      |      \n";
	std::cout << "┌─────┴─────┐ \┌─────┴─────┐/ ┌───────────┐  ┌───────────┐ \┌─────┴─────┐\n";
	std::cout << "│  Myspace  │  │ BuzzFeed  │  │  Youtube  │  │  Twitch   │  │  Reddit   │\n";
	std::cout << "│           │  │           ├--┤           ├--┤           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└───────────┘\ └─────┬─────┘  └─────┬─────┘  └─────┬─────┘\ └───────────┘\n";
	std::cout << "             \\      |              |              |      \\             \n";
	std::cout << "┌───────────┐ \┌─────┴─────┐  ┌─────┴─────┐  ┌─────┴─────┐ \┌───────────┐\n";
	std::cout << "│   Email   │  │ Facebook  │  │   Vine    │  │   Steam   │  │  Discord  │\n";
	std::cout << "│           ├--┤           │  │           │  │           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└───────────┘\ └─────┬─────┘\ └─────┬─────┘\ └───────────┘  └───────────┘\n";
	std::cout << "             \\      |      \\      |      \\                            \n";
	std::cout << "┌───────────┐ \┌─────┴─────┐ \┌─────┴─────┐ \┌───────────┐  ┌───────────┐\n";
	std::cout << "│  WeChat   │  │ WhatsApp  │  │  Twitter  │  │ Pinterest │  │ Snapchat  │\n";
	std::cout << "│           ├--┤           │  │           ├--┤           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└─────┬─────┘\ └─────┬─────┘\ └───────────┘  └─────┬─────┘ /└───────────┘\n";
	std::cout << "      |      \\      |      \\                     |      //             \n";
	std::cout << "┌─────┴─────┐ \┌─────┴─────┐ \┌───────────┐  ┌─────┴─────┐/              \n";
	std::cout << "│   Weibo   │  │    QQ     │  │    VK     │  │ Instagram │ Outbreaks: 2/8\n";
	std::cout << "│           ├--┤           ├--┤           │  │           │ Cures: C C C C\n";
	std::cout << "│           │  │           │  │           │  │           │ P-Cards: 14/59\n";
	std::cout << "└───────────┘  └───────────┘  └───────────┘  └───────────┘               \n";
	*/

	// First row of locations
	std::cout << "┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐\n";
	std::cout << "│  Tumbler  │  │  iFunny   │  │   9GAG    │  │   Imgur   │  │   4chan   │\n";
	
	std::cout << "│";
	printCounters(16);
	printCMC(16);
	std::cout << "│  │";
	printCounters(1);
	printCMC(1);
	std::cout << "├--┤";
	printCounters(0);
	printCMC(0);
	std::cout << "├--┤";
	printCounters(2);
	printCMC(2);
	std::cout << "├--┤";
	printCounters(3);
	printCMC(3);
	std::cout << "│\n";

	std::cout << "│";
	printPlayers(16);
	std::cout << "│  │";
	printPlayers(1);
	std::cout << "│  │";
	printPlayers(0);
	std::cout << "│  │";
	printPlayers(2);
	std::cout << "│  │";
	printPlayers(3);
	std::cout << "│\n";

	std::cout << "└─────┬─────┘\ └─────┬─────┘ /└───────────┘  └───────────┘\ └─────┬─────┘\n";
	std::cout << "      |      \\      |      //                            \\      |      \n";
	
	// Second row of locations
	std::cout << "┌─────┴─────┐ \\┌─────┴─────┐/ ┌───────────┐  ┌───────────┐ \\┌─────┴─────┐\n";
	std::cout << "│  Myspace  │  │ BuzzFeed  │  │  Youtube  │  │  Twitch   │  │  Reddit   │\n";

	std::cout << "│";
	printCounters(17);
	printCMC(17);
	std::cout << "│  │";
	printCounters(15);
	printCMC(15);
	std::cout << "├--┤";
	printCounters(8);
	printCMC(8);
	std::cout << "├--┤";
	printCounters(7);
	printCMC(7);
	std::cout << "├--┤";
	printCounters(4);
	printCMC(4);
	std::cout << "│\n";

	std::cout << "│";
	printPlayers(17);
	std::cout << "│  │";
	printPlayers(15);
	std::cout << "│  │";
	printPlayers(8);
	std::cout << "│  │";
	printPlayers(7);
	std::cout << "│  │";
	printPlayers(4);
	std::cout << "│\n";

	std::cout << "└───────────┘\ └─────┬─────┘  └─────┬─────┘  └─────┬─────┘\ └───────────┘\n";
	std::cout << "             \\      |              |              |      \\             \n";
	
	// Third row of locations
	std::cout << "┌───────────┐ \\┌─────┴─────┐  ┌─────┴─────┐  ┌─────┴─────┐ \\┌───────────┐\n";
	std::cout << "│   Email   │  │ Facebook  │  │   Vine    │  │   Steam   │  │  Discord  │\n";

	std::cout << "│";
	printCounters(18);
	printCMC(18);
	std::cout << "├--┤";
	printCounters(14);
	printCMC(14);
	std::cout << "│  │";
	printCounters(9);
	printCMC(9);
	std::cout << "│  │";
	printCounters(6);
	printCMC(6);
	std::cout << "├--┤";
	printCounters(5);
	printCMC(5);
	std::cout << "│\n";

	std::cout << "│";
	printPlayers(18);
	std::cout << "│  │";
	printPlayers(14);
	std::cout << "│  │";
	printPlayers(9);
	std::cout << "│  │";
	printPlayers(6);
	std::cout << "│  │";
	printPlayers(5);
	std::cout << "│\n";

	std::cout << "└───────────┘\ └─────┬─────┘\ └─────┬─────┘\ └───────────┘  └───────────┘\n";
	std::cout << "             \\      |      \\      |      \\                            \n";
	
	// Fourth row of locations
	std::cout << "┌───────────┐ \\┌─────┴─────┐ \\┌─────┴─────┐ \\┌───────────┐  ┌───────────┐\n";
	std::cout << "│  WeChat   │  │ WhatsApp  │  │  Twitter  │  │ Pinterest │  │ Snapchat  │\n";

	std::cout << "│";
	printCounters(20);
	printCMC(20);
	std::cout << "├--┤";
	printCounters(19);
	printCMC(19);
	std::cout << "│  │";
	printCounters(13);
	printCMC(13);
	std::cout << "├--┤";
	printCounters(12);
	printCMC(12);
	std::cout << "├--┤";
	printCounters(10);
	printCMC(10);
	std::cout << "│\n";

	std::cout << "│";
	printPlayers(20);
	std::cout << "│  │";
	printPlayers(19);
	std::cout << "│  │";
	printPlayers(13);
	std::cout << "│  │";
	printPlayers(12);
	std::cout << "│  │";
	printPlayers(10);
	std::cout << "│\n";

	std::cout << "└─────┬─────┘\ └─────┬─────┘\ └───────────┘  └─────┬─────┘ /└───────────┘\n";
	std::cout << "      |      \\      |      \\                     |      //             \n";
	
	// Fifth row of locations
	std::cout << "┌─────┴─────┐ \\┌─────┴─────┐ \\┌───────────┐  ┌─────┴─────┐/              \n";
	std::cout << "│   Weibo   │  │    QQ     │  │    VK     │  │ Instagram │ ";

	printOutbreaks();
	std::cout << "\n";

	std::cout << "│";
	printCounters(21);
	printCMC(21);
	std::cout << "├--┤";
	printCounters(22);
	printCMC(22);
	std::cout << "├--┤";
	printCounters(23);
	printCMC(23);
	std::cout << "│  │";
	printCounters(11);
	printCMC(11);
	std::cout << "│ ";
	printCures();
	std::cout << "\n";

	std::cout << "│";
	printPlayers(21);
	std::cout << "│  │";
	printPlayers(22);
	std::cout << "│  │";
	printPlayers(23);
	std::cout << "│  │";
	printPlayers(11);
	std::cout << "│ ";
	printPlayerCards();
	std::cout << "\n";
	
	std::cout << "└───────────┘  └───────────┘  └───────────┘  └───────────┘               \n";
}

/**
	Prints the meme counters for the given location to the command line.  If the meme counter
	is zero for the given meme, prints an empty space
*/
void Board::printCounters(int loc) {
	for (int i = 0; i < 4; i++) {
		if (locations[loc].memes[i]) {
			std::cout << locations[loc].memes[i];
		}
		else {
			std::cout << " ";
		}
		std::cout << " ";
	}
}

/**
	If the given location has a CMC counter, prints CMC to the command line, else
	prints empty spaces
*/
void Board::printCMC(int loc) {
	if (locations[loc].cmcServer) {
		std::cout << "CMC";
	}
	else {
		std::cout << "   ";
	}
}

/**
	If there is/are player(s) at the given location, prints which players are at the
	location to the command line.  Else, prints empty spaces
*/
void Board::printPlayers(int loc) {
	for (int i = 0; i < 4; i++) {
		if (locations[loc].players[i]) {
			std::cout << playerRoles[i];
		}
		else {
			std::cout << "  ";
		}
		if (i != 3) {
			std::cout << " ";
		}
	}
}

/**
	Prints the outbreak counter to the command line
*/
void Board::printOutbreaks() {
	std::cout << "Outbreaks: " << outbreakCounter << "/8";
}

void Board::printCures() {
	std::cout << "Cures: ";
	for (int i = 0; i < 4; i++) {
		if (cures[i]) {
			std::cout << "C";
		}
		else {
			std::cout << " ";
		}
		if (i != 3) {
			std::cout << " ";
		}
	}
}

/**
	Prints the number of remaining player card to the command line
*/
void Board::printPlayerCards() {
	std::cout << "P-Cards: " << playerCards << "/59";
}