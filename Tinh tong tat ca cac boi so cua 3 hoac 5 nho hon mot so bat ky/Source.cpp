#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	double n, a, b, Tong;
	cout << "      Tinh tong tat ca cac boi so cua 3 hoac 5 nho hon mot so bat ky.?" << endl;
	cout << "Hay nhap so: ";
	cin >> n;
	Tong = 0;
	n = n - 1;
	cout << "Tong cac boi cua 3 hoac 5 nho hon " << n << " la: ";
	while (n > 2)
	{
		a = n / 3;
		b = n / 5;
		if ((a == (int)a) || (b == (int)b))
		{
			cout << n << " + ";
			Tong = Tong + n;
		}
		n--;
	}
	
	cout << "0 = " << Tong << endl;


	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;

	_getch();
	return 0;
}