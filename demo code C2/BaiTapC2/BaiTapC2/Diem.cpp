#include "Diem.h"

Diem::Diem()
{
	x = 0;
	y = 0;
}

Diem::Diem(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Diem::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Diem::setX(int x)
{
	this->x = x;
}

int Diem::getX() const
{
	return x;
}

void Diem::setY(int y)
{
	this->y = y;
}

int Diem::getY() const
{
	return y;
}