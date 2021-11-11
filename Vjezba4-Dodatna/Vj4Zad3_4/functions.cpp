#include <iostream>
#include <string>
#include "stuffing_unstuffing.h"

using namespace std;

void print_binary(string container, int n) {
	for (int i = 0; i < n; i++) {
		cout << container[i];
	}
}

void stuffing_bit(string& container, int n) {

	int c = 0;
	for (int i = 0; i < n; i++) {
		if (container[i] == '1') {
			c++;
			if (c == 5) {
				container.insert(++i, "0");
				c = 0;
			}
		}
		else {
			c = 0;
		}
	}
}

void unstuffing_bit(string& container, int size) {
	int c = 0;
	for (int i = 0; i < size; i++) {
		if (container[i] == '1') {
			c += 1;
			if (c == 5) {
				container.erase(++i, 1);
				c = 0;
			}
		}
		else {
			c = 0;
		}
	}
}
