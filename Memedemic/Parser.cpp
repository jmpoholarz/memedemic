#include "Parser.h"
#include <iostream>

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
			/*for (int i = 0; i < str.length(); i++) {
				str[i] = std::tolower(str[i]);
			}*/
			tokens.push_back(str);
		}
	}
	if (tokens.empty()) {
		return "Empty line";
	}

	// At this point, we have our vector of words to deal with
	if (tokens[0] == "help") {
		if (tokens.size() == 1) {
			return "Help on the following topics is available:\n"
				"   goal, winning, losing, CMC, roles, epidemic, \n"
				"  outbreak track, viral quotient, meme filter\n"
				"Help for the following commands is available:\n"
				"   usage, access, move, build, ban, give, take, filter,\n "
				"draw, discard, cards, end, save";
		}
		else if (tokens.size() >= 2) {
			if (tokens[1] == "usage") {
				return "Provides instructions on how to use a command.\n";
			}
			else if (tokens[1] == "access") {
				return "Use this to change to another location.\n"
					"You may move to: \n"
					"\t- An adjacent location\n"
					"\t- A location you hold the card of\n"
					"\t- Any location if holding the current location's card\n"
					"\t- A location of a CMC Server if you are at a CMC Server\n"
					"\t- (Professor) Any location by playing any location\n";
			}
			else if (tokens[1] == "move") {
				return "Use this to move a player to another location.\n"
					"You may move the specified player to: \n"
					"\t- An adjacent location\n"
					"\t- A location you hold the card of\n"
					"\t- Any location if holding the current location's card\n"
					"\t- A location of a CMC Server if you are at a CMC Server\n"
					"\t- Any location occupied by another player\n";
			}
			else if (tokens[1] == "build") {
				return "Use this to construct a CMC Server\n"
					"Maximum of 6 allowed. "
					"Allows efficient board movement.\n"
					"\t- Requires the current held card"
					"\t- (Professor) No card required\n";
			}
			else if (tokens[1] == "ban") {
				return "Use this to decrease the quantity of a meme in a site\n"
					"Decrease depends on the following: \n"
					"\t- Decrease a meme by 1 severity\n"
					"\t- (Moderator) Decrease a meme to 0 severity\n"
					"If a meme filter has been established for the given meme:\n"
					"\t- Decrease meme presence to 0\n"
					"\t- (Moderator) Passively reduces meme presence to 0\n";
			}
			else if (tokens[1] == "give") {
				return "Use this in card transfers\n"
					"\t- If in a held card location with another player, \n"
					"\t\t give the held card to that player\n"
					"\t- (Millenial) If in the same location as another player,\n"
					"\t\t give any held card to that player\n";
			}
			else if (tokens[1] == "take") {
				return "Use this in card transfers\n"
					"\t- If in a held card location with another player, \n"
					"\t\t take the held card from that player\n"
					"\t- (Millenial) If in the same location as another player,\n"
					"\t\t take any held card from that player\n";
			}
			else if (tokens[1] == "filter") {
				return "Use this to develop a meme filter which can be used to "
					"prevent additional memes from spreading\n"
					"Requirements:\n"
					"\t- 5 valid location cards must be played\n"
					"\t- (H4cker) Only 4 valid location cards are required\n";
			}
			else if (tokens[1] == "event") {
				return "Use this to play a particular event card. Each card may \n"
					"only be played once.  Event cards do not consume an action when played.\n"
					"Event cards include:\n"
					"\t- Serious Discussion - Remove the card of a given site\n"
					"\t\t from the infection deck, preventing direct meme spawns\n"
					"\t\t in the particular location\n"
					"\t- Power Outage - Skip the next meme infection step of play\n"
					"\t- Meme Forecast - Look at the next 6 infection cards and\n"
					"\t\t rearrange them in any chosen order.\n"
					"\t- VPN - Immediately move ot any location on the board\n"
					"\t- Government Grant - Build a free CMC Server on any location\n"
					"\t\t of the board";
			}
			else if (tokens[1] == "roles") {
				return "The following roles exist in Memedemic:\n"
					"\t1. The Professor\n"
					"\t\t> May build a research station at any time.\n"
					"\t\t> May discard a card to move to any city.\n"
					"\t2. The H4cker\n"
					"\t\t> Needs only 4 cards to develop a meme filter.\n"
					"\t3. The Moderator\n"
					"\t\t> Removes memes entirely when banning them from a site\n"
					"\t\t> Auto-bans filtered memes from visited sites.\n"
					"\t4. The Router\n"
					"\t\t> May use an action to move another player.\n"
					"\t\t> May move a player to another player's location\n"
					"\t5. The Firewall\n"
					"\t\t> Prevents the spread of memes to the current and adjacent sites\n"
					"\t6. The Millenial\n"
					"\t\t> When in the same location as another player, may trade held cards\n";
			}
			else if (tokens[1] == "outbreak") {
				return "The Outbreak Track keeps a counter for how many\n"
					"\toutbreaks have occurred.  If 8 occur in one game,\n"
					"\tthe players will lose.  The following cause an outbreak:\n"
					"\t1. An epidemic card is drawn\n"
					"\t2. An infection occurs on a location of meme level 3\n"
					"\t\t- infection will spread to all adjacencies";
			}
			else if (tokens[1] == "viral") {
				return "The Viral Quotient is a counter of the following format:\n"
					"\t\t[2,2,2,3,3,4,4]\n"
					"\tEach position of the quotient determines how many\n"
					"\tinfections will occur at the end of each player turn.\n"
					"\tOutbreaks will increase the Viral Quotient.";
			}
			else if (tokens[1] == "meme") {
				return "A meme filter is used prevent the spread of memes.\n"
					"\tIt requires 5 cards of the same internet region to be\n"
					"\ttaken to a CMC.  Once a filter for a meme has been\n"
					"\tdeveloped, the meme will not randomly infect locations\n"
					"\tanymore.  It will only spread from existing locations.\n"
					"\tA player may eradicate a meme by removing it from the\n"
					"\tentire board.  However, this is not necessary to win.";
			}
			else if (tokens[1] == "players") {
				return "Use this to view the locations of all players\n";
			}
			else if (tokens[1] == "roles") {
				return "Use this to view the roles of all players\n";
			}
			/*else if (tokens[1] == "cmc") {
				return "Use this to view a list of all CMC locations\n";
			}*/
			else if (tokens[1] == "servers") {
				return "Use this to view a list of all CMC Server locations\n";
			}
			else if (tokens[1] == "draw") {
				return "Use this to draw 2 cards at the start of your turn\n";
			}
			else if (tokens[1] == "discard") {
				return "Use this to discard as many cards as necessary to not\n"
					"\t exceed the hand maximum of 8 cards.\n";
			}
			else if (tokens[1] == "cards") {
				return "Use this to view the cards held by other players\n";
			}
			else if (tokens[1] == "end") {
				return "Use this to end a turn and trigger the infection phase\n";
			}
			else if (tokens[1] == "new") {
				return "Use this to quit the current game and begin another\n";
			}
			else if (tokens[1] == "goal") {
				return "In Memedemic, you play the role of a galliant\n"
					"\tdefender of the internet, safeguarding it from the\n"
					"\tstale memes that seek to destroy it.\n"
					"To do this, your goal is to develop 4 meme filters\n"
					"\tand stop the memes from taking over.  You do this\n"
					"\tby obtaining 5 cards of the same internet region and\n"
					"\ttaking them to a Center for Meme Control (CMC) Server.";
			}
			else if (tokens[1] == "winning") {
				return "To win a game of Memedemic, you must develop 4 meme\n"
					"\tfilters by bring 5 cards of each internet region to a\n"
					"\tCMC server and using the 'filter' command with the cards.";
			}
			else if (tokens[1] == "losing") {
				return "Careful!  You can lose Memedemic in any of the\n"
					"following 3 ways:\n"
					"\t1. Allow the Outbreak Track to reach level 8\n"
					"\t2. Run out of cards in the deck\n"
					"\t3. Allow the quantity of any meme to exceed 18\n";
			}
			else if (tokens[1] == "CMC" || tokens[1] == "cmc") {
				return "A Center for Meme Control Server (CMC) is a building\n"
					"\ta player can construct in any location on the internet.\n"
					"\tYou need the card of the location to construct it with\n"
					"\tthe 'build' command.  Players can fast travel between\n"
					"\tCMCs.  There can be a maximum of 6.";
			}
			else if (tokens[1] == "epidemic") {
				return "The deck is populated with epidemic cards.  When any\n"
					"\tof these cards is drawn, the following will happen.\n"
					"\t1. A random location's meme level will be set to 3\n"
					"\t2. The Outbreak Track will increase by 1\n"
					"\t3. The Viral Quotient will move to the next stage\n"
					"\t4. An oubreak occurs at the epidemic location";
			}
			else return "No help available on " + tokens[1] + "\n";
		}
		else return "Incorrect usage of help: " + getUsage("help");
	}
	else if (tokens[0] == "usage") {
		if (tokens.size() > 1)
			return getUsage(tokens[1]);
		else return getUsage("usage");
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
		else if (successful == 0) {
			return "You have no actions remaining.  Please end your turn.";
		}
		else if (successful == -1) {
			// Location non-adjacent and no held card
			return "You cannot move to " + tokens[1] + 
				" unless you:\n1. Hold its card\n"
				"2. Hold the current location's card\n"
				"3. Are adjacent to it\n" +
				"4. It is the location of a CMC server, and" +
				" you are at a CMC server";
		}
		else if (successful == -2) {
			return "Current location has not changed.";
		}
		else return "Unable to move to " + tokens[1];
	}
    else if (tokens[0] == "move") {
        // Check for wrong number of arguments, that game has more than 1 player, and that user specified player number
        if (tokens.size() != 3 || gsm.getPlayers().size() < 2 || tokens[1].size() != 1 ||
                !std::isdigit(tokens[1][0])) {
            return "Incorrect usage of move: " + getUsage("move");
        }
        // Check that specified player number to move is valid
        int playerToMove = atoi(tokens[1].c_str()) - 1;
        if (playerToMove < 0 || playerToMove > gsm.getPlayers().size() - 1) {
            return "Invalid player number: " + getUsage("move");
        }
		// Get location number from enum
		int location = convertCard(tokens[2]);
		// Check if valid location
		if (!(location >= 0 && location <= 23)) {
			return "Invalid location: " + getUsage("move");
		}

        int successful = gsm.moveOtherPlayer(playerToMove, location);
		if (successful == 1)
			return "Moved player " + std::to_string(playerToMove + 1) + " to " + tokens[2];
		else if (successful == 0) {
			return "You have no actions remaining.  Please end your turn.";
		}
		else if (successful == -1) {
			// Location non-adjacent and no held card
			return "You cannot move to " + tokens[1] + 
				" unless you:\n1. Hold its card\n"
				"2. Hold the current location's card\n"
				"3. Are adjacent to it\n" +
				"4. It is the location of a CMC server, and" +
				" you are at a CMC server";
		}
		else if (successful == -2) {
			return "Current location has not changed.";
		}
        else if (successful == -3) {
            return "Cannot use move on current player; use access instead.";
        }
        else if (successful == -4) {
            return "Only a player with the role of router can use the move command.";
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
		else if (successful == 0) {
			return "You have no actions remaining.  Please end your turn.";
		}
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
			return "You must hold this location's card, or have the role of Meme Studies Professor to build a CMC Server.";
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
		if (whichMeme < 1 || whichMeme > 4)
			return "Please choose a valid meme: (1-4).  You chose " + whichMeme;
		int successful = gsm.banMeme(whichMeme - 1);
		if (successful == 1)
			return "Banned meme " + tokens[1] + " from current location.";
		else if (successful == 0) {
			return "You have no actions remaining.  Please end your turn.";
		}
		else if (successful == -1) {
			// Meme already filtered - doesn't exist on map anymore
			return "Meme " + tokens[1] + " has already been eradicated.";
		}
		else if (successful == -2) {
			// Meme not at current location
			return "Meme " + tokens[1] + " was not present in this location.";
		}
		else return "Unable to ban meme " + tokens[1] + " from current location.";
	}
	else if (tokens[0] == "give") {
		// Check for wrong number of arguments or non player number input
		if (tokens.size() != 3 || tokens[2].size() != 1 || !std::isdigit(tokens[2][0])) {
			return "Incorrect usage of give: " + getUsage("give");
		}

		// Attempt to give card
		int cardIndex = atoi(tokens[1].c_str()); //- 1;
		int otherPlayer = atoi(tokens[2].c_str()) - 1;
		int successful = gsm.shareCard(1, cardIndex, otherPlayer);
		if (successful == 1)
			return "Traded card " + tokens[1] + " to player " + tokens[2];
		else if (successful == 0)
			return "You have no actions remaining.  Please end your turn.";
		else if (successful == -1) {
			// invalid player chosen
			return "Player " + tokens[2] + " is not a valid player for giving a card.";
		}
		else if (successful == -2) {
			// invalid card chosen
			return "Card " + tokens[1] + " is not a valid card for giving.";
		}
		else if (successful == -2) {
			// not holding card of current location
			return "You must be holding the current location's card to trade cards.";
		}
		else if (successful == -3) {
			// players not in same location
			return "You must be in the same location as the player you wish to trade with.";
		}
		else if (successful == -4) {
			return "Player " + tokens[2] + "'s hand is full.";
		}
		else if (successful == -5) {
			return "You can only trade the card for your current location.";
		}
		else return "Unable to trade card " + tokens[1] + " to player " + tokens[2];
	}
	else if (tokens[0] == "take") {
		// Check for wrong number of arguments or non player number input
		if (tokens.size() != 3 || tokens[2].size() != 1 || !std::isdigit(tokens[2][0])) {
			return "Incorrect usage of give: " + getUsage("take");
		}
		// Attempt to take card
		int cardIndex = atoi(tokens[1].c_str()); //- 1;
		int otherPlayer = atoi(tokens[2].c_str()) - 1;
		int successful = gsm.shareCard(-1, cardIndex, otherPlayer);
		if (successful == 1)
			return "Traded card " + tokens[1] + " from player " + tokens[2];
		else if (successful == 0)
			return "You have no actions remaining.  Please end your turn.";
		else if (successful == -1) {
			// invalid player chosen
			return "Player " + tokens[2] + " is not a valid player for taking a card.";
		}
		else if (successful == -2) {
			// invalid card chosen
			return "Card " + tokens[1] + " is not a valid card for taking.";
		}
		else if (successful == -2) {
			// not holding card of current location
			return "You must be holding the current location's card to trade cards.";
		}
		else if (successful == -3) {
			// players not in same location
			return "You must be in the same location as the player you wish to trade with.";
		}
		else if (successful == -4) {
			return "Your hand is full.";
		}
		else if (successful == -5) {
			return "You can only trade the card for your current location.";
		}
		else return "Unable to trade card " + tokens[1] + " from player " + tokens[2];

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
		else if (successful == 0) {
			return "You have no actions remaining.  Please end your turn.";
		}
		else if (successful == -1) {
			// Cards don't all match
			return "Cards must all be from the same region to develop a filter.";
		}
		else if (successful == -2) {
			// Only provided 5 cards when not the role that allows that
			return "Incorrect number of cards provided.";
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
		else if (successful == -6) {
			// Used the same card multiple times
			return "You cannot use the same card more than once.";
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
		return "";
	}
	else if (tokens[0] == "viral") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of viral: " + getUsage("viral");
		}
		// Try to print viral quotient
		return "";
	}
	else if (tokens[0] == "meme") {
		// Check for wrong number of arguments
		if (tokens.size() != 2 && tokens.size() != 3) {
			return "Incorrect usage of meme: " + getUsage("meme");
		}
		// Attempt to print meme status
		return "";
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
		if (tokens.size() != 1 && tokens.size() != 2) {
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
			return "Holding too many cards.  Please discard at least one.";
		}
		else if (successful == -2) {
			// 2 too many cards in hand
			return "Holding too many cards.  Please discard two.";
		}
		else if (successful == -3) {
			// Player has already drawn this turn
			return "You have already drawn this turn.";
		}
		else return "Unable to draw cards.";
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
		std::cout << card1 << card2 << std::endl;
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
		else {
            if (tokens[1].size() != 1 || !std::isdigit(tokens[1][0])) {
                return "Incorrect usage of cards: " + getUsage("cards");
            }
            std::string result = gsm.printPlayerCards(tokens[1]);
            if (result == "INVALIDPLAYER") {
                return "Invalid player number specified.";
            }
            return result;
        }
	}
	else if (tokens[0] == "end") {
		// Check for wrong number of arguments
		if (tokens.size() != 1 && tokens.size() != 2) {
			return "Incorrect usage of end: " + getUsage("end");
		}

		// Current player draws (and discards) cards
		int drawAndDiscardSuccess = gsm.endTurn();
		if (drawAndDiscardSuccess == -1) {
			// 1 too many cards in hand
			return "Holding too many cards.  Please discard at least one.";
		}
		else if (drawAndDiscardSuccess == -2) {
			// 2 too many cards in hand
			return "Holding too many cards.  Please discard two.";
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
		
		//return "__main_menu";
		
	}
	else if (tokens[0] == "save") {
		// Check for wrong number of arguments
		if (tokens.size() != 1 && tokens.size() != 2)
			return "Incorrect usage of save: " + getUsage("save");
		// Attempt to save
		int successful = 0;
		if (tokens.size() == 2) {
			successful = gsm.saveGame(tokens[1]);
		}
		else successful = gsm.saveGame();

		if (successful == 1)
			return "Saved game!";
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
	if (command == "help") {
		return "help\nhelp <topic>\nhelp <command>";
	}
	else if (command == "save") {
		return "save\nsave <filename>";
	}
	else if (command == "usage") {
		return "usage <command>";
	}
	else if (command == "access") {
		return "access <location>";
	}
	else if (command == "move") {
		return "move <player #> <location>";
	}
	else if (command == "build") {
		return "build";
	}
	else if (command == "ban") {
		return "ban <number of meme>";
	}
	else if (command == "give") {
		return "give <card #> <player #>";
	}
	else if (command == "take") {
		return "take <card #> <player #>";
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
		return "cards <player #>";
	}
	else if (command == "end") {
		return "end turn";
	}
	else if (command == "new") {
		return "new game";
	}
	else return "No information found on " + command;
}
