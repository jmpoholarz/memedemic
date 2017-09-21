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
		if (str.length() != 1) {
			// Make all characters lowercase
			for each (char c in str) {
				std::tolower(c);
			}
			tokens.push_back(str);
		}
	}

	// At this point, we have our vector of words to deal with
	if (tokens[0] == "usage") {
		return getUsage(tokens[1]);
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
	}
	else if (tokens[0] == "take") {
		// Check for wrong number of arguments
		if (tokens.size() != 3) {
			return "Incorrect usage of give: " + getUsage("take");
		}
		// Attempt to take card
		int card = convertCard(tokens[1]);
		/// TODO
	}
	else if (tokens[0] == "filter") {
		// Check for wrong number of arguments
		if (tokens.size() != 6 && tokens.size() != 5) {
			return "Incorrect usage of give: " + getUsage("filter");
		}

		/// TODO
	}
	else if (tokens[0] == "event") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of event: " + getUsage("event");
		}
		// Attempt to play card
		int card = convertCard(tokens[1]);

		/// TODO
	}
	else if (tokens[0] == "outbreak") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of outbreak: " + getUsage("outbreak");
		}
		// Try to print outbreak track
		/// TODO
	}
	else if (tokens[0] == "viral") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of viral: " + getUsage("viral");
		}
		// Try to print viral quotient
		/// TODO
	}
	else if (tokens[0] == "meme") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of meme: " + getUsage("meme");
		}
		// Attempt to print meme status
		/// TODO
	}
	else if (tokens[0] == "players") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of players: " + getUsage("players");
		}

		/// TODO
	}
	else if (tokens[0] == "roles") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of roles: " + getUsage("roles");
		}

		/// TODO
	}
	else if (tokens[0] == "cmc") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of cmc: " + getUsage("cmc");
		}

		/// TODO
	}
	else if (tokens[0] == "servers") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of servers: " + getUsage("servers");
		}

		/// TODO
	}
	else if (tokens[0] == "draw") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of draw: " + getUsage("draw");
		}

		/// TODO
	}
	else if (tokens[0] == "discard") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of discard: " + getUsage("discard");
		}

		/// TODO
	}
	else if (tokens[0] == "cards") {
		// Check for wrong number of arguments
		if (tokens.size() != 2) {
			return "Incorrect usage of cards: " + getUsage("cards");
		}

		/// TODO
	}
	else if (tokens[0] == "end") {
		// Check for wrong number of arguments
		if (tokens.size() != 1 && tokens.size() != 2) {
			return "Incorrect usage of end: " + getUsage("end");
		}
		// Attempt to end turn
		bool successful = gsm.nextTurn();
		if (successful) return "Proceeding to next turn.";
		else return "Unable to end turn.";
	}
	else if (tokens[0] == "new") {
		// Check for wrong number of arguments
		if (tokens.size() != 1) {
			return "Incorrect usage of new: " + getUsage("new");
		}
		// Attempt to start new game
		/// TODO
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
}
