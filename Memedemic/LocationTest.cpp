#include <iostream>
#include <string.h>
#include "Location.h"

void locationTest(Location& location, int l,std::vector<int> list, const char *expectation) {
    std::vector<int> r = location.getAdjacentLocations(l);
    bool passing;
    if (list == r) {
        passing = true;
    } else {
        passing = false;
    }
    if (strcmp(expectation, "pass") == 0 && passing) {
        std::cout << "passed" << std::endl;
        return;
    } else {
        std::cout << "failed" << std::endl;
        return;
    }
    if (strcmp(expectation,"fail") == 0 && !passing) {
        std::cout << "passed" << std::endl;
        return;
    } else {
        std::cout << "failed" << std::endl;
        return;
    }
}

int main() {
	
	// Create GameStateManager to setup game
	Location* location = new Location();
    std::cout << "test" << std::endl;
    
    std::vector<int> list = {1, 2, 15};
    locationTest(*location,0,list, "pass");
    std::vector<int> list2 = {11,12};
    locationTest(*location,10,list2, "pass");
    std::vector<int> list3 = {22,19};
    locationTest(*location,23,list3, "pass");
    locationTest(*location,19,list3, "fail");
    
}