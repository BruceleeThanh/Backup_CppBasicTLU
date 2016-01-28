#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, denta, X, X1, X2, X11, X12;
	cout << "           Phuong trinh bac 2 co dang: aX^2 + bX + c = 0" << endl;
	cout << "Nhap he so a: " ;
	cin >> a;
	cout << "Nhap he so b: ";
	cin >> b;
	cout << "Nhap he so c: ";
	cin >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				cout << "Phuong trinh co vo so nghiem." << endl;
			if (c != 0)
				cout << "Phuong trinh vo nghiem." << endl;
		}
		else
		{
			X = (-c) / b;
			cout << "Phuong trinh co nghiem la: " << X << endl;
		}
	}
	else
	{
		denta = pow(b, 2) - 4 * a*c;
		if (denta < 0)
		{
			cout << "Phuong trinh vo nghiem thuc." << endl;
			denta = denta*(-1);
			X11 = (-b) / (2 * a);
			X12 = (sqrt(denta)) / (2 * a);
			
			cout << "Phuong trinh co 2 nghiem Phuc la:" << endl;
			cout << "X1 = " << X11 << " + " << X12 << "i" << endl;
			cout << "X2 = " << X11 << " - " << X12 << "i" << endl;
		}
		else
		{
			if (denta == 0)
			{
				X = (-b) / (2 * a);
				cout << "Phuong trinh co nghiem la X = " << X << endl;
			}
			else
			{
				X1 = (-b - sqrt(denta)) / (2 * a);
				X2 = (-b + sqrt(denta)) / (2 * a);
				cout << "Phuong trinh co 2 Nghiem la:" << endl;
				cout << "X1 = " << X1 << endl;
				cout << "X2 = " << X2 << endl;
			}
		}
	}
	cout << "_____________________________________________" <<endl;
	cout << endl << "Thanks for watching"<< endl <<"Design by Brucelee Thanh"<< endl;

	_getch();
	return 0;

}