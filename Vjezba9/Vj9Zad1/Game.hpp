#pragma once
#include <vector>
#include <iostream>
#include "Player.hpp"


class Game {
	bool gameOver;
	int defaultScore;
	std::vector<int> coins;

public:
	Game();
	int getScore();
	void setGameOver();
	bool getGameOver();
	void checkGuesses(std::vector<Player*> player, int totalPlayers);
};