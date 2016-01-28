#ifndef MONHOC_H
#define MONHOC_H
#include "Lib.h"

class MonHoc{

private:
	string MaMon;
	string TenMon;
	string MaKhoa;
	int SoTin;
	string DCCN;
	
public:
	MonHoc();
	MonHoc(string, string, string, int, string);
	void setMaMon(string);
	void setTenMon(string);
	void setSoTin(int);
	void setDCCN(string);
	void setMaKhoa(string);
	string getMaMon();
	string getTenMon();
	int getSoTin();
	string getDCCN();
	string getMaKhoa();
	~MonHoc();

};

class ListMonHoc{
private:
	vector<MonHoc> DSMonHoc;
public:
	ListMonHoc();
	void setDSMonHoc(MonHoc);
	vector<MonHoc> getDSMonHoc();
	void menuMon();
	void xoaMon();
	void themMon();
	void suaMon();
	void timkiemMon();
	void hienthiMon(int);
	void hienthiDSMon();
	~ListMonHoc();
};

#endif
