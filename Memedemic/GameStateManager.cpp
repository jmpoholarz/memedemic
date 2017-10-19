#include "GameStateManager.h"
#include "Main.h"
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
	viralQuotient = 2;
	currentPlayer = 0;
    actionsRemaining = 4;
    playerHasDrawn = 0; // may need to be stored in save file
    gameEnd = false;
    // Each meme is allocated 12 cubes
    cubesLeft[0] = 12;
    cubesLeft[1] = 12;
    cubesLeft[2] = 12;
    cubesLeft[3] = 12;
	//initialInfection(); // called in Main's game setup to not break loading
    //setupDeck(); // called in Main's game setup to not break loading
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
                    convertIntToCard(players[currentPlayer] -> getPlayerCards()[i]) + '\n';
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
			board.removeMemeCube(players[currentPlayer]->getPlayerLocation(), memeNumber);
			//locations.setMemeStatus(memeNumber, numberOfRemainingCubes - 1,
			//	players[currentPlayer]->getPlayerLocation());
			setActionsRemaining(--actionsRemaining);
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
int GameStateManager::shareCard(int direction, int card, std::string playerName) {
	// Check for actions
	if (actionsRemaining <= 0) return 0;
	int otherPlayer = -1;
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->getPlayerName() == playerName)
			otherPlayer = i;
	}
	// If could not find player referenced in trade request
	if (otherPlayer == -1)
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
		// Transfer card ownership to otherPlayer
		players[otherPlayer]->addCard(players[currentPlayer]->getPlayerCards()[card]);
		players[currentPlayer]->removeCardAtIndex(card);
		return 1;
	}
	// Taking
	else if (direction == -1) {
		// Check for valid card
		if (card < 0 || card >= players[currentPlayer]->getPlayerCards().size()) {
			return -2;
		}
		// Transfer card ownership to currentPlayer
		players[currentPlayer]->addCard(players[otherPlayer]->getPlayerCards()[card]);
		players[otherPlayer]->removeCardAtIndex(card);
		return 1;
	}

	return -100;
}
int GameStateManager::drawCards() {
    int playerHandSize = players[currentPlayer] -> getPlayerCards().size();

    if (playerHasDrawn) {
        return -3;
    } else if (playerHandSize == 7) {
        return -1;
    } else if (playerHandSize >= 8) {
        return -2;
    } else if (cards.size() < 2) {
        endGame();
    } else if (cards.size() <= 0) {
        std::cout << "Error: no cards remaining" << std::endl;
        return -1;
    } else if (cards.size() == 1 || playerHandSize == 6) { // Add one card to player's deck
        playerHasDrawn = 1;
        players[currentPlayer] -> addCard(cards.back());
        cards.pop_back();
        board.updatePlayerCardCount(cards.size());
		return 2;
    } else { // Add two cards to player's deck
        playerHasDrawn = 1;
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
int GameStateManager::autoSave(std::string filename = "autosave.txt") {
	if (saveGame(filename) == 0)
		return 0;
	else return -1;
}

int GameStateManager::incrementInfect(int loca, std::vector<int> track, int meme) {
	//check if the location has already been infected this cycle
	for(int i = 0; i < track.size()-1; i++)
	{
		if(loca == track[i] && track.size() != 1)
			return 1;
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
		for(int i = 0; i < adja.size(); i++)
		{
			setOutbreakTrack(getOutbreakTrack()+1);
			track.push_back(adja[i]);
			incrementInfect(adja[i], track, meme);
			track.pop_back();
		}
	}
	return 1;
}
int GameStateManager::nextTurn() {
    playerHasDrawn = 0;
    actionsRemaining = 4;
	currentPlayer++;
	currentPlayer %= players.size();

	// Perhaps print board with each new turn? board->printBoard();

	//spread memes number of viral quotient
	//create the random device engine and stuff
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0,23);
	for(int x = 0; x < viralQuotient; x++)
	{
		//choose the location
		int loca = distr(eng);
		std::vector<int> locas;
		locas.push_back(loca);
		int meme = 0;
		incrementInfect(loca, locas, meme);
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

	// Decrements number of cubes available for that meme
	// If it's less than 0 than game lost
	cubesLeft[meme]--;
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
	for (int i = 0; i < cards.size()-1; i++) {
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
			"," << players[i]->getPlayerCards().size() << ",";
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

int GameStateManager::endGame() {
	bool won = false;
	for (int i = 0; i < 4; i++) {
		if (board.getCure(i) == 0) {
			won = false;
			break;
		}
		won = true;
	}
	if (won) {
		std::cout << "You Won" << std::endl;
		gameEnd = true;
	}

	if (outbreakTrack == 8 || cards.size() < 2) {
		std::cout << "You Lost" << std::endl;
		std::cout << "Game Over" << std::endl;
		gameEnd = true;
	} else {
		//checks cubesLeft array to see if there are any cubes left for a meme
		//if not then the game is lost
		for (int i = 0; i < 4; i++) {
			if (cubesLeft[i] < 0) {
				std::cout << "Game Over" << std::endl;
                gameEnd = true;
                break;
			}
		}
	}

	if (gameEnd) {
		//TODO go back to mainMenu();
		// This is broken right now, if you try to quit after the main menu shows it goes back to old game board
		//mainMenu();
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

bool GameStateManager::locationHasPlayer(int loc) {
    for (int i = 0; i < players.size(); i++) {
        if (players[i] -> getPlayerLocation() == loc) {
            return true;
        }
    }
    return false;
}
