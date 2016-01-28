#include "header1.h"

void HinhChuNhat::setA(int aa)
{
	a=aa;
}
float HinhChuNhat::getA() const
{
	return a;
}
void HinhChuNhat::setB(int bb)
{
	b=bb;
}
float HinhChuNhat::getB() const
{
	return b;
}


float HinhChuNhat::getChuVi() const
{
	return (a+b)*2;
}

float HinhChuNhat::getDienTich() const
{
	return a*b;
}