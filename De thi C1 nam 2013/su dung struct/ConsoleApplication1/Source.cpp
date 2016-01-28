#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct nhanVien
{
	string tennv;
	int giolv;
	char xl;
	int stt;
	int day;
	int month;
	int years;
};
nhanVien t[100];
int n;
void nhapDulieu()
{
	cout << "Nhap so nhan vien: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten cua nhan vien " << i + 1 << " : "; cin.ignore(); getline(cin, t[i].tennv);
		cout << "Nhap gio lam viec cua nhan vien " << i + 1 << " : "; cin >> t[i].giolv;
		t[i].stt = i + 1;
		cout << "Nhap ngay, thang, nam sinh cua nhan vien " << i + 1 << " : "; cin >> t[i].day >> t[i].month >> t[i].years;
	}
}
void xepLoai()
{
	for (int i = 0; i < n; i++)
	{
		if (t[i].giolv<100) t[i].xl = 'D';
		if (t[i].giolv >= 100 && t[i].giolv<150) t[i].xl = 'C';
		if (t[i].giolv >= 150 && t[i].giolv<200) t[i].xl = 'B';
		if (t[i].giolv >= 200) t[i].xl = 'A';
	}
}
void disPlay()
{
	cout << "STT" << setw(30) << "TenNv" << setw(10) << "GioLv" << setw(10) << "Xeploai" << setw(10) << "Ngaysinh" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << t[i].stt << setw(30) << t[i].tennv << setw(10) << t[i].giolv << setw(10) << t[i].xl << setw(10) << t[i].day << "/" << t[i].month << "/" << t[i].years << endl;
	}
}
void sapXep()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i].giolv<t[j].giolv)
			{
				nhanVien temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}

	}
}
int main(int argc, char *argv[])
{
	nhapDulieu();
	xepLoai();
	disPlay();
	sapXep();
	cout << "______________________________________" << endl;
	disPlay();

	return 0;
}