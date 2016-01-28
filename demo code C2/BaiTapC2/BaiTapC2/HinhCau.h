#ifndef HINH_CAU_H
#define HINH_CAU_H

#include "Hinhtron.h"

class HinhCau : public HinhTron
{
	public:
		HinhCau();
		HinhCau(int);

		double getDienTich() const;
		double getTheTich() const;
};

#endif