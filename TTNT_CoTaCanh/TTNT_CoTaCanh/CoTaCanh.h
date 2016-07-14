#pragma once
#include <iostream>
using namespace std;
class CoTaCanh
{
private:
	int DinhDanh;
	int Cha;
	int TaCanh[9];
	int DiemSoH = 0;
	int DiemSoG = 0;
public:
	CoTaCanh()
	{

	}
	CoTaCanh(int dd, int c, int tc[])
	{
		DinhDanh = dd;
		Cha = c;
		for (int i = 0; i < 9; i++)
		{
			TaCanh[i] = tc[i];
		}
	}
	void setDinhDanh(int dd)
	{
		DinhDanh = dd;
	}
	void setCha(int c)
	{
		Cha = c;
	}
	void setTaCanh(int tc[])
	{
		for (int i = 0; i < 9; i++)
			TaCanh[i] = tc[i];
	}
	void setDiemSo(int kt[], int g)
	{
		DiemSoH = 0;
		DiemSoG = 0;
		int a[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		int b[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		int k = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a[i][j] = TaCanh[k];
				b[i][j] = kt[k];
				k++;
			}
		}
		int a1, a2, b1, b2;
		for (int h = 1; h <= 8; h++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (a[i][j] == h){
						a1 = i;
						a2 = j;
					}
					if (b[i][j] == h){
						b1 = i;
						b2 = j;
					}
				}
			}
			DiemSoH += (abs(a1 - b1) + abs(a2 - b2));
		}
		DiemSoG = g + 1;
	}
	int getDinhDanh()
	{
		return DinhDanh;
	}
	int getCha()
	{
		return Cha;
	}
	int* getTaCanh()
	{
		return TaCanh;
	}
	int getDiemSoH()
	{
		return DiemSoH;
	}
	int getDiemSoG()
	{
		return DiemSoG;
	}
	int getDiemSo()
	{
		return DiemSoG + DiemSoH;
	}
	bool operator ==(CoTaCanh x)
	{
		if (getDinhDanh() == x.getDinhDanh() && getCha() == x.getCha())
		{
			for (int i = 0; i < 9; i++)
			{
				if (TaCanh[i] != x.getTaCanh()[i]) 
				{
					return 0;
				}
			}
			return 1;
		}
			
		else
			return 0;
	}
	void operator =(CoTaCanh x)
	{
		DinhDanh = x.getDinhDanh();
		Cha = x.getCha();
		for (int i = 0; i < 9; i++)
		{
			TaCanh[i] = x.getTaCanh()[i];
		}
		DiemSoH = x.getDiemSoH();
		DiemSoG = x.getDiemSoG();
	}
	friend ostream& operator<< (ostream &out, CoTaCanh &a)
	{
		out << "I: " << a.getDinhDanh() << ", P: " << a.getCha() << endl;
		for (int i = 0; i < 9; i = i + 3) 
		{
			out << a.getTaCanh()[i] << " " << a.getTaCanh()[i + 1] << " " << a.getTaCanh()[i + 2] << endl;
		}
		return out;
	}

};

class DieuKien
{
private:
	int Vitri;
	bool Len;
	bool Xuong;
	bool Trai;
	bool Phai;
public:
	DieuKien()
	{

	}
	DieuKien(int vt, bool l, bool x, bool t, bool p)
	{
		Vitri = vt;
		Len = l;
		Xuong = x;
		Trai = t;
		Phai = p;
	}
	void setViTri(int vt)
	{
		Vitri = vt;
	}
	void setLen(bool l)
	{
		Len = l;
	}
	void setXuong(bool x)
	{
		Xuong = x;
	}
	void setTrai(bool t)
	{
		Trai = t;
	}
	void setPhai(bool p)
	{
		Phai = p;
	}
	int getViTri()
	{
		return Vitri;
	}
	bool getLen()
	{
		return Len;
	}
	bool getXuong()
	{
		return Xuong;
	}
	bool getTrai()
	{
		return Trai;
	}
	bool getPhai()
	{
		return Phai;
	}
};