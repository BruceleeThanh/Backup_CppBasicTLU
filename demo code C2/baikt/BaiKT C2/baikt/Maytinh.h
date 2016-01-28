#ifndef MAYTINH_H
#define MAYTINH_H

#include "Date.h"
#include <string>

class MayTinh{
private:
	Date namsanxuat;
	char hang[50];
public:
	MayTinh();
	MayTinh(Date namsanxuat, const char* hang);
	void setNamsanxuat(int);
	int getNamsanxuat()const;
	void setHang(const char*);
	char getHang()const;
	void disPlay();

};

#endif