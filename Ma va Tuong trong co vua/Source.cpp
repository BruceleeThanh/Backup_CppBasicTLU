#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, ma = 0, tuong = 0;
	cout << "     Ma va Tuong trong co Vua quan nao thang, quan nao thua.???" << endl << endl;
	cout << "Nhap toa do cua Ma: "; cin >> a >> b;
	cout << endl << "Nhap toa do cua Tuong: "; cin >> c >> d;
	if (((c - a) == 2) || ((a - c) == 2))
	{
		if (((d - b) == 1) || ((b - d) == 1))
			ma++;
	}
	if (((c - a) == 1) || ((a - c) == 1))
	{
		if (((d - b) == 2) || ((b - d) == 2))
			ma++;
	}
	for (int i = 1; i <= 7; i++)
	{
		if (((c + i) == a) && (((d - i) == b) || ((d + i) == b)))
			tuong++;
		if (((c - i) == a) && (((d - i) == b) || ((d + i) == b)))
			tuong++;
	}
	if (ma == 1)
		cout << endl << "Ma an Tuong. Ma thang roi.!" << endl;
	if (tuong == 1)
		cout << endl << "Tuong an Ma. Tuong thang roi.!" << endl;
	if ((ma == 0) && (tuong == 0))
		cout << endl << "Khong quan nao an duoc nhau.!" << endl;

	return 0;
}