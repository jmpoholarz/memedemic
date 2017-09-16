#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

class Parser {
public:
	Parser();
	~Parser();
	bool parse(std::string command);
private:
};