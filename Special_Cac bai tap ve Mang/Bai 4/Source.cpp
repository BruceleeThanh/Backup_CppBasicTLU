#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double daySo[100000], N, x, tong = 0;
	long i;
	cout << "Nhap gioi han cua day so thuc: "; cin >> N;
	cout << "Nhap day so: ";
	for (i = 0; i < N; i++) cin >> daySo[i];
	cout << "Nhap so thuc X: "; cin >> x;
	for (i = 0; i < N; i++)
	{
		tong += daySo[i] * pow(x, i);
	}
	cout << "Ket qua cua da thuc la: " << tong << endl;

	return 0;
}