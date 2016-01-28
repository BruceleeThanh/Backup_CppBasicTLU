#include<iostream>
using namespace std;

int main()
{
	int n, x, m, y, j = 0, a[10000];
	cout << "Nhap so bit trong xau: "; cin >> n;
	x = n;
	for (int i = 0; i < x; i++)
	{
		cout << "Toi doan la: ";
		for (int k = 0; k < x - n; k++) cout << 0;
		for (int h = 0; h < n; h++) cout << 1;
		cout << endl << "Co bao nhieu so dung: "; cin >> m;
		if (m==x) goto jump;
		a[j++] = m;
		n--;
	}
	a[j++] = x - a[0];
	for (int y = 0; y < j - 1; y++)
	{
		if (a[y]>a[y + 1]) cout << 1;
		else cout << 0;
	}
	jump:
	cout << endl << "Toi doan dung roi nhe.!" << endl << endl;


}