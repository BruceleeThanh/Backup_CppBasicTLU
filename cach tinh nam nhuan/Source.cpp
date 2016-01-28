#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	double a,b,c,d;
	cout << "              Ban muon biet nam nao la nam nhuan.?" << endl;
	cout << "Hay nhap nam: ";
	cin >> a;
	b = a / 4;
	c = a / 100;
	d = a / 400;
	if (a<400)
	{
		if (b == (int)b)
			cout << "Nam " << a << " la nam nhuan" << endl;
		else
			cout << "Nam " << a << " khong phai la nam nhuan" << endl;

	}
	else
		if (c==(int)c)
		{
			if (d == (int)d)
				cout << "Nam " << a << " la nam nhuan" << endl;
			else
				cout << "Nam " << a << " khong phai la nam nhuan" << endl;
		}
		else
		{
			if (b == (int)b)
				cout << "Nam " << a << " la nam nhuan" << endl;
			else
				cout << "Nam " << a << " khong phai la nam nhuan" << endl;
		}
	cout << "_____________________________________________" << endl;
	cout << endl << "Thanks for watching" << endl << "Design by Brucelee Thanh" << endl;
	_getch();
	return 0;
}