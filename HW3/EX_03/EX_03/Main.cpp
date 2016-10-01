#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;

int main()
{
	int low, high;
	cout << "Enter the range of values to read.\n";
	cout << "low: ";
	cin >> low;
	cout << "high: ";
	cin >> high;
	try
	{	
		if (low >= high)
			throw invalid_argument(" ");
		int number = read_int("Please enter a number within the range: ", low, high);
		cout << "You entered " << number << endl;
	}
	catch (invalid_argument &e) {
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		main();
	}
}
