#ifndef HINH_CHU_NHAT_H
#define HINH_CHU_NHAT_H

#include <iostream>
#include "Diem.h"

using namespace std;

class HinhChuNhat
{
	private:
		Diem TrenTrai, DuoiPhai;

	public:
		HinhChuNhat();
		HinhChuNhat(Diem, Diem);
		HinhChuNhat(int, int, int, int);

		void setTrenTrai(Diem);
		void setTrenTrai(int, int);
		Diem getTrenTrai() const;

		void setDuoiPhai(Diem);
		void setDuoiPhai(int, int);
		Diem getDuoiPhai() const;

		void println() const;
};

#endif