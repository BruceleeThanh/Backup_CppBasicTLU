#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
using namespace std;
class DoMin
{
private:
	int a[100][100];
	int Dong, Cot;
	int x, y;
public:
	DoMin();
	void KhoiTaoMaTranBanDau()
	{
		cout << "Nhap kich thuoc ma tran" << endl;
		cout << "Dong: ";
		cin >> Dong;
		cout << "Cot: ";
		cin >> Cot;
		srand(time(0));
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				a[i][j] = rand() % 2;
			}
			cout << endl;
		}
		ofstream fout("matran.txt");
		fout << Dong << " " << Cot << endl;
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				fout << a[i][j] << " ";
			}
			fout << endl;
		}
		fout.close();
		system("cls");
	}
	void InMaTranBanDau()
	{
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				cout << "X" << " ";
			}
			cout << endl;
		}
	}
	void NhapToaDo()
	{
		bool tieptuc = true;
		do{
			cout << " Nhap dong: ";
			cin >> x;
			cout << "Nhap  cot: ";
			cin >> y;
			x--;
			y--;
			if (a[x][y] == 1)
			{
				GameOver();
				tieptuc = false;

			}
			else if (a[x][y] == 0)
			{
				TimDuongDi(x, y);
				if (CheckWin() == true)
				{
					YouWin();
					break;
				}
				MaTranSauKhiNhap();
			}
		} while (tieptuc);
	}
	void GameOver()
	{
		/*
		Có đường đi nhưng chưa đi là: trái tim
		Có đường đi (có thể đi được) và đi rồi sẽ là 0
		Có đường đi (bom) và chưa đi hay đi rồi thì sẽ là 1
		Chưa mở sẽ là X
		*/
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				if (a[i][j] == 0)
				{
					cout << char(3) << " ";
				}
				if (a[i][j] == 1)
				{
					cout << char(15) << " ";
				}
				if (a[i][j] == 9)
				{
					cout << char(2) << " ";
				}
			}
			cout << endl;
		}
		cout << "Game Over" << endl;
	}
	void TimDuongDi(int x, int y)
	{
		a[x][y] = 9;
		if (a[x][y + 1] == 0 && y + 1 < Cot)
		{
			TimDuongDi(x, y + 1);
		}
		if (a[x][y - 1] == 0 && y - 1 >= 0)
		{
			TimDuongDi(x, y - 1);
		}
		if (a[x+1][y] == 0 && x + 1 >=0)
		{
			TimDuongDi(x+1, y);
		}
		if (a[x-1][y] == 0 && x - 1 < Dong)
		{
			TimDuongDi(x-1, y);
		}
	}
	bool CheckWin()
	{
		int SoDiemCoTheDi = 0;
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				if (a[i][j] == 0)
					SoDiemCoTheDi++;
			}
		}
		if (SoDiemCoTheDi == 0)
			return true;
		return false;
	}
	void YouWin()
	{
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				if (a[i][j] == 1)
				{
					cout << a[i][j] << " ";
				}
				else if (a[i][j] == 9)
				{
					cout << char(2) << " ";
				}
			}
			cout << endl;
		}
		cout << "YOU WIN" << endl;
	}
	~DoMin();
	void MaTranSauKhiNhap()
	{
		for (int i = 0; i < Dong; i++)
		{
			for (int j = 0; j < Cot; j++)
			{
				if (a[i][j] == 1)
				{
					cout << "X" << " ";
				}
				else if (a[i][j] == 0)
				{
					cout << "X" << " ";
				}
				else if (a[i][j] == 9)
				{
					cout << char(2) << " ";
				}
			}		
			cout << endl;
		}
	}
};

