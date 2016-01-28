#ifndef MAYTINH_H
#define MAYTINH_H
#include "Date.h"
#include <string.h>
class MayTinh
{
protected:
	Date namsanxuat;
	char hang[30];
public:
	MayTinh(){

	}

	MayTinh(Date namsanxuat, const char* hang){
		strcpy(this->hang,hang);
		this->namsanxuat = namsanxuat;
	}

	void setNamSanXuat(Date namsanxuat){
		this->namsanxuat = namsanxuat;
	}

	void setHang(const char* hang){
		strcpy(this->hang,hang);
	}

	int getNamSanXuat()const{
		return namsanxuat.getNam();
	}
	char *getHang(){
		return hang;
	}
	/* data */
};
#endif