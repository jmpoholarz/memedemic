#pragma once
#include <string>
#include <vector>

class Player {
	
public:
	Player();
	~Player();
	bool setName(std::string name);
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
