#include "hinhtron.h"

void HinhTron::setR(float rr)
{
	r=rr;
}
float HinhTron::getChuVi() const
{
	return 2*PI*r;
}
float HinhTron::getDienTich() const
{
	return PI*r*r;
}