#include "Parser.h"

Parser::Parser() {

}

Parser::~Parser() {

}

bool Parser::parse(std::string command) {
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

}