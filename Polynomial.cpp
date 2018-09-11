#include "Polynomial.h"



Polynomial::Polynomial()
{
	constant = 1;
	variable = ' ';
	exponent = 1;
}

Polynomial::Polynomial(int c, char v, int p)
{
	constant = c;
	variable = v;
	exponent = p;
}

void Polynomial::print()
{
	if (constant == 1) { // Will not print constant if equal to 1
		cout << variable << "^" << to_string(exponent) << endl;
	}
	else if (exponent == 1) { // Will not print exponent
		cout << to_string(constant) << variable << endl;
	}
	else if (exponent == 0) { // It does not print "x^0"
		cout << to_string(constant) << endl;
	}
	else { // regular print expression: i.e. 7x^4
		cout << to_string(constant) << variable << "^" << to_string(exponent) << endl;
	}
}

void Polynomial::derivative()
{
	if (exponent != 0) { // need so we do not get negative exponents (and 0 as a constant)
		constant *= exponent;
		exponent -= 1;
	}
	else { // when term is a constant and next derivative is 0
		constant = 0;
	}
}


Polynomial::~Polynomial()
{
}
