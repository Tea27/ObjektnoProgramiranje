#include <iostream>
#include <string>
#include "stuffing_unstuffing.h"

using namespace std;

int main()
{
	char bin;
	string binary;
	cout << "Enter bits" << endl;
	while (cin >> bin) {
		if((bin != '1') && (bin != '0')) {
			break;
		}
		binary.push_back(bin);
	}

	stuffing_bit(binary, binary.size());

	cout << endl << "Result of stuffing_bit" << endl;
	print_binary(binary, binary.size());

	
	unstuffing_bit(binary, binary.size());

	cout << endl << "Result of unstuffing_bit" << endl;
	print_binary(binary, binary.size());
}

