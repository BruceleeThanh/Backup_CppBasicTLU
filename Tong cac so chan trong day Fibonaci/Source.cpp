#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int long long n, a, b, Tong;
	cout << "Nhap gioi han cua Fibonaci: ";
	cin >> n;
	a = 1;
	b = 2;
	Tong = 2;
	while ((a <= n) && (b <= n))
	{
		a = a + b;
		if ((a <= n) && (b <= n))
		{
			if ((a % 2) == 0)
			{
				Tong = Tong + a;
				cout << a << " ";
			}
		}
			b = a + b;
			if ((a <= n) && (b <= n))
			{
				if ((b % 2) == 0)
				{
					Tong = Tong + b;
					cout << b << " ";
				}
			}
			
	}
	cout << endl << "Tong cac so chan trong day Fibonaci nho hon " << n << " la: " << Tong << endl;

	_getch();
	return 0;
}