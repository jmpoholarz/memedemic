#include <iostream>
#include "Board.h"
#include <string>

/**
	Testing the movePLayer function
*/
void boardTest00(Board &b) {
	std::string number = "00";
	b.movePlayer(0, 0);
	bool beforeLocation = b.getLocation(18).players[0];
	bool afterLocation = b.getLocation(0).players[0];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 00 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 00 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest01(Board &b) {
	std::string number = "01";
	b.movePlayer(23, 0);
	bool beforeLocation = b.getLocation(0).players[0];
	bool afterLocation = b.getLocation(23).players[0];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 01 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 01 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest02(Board &b) {
	std::string number = "02";
	b.movePlayer(0, 1);
	bool beforeLocation = b.getLocation(18).players[1];
	bool afterLocation = b.getLocation(0).players[1];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 02 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 02 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest03(Board &b) {
	std::string number = "03";
	b.movePlayer(23, 1);
	bool beforeLocation = b.getLocation(0).players[1];
	bool afterLocation = b.getLocation(23).players[1];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 03 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 03 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest04(Board &b) {
	std::string number = "04";
	b.movePlayer(0, 2);
	bool beforeLocation = b.getLocation(18).players[2];
	bool afterLocation = b.getLocation(0).players[2];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 04 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 04 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest05(Board &b) {
	std::string number = "05";
	b.movePlayer(23, 2);
	bool beforeLocation = b.getLocation(0).players[2];
	bool afterLocation = b.getLocation(23).players[2];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 05 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 05 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest06(Board &b) {
	std::string number = "06";
	b.movePlayer(0, 3);
	bool beforeLocation = b.getLocation(18).players[3];
	bool afterLocation = b.getLocation(0).players[3];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 06 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 06 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

void boardTest07(Board &b) {
	std::string number = "07";
	b.movePlayer(23, 3);
	bool beforeLocation = b.getLocation(0).players[3];
	bool afterLocation = b.getLocation(23).players[3];

	std::cout << "Test number: " << number << std::endl;
	if (beforeLocation == false && afterLocation == true) {
		std::cout << "\tTest 07 passed" << std::endl;
	}
	else {
		std::cout << "\tTest 07 failed" << std::endl;
		std::cout << "\tExpected: " << "beforeLocation: " << 0 << " afterLocation: " << 1 << std::endl;
		std::cout << "\tReceived: " << "beforeLocation: " << beforeLocation << " afterLocation: " << afterLocation << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the addMemeCube function
*/
void boardTest08(Board &b) {
	std::string number = "08";
	b.addMemeCubes(0, 0, 1);
	int memeCubeCount = b.getLocation(0).memes[0];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest09(Board &b) {
	std::string number = "09";
	b.addMemeCubes(23, 0, 1);
	int memeCubeCount = b.getLocation(23).memes[0];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest10(Board &b) {
	std::string number = "10";
	b.addMemeCubes(0, 1, 1);
	int memeCubeCount = b.getLocation(0).memes[1];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest11(Board &b) {
	std::string number = "11";
	b.addMemeCubes(23, 1, 1);
	int memeCubeCount = b.getLocation(23).memes[1];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest12(Board &b) {
	std::string number = "12";
	b.addMemeCubes(0, 2, 1);
	int memeCubeCount = b.getLocation(0).memes[2];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest13(Board &b) {
	std::string number = "13";
	b.addMemeCubes(23, 2, 1);
	int memeCubeCount = b.getLocation(23).memes[2];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest14(Board &b) {
	std::string number = "14";
	b.addMemeCubes(0, 3, 1);
	int memeCubeCount = b.getLocation(0).memes[3];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest15(Board &b) {
	std::string number = "15";
	b.addMemeCubes(23, 3, 1);
	int memeCubeCount = b.getLocation(23).memes[3];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 1 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the removeMemeCube function
*/
void boardTest16(Board &b) {
	std::string number = "16";
	b.removeMemeCube(0, 0);
	int memeCubeCount = b.getLocation(0).memes[0];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest17(Board &b) {
	std::string number = "17";
	b.removeMemeCube(23, 0);
	int memeCubeCount = b.getLocation(23).memes[0];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest18(Board &b) {
	std::string number = "18";
	b.removeMemeCube(0, 1);
	int memeCubeCount = b.getLocation(0).memes[1];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest19(Board &b) {
	std::string number = "19";
	b.removeMemeCube(23, 1);
	int memeCubeCount = b.getLocation(23).memes[1];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest20(Board &b) {
	std::string number = "20";
	b.removeMemeCube(0, 2);
	int memeCubeCount = b.getLocation(0).memes[2];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest21(Board &b) {
	std::string number = "21";
	b.removeMemeCube(23, 2);
	int memeCubeCount = b.getLocation(23).memes[2];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest22(Board &b) {
	std::string number = "22";
	b.removeMemeCube(0, 3);
	int memeCubeCount = b.getLocation(0).memes[3];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

void boardTest23(Board &b) {
	std::string number = "23";
	b.removeMemeCube(23, 3);
	int memeCubeCount = b.getLocation(23).memes[3];

	std::cout << "Test number: " << number << std::endl;
	if (memeCubeCount == 0) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "memeCubeCount: " << 0 << std::endl;
		std::cout << "\tReceived: " << "memeCubeCount: " << memeCubeCount << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the addCMC function
*/
void boardTest24(Board &b) {
	std::string number = "24";
	b.addCMC(0);
	bool cmcServer = b.getLocation(0).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 1 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

void boardTest25(Board &b) {
	std::string number = "25";
	b.addCMC(23);
	bool cmcServer = b.getLocation(23).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 1 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the removeCMC function
*/
void boardTest26(Board &b) {
	std::string number = "26";
	b.removeCMC(0);
	bool cmcServer = b.getLocation(0).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (!cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 0 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

void boardTest27(Board &b) {
	std::string number = "27";
	b.removeCMC(23);
	bool cmcServer = b.getLocation(23).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (!cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 0 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the addOutbreak function
*/
void boardTest28(Board &b) {
	std::string number = "28";
	b.addOutbreak();
	int outbreakCounter = b.getOutbreakCounter();

	std::cout << "Test number: " << number << std::endl;
	if (outbreakCounter == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "outbreakCounter: " << 3 << std::endl;
		std::cout << "\tReceived: " << "outbreakCounter: " << outbreakCounter << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the addCure function
*/
void boardTest29(Board &b) {
	std::string number = "29";
	b.addCure(0);
	int cure = b.getCure(0);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest30(Board &b) {
	std::string number = "30";
	b.addCure(1);
	int cure = b.getCure(1);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest31(Board &b) {
	std::string number = "31";
	b.addCure(2);
	int cure = b.getCure(2);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest32(Board &b) {
	std::string number = "32";
	b.addCure(3);
	int cure = b.getCure(3);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the updatePlayerCard function
*/
void boardTest33(Board &b) {
	std::string number = "33";
	b.updatePlayerCardCount(20);
	int playerCards = b.getPlayerCards();

	std::cout << "Test number: " << number << std::endl;
	if (playerCards == 20) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerCards: " << 20 << std::endl;
		std::cout << "\tReceived: " << "playerCards: " << playerCards << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the construction of player roles
*/
void boardTest34(Board &b) {
	std::string number = "34";
	Board* tempBoard = new Board();
	tempBoard->setupPlayers(2);
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "ME" && playerRoles[1] == "HA") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "ME" << " playerRoles[1]: " << "HA" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << std::endl;
	}
	std::cout << std::endl;
}

void boardTest35(Board &b) {
	std::string number = "35";
	Board* tempBoard = new Board();
	tempBoard->setupPlayers(3);
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "ME" && playerRoles[1] == "HA" && playerRoles[2] == "MO") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "ME" << " playerRoles[1]: " << "HA" << " playerRoles[2]: " << "MO" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << " playerRoles[2]: " << playerRoles[2] << std::endl;
	}
	std::cout << std::endl;
}

void boardTest36(Board &b) {
	std::string number = "36";
	Board* tempBoard = new Board();
	tempBoard->setupPlayers(4);
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "ME" && playerRoles[1] == "HA" && playerRoles[2] == "MO" && playerRoles[3] == "RO") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "ME" << " playerRoles[1]: " << "HA" << " playerRoles[2]: " << "MO" << " playerRoles[3]: " << "RO" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << " playerRoles[2]: " << playerRoles[2] << " playerRoles[3]: " << playerRoles[3] << std::endl;
	}
	std::cout << std::endl;
}

/**
Testing the eradicateMeme function
*/
void boardTest37(Board &b) {
	std::string number = "37";
	b.eradicateMeme(0);
	int cure = b.getCure(0);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest38(Board &b) {
	std::string number = "38";
	b.eradicateMeme(1);
	int cure = b.getCure(1);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest39(Board &b) {
	std::string number = "39";
	b.eradicateMeme(2);
	int cure = b.getCure(2);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest40(Board &b) {
	std::string number = "40";
	b.eradicateMeme(3);
	int cure = b.getCure(3);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

/**
Testing the setCure function
*/
void boardTest41(Board &b) {
	std::string number = "41";
	b.setCure(0, 1);
	int cure = b.getCure(0);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest42(Board &b) {
	std::string number = "42";
	b.setCure(1, 1);
	int cure = b.getCure(1);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest43(Board &b) {
	std::string number = "43";
	b.setCure(2, 1);
	int cure = b.getCure(2);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest44(Board &b) {
	std::string number = "44";
	b.setCure(3, 1);
	int cure = b.getCure(3);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 1) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 1 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest45(Board &b) {
	std::string number = "45";
	b.setCure(0, 2);
	int cure = b.getCure(0);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest46(Board &b) {
	std::string number = "46";
	b.setCure(1, 2);
	int cure = b.getCure(1);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest47(Board &b) {
	std::string number = "47";
	b.setCure(2, 2);
	int cure = b.getCure(2);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

void boardTest48(Board &b) {
	std::string number = "48";
	b.setCure(3, 2);
	int cure = b.getCure(3);

	std::cout << "Test number: " << number << std::endl;
	if (cure == 2) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "Cure: " << 2 << std::endl;
		std::cout << "\tReceived: " << "Cure: " << cure << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the setCMCServer function
*/
void boardTest49(Board &b) {
	std::string number = "49";
	b.setCMCServer(10, true);

	bool cmcServer = b.getLocation(10).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 1 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

void boardTest50(Board &b) {
	std::string number = "50";
	b.setCMCServer(18, false);
	bool cmcServer = b.getLocation(18).cmcServer;

	std::cout << "Test number: " << number << std::endl;
	if (!cmcServer) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "cmcServer: " << 0 << std::endl;
		std::cout << "\tReceived: " << "cmcServer: " << cmcServer << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the setMemes function
*/
void boardTest51(Board &b) {
	std::string number = "51";
	int memeCounts[4] = { 0, 1, 2, 3 };
	b.setMemes(0, memeCounts);
	int meme0 = b.getLocation(0).memes[0];
	int meme1 = b.getLocation(0).memes[1];
	int meme2 = b.getLocation(0).memes[2];
	int meme3 = b.getLocation(0).memes[3];

	std::cout << "Test number: " << number << std::endl;
	if (meme0 == 0 && meme1 == 1 && meme2 == 2 && meme3 == 3) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "meme0: " << 0 << "meme1: " << 1 << "meme2: " << 2 << "meme3: " << 3 << std::endl;
		std::cout << "\tReceived: " << "meme0: " << meme0 << "meme1: " << meme1 << "meme2: " << meme2 << "meme3: " << meme3 << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the setPlayers function
*/
void boardTest52(Board &b) {
	std::string number = "52";
	b.setPlayers(0, 0, true);
	bool player = b.getLocation(0).players[0];

	std::cout << "Test number: " << number << std::endl;
	if (player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 1 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest53(Board &b) {
	std::string number = "53";
	b.setPlayers(1, 1, true);
	bool player = b.getLocation(1).players[1];

	std::cout << "Test number: " << number << std::endl;
	if (player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 1 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest54(Board &b) {
	std::string number = "54";
	b.setPlayers(2, 2, true);
	bool player = b.getLocation(2).players[2];

	std::cout << "Test number: " << number << std::endl;
	if (player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 1 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest55(Board &b) {
	std::string number = "55";
	b.setPlayers(3, 3, true);
	bool player = b.getLocation(3).players[3];

	std::cout << "Test number: " << number << std::endl;
	if (player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 1 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest56(Board &b) {
	std::string number = "56";
	b.setPlayers(18, 0, false);
	bool player = b.getLocation(18).players[0];

	std::cout << "Test number: " << number << std::endl;
	if (!player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 0 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest57(Board &b) {
	std::string number = "57";
	b.setPlayers(18, 1, false);
	bool player = b.getLocation(18).players[1];

	std::cout << "Test number: " << number << std::endl;
	if (!player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 0 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest58(Board &b) {
	std::string number = "58";
	b.setPlayers(18, 2, false);
	bool player = b.getLocation(18).players[2];

	std::cout << "Test number: " << number << std::endl;
	if (!player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 0 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

void boardTest59(Board &b) {
	std::string number = "59";
	b.setPlayers(18, 3, false);
	bool player = b.getLocation(18).players[3];

	std::cout << "Test number: " << number << std::endl;
	if (!player) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "player: " << 0 << std::endl;
		std::cout << "\tReceived: " << "player: " << player << std::endl;
	}
	std::cout << std::endl;
}

/**
	Runs the tests
*/
int main() {
	Board* b = new Board();
	b->setupPlayers(4);

	boardTest00(*b);
	boardTest01(*b);
	boardTest02(*b);
	boardTest03(*b);
	boardTest04(*b);
	boardTest05(*b);
	boardTest06(*b);
	boardTest07(*b);
	boardTest08(*b);
	boardTest09(*b);
	boardTest10(*b);
	boardTest11(*b);
	boardTest12(*b);
	boardTest13(*b);
	boardTest14(*b);
	boardTest15(*b);
	boardTest16(*b);
	boardTest17(*b);
	boardTest18(*b);
	boardTest19(*b);
	boardTest20(*b);
	boardTest21(*b);
	boardTest22(*b);
	boardTest23(*b);
	boardTest24(*b);
	boardTest25(*b);
	boardTest26(*b);
	boardTest27(*b);
	boardTest28(*b);
	boardTest29(*b);
	boardTest30(*b);
	boardTest31(*b);
	boardTest32(*b);
	boardTest33(*b);
	boardTest34(*b);
	boardTest35(*b);
	boardTest36(*b);
	boardTest37(*b);
	boardTest38(*b);
	boardTest39(*b);
	boardTest40(*b);
	boardTest41(*b);
	boardTest42(*b);
	boardTest43(*b);
	boardTest44(*b);
	boardTest45(*b);
	boardTest46(*b);
	boardTest47(*b);
	boardTest48(*b);
	boardTest49(*b);
	boardTest50(*b);
	boardTest51(*b);
	boardTest52(*b);
	boardTest53(*b);
	boardTest54(*b);
	boardTest55(*b);
	boardTest56(*b);
	boardTest57(*b);
	boardTest58(*b);
	boardTest59(*b);

	system("pause");
}