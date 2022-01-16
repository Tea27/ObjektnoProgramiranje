#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Counter.hpp"
#include "Bedbug.hpp"
#include "Hawk.hpp"
#include "BrownRecluse.hpp"
using namespace std;

int main()
{
    vector<Animal*> animal;
    Counter counter;

    animal.push_back(new Bedbug);
    animal.push_back(new Hawk);
    animal.push_back(new BrownRecluse);

    counter.count(animal);

    return 0;
}

