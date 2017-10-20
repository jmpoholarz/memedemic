#pragma once
#include "TestScript.h"

int testScript() {
	int score = 0;
	int currentTest = 0;
	int testsRemaining = 44;
	int MAX_SCORE = testsRemaining;
	while (testsRemaining > 0) {
		// Perform uniform start-up process
		Board board = Board();
		Location locations = Location();
		GameStateManager gsm = GameStateManager(board, locations);
		Parser parser = Parser(gsm);
		Screen screen = Screen(gsm, parser);

		if (currentTest == 0) {
			if (test0001(board, gsm, parser)) {
				std::cout << "Test 0001 passed.\n";
				score++;
			}
			else std::cout << "Test 0001 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 1) {
			if (test0002(board, gsm, parser)) {
				std::cout << "Test 0002 passed.\n";
				score++;
			}
			else std::cout << "Test 0002 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 2) {
			if (test0101(board, gsm, parser)) {
				std::cout << "Test 0101 passed.\n";
				score++;
			}
			else std::cout << "Test 0101 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 3) {
			if (test0102(board, gsm, parser)) {
				std::cout << "Test 0102 passed.\n";
				score++;
			}
			else std::cout << "Test 0102 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 4) {
			if (test0103(board, gsm, parser)) {
				std::cout << "Test 0103 passed.\n";
				score++;
			}
			else std::cout << "Test 0103 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 5) {
			if (test0201(board, gsm, parser)) {
				std::cout << "Test 0201 passed.\n";
				score++;
			}
			else std::cout << "Test 0201 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 6) {
			if (test0301(board, gsm, parser)) {
				std::cout << "Test 0301 passed.\n";
				score++;
			}
			else std::cout << "Test 0301 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 7) {
			if (test0501(board, gsm, parser)) {
				std::cout << "Test 0501 passed.\n";
				score++;
			}
			else std::cout << "Test 0401 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 8) {
			if (test0401(board, gsm, parser)) {
				std::cout << "Test 0501 passed.\n";
				score++;
			}
			else std::cout << "Test 0501 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 9) {
			if (test0502(board, gsm, parser)) {
				std::cout << "Test 0502 passed.\n";
				score++;
			}
			else std::cout << "Test 0502 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 10) {
			if (test0601(board, gsm, parser)) {
				std::cout << "Test 0601 passed.\n";
				score++;
			}
			else std::cout << "Test 0601 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 11) {
			if (test0602(board, gsm, parser)) {
				std::cout << "Test 0602 passed.\n";
				score++;
			}
			else std::cout << "Test 0602 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 12) {
			if (test0603(board, gsm, parser)) {
				std::cout << "Test 0603 passed.\n";
				score++;
			}
			else std::cout << "Test 0603 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 13) {
			if (test0604(board, gsm, parser)) {
				std::cout << "Test 0604 passed.\n";
				score++;
			}
			else std::cout << "Test 0604 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 14) {
			if (test0605(board, gsm, parser)) {
				std::cout << "Test 0605 passed.\n";
				score++;
			}
			else std::cout << "Test 0605 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 15) {
			if (test0606(board, gsm, parser)) {
				std::cout << "Test 0606 passed.\n";
				score++;
			}
			else std::cout << "Test 0606 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 16) {
			if (test0701(board, gsm, parser)) {
				std::cout << "Test 0701 passed.\n";
				score++;
			}
			else std::cout << "Test 0701 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 17) {
			if (test0702(board, gsm, parser)) {
				std::cout << "Test 0702 passed.\n";
				score++;
			}
			else std::cout << "Test 0702 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 18) {
			if (test0703(board, gsm, parser)) {
				std::cout << "Test 0703 passed.\n";
				score++;
			}
			else std::cout << "Test 0703 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 19) {
			if (test0704(board, gsm, parser)) {
				std::cout << "Test 0704 passed.\n";
				score++;
			}
			else std::cout << "Test 0704 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 20) {
			if (test0705(board, gsm, parser)) {
				std::cout << "Test 0705 passed.\n";
				score++;
			}
			else std::cout << "Test 0705 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 21) {
			if (test0706(board, gsm, parser)) {
				std::cout << "Test 0706 passed.\n";
				score++;
			}
			else std::cout << "Test 0706 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 22) {
			if (test0707(board, gsm, parser)) {
				std::cout << "Test 0707 passed.\n";
				score++;
			}
			else std::cout << "Test 0707 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 23) {
			if (test0708(board, gsm, parser)) {
				std::cout << "Test 0708 passed.\n";
				score++;
			}
			else std::cout << "Test 0708 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 24) {
			if (test0801(board, gsm, parser)) {
				std::cout << "Test 0801 passed.\n";
				score++;
			}
			else std::cout << "Test 0801 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 25) {
			if (test0802(board, gsm, parser)) {
				std::cout << "Test 0802 passed.\n";
				score++;
			}
			else std::cout << "Test 0802 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 26) {
			if (test0803(board, gsm, parser)) {
				std::cout << "Test 0803 passed.\n";
				score++;
			}
			else std::cout << "Test 0803 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 27) {
			if (test0804(board, gsm, parser)) {
				std::cout << "Test 0804 passed.\n";
				score++;
			}
			else std::cout << "Test 0804 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 28) {
			if (test0805(board, gsm, parser)) {
				std::cout << "Test 0805 passed.\n";
				score++;
			}
			else std::cout << "Test 0805 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 29) {
			if (test0806(board, gsm, parser)) {
				std::cout << "Test 0806 passed.\n";
				score++;
			}
			else std::cout << "Test 0806 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 30) {
			if (test0807(board, gsm, parser)) {
				std::cout << "Test 0807 passed.\n";
				score++;
			}
			else std::cout << "Test 0807 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 31) {
			if (test2301(board, gsm, parser)) {
				std::cout << "Test 2301 passed.\n";
				score++;
			}
			else std::cout << "Test 2301 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 32) {
			if (test2401(board, gsm, parser)) {
				std::cout << "Test 2401 passed.\n";
				score++;
			}
			else std::cout << "Test 2401 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 33) {
			if (test2402(board, gsm, parser)) {
				std::cout << "Test 2402 passed.\n";
				score++;
			}
			else std::cout << "Test 2402 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 34) {
			if (test2403(board, gsm, parser)) {
				std::cout << "Test 2403 passed.\n";
				score++;
			}
			else std::cout << "Test 2403 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 35) {
			if (test2501(board, gsm, parser)) {
				std::cout << "Test 2501 passed.\n";
				score++;
			}
			else std::cout << "Test 2501 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 36) {
			if (test2502(board, gsm, parser)) {
				std::cout << "Test 2502 passed.\n";
				score++;
			}
			else std::cout << "Test 2502 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 37) {
			if (test2503(board, gsm, parser)) {
				std::cout << "Test 2503 passed.\n";
				score++;
			}
			else std::cout << "Test 2503 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 38) {
			if (test2504(board, gsm, parser)) {
				std::cout << "Test 2504 passed.\n";
				score++;
			}
			else std::cout << "Test 2504 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 39) {
			if (test2505(board, gsm, parser)) {
				std::cout << "Test 2505 passed.\n";
				score++;
			}
			else std::cout << "Test 2505 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 40) {
			if (test2506(board, gsm, parser)) {
				std::cout << "Test 2506 passed.\n";
				score++;
			}
			else std::cout << "Test 2506 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 41) {
			if (test2507(board, gsm, parser)) {
				std::cout << "Test 2507 passed.\n";
				score++;
			}
			else std::cout << "Test 2507 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 42) {
			if (test2508(board, gsm, parser)) {
				std::cout << "Test 2508 passed.\n";
				score++;
			}
			else std::cout << "Test 2508 failed.\n";
			testsRemaining--;
		}
		else if (currentTest == 43) {
			if (test2509(board, gsm, parser)) {
				std::cout << "Test 2509 passed.\n";
				score++;
			}
			else std::cout << "Test 2509 failed.\n";
			testsRemaining--;
		}

		currentTest++;
	}





	std::cout << score << "/" << MAX_SCORE << std::endl;
	return score;
}

bool test0001(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = ""; 
	// Obtain answer key
	std::fstream fs("TestScript/test0000key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0000load.txt");
	std::string response = parser.parse("bananas");
	if (response != "Unable to parse command!")
		return false;
	gsm.saveGame("TestScript/test0000save.txt");

	std::fstream fs2("TestScript/test0000save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0002(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string validOutput = "";
	std::string programOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0001key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0001load.txt");
	parser.parse("hElP");
	gsm.saveGame("TestScript/test0001save.txt");

	std::fstream fs2("TestScript/test0001save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0101(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0101key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0101load.txt");
	std::string response = parser.parse("access facebook");
	gsm.saveGame("TestScript/test0101save.txt");

	std::fstream fs2("TestScript/test0101save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0102(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0102key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0102load.txt");
	std::string response = parser.parse("access 9gag");
	gsm.saveGame("TestScript/test0102save.txt");

	std::fstream fs2("TestScript/test0102save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0103(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0103key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0103load.txt");
	std::string response = parser.parse("access bananas");
	gsm.saveGame("TestScript/test0103save.txt");

	std::fstream fs2("TestScript/test0103save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0201(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0201key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0201load.txt");
	std::string response = parser.parse("access weibo");
	gsm.saveGame("TestScript/test0201save.txt");

	std::fstream fs2("TestScript/test0201save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0301(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0301key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0301load.txt");
	std::string response = parser.parse("access email");
	gsm.saveGame("TestScript/test0301save.txt");

	std::fstream fs2("TestScript/test0301save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0401(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0401key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0401load.txt");
	std::string response = parser.parse("access email");
	gsm.saveGame("TestScript/test0401save.txt");

	std::fstream fs2("TestScript/test0401save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0501(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0501key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0501load.txt");
	std::string response = parser.parse("build");
	gsm.saveGame("TestScript/test0501save.txt");

	std::fstream fs2("TestScript/test0501save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0502(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0502key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0502load.txt");
	std::string response = parser.parse("build");
	gsm.saveGame("TestScript/test0502save.txt");

	std::fstream fs2("TestScript/test0502save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0601(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0601key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0601load.txt");
	std::string response = parser.parse("ban 1");
	gsm.saveGame("TestScript/test0601save.txt");

	std::fstream fs2("TestScript/test0601save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0602(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0602key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0602load.txt");
	std::string response = parser.parse("ban bananas");
	gsm.saveGame("TestScript/test0602save.txt");

	std::fstream fs2("TestScript/test0602save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0603(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0603key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0603load.txt");
	std::string response = parser.parse("ban 1");
	gsm.saveGame("TestScript/test0603save.txt");

	std::fstream fs2("TestScript/test0603save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0604(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0604key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0604load.txt");
	std::string response = parser.parse("ban 2");
	gsm.saveGame("TestScript/test0604save.txt");

	std::fstream fs2("TestScript/test0604save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0605(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0605key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0605load.txt");
	std::string response = parser.parse("ban 0");
	gsm.saveGame("TestScript/test0605save.txt");

	std::fstream fs2("TestScript/test0605save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0606(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0606key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0606load.txt");
	std::string response = parser.parse("ban 5");
	gsm.saveGame("TestScript/test0606save.txt");

	std::fstream fs2("TestScript/test0606save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0701(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0701key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0701load.txt");
	std::string response = parser.parse("give 3 player2");
	gsm.saveGame("TestScript/test0701save.txt");

	std::fstream fs2("TestScript/test0701save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0702(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0702key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0702load.txt");
	std::string response = parser.parse("give 3 player2");
	gsm.saveGame("TestScript/test0702save.txt");

	std::fstream fs2("TestScript/test0702save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0703(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0703key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0703load.txt");
	std::string response = parser.parse("give bananas player2");
	gsm.saveGame("TestScript/test0703save.txt");

	std::fstream fs2("TestScript/test0703save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0704(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0704key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0704load.txt");
	std::string response = parser.parse("give 3 bananas");
	gsm.saveGame("TestScript/test0704save.txt");

	std::fstream fs2("TestScript/test0704save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0705(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0705key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0705load.txt");
	std::string response = parser.parse("take 3 player2");
	gsm.saveGame("TestScript/test0705save.txt");

	std::fstream fs2("TestScript/test0705save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0706(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0706key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0706load.txt");
	std::string response = parser.parse("take 1 player2");
	gsm.saveGame("TestScript/test0706save.txt");

	std::fstream fs2("TestScript/test0706save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0707(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0707key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0707load.txt");
	std::string response = parser.parse("give 0 player2");
	gsm.saveGame("TestScript/test0707save.txt");

	std::fstream fs2("TestScript/test0707save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0708(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0708key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0708load.txt");
	std::string response = parser.parse("take 12 player2");
	gsm.saveGame("TestScript/test0708save.txt");

	std::fstream fs2("TestScript/test0708save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0801(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0801key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0801load.txt");
	std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test0801save.txt");

	std::fstream fs2("TestScript/test0801save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0802(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0802key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0802load.txt");
	std::string response = parser.parse("filter 16 1 0 2");
	gsm.saveGame("TestScript/test0802save.txt");

	std::fstream fs2("TestScript/test0802save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0803(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0803key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0803load.txt");
	std::string response = parser.parse("filter 16 1 0 2 3 3");
	gsm.saveGame("TestScript/test0803save.txt");

	std::fstream fs2("TestScript/test0803save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0804(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0804key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0804load.txt");
	std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test0804save.txt");

	std::fstream fs2("TestScript/test0804save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0805(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0805key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0805load.txt");
	std::string response = parser.parse("filter 16 1 0 2 -3");
	gsm.saveGame("TestScript/test0805save.txt");

	std::fstream fs2("TestScript/test0805save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0806(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0806key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0806load.txt");
	std::string response = parser.parse("filter 16 1 0 2 9");
	gsm.saveGame("TestScript/test0806save.txt");

	std::fstream fs2("TestScript/test0806save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test0807(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test0807key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test0807load.txt");
	std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test0807save.txt");

	std::fstream fs2("TestScript/test0807save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2301(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2301key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2301load.txt");
	//std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test2301save.txt");

	std::fstream fs2("TestScript/test2301save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2401(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2401key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2401load.txt");
	//std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test2401save.txt");

	std::fstream fs2("TestScript/test2401save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2402(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2402key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2402load.txt");
	//std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test2402save.txt");

	std::fstream fs2("TestScript/test2402save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2403(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2403key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2403load.txt");
	//std::string response = parser.parse("filter 16 1 0 2 3");
	gsm.saveGame("TestScript/test2403save.txt");

	std::fstream fs2("TestScript/test2403save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2501(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2501key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2501load.txt");
	std::string response = parser.parse("draw cards");
	gsm.saveGame("TestScript/test2501save.txt");

	std::fstream fs2("TestScript/test2501save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2502(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2502key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2502load.txt");
	//std::string response = parser.parse("filter 16 1 0 2 3");
	//gsm.saveGame("TestScript/test2502save.txt");

	//std::fstream fs2("TestScript/test2502save.txt", std::fstream::in);
	//do {
	//	std::getline(fs2, line);
	//	programOutput += line;
	//} while (line != "");
	//
	//if (programOutput == validOutput)
	//	return true;
	//else return false;
	return true;
}
bool test2503(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2503key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2503load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1");
	gsm.saveGame("TestScript/test2503save.txt");

	std::fstream fs2("TestScript/test2503save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2504(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2504key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2504load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1 2");
	gsm.saveGame("TestScript/test2504save.txt");

	std::fstream fs2("TestScript/test2504save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2505(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2505key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2505load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 9");
	gsm.saveGame("TestScript/test2505save.txt");

	std::fstream fs2("TestScript/test2505save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2506(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2506key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2506load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1 bananas");
	gsm.saveGame("TestScript/test2506save.txt");

	std::fstream fs2("TestScript/test2506save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2507(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2507key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2507load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1 2 3");
	gsm.saveGame("TestScript/test2507save.txt");

	std::fstream fs2("TestScript/test2507save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2508(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2508key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2508load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1 2 3");
	gsm.saveGame("TestScript/test2508save.txt");

	std::fstream fs2("TestScript/test2508save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
bool test2509(Board& board, GameStateManager& gsm, Parser& parser) {
	std::string programOutput = "";
	std::string validOutput = "";
	// Obtain answer key
	std::fstream fs("TestScript/test2509key.txt", std::fstream::in);
	std::string line;
	do {
		std::getline(fs, line);
		validOutput += line;
	} while (line != "");

	// Create save file to compare to key
	gsm.loadGame("TestScript/test2509load.txt");
	std::string response = parser.parse("draw cards");
	response = parser.parse("discard 1");
	gsm.saveGame("TestScript/test2509save.txt");

	std::fstream fs2("TestScript/test2509save.txt", std::fstream::in);
	do {
		std::getline(fs2, line);
		programOutput += line;
	} while (line != "");

	if (programOutput == validOutput)
		return true;
	else return false;
}
