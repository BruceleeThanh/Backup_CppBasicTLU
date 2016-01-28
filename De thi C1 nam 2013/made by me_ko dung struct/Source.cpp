#include <iostream>
#include <iomanip>
using namespace std;
char xeploai(double gio);
void inThongtin(int n, double gio, char xeploai1);
double sapxep(int n, double gio[]);
void inThongtin(int n, double gio[], char xeploai1[])
{
	int i;
	cout << endl << "STT" << setw(10) << "GioLV" << setw(10) << "Xep loai" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << i << setw(10) << gio[i] << setw(10) << xeploai1[i] << endl;
	}
}
char xeploai(double gio)
{
	char xeploai;
	if (gio < 100) xeploai = 'D';
	if (gio >= 100 && gio < 150) xeploai = 'C';
	if (gio >= 150 && gio < 200) xeploai = 'B';
	if (gio >= 200) xeploai = 'A';
	return xeploai;
}
double sapxep(int n, double gio[])
{
	double temp;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (gio[i] < gio[j])
			{
				temp = gio[i];
				gio[i] = gio[j];
				gio[j] = temp;
			}
		}
	}
	return gio[100];
}
int main()
{
	int n, i, dem = 0;
	double gio[100], tong = 0;
	char xeploai1[100];
	cout << "Nhap so nhan vien: "; cin >> n;
	cout << "Nhap so gio lam cua cac nhan vien:" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "Nhan vien " << i << " : "; cin >> gio[i];
		xeploai1[i] = xeploai(gio[i]);
		tong += gio[i];
	}
	inThongtin(n, gio, xeploai1);
	cout << endl << "Tong so gio lam viec cua nhan vien la: " << tong << endl;
	for (i = 1; i <= n; i++)
	{
		if (gio[i] >= 200) 
			dem++;
	}
	cout << "Co " << dem << " cong nhan xep loai A. So thu tu la: ";
	for (i = 1; i <= n; i++)
	{
		if (gio[i] >= 200)
			cout << i << " ";
	}
	sapxep(n, gio);
	for (i = 1; i <= n; i++)
	{
		xeploai1[i] = xeploai(gio[i]);
	}
	cout << endl << endl << "Ket qua sau khi sap xep la." << endl;
	inThongtin(n, gio, xeploai1);
	return 0;
}