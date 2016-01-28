#ifndef MAY_TINH_DE_BAN_H
#define MAY_TINH_DE_BAN_H
#include <iostream>
using namespace std;
#include "MayTinh.h"
#include "Date.h"
class MayTinhDeBan: public MayTinh
{
private:
	bool _case;
public:
	MayTinhDeBan(){
		_case=false;
	}

	MayTinhDeBan(Date d1,const char* hang ,bool _case):MayTinh(d1,hang){
		this->_case=_case;
	}

	void setCase(Date d1,const char* hang ,bool _case){
		//MayTinh(d1,hang);
		this->_case=_case;
	}

	void getCase()const{
		if(_case==true){
			cout<<"May tinh dung"<<endl;
		}else cout<<"May tinh nam"<<endl;
	}

};
#endif