/*Koristeći vector napravite implementaciju igre šibica gdje korisnik igra protiv ra-
čunala. Pravila ove igre su vrlo jednostavna. Pred 2 igrača postavi se 21 šibica.
Igrači se izmjenjuju i uklanjaju 1, 2 ili 3 šibice odjednom. Igrač koji je prisiljen uzeti
posljednju šibicu gubi.
Korisnik unosi izbor, dok se za odabir računala bira slučajnim izborom. Igraču se
mora dati prednost, tako da računalo prvo započinje igru.
Prije pisanja koda promislite o problemu, koji su mogući slučajevi, kad je sigurna
pobjeda, kad je neizbježan poraz.*/

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <windows.h>

using namespace std;

void printMatches(vector<char> matchBox,int n) {
    cout << endl << "There are currently " << n << " matches:" << endl;
    for (int i = 0; i < n; i++) {
        cout << matchBox[i] << " ";
    }
}

void popBackMatches(vector<char>& matchBox, int n) {
    for (int i = 0; i < n; i++) {
        matchBox.pop_back();
    }
}
int main()
{
    srand(time(NULL));
    vector<char> matchBox(21, '|');
    int matchesCount = matchBox.size();
    int userChosen = NULL, computerChosen;
    bool winner = false;

    system("Color E4");

    printMatches(matchBox, matchesCount);

    while (matchesCount > 1) {


        if (matchesCount < 5) {
            computerChosen = (matchesCount - 1);
        }
        else if (!userChosen) {
            computerChosen = (rand() % 3) + 1;
        }
        else if ((userChosen % 2) == 0) {
            computerChosen = 1 + (2 * rand()) % 4; //if user chosen is even, computer picks one odd number (1 or 3)
        }
        else {
            computerChosen = 2;
        }

        winner = false;
        cout << endl << endl << "Computer picks up " << computerChosen << " match sticks." << endl;

        popBackMatches(matchBox, computerChosen);
        matchesCount -= computerChosen;
        printMatches(matchBox, matchesCount);

        if (matchesCount == 1) break;

        cout << endl << endl << "Pick up the match sticks between (1 to 3): ";
        cin >> userChosen;
        winner = true;
        if ((userChosen > 3) || (userChosen < 1)) {
            cout << endl << "Invalid Entry";
            break;
        }

        popBackMatches(matchBox, userChosen);
        matchesCount -= userChosen;
        printMatches(matchBox, matchesCount);

        matchesCount = matchBox.size();
    }

    if (winner && (matchesCount == 1)) {
        cout << endl << "CONGRATULATIONS!!! YOU WON!!!!! ";
    }
    if(!winner && (matchesCount == 1)){
        cout << endl << "YOU LOST!!!";
    }
}
