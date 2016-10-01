#include "readint.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include <ios>

using namespace std;

int read_int(const string &prompt, int low, int high) {
	
	cin.exceptions(ios_base::failbit);
	int num = 0;

	while (true) {			//Loop until vaild input
		try {
			cout << prompt;
			cin >> num;
			if (num < low || num > high)
				throw range_error("");
			else
				return num;
		}
		catch (range_error& er) {
			cout << "Try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

	}
	



}
