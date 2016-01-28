#ifndef NhanVien_h
#define NhanVien_h
#include<iostream>
#include<string>
using namespace std;

class NhanVien
{
protected:
	int ID;
	string HoTen;
	string NgaySinh;
	double LuongCoBan;
	double HeSoLuong;
public:
	NhanVien();
	void setID(int id);
	void setHoTen(string ten);
	void setNgaySinh(string ns);
	void setLuongCoBan(double luong);
	void setHeSoLuong(double heso);
	int getID();
	string getHoTen();
	string getNgaySinh();
	double getLuongCoBan();
	double getHeSoLuong();
	virtual double TinhLuong() = 0;
	virtual void HienThiThongTin() = 0;
	~NhanVien();
};



#endif;