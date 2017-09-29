#pragma once
#include <vector>
#include <string>
#include <list>

class Location {
public:
	Location();
	Location(int name);
	~Location();

	std::vector<int> getMemeStatus();
	void setMemeStatus(int meme, int level);
	bool hasCMCServer();
	void setCMCServer(bool exists);
	std::vector<int> getAdjacentLocations(int name);
	bool isAdjacent(int current, int location);

private:
	int name;
	std::vector<int> memeStatus;
	bool CMCServer;
	struct site {
		int id;
		std::vector<int> adjacencies;
		std::vector<site> a;
	};
	std::list<site> sites;
};