/*Napišite template klasu Stack. Implementirajte funkcije članove za operacije
push, pop i is_empty.
Napomena: Odvojite sučelje i implementaciju u različite .cpp i .h datoteke.*/
#include "Stack.hpp"
#include <iostream>

using namespace std;

int main() {
	int n = 4;
	Stack<int> intStack(n);

	for (int i = 0; i < n; i++) {
		intStack.push(i);
	}
	
	intStack.print();
	intStack.pop();

	if (intStack.isEmpty()) {
		cout << "Stack is not empty";
	}
	else {
		cout << "Stack is empty";
	}
	
}