#include <iostream>
#include <math.h>
using namespace std;

int TongCacChuSo(int x);
void TamGiac(int a, int b, int c, double &dienTich, double &chuVi);

int main(){

	// Bai 1
	/*int x;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Ket qua: " << TongCacChuSo(x) << endl;*/

	// Bai 2
	/*int a, b, c;
	double dienTich, chuVi;
	cout << "Nhap canh a: ";
	cin >> a;
	cout << "Nhap canh b: ";
	cin >> b;
	cout << "Nhap canh c: ";
	cin >> c;
	TamGiac(a, b, c, dienTich, chuVi);
	cout << "Dien tich Tam giac la: " << dienTich << endl;
	cout << "Chu vi Tam giac la: " << chuVi << endl;*/

	return 0;
}

// Bai 1
int TongCacChuSo(int x){
	int tong = 0;
	while (x != 0){
		tong += x % 10;
		x = x / 10;
	}
	return tong;
}

// Bai 2
void TamGiac(int a, int b, int c, double &dienTich, double &chuVi){
	if (((a + b) > c) && ((b + c) > a) && ((c + a) > b)){
		double s = (double)(a + b + c) / 2;
		dienTich = sqrt(s*(s - a)*(s - b)*(s - c));
		chuVi = s * 2;
	}
	else{
		dienTich = 0;
		chuVi = 0;
		cout << "Day khong phai la ba canh cua Tam giac." << endl;
	}
}

// Bai 3
int KiemTraSoLonNhat(double a, double b, double c){
	if (a > b){
		if (a > c){
			return a;
		}
		else{
			return c;
		}
	}
	else{
		if (b > c){
			return b;
		}
		else{
			return c;
		}
	}
}