#ifndef CongNhan_h
#define CongNhan_h
#include"NhanVien.h"
#include<vector>
#include<fstream>
using namespace std;

class CongNhan :public NhanVien
{
private:
	double SoNgayCong;
public:
	CongNhan();
	void setSoNgayCong(double sn);
	double getSoNgayCong();
	double TinhLuong();
	void HienThiThongTin();
	~CongNhan();
};

class ListCongNhan
{
private:
	vector<CongNhan>CN;
public:
	ListCongNhan();
	vector<CongNhan> getListCN();
	void ThemCN(int &id);
	void SuaCN();
	void XoaCN();
	void TimKiemCN();
	void DocFileCN(int &id);
	void GhiFileCN();
	//void MenuCN(int id);
	void CNLuongMax();
	void CNLuongMin();
	void HienThiDanhSachCN();
	~ListCongNhan();
};

#endif;