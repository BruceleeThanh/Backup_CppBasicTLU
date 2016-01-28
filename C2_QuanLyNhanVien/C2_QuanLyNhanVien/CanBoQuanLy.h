#ifndef CanBoQuanLy_h
#define CanBoQuanLy_h
#include"NhanVien.h"
#include<string>
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class CanBoQuanLy : public NhanVien
{
private:
	double PhuCap;
public:
	CanBoQuanLy();
	void setPhuCap(double pc);
	double getPhuCap();
	double TinhLuong();
	void HienThiThongTin();
	~CanBoQuanLy();
};

class ListCanBoQuanLy
{
private:
	vector<CanBoQuanLy>CB;
public:
	ListCanBoQuanLy();
	vector<CanBoQuanLy> getListCB();
	void ThemCB(int &id);
	void SuaCB();
	void XoaCB();
	void TimKiemCB();
	void DocFileCB(int &id);
	void GhiFileCB();
	//void MenuCB(int id);
	void CBLuongMax();
	void CBLuongMin();
	void HienhiDanhSachCB();
	~ListCanBoQuanLy();
};

#endif;