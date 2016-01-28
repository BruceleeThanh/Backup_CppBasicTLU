#ifndef MAYTINHDEBAN_H
#define MAYTINHDEBAN_H
#include "Maytinh.h"
#include <iostream>
using namespace std;

class MayTinhDeBan :public MayTinh{
private:
	bool loaicase;
public:
	MayTinhDeBan();
	MayTinhDeBan(Date namsanxuat, const char* hang, bool loaicase) : MayTinh(namsanxuat, hang){
		this->loaicase = loaicase;
	}
	void setLoaicase(bool loaicase);
	void getLoaicase()const;


};

#endif