#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	double n, b, c, Tong, Tong1, Tong2;
	int i;
	i = 1;
	Tong = 0;
	Tong1 = 0;
	Tong2 = 0;
	cout << "Nhap so: ";
	cin >> n;
	while (n > 1)
	{
		while (i < n)
		{
			b = n / i;
			if (b == (int)b)
			{
				Tong1 = Tong1 + i;
				i++;
			}
			else
				i++;
		}
		i = 1;
		if (Tong1 != n)
		{
			while (i < Tong1)
			{
				c = Tong1 / i;
				if (c == (int)c)
				{
					Tong2 = Tong2 + i;
					i++;
				}
				else
					i++;
			}
		}
		if (Tong2 == n)
		{
			Tong = Tong + n;
		}
		n--;
		i = 1;
		Tong1 = 0;
		Tong2 = 0;
	}
	cout << "Ket qua la: " << Tong << endl;


	_getch();
	return 0;
}