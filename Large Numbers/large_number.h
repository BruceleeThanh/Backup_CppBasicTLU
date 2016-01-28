#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

class LargeNumber
{
private:
	string a, b, ans;
public:
	LargeNumber();
	LargeNumber(string);
	void setLargeNumber(string);
	string getLargeNumber();
	int Length() const;
	LargeNumber operator +(LargeNumber x);
	LargeNumber operator -(LargeNumber x);
	LargeNumber operator *(LargeNumber x);
	LargeNumber operator /(LargeNumber x);
};


#endif