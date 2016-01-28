#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat()
{
	TrenTrai.setXY(0, 0);
	DuoiPhai.setXY(0, 0);
}

HinhChuNhat::HinhChuNhat(Diem tt, Diem dp) 
{	
	TrenTrai = tt;
	DuoiPhai = dp;
}

HinhChuNhat::HinhChuNhat(int x1, int y1, int x2, int y2) : TrenTrai(x1, y1), 
														    DuoiPhai(x2, y2)
{
}

void HinhChuNhat::setTrenTrai(Diem tt)
{
	TrenTrai = tt;
}

void HinhChuNhat::setTrenTrai(int x1, int y1) 
{
	TrenTrai.setXY(x1, y1);
}

Diem HinhChuNhat::getTrenTrai() const
{
	return TrenTrai;
}

void HinhChuNhat::setDuoiPhai(Diem tt)
{
	DuoiPhai = tt;
}

void HinhChuNhat::setDuoiPhai(int x2, int y2)
{
	DuoiPhai.setXY(x2, y2);
}

Diem HinhChuNhat::getDuoiPhai() const
{
	return DuoiPhai;
}

void HinhChuNhat::println() const
{
	cout << "Toa do Tren Trai la: (" << TrenTrai.getX() << ", " << TrenTrai.getY() << ")" << endl;
	cout << "Toa do Duoi Phai la: (" << DuoiPhai.getX() << ", " << DuoiPhai.getY() << ")" << endl;
}