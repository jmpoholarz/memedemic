#pragma once
#include <string>

class Parser {
public:
	Parser();
	~Parser();
	bool parse(std::string command);
private:
};