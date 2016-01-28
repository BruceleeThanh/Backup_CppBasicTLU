#ifndef SACHTINHOC_H
#define SACHTINHOC_H
#include "Sach.h"
class SachTinHoc : public Sach
{
private:
	double gianhap;
public:
	SachTinHoc();
	SachTinHoc(const char*, int, double, double);
	//set
	void setGiaNhap(double);
	//get
	double getGiaNhap() const;

	double GiaBan();


	~SachTinHoc();
};

#endif