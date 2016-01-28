#include <iostream>
#include "Date.h"
#include "Maytinh.h"
#include "Maytinhdeban.h"
using namespace std;

int main(){
	Date d(19, 06, 2014);
	
	MayTinh mt(d, "Asus");
	mt.disPlay();
	cout << "---------------------" << endl;
	MayTinhDeBan pc(d,"asus", 1);
	pc.disPlay();
	pc.getLoaicase();
	

	return 0;
}