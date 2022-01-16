#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#define COINONE 1
#define COINTWO 2
#define COINTHREE 5
class Player {
protected:
	std::vector<int> selectedCoins;
	std::vector<int> possibleCoins;
	int coin;
	int numberOfSelectedCoins;
	int score;
	int guess;
	int sumOfCoins;
	bool winner = false;

public:
	Player();
	void setSumOfCoins();
	virtual void selectCoins() = 0;
	void setScore();
	bool checkguessCoinsSum(int guess);
	int getSumOfCoins();
	void checkifPlayerWins(int gameScore);
	bool getWinner();
	virtual int guessCoinsSum(int i, int j) = 0;
	void checkInput();
};

class HumanPlayer : public Player {
public:
	void selectCoins();
	int guessCoinsSum(int i, int j);
};

class ComputerPlayer : public Player {
	std::vector<int> guesses = { 0, 1, 2, 3, 5, 6, 7, 8 };

public:
	void selectCoins();
	int guessCoinsSum(int i, int j);
};