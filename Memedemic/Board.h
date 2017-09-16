#pragma once
#include <vector>
#include "Location.h"

class Board {

public:
	Board();
	~Board();

private:
	std::vector<Location> locations;

};