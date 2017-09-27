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
	b.addMemeCube(0, 0);
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
	b.addMemeCube(23, 0);
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
	b.addMemeCube(0, 1);
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
	b.addMemeCube(23, 1);
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
	b.addMemeCube(0, 2);
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
	b.addMemeCube(23, 2);
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
	b.addMemeCube(0, 3);
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
	b.addMemeCube(23, 3);
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
	if (outbreakCounter == 3) {
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
	bool cure = b.getCure(0);

	std::cout << "Test number: " << number << std::endl;
	if (cure) {
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
	bool cure = b.getCure(1);

	std::cout << "Test number: " << number << std::endl;
	if (cure) {
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
	bool cure = b.getCure(2);

	std::cout << "Test number: " << number << std::endl;
	if (cure) {
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
	bool cure = b.getCure(3);

	std::cout << "Test number: " << number << std::endl;
	if (cure) {
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
	Testing the removePlayerCard function
*/
void boardTest33(Board &b) {
	std::string number = "33";
	b.removePlayerCard();
	int playerCards = b.getPlayerCards();

	std::cout << "Test number: " << number << std::endl;
	if (playerCards == 58) {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerCards: " << 58 << std::endl;
		std::cout << "\tReceived: " << "playerCards: " << playerCards << std::endl;
	}
	std::cout << std::endl;
}

/**
	Testing the construction of player roles
*/
void boardTest34(Board &b) {
	std::string number = "34";
	Board* tempBoard = new Board("p1", "p2");
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "p1" && playerRoles[1] == "p2") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "p1" << " playerRoles[1]: " << "p2" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << std::endl;
	}
	std::cout << std::endl;
}

void boardTest35(Board &b) {
	std::string number = "35";
	Board* tempBoard = new Board("p1", "p2", "p3");
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "p1" && playerRoles[1] == "p2" && playerRoles[2] == "p3") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "p1" << " playerRoles[1]: " << "p2" << "playerRoles[2]: " << "p3" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << " playerRoles[2]: " << playerRoles[2] << std::endl;
	}
	std::cout << std::endl;
}

void boardTest36(Board &b) {
	std::string number = "36";
	Board* tempBoard = new Board("p1", "p2", "p3", "p4");
	std::vector<std::string> playerRoles = tempBoard->getPlayerRoles();

	std::cout << "Test number: " << number << std::endl;
	if (playerRoles[0] == "p1" && playerRoles[1] == "p2" && playerRoles[2] == "p3" && playerRoles[3] == "p4") {
		std::cout << "\tTest " << number << " passed" << std::endl;
	}
	else {
		std::cout << "\tTest " << number << " failed" << std::endl;
		std::cout << "\tExpected: " << "playerRoles[0]: " << "p1" << " playerRoles[1]: " << "p2" << "playerRoles[2]: " << "p3" << "playerRoles[3]: " << "p4" << std::endl;
		std::cout << "\tReceived: " << "playerRoles[0]: " << playerRoles[0] << " playerRoles[1]: " << playerRoles[1] << " playerRoles[2]: " << playerRoles[2] << " playerRoles[3]: " << playerRoles[3] << std::endl;
	}
	std::cout << std::endl;
}

/**
	Runs the previous tests
*/
int main() {
	Board* b = new Board("p1", "p2", "p3", "p4");

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

	system("pause");
}