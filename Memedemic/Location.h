#pragma once
#include <vector>

class Location {
public:
	Location(int name);
	~Location();

	std::vector<int> getMemeStatus();
	bool hasCMCServer();
	std::vector<int> getAdjacentLocations();
	bool isAdjacent(int location);

private:
	int name;
	int memeStatus[4];
	bool CMCServer;
};