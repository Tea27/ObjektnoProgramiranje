#include "Game.hpp"

using namespace std;
Game::Game() {
	bool gameOver = false;
	defaultScore = 5;
	coins = { COINONE, COINTWO, COINTHREE };
}

int Game::getScore() {
	return defaultScore;
}

bool Game::getGameOver() {
	return gameOver;
}

void Game::setGameOver() {
	gameOver = true;
}

void Game::checkGuesses(std::vector<Player*> player, int totalPlayers) {
	int guess;
    
    for (int i = 0; i < totalPlayers; i++) {
        for (int j = 0; j < totalPlayers; j++) {
            if (i != j) {
                guess = player[i]->guessCoinsSum(i, j);
                if (guess == player[j]->getSumOfCoins()) {
                    cout << "Right Guess!" << endl;
                    player[i]->setScore();
                }
                else {
                    cout << "Wrong Guess!" << endl;
                }
            }   
        }
    }
}