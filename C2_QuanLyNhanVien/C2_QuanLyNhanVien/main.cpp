#include<iostream>
#include <string>
#include"NhanVien.h"
#include"CongNhan.h"
#include"CanBoQuanLy.h"
#include"Menu.h"
#include<iomanip>
using namespace std;

int main()
{
	ListCongNhan CN;
	ListCanBoQuanLy CB;
	Menu(CN, CB);

	return 0;
}