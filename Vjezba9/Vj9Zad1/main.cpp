/*Napravite igru Japaneža za više igrača.U igri svaki igrač ima tri kovanice,
od 1, 2 i 5 kuna.U svakoj ruci odabire od nula do tri kovanice i pogađa zbroj
odabranih kovanica u rukama svih igrača.Igrači koji pogode zbroj dobiju po
jedan bod.Igrač može biti čovjek ili kompjuter.Igra se igra dok jedan od
igrača ne postigne unaprijed zadani broj bodova.
Klase koje trebate definirati :
· Game, zadužena za logiku igre
· Player, predstavlja igrača.Iz te klase izvedite dvije klase : HumanPlayer
i ComputerPlayer.*/
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
int main()
{
    srand(time(NULL));
    int humanPlayers, computerPlayers;
    Game game;

    cout << "enter the number of human players: ";
    cin >> humanPlayers;
    cout << "enter the number of computer players: ";
    cin >> computerPlayers;
    const int totalPlayers = humanPlayers + computerPlayers;

    vector<Player*> player;

    for (int i = 0; i < totalPlayers; i++) {
        if (i < humanPlayers) {
            player.push_back(new HumanPlayer);
        }
        else {  
            player.push_back(new ComputerPlayer);
        }
    }
    
    while (!game.getGameOver()) {
        for (auto el : player) {
            el->selectCoins();
            el->checkifPlayerWins(game.getScore());
        }
     
        game.checkGuesses(player, totalPlayers);

        
        for(int i = 0; i < totalPlayers; i++){
            player[i]->setSumOfCoins();
            if (player[i]->getWinner()) {
                cout << "Player number: " << i << " won!";
                game.setGameOver();
            }
           
        }
    }
    
}


