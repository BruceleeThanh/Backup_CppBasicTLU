#include "phanso.h"
#include <iostream>
using namespace std;

int main()
{
	PhanSo ps1(9, 5), ps2(10, 5), ps3(50, 15),ps4;
	cout << ps1.getPhanso() << endl;
	ps4 = ps1 + ps2;
	cout << " + " << ps4.getPhanso() << endl;
	ps4 = (ps1*ps2)*ps3;
	cout << " * " << ps4.getPhanso() << endl;
	ps4 = ps3 - ps2;
	cout << " - " << ps4.getPhanso() << endl;
	ps4 = ps3 / ps2;
	cout << " / " << ps4.getPhanso() << endl;
	ps1++;
	cout << " ++ " << ps1.getPhanso() << endl;
	ps2--;
	cout << " -- " << ps2.getPhanso() << endl;

	return 0;
}