#include <iostream>
#include <string.h>
#include "Location.h"

void locationTest(Location& location, int l,std::vector<int> list, const char *expectation, int number) {
    std::vector<int> r = location.getAdjacentLocations(l);
    bool passing;
    if (list == r) {
        passing = true;
    } else {
        passing = false;
    }
    if (strcmp(expectation, "pass") == 0) {
        if (passing) {
            std::cout << "Test " << number << " passed" << std::endl;
            return;
        } else {
            std::cout << "Test " << number << " failed" << std::endl;
            return;
        }
    }
    
    if (strcmp(expectation,"fail") == 0) {
        if (!passing) {
            std::cout << "Test " << number << " passed" << std::endl;
            return;
        } else {
            std::cout << "Test " << number << " failed" << std::endl;
            return;
        }
    }
}

void adjacentTest(Location& location, int one, int two, const char *expectation, int number) {
    if (strcmp(expectation,"pass") == 0) {
        if (location.isAdjacent(one, two) == 1) {
            std::cout << "Test " << number << " passed" << std::endl;
            return;
        } else {
            std::cout << "Test " << number << " failed" << std::endl;
            return;
        }
    }
    if (strcmp(expectation,"fail") == 0) {
        if (location.isAdjacent(one, two) == 0) {
            std::cout << "Test " << number << " passed" << std::endl;
            return;
        } else {
            std::cout << "Test " << number << " failed" << std::endl;
            return;
        }
    }
}

int main() {
	
	Location* location = new Location();
    std::cout << "Tests" << std::endl;
    
    std::vector<int> list = {1, 2, 15};
    locationTest(*location,0,list, "pass", 1);
    std::vector<int> list2 = {11,12};
    locationTest(*location,10,list2, "pass", 2);
    std::vector<int> list3 = {22,19};
    locationTest(*location,23,list3, "pass", 3);
    locationTest(*location,19,list3, "fail", 4);
    locationTest(*location,29,list3, "fail", 5);
    
    adjacentTest(*location, 19, 14, "pass", 6);
    adjacentTest(*location, 9, 8, "pass", 7);
    adjacentTest(*location, 5, 9, "fail", 8);
    adjacentTest(*location, 55, 95, "fail", 9);


    
    
}