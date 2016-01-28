#include <iostream>
using namespace std;
void Cong(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2);
void ToiGian(long &tuso, long &mauso);
void Tru(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2);
void Chia(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2);
void DoiDau(long &tuso, long &mauso);
void Cong(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2)
{
	tuso = tuso1*mauso2 + tuso2*mauso1;
	mauso = mauso1*mauso2;
	ToiGian(tuso, mauso);
}
void ToiGian(long &tuso, long &mauso)
{
	long a = tuso, b = mauso;
	if (a < b)
	{
		long c = a;
		a = b;
		b = c;
	}
	while (b != 0)
	{
		long c = a%b;
		a = b;
		b = c;
	}
	tuso = tuso / a;
	mauso = mauso / a;
	DoiDau(tuso, mauso);
}
void Tru(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2)
{ 
	tuso = tuso1*mauso2 - tuso2*mauso1;
	mauso = mauso1*mauso2;
	ToiGian(tuso, mauso);
}
void Chia(long &tuso, long &mauso, long tuso1, long mauso1, long tuso2, long mauso2)
{
	tuso = tuso1*mauso2;
	mauso = mauso1*tuso2;
	ToiGian(tuso, mauso);
}
void DoiDau(long &tuso, long &mauso)
{
	if (mauso<0 && tuso>0)
	{
		mauso *= -1;
		tuso *= -1;
	}
	if (mauso < 0 && tuso < 0)
	{
		mauso *= -1;
		tuso *= -1;
	}
}
int main()
{
	long a, b, c, d, tuso, mauso;
	cout << "Nhap Tu so 1: "; cin >> a;
	cout << "Nhap Mau so 1: "; cin >> b;
	cout << "Nhap Tu so 2: "; cin >> c;
	cout << "Nhap Mau so 2: "; cin >> d;
	Cong(tuso, mauso, a, b, c, d);
	cout << "Tong 2 phan so: " << a << "/" << b << " + " << c << "/" << d << " = " << tuso << "/" << mauso << endl;
	Tru(tuso, mauso, a, b, c, d);
	cout << "Hieu 2 phan so: " << a << "/" << b << " - " << c << "/" << d << " = " << tuso << "/" << mauso << endl;
	Chia(tuso, mauso, a, b, c, d);
	cout << "Thuong 2 phan so: " << a << "/" << b << " : " << c << "/" << d << " = " << tuso << "/" << mauso << endl;


	return 0;
}