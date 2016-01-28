#include "Caro.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
using namespace std;

int main(){
	int n, x = 0, y = 0;
	char p = 'o';
	cout << "Nhap N hang, N cot: "; cin >> n;
	Caro caro(n);
	caro.Display(n,x,y);
	do{
		caro.Move(x, y, p, n);
	} while (1);

	


	return 0;
}
