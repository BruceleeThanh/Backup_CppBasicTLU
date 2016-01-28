#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int a[100][100];
	int n, m, max, min, i, j;
	cout << "Nhap so dong m= ";
	cin >> m;
	cout << "\nNhap so cot n= ";
	cin >> n;
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
	{
		cout << "\n Nhap a[" << i << "][" << j << "]=";
		cin >> a[i][j];
	}
	cout << "\n ma tran vua nhap la: \n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j];
		cout << "\n";
	}
	for (i = 0; i<m; i++)
	{
		max = a[i][0];
		min = a[i][0];
		for (j = 1; j < n; j++)
		{
			if (min>a[i][j])
				min = a[i][j];
			if (max < a[i][j])
				max = a[i][j];

		}
		cout << "\nGTLN cua dong " << i + 1 << " la: ";
		cout << max;
		cout << "\n GTNN cua dong " << i + 1 << " la: ";
		cout << min;
	}
	_getch();
}