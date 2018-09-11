#pragma once
class Function
{
protected:
	int constant; // must be positive or negative
	char variable;
	int exponent;
public:
	Function() {};
	~Function() {};
	virtual void print() = 0;
	virtual void derivative() = 0;
};

