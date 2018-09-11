#pragma once
#include <iostream>
#include <string>
#include "Function.h"

using namespace std;

class Polynomial : public Function
{
public:
	Polynomial();
	Polynomial(int c, char v, int p);
	void print();
	void derivative();
	~Polynomial();
};

