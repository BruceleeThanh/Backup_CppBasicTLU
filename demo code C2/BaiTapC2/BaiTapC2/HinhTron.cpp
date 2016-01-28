#include "Hinhtron.h"

HinhTron::HinhTron()
{
	banKinh = 0;
}

HinhTron::HinhTron(int banKinh)
{
	this->banKinh = banKinh;
}

void HinhTron::setBanKinh(int banKinh)
{
	this->banKinh = banKinh;
}

int HinhTron::getBanKinh() const
{
	return banKinh;
}

int HinhTron::getDuongKinh() const
{
	return 2*banKinh;
}

double HinhTron::getDienTich() const
{
	return PI * banKinh * banKinh;
}

double HinhTron::getChuVi() const
{
	return 2 * PI * banKinh;
}