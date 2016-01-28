#include <iostream>
#include <math.h>
using namespace std;

int Giaithua(int);
int Tong(int);

int Giaithua(int n)
{
	int giaithua = 1;
	for (int i = 1; i <= n; i++)
		giaithua *= i;
	return giaithua;
}
int Tong(int n)
{
	int tong = 0;
	for (int i = 1; i <= n; i++)
		tong += i;
	return tong;
}
int main()
{
	int n;
	float Tong1, Tong2 = 0;
	cout << "Nhap n: "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		Tong1 = sqrt(Giaithua(i)) / Tong(i);
		Tong2 += Tong1;
	}
	cout << "Ket qua ung voi n = " << n << " la: " << Tong2 << endl;
	return 0;
}