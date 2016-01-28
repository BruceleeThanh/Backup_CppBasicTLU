#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
ifstream doc("Problem 11.txt");
ofstream ghi("Record.txt");
int main()
{
	int a[20][20];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			doc >> a[i][j];
		}
	}


	long long tich[100000], max;
	int z = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i < 17)
			{
				tich[z] = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
				z++;
			}
			if (j < 17)
			{
				tich[z] = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
				z++;
			}
			if ((i < 17) && (j < 17))
			{
				tich[z] = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
				z++;
			}
			if ((i>3) && (j < 17))
			{
				tich[z] = a[i][j] * a[i - 1][j + 1] * a[i - 2][j + 2] * a[i - 3][j + 3];
				z++;
			}
		}
	}
	max = tich[0];
	for (int i = 1; i < z; i++)
	{
		if (max < tich[i]) max = tich[i];
	}
	cout << "KQ: " << max << endl;
	ghi << max;
	return 0;
}