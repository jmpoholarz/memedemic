#include <assert.h>
#include "Main.h"

int main() {
	
	// Create GameStateManager to setup game
	GameStateManager* gsm = new GameStateManager(1);
	Parser* parser = new Parser(*gsm);
	
	

}