#include "HinhCau.h"

HinhCau::HinhCau() 
{
	setBanKinh(0);
}

HinhCau::HinhCau(int banKinh) : HinhTron(banKinh)
{
}

double HinhCau::getDienTich() const
{
	return 4 * PI * banKinh * banKinh;
}


double HinhCau::getTheTich() const
{
	return ((double)4 / 3) *  PI * banKinh * banKinh * banKinh;
}