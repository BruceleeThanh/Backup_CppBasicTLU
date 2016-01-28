#ifndef MAY_TINH_XACH_TAY_H
#define MAY_TINH_XACH_TAY_H
#include<iostream>
using namespace std;
#include "Date.h"
#include "MayTinh.h"
class MayTinhXachTay:public MayTinh
{
private:
	float can_nang;
public:
	MayTinhXachTay(){}

	MayTinhXachTay(Date d1,const char* a,float can_nang):MayTinh(d1,a){
		this ->can_nang=can_nang;
	}
	void setMayTinhXachTay(Date d1,const char* a,float can_nang){
		MayTinh(d1,a);
		this ->can_nang=can_nang;
	}
	float getCanNang(){
		return can_nang;
	}
	int getSoNamSuDung(int a){
		return a-namsanxuat.getNam();
	}
	~MayTinhXachTay(){
		
	}

	/* data */
};

#endif