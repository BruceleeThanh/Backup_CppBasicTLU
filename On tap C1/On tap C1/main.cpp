#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct SinhVien{
	char msv[10];
	double diem_QT;
	double diem_LT;
	double diem_TH;
	double diem_TK;
};

void nhapSinhVien(SinhVien sv[], int i);
void sapXep(SinhVien sv[], int n);
char* xepLoai(double diem_TK);

int main(){
	SinhVien sv[100];
	int i = 0;
	//nhapSinhVien(sv, i);
	cout << xepLoai(3.4) << endl;


	return 0;
}

void nhapSinhVien(SinhVien sv[],int i){
	cout << "Nhap Ma sinh vien: ";
	cin.getline(sv[i].msv, 10);
	cout << "Nhap diem Qua Trinh: ";
	cin >> sv[i].diem_QT;
	cout << "Nhap diem Ly Thuyet: ";
	cin >> sv[i].diem_LT;
	cout << "Nhap diem Thuc Hanh: ";
	cin >> sv[i].diem_TH;
	sv[i].diem_TK = sv[i].diem_QT * 0.3 + 0.7 * (sv[i].diem_TH + sv[i].diem_LT) / 2;
	cout << "Diem Tong Ket cua sinh vien " << sv[i].msv << " la: " << sv[i].diem_TK << endl;
}

void sapXep(SinhVien sv[], int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (sv[i].diem_TK>sv[j].diem_TK){
				SinhVien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

char* xepLoai(double diem_TK){
	
	if (diem_TK < 4.6){
		return "Truot";
	}
}