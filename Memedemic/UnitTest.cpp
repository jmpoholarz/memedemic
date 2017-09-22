#include <iostream>
#include "Main.h"

void parserTest00(Parser& parser) {
	std::string number = "00";
	std::string expected = "access <location>";
	std::string response = parser.parse("usage access");
	
	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[usage access] test passed" << std::endl;
	else std::cout << "\t[usage access] test failed"
		<< std::endl << "expected: " << expected << std::endl
		<< "received: " << response << std::endl;
}

void parserTest01(Parser& parser) {
	std::string number = "01";
	std::string expected = "access <location>";
	std::string response = parser.parse("uSaGe AcCEsS");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[uSaGe AcCEsS] test passed" << std::endl;
	else std::cout << "\t[uSaGe AcCEsS] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest02(Parser& parser) {
	std::string number = "02";
	std::string expected = "access <location>";
	std::string response = parser.parse("USAGE ACCESS");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[USAGE ACCESS] test passed" << std::endl;
	else std::cout << "\t[USAGE ACCESS] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest03(Parser& parser) {
	std::string number = "03";
	std::string expected = "No information found on ";
	std::string response = parser.parse("usage  access");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[usage  access] test passed" << std::endl;
	else std::cout << "\t[usage  access] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest04(Parser& parser) {
	std::string number = "04";
	std::string expected = "Invalid location: access <location>";
	std::string response = parser.parse("access bananas");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[access bananas] test passed" << std::endl;
	else std::cout << "\t[access bananas] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest05(Parser& parser) {
	std::string number = "05";
	std::string expected = "Unable to move to facebook";
	std::string response = parser.parse("access FaceBook");

	std::cout << "Test number: " << number << std::endl;
	std::cout << "Note: temporary test case" << std::endl;
	if (response == expected)
		std::cout << "\t[access FaceBook] test passed" << std::endl;
	else std::cout << "\t[access Facebook] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest06(Parser& parser) {
	std::string number = "06";
	std::string expected = "Incorrect usage of access: access <location>";
	std::string response = parser.parse("access reddit please");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[access reddit please] test passed" << std::endl;
	else std::cout << "\t[access reddit please] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest07(Parser& parser) {
	std::string number = "07";
	int expected = 5;
	int response = parser.convertCard("discord");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[discord] test passed" << std::endl;
	else std::cout << "\t[discord] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest08(Parser& parser) {
	std::string number = "08";
	int expected = -1;
	int response = parser.convertCard("bananas");

	std::cout << "Test number: " << number << std::endl;
	if (response == expected)
		std::cout << "\t[bananas] test passed" << std::endl;
	else std::cout << "\t[bananas] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest09(Parser& parser) {
	std::string number = "09";
	std::string expected = "Unable to build CMC Server.";
	std::string response = parser.parse("builD");

	std::cout << "Test number: " << number << std::endl;
	std::cout << "Note: temporary test case" << std::endl;
	if (response == expected)
		std::cout << "\t[builD] test passed" << std::endl;
	else std::cout << "\t[builD] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest10(Parser& parser) {
	std::string number = "10";
	std::string expected = "Unable to ban meme 2 from current location.";
	std::string response = parser.parse("ban 2");

	std::cout << "Test number: " << number << std::endl;
	std::cout << "Note: temporary test case" << std::endl;
	if (response == expected)
		std::cout << "\t[ban 2] test passed" << std::endl;
	else std::cout << "\t[ban 2] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}

void parserTest11(Parser& parser) {
	std::string number = "11";
	std::string expected = "Unable to end turn.";
	std::string response = parser.parse("end turn");

	std::cout << "Test number: " << number << std::endl;
	std::cout << "Note: temporary test case" << std::endl;
	if (response == expected)
		std::cout << "\t[end turn] test passed" << std::endl;
	else std::cout << "\t[end turn] test failed"
		<< std::endl << "\texpected: " << expected << std::endl
		<< "\treceived: " << response << std::endl;
}


int main() {
	
	// Create GameStateManager to setup game
	GameStateManager* gsm = new GameStateManager(1);
	Parser* parser = new Parser(*gsm);
	
	parserTest00(*parser);
	parserTest01(*parser);
	parserTest02(*parser);
	parserTest03(*parser);
	parserTest04(*parser);
	parserTest05(*parser);
	parserTest06(*parser);
	parserTest07(*parser);
	parserTest08(*parser);
	parserTest09(*parser);
	parserTest10(*parser);
	parserTest11(*parser);
}