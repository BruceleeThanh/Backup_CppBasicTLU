#include <iostream>
#include <math.h>
using namespace std;
bool kiemtraNguyenTo(long long b);
bool kiemtraNguyenTo(long long b)
{
	int i = 2;
	if (b == 2 || b == 3)
		return 1;
	else
	{
		while (i <= (int)sqrt((double)b))
		{
			if (b%i == 0)
			{
				return 0;
				break;
			}
			else
				i++;
			if (i>(int)sqrt((double)b))
				return 1;

		}
	}
	return kiemtraNguyenTo;
}
int main()
{
	long long n, i;
	cout << "Nhap n: "; cin >> n;
	cout << "Ket qua la: " << n << " = ";
	for (i = 2; i <= n; i++)
	{
		if (kiemtraNguyenTo(i) == 1)
		{

			while (n%i == 0)
			{
				n = n / i;
				cout << i << " ";
			}
		}
	}


	return 0;
}