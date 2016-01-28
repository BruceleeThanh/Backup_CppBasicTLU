#include <iostream>
#include "HinhCau.h"
#include "Hinhtron.h"

using namespace std;

int main()
{
	HinhCau hc(7);

	cout << "Dien tich mat cau la: " << hc.getDienTich() << endl;
	cout << "Dien tich mat cat qua tam la: " << hc.HinhTron::getDienTich() << endl;

	HinhTron ht;

	ht.banKinh = 8;

	return 0;
}