#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int a, b, c, b1, b2, c1, c2, d;
	cout << "          Nhap so co 4 chu so, in ra man hinh tong cua 4 chu so do.?" << endl;
	cout << "Hay nhap so: ";
	cin >> a;
	b = a / 100;
	b1 = b / 10;
	b2 = b % 10;
	c = a % 100;
	c1 = c / 10;
	c2 = c % 10;
	d = b1 + b2 + c1 + c2;
	cout << "Tong cac chu so cua so tren la: " << b1 << "+" << b2 << "+" << c1 << "+" << c2 << "=" << d << endl;
	

	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;

	_getch();
	return 0;
}