#include "Parser.h"

Parser::Parser(GameStateManager& g) : gsm(g) {
}

Parser::~Parser() {

}

std::string Parser::parse(std::string command) {
	// Create a stringstream to read through the command
	std::stringstream ss(command); 
	// Temp string to store each "word" of the command
	std::string str = "";
	// Create a vector to hold parts of the command
	std::vector<std::string> tokens;
	// Split based on spaces
	while (std::getline(ss, str, ' ')) {
		
		if (1){ //str != " ") {
			// Make all characters lowercase
			for (int i = 0; i < str.length(); i++) {
				str[i] = std::tolower(str[i]);
			}
			tokens.push_back(str);
		}
	}
	if (tokens.empty()) {
		return "Empty line";
	}

	// At this point, we have our vector of words to deal with
	if (tokens[0] == "usage") {
		if (tokens[1] != "") 
			return "Incorrect usage of access: " + getUsage("access");
		else return getUsage(tokens[1]);
	}
	else if (tokens[0] == "access") {
		// Check for wrong number of arguments
		if (tokens.size() != 2)
			return "Incorrect usage of access: " + getUsage("access");
		// Get location number from enum
		int location = convertCard(tokens[1]);
		// Check if valid location
		if (!(location >= 0 && location <= 23)) {
			return "Invalid location: " + getUsage("access");
		}

		// Attempt to move player
		int successful = gsm.movePlayer(location);
		if (successful == 1)
			return "Moved to " + tokens[1];
		else if (successful == -1) {
			// Location non-adjacent and no held card
			return "You cannot move to " + tokens[1] + 
				" unless you:\n1. Hold its card\n2. Are adjacent\n" +
				"3.It is the location of a CMC server, and" +
				" you are at a CMC server";
		}
		else return "Unable to move to " + tokens[1];
	}
	else if (tokens[0] == "build") {
		// Check for wrong number of arguments
		if (tokens.size() != 1) {
			return "Incorrect usage of build: " + getUsage("build");
		}
		// Attempt to build
		int successful = gsm.buildCMCServer();
		if (successful == 1)
			return "Built CMC Server.";
		else if (successful == -1) {
			// CMC Server Present
			return "There is already a CMC Server at this location.";
		}
		else if (successful == -2) {
			// Hit max CMC Servers allowed
			return "You have built the maximum CMC Servers possible already.";
		}
		else if (successful == -3) {
			// Not holding location card
			return "You must hold this location's card to build a CMC Server.";
		}
		else return "Unable to build CMC Server.";
	}
	else if (tokens[0] == "ban") {
		// Check for wrong number of arguments
		if (tokens.size() != 2) {
			return "Incorrect usage of ban: " + getUsage("ban");
		}
		// Attempt to ban disease
		int whichMeme = atoi(tokens[1].c_str());
		int successful = gsm.banMeme(whichMeme);
		if (successful == 1)
			return "Banned meme " + tokens[1] + " from current location.";
		else if (successful == -1) {
			// Meme already filtered - doesn't exist on map anymore
			return "Meme " + tokens[1] + " has already been filtered.";
		}
		else if (successful == -2) {
			// Meme not at current location
			return "Meme " + tokens[1] + " was not present in this location.";
		}
		else return "Unable to ban meme " + tokens[1] + " from current location.";
	}
	else if (tokens[0] == "give") {
		// Check for wrong number of arguments
		if (tokens.size() != 3) {
			return "Incorrect usage of give: " + getUsage("give");
		}
		// Attempt to give card
		int card = convertCard(tokens[1]);
		/// TODO
		return "";
	}
	else if (tokens[0] == "take") {
		// Check for wrong number of arguments
		if (tokens.size() != 3) {
			return "Incorrect usage of give: " + getUsage("take");
		}
		// Attempt to take card
		int card = convertCard(tokens[1]);
		/// TODO
		return "";
	}
	else if (tokens[0] == "filter") {
		// Check for wrong number of arguments
		if (tokens.size() != 6 && tokens.size() != 5) {
			return "Incorrect usage of filter: " + getUsage("filter");
		}
		// Convert card strings to usable integer values
		int card1, card2, card3, card4, card5 = -1;
		card1 = atoi(tokens[1].c_str());
		card2 = atoi(tokens[2].c_str());
		card3 = atoi(tokens[3].c_str());
		card4 = atoi(tokens[4].c_str());
		if (tokens.size() == 6)
			card5 = atoi(tokens[5].c_str());
		int successful = gsm.developMemeFilter(card1, card2, card3, card4, card5);
			
		if (successful == 1) {
			return "Successfully developed a meme filter!";
		}
		else if (successful == -1) {
			// Cards don't all match
			return "Cards must all be from the same region to develop a filter.";
		}
		else if (successful == -2) {
			// Only provided 5 cards when not the role that allows that
			return "Not enough cards provided.";
		}
		else if (successful == -3) {
			// Trying to filter a meme that has already been filtered
			return "There is already a filter for that meme.";
		}
		else if (successful == -4) {
			// Numbers don't match cards in hand
			return "You must select cards in your hand.";
		}
		else if (successful == -5) {
			// Not at a CMC Server
			return "You must be at a CMC Server to develop a filter.";
		}
		else return "Unable to develop meme filter.";
	}
	else if (tokens[0] == "event") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of event: " + getUsage("event");
		}
		// Attempt to play card
		int card = convertCard(tokens[1]);

		/// TODO
		return "";
	}
	else if (tokens[0] == "outbreak") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of outbreak: " + getUsage("outbreak");
		}
		// Try to print outbreak track
		return 0;
	}
	else if (tokens[0] == "viral") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of viral: " + getUsage("viral");
		}
		// Try to print viral quotient
		return 0;
	}
	else if (tokens[0] == "meme") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of meme: " + getUsage("meme");
		}
		// Attempt to print meme status
		return 0;
	}
	else if (tokens[0] == "players") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of players: " + getUsage("players");
		}
		// Try to print players
		return gsm.printPlayerLocations();
	}
	else if (tokens[0] == "roles") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of roles: " + getUsage("roles");
		}
		// Try to print player roles
		return gsm.printPlayerRoles();
	}
	else if (tokens[0] == "cmc") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of cmc: " + getUsage("cmc");
		}

		/// TODO
		return "";
	}
	else if (tokens[0] == "servers") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of servers: " + getUsage("servers");
		}

		/// TODO
		return "";
	}
	else if (tokens[0] == "draw") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of draw: " + getUsage("draw");
		}
		// Try to draw cards
		int successful = gsm.drawCards();
		if (successful == 1)
			return "Drew two cards.";
		else if (successful == 2)
			return "Drew one card.";
		else if (successful == -1) {
			// 1 too many cards in hand
			return "Holding too many cards.  Please discard one.";
		}
		else if (successful == -2) {
			// 2 too many cards in hand
			return "Holding too many cards.  Please discard two.";
		}
	}
	else if (tokens[0] == "discard") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of discard: " + getUsage("discard");
		}
		// Attempt to discard
		int card1, card2 = -1;
		if (tokens.size() == 3)
			card2 = atoi(tokens[2].c_str());
		card1 = atoi(tokens[1].c_str());
		int successful = gsm.discardCard(card1, card2);
		if (successful == 1) {
			return "Successfully discarded.";
		}
		else if (successful == -1) {
			return "Invalid cards for discard.";
		}
		else if (successful == -2) {
			return "Cannot discard an event card.";
		}
		else if (successful == -3) {
			return "Cannot discard the same card multiple times.";
		}
		else return "Could not discard card(s).";
	}
	else if (tokens[0] == "cards") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 1) {
			return "Incorrect usage of cards: " + getUsage("cards");
		}
		// Try to print cards
		if (tokens.size() == 1)
			return gsm.printPlayerCards("");
		else return gsm.printPlayerCards(tokens[1]);
	}
	else if (tokens[0] == "end") {
		// Check for wrong number of arguments
		if (tokens.size() != 1 && tokens.size() != 2) {
			return "Incorrect usage of end: " + getUsage("end");
		}
		// Attempt to end turn
		int successful = gsm.nextTurn();
		if (successful == 1)
			return "Proceeding to next turn.";
		else return "Unable to end turn.";
	}
	else if (tokens[0] == "new") {
		// Check for wrong number of arguments
		if (tokens.size() != 1) {
			return "Incorrect usage of new: " + getUsage("new");
		}
		// Attempt to start new game
		return "Starting a new game!";
	}
	else {
		return "Unable to parse command!";
	}
}

int Parser::convertCard(std::string name) {
	if (name == "ninegag" || name == "9gag" || name == "9g" || name == "ng") {
		return NINEGAG;
	}
	else if (name == "ifunny" || name == "if") {
		return IFUNNY;
	}
	else if (name == "imgur" || name == "ig") {
		return IMGUR;
	}
	else if (name == "fourchan" || name == "4chan" || name == "4c"
		|| name == "fc") {
		return FOURCHAN;
	}
	else if (name == "reddit" || name == "red" || name == "re") {
		return REDDIT;
	}
	else if (name == "discord" || name == "dc") {
		return DISCORD;
	}
	else if (name == "steam" || name == "st") {
		return STEAM;
	}
	else if (name == "twitch" || name == "tw") {
		return TWITCH;
	}
	else if (name == "youtube" || name == "yt") {
		return YOUTUBE;
	}
	else if (name == "vine" || name == "vi") {
		return VINE;
	}
	else if (name == "snapchat" || name == "snap" || name == "sc") {
		return SNAPCHAT;
	}
	else if (name == "instagram" || name == "insta" || name == "ig") {
		return INSTAGRAM;
	}
	else if (name == "pinterest" || name == "pin" || name == "pt") {
		return PINTEREST;
	}
	else if (name == "twitter" || name == "t") {
		return TWITTER;
	}
	else if (name == "facebook" || name == "face" || name == "fb") {
		return FACEBOOK;
	}
	else if (name == "buzzfeed" || name == "buzz" || name == "bf") {
		return BUZZFEED;
	}
	else if (name == "tumblr" || name == "tb") {
		return TUMBLR;
	}
	else if (name == "myspace" || name == "ms") {
		return MYSPACE;
	}
	else if (name == "email" || name == "em") {
		return EMAIL;
	}
	else if (name == "whatsapp" || name == "whats" || name == "wa") {
		return WHATSAPP;
	}
	else if (name == "wechat" || name == "wc") {
		return WECHAT;
	}
	else if (name == "weibo" || name == "we") {
		return WEIBO;
	}
	else if (name == "qq") {
		return QQ;
	}
	else if (name == "vk") {
		return VK;
	}
	else if (name == "seriousdiscussion" || name == "serious" || name == "sd") {
		return SERIOUSDISCUSSION;
	}
	else if (name == "poweroutage" || name == "power" || name == "po") {
		return POWEROUTAGE;
	}
	else if (name == "memeforecast" || name == "meme" || name == "mf") {
		return MEMEFORECAST;
	}
	else if (name == "vpn") {
		return VPN;
	}
	else if (name == "governmentgrant" || name == "government"
		|| name == "govt" || name == "gov" || name == "gg" || name == "grant") {
		return GOVERNMENTGRANT;
	}
	else if (name == "epidemic") {
		return EPIDEMIC;
	}
	else return -1;
}

std::string Parser::getUsage(std::string command) {
		if (command == "access") {
			return "access <location>";
		}
		else if (command == "build") {
			return "build";
		}
		else if (command == "ban") {
			return "ban <number of meme>";
		}
		else if (command == "give") {
			return "give <card name> <player name>";
		}
		else if (command == "take") {
			return "take <card name> <player name>";
		}
		else if (command == "filter") {
			return "filter <card1> <card2> <card3> <card4> <card5>";
		}
		else if (command == "event") {
			return "event <card name>";
		}
		else if (command == "outbreak") {
			return "outbreak track";
		}
		else if (command == "viral") {
			return "viral quotient";
		}
		else if (command == "meme") {
			return "meme status";
		}
		else if (command == "roles") {
			return "players roles";
		}
		else if (command == "players") {
			return "players";
		}
		else if (command == "cmc") {
			return "cmc servers";
		}
		else if (command == "servers") {
			return "servers";
		}
		else if (command == "draw") {
			return "draw cards";
		}
		else if (command == "discard") {
			return "discard <card position in hand>";
		}
		else if (command == "cards") {
			return "cards <player name>";
		}
		else if (command == "end") {
			return "end turn";
		}
		else if (command == "new") {
			return "new game";
		}
		else return "No information found on " + command;
}

int Parser::loadSaveFile() {
	std::string filename = "save.txt";
	std::fstream fs(filename);
	std::string line; // current line in save file
	std::string elem; // current comma separated item
	std::vector<std::string> tokens;
	// First 24 lines are each location
	for (int i = 0; i < 24; i++) {
		std::getline(fs, line);
		std::stringstream ss(line);
		// Split line by commas
		while (getline(ss, elem, ',')) {
			tokens.push_back(elem);
		}
		// Set the meme serverity of the site
		int levels[4] = {
			atoi(tokens[1].c_str()), atoi(tokens[2].c_str()),
			atoi(tokens[2].c_str()), atoi(tokens[3].c_str())
		};
		gsm.getBoard().setMemes(atoi(tokens[0].c_str()), levels);
		gsm.getBoard().setCMCServer(atoi(tokens[0].c_str()), 
			atoi(tokens[5].c_str()));
	}


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
