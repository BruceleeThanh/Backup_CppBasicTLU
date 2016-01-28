#ifndef KHOA_H
#define KHOA_H
#include "Lib.h"

class Khoa{

private:
	string MaKhoa;
	string TenKhoa;
	vector<string> ChuyenNganh;
public:
	Khoa();
	void setMaKhoa(string);
	void setTenKhoa(string);
	void setChuyenNganh(string);
	string getMaKhoa();
	string getTenKhoa();
	vector<string> getChuyenNganh();
	~Khoa();


};

class ListKhoa{
private:
	vector<Khoa> DSKhoa;
public:
	ListKhoa();
	void setDSKhoa(Khoa);
	vector<Khoa> getDSKhoa();
	void xoaKhoa();
	void themKhoa();
	void suaKhoa();
	void timkiemKhoa();
	void hienthiKhoa(int);
	void hienthiDSKhoa();

	~ListKhoa();
};

#endif