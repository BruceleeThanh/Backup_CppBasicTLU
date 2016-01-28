#include"NhanVien.h"
#include<iomanip>

NhanVien::NhanVien()
{
}

void NhanVien::setID(int id)
{
	ID = id;
}

void NhanVien::setHoTen(string ten)
{
	HoTen = ten;
}

void NhanVien::setNgaySinh(string ns)
{
	NgaySinh = ns;
}

void NhanVien::setLuongCoBan(double luong)
{
	LuongCoBan = luong;
}

void NhanVien::setHeSoLuong(double heso)
{
	HeSoLuong = heso;
}

int NhanVien::getID()
{
	return ID;
}

string NhanVien::getHoTen()
{
	return HoTen;
}

string NhanVien::getNgaySinh()
{
	return NgaySinh;
}

double NhanVien::getLuongCoBan()
{
	return LuongCoBan;
}

double NhanVien::getHeSoLuong()
{
	return HeSoLuong;
}

NhanVien::~NhanVien()
{
}