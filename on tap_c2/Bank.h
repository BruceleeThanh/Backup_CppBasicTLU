#pragma once
#include <iostream>
using namespace std;
#include "Account.h"
class Bank:public Account
{
private:
	Account acc[1000];
	int n = 0;
public:
	Bank();
	~Bank();

	void AddTK();
	void TKAmTien();
	void TKMaxTien();
	void InTK(int);
	void NapTien(int, long long);
	void RutTien(int, long long);


};

