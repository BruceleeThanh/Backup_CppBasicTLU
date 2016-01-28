#ifndef Mon_h
#define Mon_h

#include "Lib.h"
#include"Khoa.h"


class Mon
{
private:
	string MaMon;
	string TenMon;
	string MaKhoa;
	int SoTin;
	bool DCCN; // Dai Cuong hay Chuyen Nganh
	double Diem;
public:
	Mon();
	Mon(string maMon, string tenMon, string maKhoa, int soTin, bool DCCN);
	void setMaMon(string maMon);
	void setTenMon(string tenMon);
	void setMaKhoa(string maKhoa);
	void setSoTin(int soTin);
	void setDCCN(bool DCCN);
	void setDiem(double diem);
	string getMaMon();
	string getTenMon();
	int getSoTin();
	string getMaKhoa();
	bool getDCCN();
	double getDiem();
	~Mon();
};

class ListMon
{
private:
	vector<Mon> List_Mon;
public:
	ListMon();
	void setList_Mon(Mon mon);
	vector<Mon> getList_Mon();
	void ThemMon();
	bool TimKiemMon();
	void HienThiMon(int vitri);
	void InToanBoMon();
	~ListMon();
};

// Ham tro giup In danh sach

// In cac tieu de cua danh sach Khoa
void InTieuDeDSMon();

#endif;