#include <iostream>
#include "Board.h"

void boardTest00(Board& board) {
	std::string number = "00";
	std::string response = "hi";
	std::string expected;
	

	//std::cout << "Test number: " << number << std::endl;
	if (response == expected) {
		std::cout << "\tTest 00 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 00 failed" << std::endl;
		//std::cout << "Expected: " << expected << std::endl;
		//std::cout << "Received: " << response << std::endl;
	}
}

int main() {
	Board* b = new Board("p1", "p2", "p3", "p4");
	b->printBoard();
}