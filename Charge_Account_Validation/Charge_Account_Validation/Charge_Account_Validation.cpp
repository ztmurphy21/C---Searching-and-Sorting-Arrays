//Charge Account Validation Program
//Program determines if charge account number is valid based off array
//Programmer: Zach Murphy on 5-11-2017

#include<iostream>
#include <conio.h>

using namespace std;

//declaration for array size as global constant
const int SIZE = 18;

//function for search prototype
int searchArray(const int[], int, int);

int main() {
	//initalize array
	int accountNumbers[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
		8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
		1005231, 654231, 3852085, 7576651, 7881200, 4581022 };
	
	//variable declaration for search results
	int results;
	int findThis;

	//intro
	cout << "*******************************************************\n";
	cout << "\t\tAccount Number Validation\n";

	//get value to search for from user
	cout << "Please enter an account number to validate: ";
	cin >> findThis;
	cout << endl;

	results = searchArray(accountNumbers, SIZE, findThis);

	cout << endl << "\t\tResults:\n";
	//if searchArray returned -1, then value was not found...
	if (results == -1) {
		cout << "Value not found. Please try again.";
	}
	else {
		cout << findThis << " is a valid account number.";
	}

	cout << "\n*******************************************************\n";

	//allow user to exit
	cout << "\nPress any key to exit...\n";
	_getch();
	return 0;
}

int searchArray(const int accountArray[], int totalElem, int valueToFind) {
	//subscript to search array
	int index = 0;

	//records position of search value
	int position = -1;

	//flag for if the value was found
	bool isFound = false;

	while (index < totalElem && !isFound) {
		//if value was found
		if (accountArray[index] == valueToFind) {
			//set flag
			isFound = true;
			//record value subscript
			position = index;
		}
		//go to the next element
		index++;
	}
	return position; //will return position if found, but if not found will return -1
}