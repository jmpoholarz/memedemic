#pragma once
#include <string>
#include <vector>

class Player {
	
public:
	Player(std::string name);
	~Player();
	std::string getPlayerName();
	int getPlayerRole();
	std::vector<int> getPlayerCards();
	int getPlayerLocation();
private:
	std::string name;
	int role;
	int location;
	std::vector<int> cards;
};