#include<iostream>
#include<vector>
#include "CoTaCanh.h"
using namespace std;

vector<CoTaCanh> opens;
vector<CoTaCanh> closes;
vector<DieuKien> dieuKiens;
vector<CoTaCanh> duongDis;
int dinhDanh = 2;
bool flag = false;
int kt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };

void SinhTrangThai(CoTaCanh X);
void CaiDatDieuKien();
DieuKien KiemTraDieuKien(int tacanh[]);
void XuLy_SinhTragThai(CoTaCanh X, int loai);
CoTaCanh Sinh_Len(CoTaCanh X);
CoTaCanh Sinh_Xuong(CoTaCanh X);
CoTaCanh Sinh_Trai(CoTaCanh X);
CoTaCanh Sinh_Phai(CoTaCanh X);
bool KiemTraTonTai(CoTaCanh taCanhCon);
bool KetThuc(int a[], int b[]);
void InDuongDi();
void TimDuongDi();
CoTaCanh TimCha(int cha);
int HamDanhGia(CoTaCanh taCanh);

int main()
{
	CoTaCanh start;
	CoTaCanh finish(-1, -1, kt);
	CoTaCanh X;
	int bd[9];
	cout << "Nhap ban co: ";
	for (int i = 0; i < 9; i++) 
	{
		cin >> bd[i];
	}
	start.setDinhDanh(1);
	start.setCha(0);
	start.setTaCanh(bd);
	start.setDiemSo(kt, 0);
	CaiDatDieuKien();
	opens.push_back(start);
	while (!opens.empty())
	{
		X = opens[0];
		if (flag)
		{
			break;
		}
		else
		{
			opens.erase(opens.begin());
			closes.push_back(X);
			SinhTrangThai(X);
		}
	}
	cout << "Duong di la: " << endl;
	InDuongDi();

	return 0;
}

void SinhTrangThai(CoTaCanh X)
{
	DieuKien temp = KiemTraDieuKien(X.getTaCanh());
	if (temp.getLen()) 
	{
		XuLy_SinhTragThai(X, 1);
	}
	if (temp.getXuong())
	{
		XuLy_SinhTragThai(X, 2);
	}
	if (temp.getTrai())
	{
		XuLy_SinhTragThai(X, 3);
	}
	if (temp.getPhai())
	{
		XuLy_SinhTragThai(X, 4);
	}
}

void CaiDatDieuKien()
{
	dieuKiens.push_back(DieuKien(0, false, true, false, true));
	dieuKiens.push_back(DieuKien(1, false, true, true, true));
	dieuKiens.push_back(DieuKien(2, false, true, true, false));
	dieuKiens.push_back(DieuKien(3, true, true, false, true));
	dieuKiens.push_back(DieuKien(4, true, true, true, true));
	dieuKiens.push_back(DieuKien(5, true, true, true, false));
	dieuKiens.push_back(DieuKien(6, true, false, false, true));
	dieuKiens.push_back(DieuKien(7, true, false, true, true));
	dieuKiens.push_back(DieuKien(8, true, false, true, false));
}

DieuKien KiemTraDieuKien(int tacanh[])
{
	for (int i = 0; i < 9; i++) 
	{
		if (tacanh[i] == 0) 
		{
			return dieuKiens[i];
		}
	}	
}

void XuLy_SinhTragThai(CoTaCanh X, int loai)
{
	if (loai == 1)
	{
		CoTaCanh taCanhCon = Sinh_Len(X);
		if (!KiemTraTonTai(taCanhCon)) 
		{
			taCanhCon.setCha(X.getDinhDanh());
			taCanhCon.setDinhDanh(dinhDanh);
			taCanhCon.setDiemSo(kt, X.getDiemSoG());
			//cout << taCanhCon << endl;
			opens.insert(opens.begin() + HamDanhGia(taCanhCon), taCanhCon);
			dinhDanh++;
			if (KetThuc(taCanhCon.getTaCanh(), kt))
			{
				flag = true;
				return;
			}
		}
	}
	else
	{
		if (loai == 2)
		{
			CoTaCanh taCanhCon = Sinh_Xuong(X);
			if (!KiemTraTonTai(taCanhCon))
			{
				taCanhCon.setCha(X.getDinhDanh());
				taCanhCon.setDinhDanh(dinhDanh);
				taCanhCon.setDiemSo(kt, X.getDiemSoG());
				//cout << taCanhCon << endl;
				opens.insert(opens.begin() + HamDanhGia(taCanhCon), taCanhCon);
				dinhDanh++;
				if (KetThuc(taCanhCon.getTaCanh(), kt))
				{
					flag = true;
					return;
				}
			}
		}
		else {
			if (loai == 3)
			{
				CoTaCanh taCanhCon = Sinh_Trai(X);
				if (!KiemTraTonTai(taCanhCon))
				{
					taCanhCon.setCha(X.getDinhDanh());
					taCanhCon.setDinhDanh(dinhDanh);
					taCanhCon.setDiemSo(kt, X.getDiemSoG());
					//cout << taCanhCon << endl;
					opens.insert(opens.begin() + HamDanhGia(taCanhCon), taCanhCon);
					dinhDanh++;
					if (KetThuc(taCanhCon.getTaCanh(), kt))
					{
						flag = true;
						return;
					}
				}
			}else{
				if (loai == 4)
				{
					CoTaCanh taCanhCon = Sinh_Phai(X);
					if (!KiemTraTonTai(taCanhCon))
					{
						taCanhCon.setCha(X.getDinhDanh());
						taCanhCon.setDinhDanh(dinhDanh);
						taCanhCon.setDiemSo(kt, X.getDiemSoG());
						//cout << taCanhCon << endl;
						opens.insert(opens.begin() + HamDanhGia(taCanhCon), taCanhCon);
						dinhDanh++;
						if (KetThuc(taCanhCon.getTaCanh(), kt))
						{
							flag = true;
							return;
						}
					}
				}
			}
		}
	}
}

CoTaCanh Sinh_Len(CoTaCanh X)
{
	int viTri = 0;
	CoTaCanh ketQua = X;
	int taCanh[9];
	for (int i = 0; i < 9; i++)
	{
		taCanh[i] = ketQua.getTaCanh()[i];
		if (taCanh[i] == 0) 
		{
			viTri = i;
		}
	}
	int temp = taCanh[viTri];
	taCanh[viTri] = taCanh[viTri - 3];
	taCanh[viTri - 3] = temp;
	ketQua.setTaCanh(taCanh);
	return ketQua;
}

CoTaCanh Sinh_Xuong(CoTaCanh X)
{
	int viTri = 0;
	CoTaCanh ketQua = X;
	int taCanh[9];
	for (int i = 0; i < 9; i++)
	{
		taCanh[i] = ketQua.getTaCanh()[i];
		if (taCanh[i] == 0) {
			viTri = i;
		}
	}
	int temp = taCanh[viTri];
	taCanh[viTri] = taCanh[viTri + 3];
	taCanh[viTri + 3] = temp;
	ketQua.setTaCanh(taCanh);
	return ketQua;
}

CoTaCanh Sinh_Trai(CoTaCanh X)
{
	int viTri = 0;
	CoTaCanh ketQua = X;
	int taCanh[9];
	for (int i = 0; i < 9; i++)
	{
		taCanh[i] = ketQua.getTaCanh()[i];
		if (taCanh[i] == 0) {
			viTri = i;
		}
	}
	int temp = taCanh[viTri];
	taCanh[viTri] = taCanh[viTri - 1];
	taCanh[viTri - 1] = temp;
	ketQua.setTaCanh(taCanh);
	return ketQua;
}

CoTaCanh Sinh_Phai(CoTaCanh X)
{
	int viTri = 0;
	CoTaCanh ketQua = X;
	int taCanh[9];
	for (int i = 0; i < 9; i++)
	{
		taCanh[i] = ketQua.getTaCanh()[i];
		if (taCanh[i] == 0) {
			viTri = i;
		}
	}
	int temp = taCanh[viTri];
	taCanh[viTri] = taCanh[viTri + 1];
	taCanh[viTri + 1] = temp;
	ketQua.setTaCanh(taCanh);
	return ketQua;
}

bool KiemTraTonTai(CoTaCanh taCanhCon)
{
	for (int i = 0; i < opens.size(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (taCanhCon.getTaCanh()[j] != opens[i].getTaCanh()[j])
			{
				break;
			}
			if (j == 8) 
			{
				return true;
			}
		}
	}
	for (int i = 0; i < closes.size(); i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (taCanhCon.getTaCanh()[j] != closes[i].getTaCanh()[j])
			{
				break;
			}
			if (j == 8)
			{
				return true;
			}
		}
	}
	return false;
}

bool KetThuc(int a[], int b[])
{
	for (int i = 0; i < 9; i++)
	{
		if (a[i] != b[i])
		{
			break;
		}
		if (i == 8)
		{
			return true;
		}
	}
	return false;
}

void InDuongDi()
{
	TimDuongDi();
	for (int i = duongDis.size() - 1; i >= 0; i--)
	{
		cout << duongDis[i] << endl;
	}
}

void TimDuongDi()
{
	CoTaCanh taCanh;
	for (int i = 0; i < opens.size(); i++)
	{
		if (KetThuc(opens[i].getTaCanh(), kt))
		{
			taCanh = opens[i];
			break;
		}
	}
	int cha = taCanh.getCha();
	duongDis.push_back(taCanh);
	do 
	{
		taCanh = TimCha(cha);
		cha = taCanh.getCha();
		duongDis.push_back(taCanh);
	} while (cha != 0);
}

CoTaCanh TimCha(int cha)
{
	for (int i = 0; i < closes.size(); i++)
	{
		if (closes[i].getDinhDanh() == cha)
		{
			return closes[i];
		}
	}
}

int HamDanhGia(CoTaCanh taCanh){
	for (int i = 0; i < opens.size(); i++)
	{
		if (opens[i].getDiemSo() > taCanh.getDiemSo()){
			return i;
		}
		if (i == opens.size() - 1){
			return opens.size();
		}
	}
	return 0;
}