#pragma once
#include <vector>
#include <string>
#include <list>

class Location {
public:
	Location();
	//Location(int name);
	~Location();

	std::vector<int> getMemeStatus(int name);
	void setMemeStatus(int name, int meme, int level);
	bool hasCMCServer(int name);
	void setCMCServer(int name);
	std::vector<int> getAdjacentLocations(int name);
	bool isAdjacent(int current, int location);

private:		
	struct site {
		int id;
		std::string siteName;
		std::vector<int> adjacencies;
		std::vector<site> a;
		std::vector<int> memeStatus;  // do not use xd
		bool CMCServer;	
	};
	std::list<site> sites;
};
