#ifndef Khoa_h
#define Khoa_h

#include "Lib.h"

class Khoa
{
protected:
	string MaKhoa;
	string TenKhoa;
public:
	Khoa();
	Khoa(string maKhoa, string tenKhoa);
	void setMaKhoa(string maKhoa);
	void setTenKhoa(string tenKhoa);
	string getMaKhoa();
	string getTenKhoa();
	~Khoa();
};

//
class ListKhoa
{
private:
	vector<Khoa>List_Khoa;
public:
	ListKhoa();
	void setList_Khoa(Khoa);
	vector<Khoa> getList_Khoa();
	bool TimKiemKhoa();
	void HienThiKhoa(int vitri);
	void InToanBoKhoa();
	~ListKhoa();
};

// Ham tro giup In danh sach

// In cac tieu de cua danh sach Khoa
void InTieuDeDSKhoa();

#endif;