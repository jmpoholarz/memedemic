#include "Main.h"

int main() {
	std::string startMenuResponse = "";
	int response = 0;
	// Get start menu response
	do {
		// Output start menu
		std::cout << "Memedemic: Please enter 1-3:" << std::endl;
		std::cout << "1. New" << std::endl;
		std::cout << "2. Load" << std::endl;
		std::cout << "3. Quit" << std::endl;
		std::getline(std::cin, startMenuResponse);
	} while (!(startMenuResponse == "1" || startMenuResponse == "2" ||
		startMenuResponse == "3"));
	
	// Perform uniform start-up process
	Board* board = new Board();
	Location* locations = new Location();
	GameStateManager* gsm = new GameStateManager(*board, *locations);
	Parser* parser = new Parser(*gsm);
	Screen* screen = new Screen(*gsm, *parser);

	// Process start menu response
	if (startMenuResponse == "1") {
		setupNewGame(*gsm);
	}
	else if (startMenuResponse == "2") {
		loadGame(*gsm);
	}
	else if (startMenuResponse == "3") {
		// Quit the game
		std::cout << "But if not you, then who will stop the memes.";
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
		std::cout << "?" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		return 0;
	}	
	
	// Now that setup has finished, run the game
	screen->run();
}

int setupNewGame(GameStateManager& gsm) {
	// Start a new game
	int playerCount = 0;
	// Prompt player count
	std::string strPlayers = "";
	do {
		std::cout << "Enter players (1-4): ";
		std::getline(std::cin, strPlayers);
		if (strPlayers.size() == 1 && std::isdigit(strPlayers[0]))
			playerCount = atoi(strPlayers.c_str());
	} while (!(playerCount > 0 && playerCount < 5));
	// Set players at start positions, etc.
	gsm.setupPlayers(playerCount);
	// Prompt player names
	for (int i = 0; i < playerCount; i++) {
		bool isValidName = false;
		std::string playerName = "";
		while (!isValidName) {
			do {
				std::cout << "Enter name of player " << i+1 << ":" << std::endl;
				std::getline(std::cin, playerName);
			} while (playerName.length() == 0);
			// Iterate through characters to check if alphanumeric+space
			isValidName = true;
			for (int i = 0; i < playerName.length(); i++) {
				if (playerName[i] < 32 || playerName[i] > 126)
					isValidName = false;
			}
			if (!isValidName)
				std::cout << "Name contained invalid characters." << std::endl;
		}
		gsm.getPlayer(i).setPlayerName(playerName);
		
	}
	// Prompt player roles
	std::cout << "\nNow select a role from the following (1-6):" << std::endl;
	std::cout << "\t1. The Professor\n";
	std::cout << "\t\t> May build a research station at any time.\n";
	std::cout << "\t\t> May discard a card to move to any city.\n";
	std::cout << "\t2. The H4cker\n";
	std::cout << "\t\t> Needs only 4 cards to develop a meme filter.\n";
	std::cout << "\t3. The Moderator\n";
	std::cout << "\t\t> Removes memes entirely when banning them from a site\n";
	std::cout << "\t\t> Auto-bans filtered memes from visited sites.\n";
	std::cout << "\t4. The Router\n";
	std::cout << "\t\t> May use an action to move another player.\n";
	std::cout << "\t\t> May move a player to another player's location\n";
	std::cout << "\t5. The Firewall\n";
	std::cout << "\t\t> Prevents the spread of memes to the current and adjacent sites\n";
	std::cout << "\t6. The Millenial\n";
	std::cout << "\t\t> When in the same location as another player, may trade held cards\n";

	for (int i = 0; i < playerCount; i++) {
		int roleChoice = 0;
		std::string strRole = "";
		do {
			std::cout << "Player " << i+1 << " - Enter role choice (1-6): ";
			std::getline(std::cin, strRole);
			if (strRole.length() == 1 && std::isdigit(strRole[0]))
				roleChoice = atoi(strRole.c_str());
		} while (!(roleChoice > 0 && roleChoice < 7));
		gsm.getPlayer(i).setPlayerRole(PlayerRoles(roleChoice - 1));
	}

	return 0; // success
}

int loadGame(GameStateManager& gsm) {
	std::string filename = "save.txt";
	std::fstream fs(filename);
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

	gsm.setupPlayers(numberOfPlayers);

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
			atoi(tokens[2].c_str()), atoi(tokens[3].c_str())
		};
		gsm.getBoard().setMemes(atoi(tokens[0].c_str()), levels);
		gsm.getBoard().setCMCServer(atoi(tokens[0].c_str()),
			atoi(tokens[5].c_str()));
		tokens.clear();
	}
	// Next line is player deck
	std::getline(fs, line);
	// Next line is meme deck
	std::getline(fs, line);
	// Next two lines are outbreak track and viral quotient
	std::getline(fs, line);
	if (line.length() != 1)
		return -1;
	else {
		int outbreak = atoi(line.c_str());
		if (outbreak < 0 || outbreak > 8)
			return -1;
		gsm.setOutbreakTrack(outbreak);
	}
	std::getline(fs, line);
	if (line.length() != 1)
		return -1;
	else {
		int viralQuotient = atoi(line.c_str());
		if (viralQuotient < 0 || viralQuotient > 8)
			return -1;
		gsm.setViralQuotient(viralQuotient);
	}

	// Next line is the 4 meme statuses
	std::getline(fs, line);
	std::stringstream ss(line);
	// Split line by commas
	while (getline(ss, elem, ',')) {
		tokens.push_back(elem);
	}
	if (tokens.size() != 4)
		return -1;
	for (int i = 0; i < 4; i++) {
		gsm.setMemeStatus(i, atoi(tokens[i].c_str()));
	}
	// Last player# of lines details things about the players

	return 0;


	/*
	// Create a stringstream to read through the command
	std::stringstream ss(command);
	// Temp string to store each "word" of the command
	std::string str = "";
	// Create a vector to hold parts of the command
	std::vector<std::string> tokens;
	// Split based on spaces
	while (std::getline(ss, str, ' ')) {
	if (1) { //str != " ") {
	// Make all characters lowercase
	for (int i = 0; i < str.length(); i++) {
	str[i] = std::tolower(str[i]);
	}
	tokens.push_back(str);
	}
	}*/
}

