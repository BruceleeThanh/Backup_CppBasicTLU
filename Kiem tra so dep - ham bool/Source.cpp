#include <iostream> 
#include <math.h> 
using namespace std;
bool kiemtraNguyento(long long);
bool soDep(long long);
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
bool soDep(long long b)
{
	if (kiemtraNguyento(b) == 1)
	{
		int d = 0, a = b;
		while (a > 0)
		{
			d = d * 10 + a % 10;
			a = a / 10;
		}
		if (d == b)
			return 1;
		else
			return 0;
	}
	if (kiemtraNguyento(b) == 0)
		return 0;
	return soDep;
}
int main()
{
	long long b, c;
	cout << "Nhap gioi han duoi: "; cin >> b;
	cout << "Nhap gioi han tren: "; cin >> c;
	cout << "Cac so Dep la: " << endl;
	for (b; b <= c; b++)
	{
		if (soDep(b) == 1)
		{
			cout << b << " ";
		}
	}
	cout << endl;

	return 0;
}