#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	double a, b, c, d;
	int e;
	cout << "           Ban muon biet so ngay trong thang cua bat ky nam nao .?" << endl;
	cout << "Hay nhap nam: ";
	cin >> a;
	cout << "Hay nhap thang: ";
	cin >> e;
	b = a / 4;
	c = a / 100;
	d = a / 400;
	if (a<400)
	{
		if (b == (int)b)
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 29 ngay" << endl;
				break;
			}
		}
		else
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 28 ngay" << endl;
				break;
			}
		}

	}
	else
	if (c == (int)c)
	{
		if (d == (int)d)
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 29 ngay" << endl;
				break;
			}
		}
		else
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 28 ngay" << endl;
				break;
			}
		}
	}
	else
	{
		if (b == (int)b)
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 29 ngay" << endl;
				break;
			}
		}
		else
		{
			switch (e)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				cout << "Thang " << e << " cua nam " << a << " co 31 ngay" << endl;
				break;
			case 4: case 6: case 9: case 11:
				cout << "Thang " << e << " cua nam " << a << " co 30 ngay" << endl;
				break;
			case 2:
				cout << "Thang " << e << " cua nam " << a << " co 28 ngay" << endl;
				break;
			}
		}
	}
	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;
	_getch();
	return 0;
}