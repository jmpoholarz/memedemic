#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "GameStateManager.h"
#include "Screen.h"
#include "Location.h"

#include "TestScript.h"

int mainMenu();
int setupNewGame(GameStateManager& gsm);
int loadGame(GameStateManager& gsm);
