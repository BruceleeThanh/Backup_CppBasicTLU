#include <iostream>
using namespace std;
#include "Date.h"
#include "MayTinh.h"
#include "MayTinhDeBan.h"
#include "MayTinhXachTay.h"
int main(){
	Date d1(18,6,2014), d2(1,1,2014); 

	cout<<d1<<"; "<<d2<<endl; // In ra màn hình 18-6-2014; 1-1-2014 

	MayTinh m1(d1,"Dell"), m2(d2,"HP");

	cout<<m1.getNamSanXuat()<<endl; // In ra màn hình năm 2014

 	MayTinhDeBan mb1(d1,"Dell", true);

	MayTinhXachTay mt1(d2,"Sony", 2.2);

	cout<<mb1.getNamSanXuat()<<endl; // In ra màn hình 2014

 	cout<<mt1.getNamSanXuat()<<endl; // In ra màn hình 2014

 	cout<<mt1.getSoNamSuDung(2017)<<endl; // In ra màn hình 3 (2017-2014 = 3) 
	
	return 0;
}