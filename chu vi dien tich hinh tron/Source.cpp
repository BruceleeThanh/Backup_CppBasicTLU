#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	double a, b, c;
	const double so_pi = 3.14;
	cout <<"nhap ban kinh hinh tron: ";
	cin >> a;
	b = so_pi * (a*a);
	cout << "Dien tich hinh tron la: " << b << endl;
	c = 2 * so_pi*a;
	cout << "Chu vi hinh tron la: "<<c;


	
	_getch();
	return 0;
}