#ifndef HINH_TAM_GIAC_H
#define HINH_TAM_GIAC_H

#include "Diem.h"

class HinhTamGiac
{
	public:
		HinhTamGiac();
		HinhTamGiac(Diem, Diem, Diem);
		HinhTamGiac(int, int, int, int, int, int);

		void setA(Diem); void setA(int, int); Diem getA() const;

		void setB(Diem); void setB(int, int); Diem getB() const;

		void setC(Diem); void setC(int, int); Diem getC() const;

		double getDienTich() const;
		double getChuVi() const;

		void println() const;

	private:
		Diem a, b, c;

		double getLength(Diem, Diem);
};

#endif