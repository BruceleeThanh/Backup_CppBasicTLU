#include <iostream>
using namespace std;
class XepHau
{
private:
	char m[20][20];
	int N;
public:
	XepHau()
	{
		N = 0;
	};
	XepHau(int _N)
	{
		N = _N;
	};
	void KhoiTao()
	{
		for (int i = 0; N > i; i++)
		{
			for (int j = 0; N > j; j++)
			{
				m[i][j] = '-';
			}
		}
	};
	void In()
	{
		for (int i = 0; N > i; i++)
		{
			for (int j = 0; N > j; j++){
				cout << m[i][j] << "   ";
			}
			cout << endl << endl;
		}
	};
	bool XepDuoc(int x,int y)
	{	//Kiem tra theo hang ngang ben trai
		for (int i = 1; i < y; i++)
		{
			if (m[x - 1][i - 1] == 'H')
				return false;
		}
		//Kiem tra theo hang cheo ben tren goc trai
		for (int i = x - 1, j = y - 1; i >= 1 && j >= 1; j--, i--)
		{
			if (m[i - 1][j - 1] == 'H')
				return false;
		}
		//Kiem tra theo hang cheo ben duoi goc trai
		for (int i = x + 1, j = y - 1; N>=i && j>=1; i++, j--)
		{
			if (m[i - 1][j - 1] == 'H')
				return false;
		}
		return true;
	};
	void Xep(int j)
	{
		int static dem = 0;
		if (j >= N)
		{
			In();
			cout << "--------------------\n";
			dem++;
			cout << "Lan xep thu " << dem<<endl;
		}
		for (int i = 1; i <= N; i++)
		{
			if (XepDuoc(i, j))
			{
				m[i - 1][j - 1] = 'H';
				Xep(j + 1);
				m[i - 1][j - 1] = '-';
			}
		}

	}
};