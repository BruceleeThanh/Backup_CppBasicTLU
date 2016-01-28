#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	double a, b, c, s, r, t, D, Dx, Dy, X, Y;
	cout << "He phuong trinh 2 an co dang:" << endl << " aX + bY = c" << endl << " sX + rY = t" << endl;
	cout << "Nhap lan luot a, b, c: ";
	cin >> a >> b >> c;
	cout << "Nhap lan luot s, r, t: ";
	cin >> s >> r >> t;
	D = a*r - s*b;
	Dx = c*r - b*t;
	Dy = a*t - s*c;
	if (D != 0)
	{
		X = Dx / D;
		Y = Dy / D;
		cout << "He phuong trinh co nghiem duy nhat: X=" << X << " , Y=" << Y << endl;
	}
	else
	{
		if (Dx == 0)
			cout << "He phuong trinh Vo nghiem" << endl;
		if (Dy == 0)
			cout << "He phuong trinh Vo nghiem" << endl;
		if (Dx == Dy == 0)
			cout << "He phuong trinh co vo so nghiem" << endl;
			
	}

	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;


	_getch();
	return 0;
}