// -- Derivative Calculator -- //

/**

We want this program to find the derivative of a polynomial
If the given input (as a polynomial) is: x^2:
	We want to output it's derivative as 2x
Likewise with longer and more complicated functions

	-- Take input as a line
		-- If input is wrong then output error message and try again
	-- Break input into components (x and its powers)
		-- Use an abstract function class for all generalized functions
		-- Function class will have: variable, power, and derivative operations
		-- All other functions will inherit these operations
			-- For polynomials specifically:
				-- Idea is to use a polynomial class to represent a single polynomial:
				-- This makes sense because you can have seperate components (i.e. constants, variables, powers, and if its positive or negative)
				-- Then you can use a list to store these components
	-- Use power rules / other rules to take the derivative to input the derivative function into another list
	-- Output the list's contents

**/

#include <iostream>
#include <conio.h> // _getch()
#include <string> // string
#include <list> // list
#include <stdlib.h> // system("CLS")

// Classes
#include "Polynomial.h"
// Eventually should make a handler
// This handler will manage all the interactions with the different function classes
// Right now we can handle single polynomials in the source file

using namespace std;

void displayMenu();
list<Polynomial*> decompose(string); // this function will decompose the string into its separate functions
									 // and will return a list of Polynomial objects 

int main() {
	int choice;

	// gets input
	displayMenu();
	cin >> choice;

	while (choice != 2) {
		if (choice == 1) {
			int constant, exponent;
			char variable;

			cout << "Please enter the constant: ";
			cin >> constant;
			cout << "Please enter the variable: ";
			cin >> variable;
			cout << "Please enter the exponent: ";
			cin >> exponent;

			Polynomial poly(constant, variable, exponent);
			cout << "Here is your polynomial: " << endl;
			poly.print();
			cout << "Here is your derivative: " << endl;
			poly.derivative();
			poly.print();

			_getch();
		}
		system("CLS");
		displayMenu();
		cin >> choice;
	}

	return 0;
}

void displayMenu() {
	cout << "-- Please input your choice --" << endl;
	cout << "1- To take the derivative of a polynomial" << endl;
	cout << "2- To quit" << endl;
}

// next step is to create a menu in which we will be able to choose an option (take derivative of polynomial is all we will have now)
// we need to be able to concactate polynomials in string form and decompose them in a function
// we will then pass these separate polynomials to a list
// we will preform our operations as needed on the list

//list<Polynomial*> decompose(string line) {
//	char character, variable = ' ';
//	int constant = 0, exponent = 0;
//	list<Polynomial*> polies;
//
//	for (int i = 0; i < line.length(); i++) {
//		if (i == '^') { // Checks for exponent
//			exponent = (i + 1) - '0';
//			i++;
//		}
//		else if (isalpha(i)) { // Checks for variable
//			variable = i;
//		}
//		else if (isdigit(i)) { // Checks for constant
//			constant = i - '0';
//		}
//		else if (constant != 0 && variable != ' ' && exponent != 0) {
//			Polynomial *p = new Polynomial(constant, variable, exponent);
//			polies.push_back(p);
//		}
//		//else { // If i == ' ', then functions will push new polynomial with values into the list
//			//Polynomial *p = new Polynomial(constant, variable, exponent);
//			//polies.push_back(p);
//		//}
//		
//	}
//	return polies;
//}