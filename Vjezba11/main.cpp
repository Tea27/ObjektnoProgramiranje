#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

void readIntsToVector(const string& fileName, vector<int>& numbers)
{
	ifstream file;
	int tmp;

	file.open(fileName.c_str());
	if (file.fail()) {
		throw exception();
	}

	istream_iterator<int> it(file);
	istream_iterator<int> eos;
	copy(it, eos, back_inserter(numbers));

}

int main()
{
	vector<int> intVector;
	const string fileName = "numbers.txt";

	try {
		readIntsToVector(fileName, intVector);
	}
	catch (const exception& e) {
		cerr << "Unable to open file " << fileName << endl;
		exit(1);
	}

	for (auto number : intVector) {
		cout << number << " ";
	}
	cout << endl << endl;

	int greaterThan500 = count_if(intVector.begin(), intVector.end(), [](int i) { return i > 500; });
	cout << "Numbers greater than 500: " << greaterThan500 << endl << endl;

	int minElement = *min_element(intVector.begin(), intVector.end());
	int maxElement = *max_element(intVector.begin(), intVector.end());
	cout << "Min element in vector is: " << minElement << endl << "Max element in vector is: " << maxElement << endl;

	std::vector<int>::iterator it;
	it = remove_if(intVector.begin(), intVector.end(), [](int i) { return i < 300; });
	intVector.resize(std::distance(intVector.begin(), it));
	sort(intVector.begin(), intVector.end(), greater<int>());

	for (auto number : intVector) {
		cout << number << " ";
	}

	cout << endl << endl;
	return (0);
}

