#include "Board.h"
#include <string>
#include <iostream>

/**
	One Player Constructor
*/
Board::Board() {
	actionsCounter = 4;
	outbreakCounter = 0;
	viralQuotientCounter = 2;
	cures[0] = 0;
	cures[1] = 0;
	cures[2] = 0;
	cures[3] = 0;
	playerCards = 54;

	initializeLocations();

	locations[18].cmcServer = true;
}

/**
	TODO: Destructor
*/
Board::~Board() {

}

/**
	TODO: Initialize player roles
*/
void Board::setupPlayers(int players) {
	switch (players) {
	case 1:
		playerRoles.push_back("p1");
	case 2:
		playerRoles.push_back("p1");
		playerRoles.push_back("p2");
	case 3:
		playerRoles.push_back("p1");
		playerRoles.push_back("p2");
		playerRoles.push_back("p3");
	default:
		playerRoles.push_back("p1");
		playerRoles.push_back("p2");
		playerRoles.push_back("p3");
		playerRoles.push_back("p4");
		break;
	}
	// Set default player locations
	for (int i = 0; i < players; i++) {
		locations[18].players[i] = true;
	}
}

/**
	Initializes the vector of locations
*/
void Board::initializeLocations() {
	for (int i = 0; i < 24; i++) {
		locations.push_back(BoardLocation());
	}
}

std::string Board::getRoleAbbreviation(PlayerRoles role) {
	switch (role) {
	case MEMESTUDIESPROFESSOR:
		return "ME";
	case HACKER:
		return "HA";
	case MODERATOR:
		return "MO";
	case ROUTER:
		return "RO";
	case FIREWALL:
		return "FI";
	case MILLENIAL:
		return "MI";
	default :
		return "NA";
	}
}

/**
	Adds a meme cube to the given location
*/
void Board::addMemeCubes(int loc, int meme, int count) {
	if (count == 3) {
		locations[loc].memes[meme] = 3;
	} else {
		locations[loc].memes[meme] = locations[loc].memes[meme] + count;
	}
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
	Increases the infection rate counter by one
*/
void Board::increaseViralQuotient() {
	viralQuotientCounter++;
}

/**
	Sets the boolean for the given cure to true
*/
void Board::addCure(int meme) {
	cures[meme] = 1;
}

void Board::setCure(int meme, int value) {
	cures[meme] = value;
}

void Board::eradicateMeme(int meme) {
	cures[meme] = 2;
}

/**
	Updates the player cards counter
*/
void Board::updatePlayerCardCount(int playerCardCount) {
	playerCards = playerCardCount;
}

/**
	Returns the given location.
*/
Board::BoardLocation Board::getLocation(int loc) {
	return locations[loc];
}

/**
	Returns the outbreak counter.
*/
int Board::getOutbreakCounter() {
	return outbreakCounter;
}

/**
	Returns whether the given meme has been cured or not.
*/
int Board::getCure(int meme) {
	return cures[meme];
}

/**
	Returns the player card count.
*/
int Board::getPlayerCards() {
	return playerCards;
}

/**
	Returns the player roles.
*/
std::vector<std::string> Board::getPlayerRoles() {
	return playerRoles;
}

/**
	Main function for printing the contents of the board to the command line
*/
void Board::printBoard() {
	/*
	Example print out of the game board (using old extending Ascii characters):

	std::cout << "┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐  ┌───────────┐\n";
	std::cout << "│  Tumblr   │  │  iFunny   │  │   9GAG    │  │   Imgur   │  │   4chan   │\n";
	std::cout << "│           │  │           ├--┤           ├--┤           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└─────┬─────┘\ └─────┬─────┘ /└───────────┘  └───────────┘\ └─────┬─────┘\n";
	std::cout << "      |      \\      |      //                            \\      |      \n";
	std::cout << "┌─────┴─────┐ \┌─────┴─────┐/ ┌───────────┐  ┌───────────┐ \┌─────┴─────┐\n";
	std::cout << "│  Myspace  │  │ BuzzFeed  │  │  YouTube  │  │  Twitch   │  │  Reddit   │\n";
	std::cout << "│           │  │           ├--┤           ├--┤           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└───────────┘\ └─────┬─────┘  └─────┬─────┘  └─────┬─────┘\ └───────────┘\n";
	std::cout << "             \\      |              |              |      \\             \n";
	std::cout << "┌───────────┐ \┌─────┴─────┐  ┌─────┴─────┐  ┌─────┴─────┐ \┌───────────┐\n";
	std::cout << "│   Email   │  │ Facebook  │  │   Vine    │  │   Steam   │  │  Discord  │\n";
	std::cout << "│1 2 1 3 CMC├--┤           │  │           │  │           ├--┤           │\n";
	std::cout << "│p1 p2 p3 p4│  │           │  │           │  │           │  │           │\n";
	std::cout << "└───────────┘\ └─────┬─────┘\ └─────┬─────┘\ └───────────┘  └───────────┘\n";
	std::cout << "             \\      |      \\      |      \\                            \n";
	std::cout << "┌───────────┐ \┌─────┴─────┐ \┌─────┴─────┐ \┌───────────┐  ┌───────────┐\n";
	std::cout << "│  WeChat   │  │ WhatsApp  │  │  Twitter  │  │ Pinterest │  │ Snapchat  │\n";
	std::cout << "│           ├--┤           │  │           ├--┤           ├--┤           │\n";
	std::cout << "│           │  │           │  │           │  │           │  │           │\n";
	std::cout << "└─────┬─────┘\ └─────┬─────┘\ └───────────┘  └─────┬─────┘ /└───────────┘\n";
	std::cout << "      |      \\      |      \\                     |      //             \n";
	std::cout << "┌─────┴─────┐ \┌─────┴─────┐ \┌───────────┐  ┌─────┴─────┐/              \n";
	std::cout << "│   Weibo   │  │    QQ     │  │    VK     │  │ Instagram │ Cures: C C C C\n";
	std::cout << "│           ├--┤           ├--┤           │  │           │ Outbreaks: 3/8\n";
	std::cout << "│           │  │           │  │           │  │           │ Infect Rate: 2\n";
	std::cout << "└───────────┘  └───────────┘  └───────────┘  └───────────┘ P-Cards: 14/59\n";
	*/

	// First row of locations
	std::cout << "&-----------&  &-----------&  &-----------&  &-----------&  &-----------&\n";
	std::cout << "|  Tumblr   |  |  iFunny   |  |   9GAG    |  |   Imgur   |  |   4chan   |\n";
	std::cout << "|           |  |           |  |           |  |           |  |           |\n";
	std::cout << "|";
	printCounters(16);
	printCMC(16);
	std::cout << "&--&";
	printCounters(1);
	printCMC(1);
	std::cout << "&--&";
	printCounters(0);
	printCMC(0);
	std::cout << "&--&";
	printCounters(2);
	printCMC(2);
	std::cout << "&--&";
	printCounters(3);
	printCMC(3);
	std::cout << "|\n";

	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printPlayers(16);
	std::cout << "|  |";
	printPlayers(1);
	std::cout << "|  |";
	printPlayers(0);
	std::cout << "|  |";
	printPlayers(2);
	std::cout << "|  |";
	printPlayers(3);
	std::cout << "|\n";

	std::cout << "&-----&-----&\\ &-----&-----& /&-----------&  &-----------&\\ &-----&-----&\n";
	std::cout << "      |      \\\\      |      //                            \\\\      |      \n";
	
	// Second row of locations
	std::cout << "#=====#=====# \\$- - -$- - -$/ $- - - - - -$  $- - - - - -$ \\$- - -$- - -$\n";
	std::cout << "|  Myspace  |  | BuzzFeed  |  |  YouTube  |  |  Twitch   |  |  Reddit   |\n";
	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printCounters(17);
	printCMC(17);
	std::cout << "|  |";
	printCounters(15);
	printCMC(15);
	std::cout << "$--$";
	printCounters(8);
	printCMC(8);
	std::cout << "$--$";
	printCounters(7);
	printCMC(7);
	std::cout << "$--$";
	printCounters(4);
	printCMC(4);
	std::cout << "|\n";

	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printPlayers(17);
	std::cout << "|  |";
	printPlayers(15);
	std::cout << "|  |";
	printPlayers(8);
	std::cout << "|  |";
	printPlayers(7);
	std::cout << "|  |";
	printPlayers(4);
	std::cout << "|\n";

	std::cout << "#===========#\\ $- - -$- - -$  $- - -$- - -$  $- - -$- - -$\\ $- - - - - -$\n";
	std::cout << "             \\\\      |              |              |      \\\\             \n";
	
	// Third row of locations
	std::cout << "@-----------@ \\#=====#=====#  #=====#=====#  $- - -$- - -$ \\$- - - - - -$\n";
	std::cout << "|   Email   |  | Facebook  |  |   Vine    |  |   Steam   |  |  Discord  |\n";
	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printCounters(18);
	printCMC(18);
	std::cout << "@--#";
	printCounters(14);
	printCMC(14);
	std::cout << "|  |";
	printCounters(9);
	printCMC(9);
	std::cout << "|  |";
	printCounters(6);
	printCMC(6);
	std::cout << "$--$";
	printCounters(5);
	printCMC(5);
	std::cout << "|\n";

	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printPlayers(18);
	std::cout << "|  |";
	printPlayers(14);
	std::cout << "|  |";
	printPlayers(9);
	std::cout << "|  |";
	printPlayers(6);
	std::cout << "|  |";
	printPlayers(5);
	std::cout << "|\n";

	std::cout << "@-----------@\\ #=====#=====#\\ #=====#=====#\\ $- - - - - -$  $- - - - - -$\n";
	std::cout << "             \\\\      |      \\\\      |      \\\\                            \n";
	
	// Fourth row of locations
	std::cout << "@-----------@ \\@-----@-----@ \\#=====#=====# \\#===========#  #===========#\n";
	std::cout << "|  WeChat   |  | WhatsApp  |  |  Twitter  |  | Pinterest |  | Snapchat  |\n";
	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printCounters(20);
	printCMC(20);
	std::cout << "@--@";
	printCounters(19);
	printCMC(19);
	std::cout << "|  |";
	printCounters(13);
	printCMC(13);
	std::cout << "#--#";
	printCounters(12);
	printCMC(12);
	std::cout << "#--#";
	printCounters(10);
	printCMC(10);
	std::cout << "|\n";

	std::cout << "|           |  |           |  |           |  |           |  |           |\n";

	std::cout << "|";
	printPlayers(20);
	std::cout << "|  |";
	printPlayers(19);
	std::cout << "|  |";
	printPlayers(13);
	std::cout << "|  |";
	printPlayers(12);
	std::cout << "|  |";
	printPlayers(10);
	std::cout << "|\n";

	std::cout << "@-----@-----@\\ @-----@-----@\\ #===========#  #=====#=====# /#===========#\n";
	std::cout << "      |      \\\\      |      \\\\                     |      //             \n";
	
	// Fifth row of locations
	std::cout << "@-----@-----@ \\@-----@-----@ \\@-----------@  #===========#/              \n";
	std::cout << "|   Weibo   |  |    QQ     |  |    VK     |  | Instagram | ";
	printCures();
	std::cout << "\n";

	std::cout << "|           |  |           |  |           |  |           | ";
	printOutbreaks();
	std::cout << "\n";

	std::cout << "|";
	printCounters(21);
	printCMC(21);
	std::cout << "@--@";
	printCounters(22);
	printCMC(22);
	std::cout << "@--@";
	printCounters(23);
	printCMC(23);
	std::cout << "|  |";
	printCounters(11);
	printCMC(11);
	std::cout << "| ";
	printPlayerCards();
	std::cout << "\n";

	std::cout << "|           |  |           |  |           |  |           | ";
	std::cout << " Viral Quote: ";
	std::cout << "\n";

	std::cout << "|";
	printPlayers(21);
	std::cout << "|  |";
	printPlayers(22);
	std::cout << "|  |";
	printPlayers(23);
	std::cout << "|  |";
	printPlayers(11);
	std::cout << "| ";
	printViralQuotient();
	std::cout << "\n";
	
	std::cout << "@-----------@  @-----------@  @-----------@  #===========#               \n";
	std::cout << "                                                           Actions left: " << actionsCounter << "\n";
}

/**
	Prints the meme counters for the given location to the command line.  If the meme counter
	is zero for the given meme, prints an underscore
*/
void Board::printCounters(int loc) {
	for (int i = 0; i < 4; i++) {
		if (locations[loc].memes[i]) {
			std::cout << locations[loc].memes[i];
		}
		else {
			std::cout << "_";
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

void Board::printViralQuotient() {
	std::cout << "Viral Quote: 2" << viralQuotientCounter;
	             //"- - - - - - -"
}

void Board::printCures() {
	std::cout << "Cures: ";
	for (int i = 0; i < 4; i++) {
		if (cures[i] == 1) {
			std::cout << "C";
		}
		else if (cures[i] == 2) {
			std::cout << "E";
		}
		else {
			std::cout << "-";
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
	std::cout << "P-Cards: " << playerCards << "/54";
}

void Board::setCMCServer(int location, bool exists) {
	locations[location].cmcServer = exists;
}
void Board::setMemes(int location, int values[]) {
	for (int i = 0; i < 4; i++)
		locations[location].memes[i] = values[i];
}
void Board::setPlayers(int location, int playerNumber, bool present) {
	locations[location].players[playerNumber] = present;
}
void Board::setActionsRemaining(int value) {
	actionsCounter = value;
}
void Board::setViralQuotient(int value) {
	viralQuotientCounter = value;
}
void Board::setOutbreakTrack(int value) {
	outbreakCounter = value;
}
