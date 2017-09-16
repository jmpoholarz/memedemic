#pragma once

class Board {

public:
	Board(int numPlayers);
	~Board();

	bool initialInfection();
	bool infect(int infectionRate);

private:

};