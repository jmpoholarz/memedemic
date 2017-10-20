#pragma once
#include "TestScript.h"

int testScript() {
	int score = 0;
	int currentTest = 0;
	int testsRemaining = 16;
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