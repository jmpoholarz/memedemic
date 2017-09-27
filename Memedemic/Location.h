#pragma once
#include <vector>
#include <string>
#include <list>

class Location {
public:
	Location();
	~Location();

	std::vector<int> getMemeStatus();
	bool hasCMCServer();
	std::vector<int> getAdjacentLocations(int name);
	bool isAdjacent(int current, int location);
	site getLocation(int name);

private:
	int name;
	std::vector<int> memeStatus;
	bool CMCServer;
	struct site {
		int id;
		std::string name;
		std::vector<int> adjacencies;
		std::vector<site> a;
	};
	std::list<site> sites;
};