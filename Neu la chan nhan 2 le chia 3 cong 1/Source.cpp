#include <iostream>
using namespace std;
bool kiemtraNguyento(long long b);
bool kiemtraNguyento(long long b)
{
	int i = 2;
	if ((b == 2) || (b == 3))
		return 1;
	while (i <= (int)sqrt((double)b))
	{
		if (b%i == 0)
		{
			return 0;
			break;
		}
		else
		{
			i++;
			if (i > (int)sqrt((double)b))
				return 1;
		}
	}
	return kiemtraNguyento;
}
int main()
{
	long long a, dem = 1, i = 0, x[100000];
	cout << "Nhap a: "; cin >> a;
	cout << "Day so la: " << a << " ";
	while (a > 1)
	{
		if ((a % 2) == 0)
		{
			a = a / 2;
			dem++;
			cout << a << " ";
			if (kiemtraNguyento(a) == 1)
			{
				x[i] = a;
				i++;
			}
		}
		else
		{
			a = a * 3 + 1;
			dem++;
			cout << a << " ";
			if (kiemtraNguyento(a) == 1)
			{
				x[i] = a;
				i++;
			}
		}
	}
	cout << endl << "Day so co: " << dem << " so." << endl;
	cout << endl << "Co " << i - 1 << " so nguyen to trong day." << endl;
	cout << "Cac so nguyen to trong day la: ";

	for (i-=2; i >= 0; i--)
	{
		cout << x[i] << " ";
	}
	cout << endl << endl;


	return 0;
}