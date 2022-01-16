#include "Player.hpp"

using namespace std;

Player::Player() {
	score = 0;
	sumOfCoins = 0;
	numberOfSelectedCoins = 0;
}

void Player::setSumOfCoins() {
	sumOfCoins = 0;
}

void Player::setScore() {
	score += 1;
}

int Player::getSumOfCoins() {
	return sumOfCoins;
}

bool Player::checkguessCoinsSum(int guess) {
	return(sumOfCoins == guess);
}

void Player::checkifPlayerWins(int gameScore) {
	if (gameScore = score) {
		winner = true;
	}
}


bool Player::getWinner() {
	return winner;
}

void Player::checkInput() {
	cout << endl << "How many coins do you want: ";
	cin >> numberOfSelectedCoins;
	while (numberOfSelectedCoins > 3 || numberOfSelectedCoins < 0) {
		cout << endl << "Wrong entry!!" << endl;
		cout << endl << "How many coins do you want: ";
		cin >> numberOfSelectedCoins;
	}
}

void HumanPlayer::selectCoins() {
	checkInput();
	
	while (selectedCoins.size() < numberOfSelectedCoins) {
		cout << "Please select coin: ";
		cin >> coin;
		sumOfCoins += coin;
		if (coin == COINONE || coin == COINTWO || coin == COINTHREE) {
			selectedCoins.push_back(coin);
		}
		else {
			cout << "Wrong entry!!" << endl;
		}
	}

	selectedCoins.clear();
	
}

void ComputerPlayer::selectCoins() {
	numberOfSelectedCoins = rand() % 4;
	cout << endl << "computer selected coins" << endl;

	possibleCoins = { COINONE, COINTWO, COINTHREE };
	int indexOfCoin = 0;

	while (selectedCoins.size() < numberOfSelectedCoins) {
		indexOfCoin = rand() % possibleCoins.size();
		coin = possibleCoins[indexOfCoin];
		sumOfCoins += coin;
		possibleCoins.erase(possibleCoins.begin() + indexOfCoin);
		selectedCoins.push_back(coin);
	}

	selectedCoins.clear();
}

int HumanPlayer::guessCoinsSum(int i, int j) {
	cout << endl << "Player number " << ++i << " guesses the number for player " << ++j << endl;
	cin >> guess;
	return guess;
}

int ComputerPlayer::guessCoinsSum(int i, int j) {
	int numberOfGuess = rand() % guesses.size();
	cout << endl << "Player number " << ++i << " guessed the number for player " << ++j << endl;
	return guesses[numberOfGuess];
}