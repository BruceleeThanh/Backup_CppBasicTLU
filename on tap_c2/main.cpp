#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include "PhanSo.h"
#include "Engineer.h"
#include "Account.h"
#include "Bank.h"
#include "Sach.h"
#include "SachTinHoc.h"

//Phan So
/*int main(){
	int n;
	PhanSo *ps, tong, max, temp;
	cout << "Ban muon nhap bao nhieu phan so: "; cin >> n;
	ps = new PhanSo[n];
	for (int i = 0; i < n; i++){
		cout << "             Nhap Phan So thu " << i + 1 << endl;
		cin >> ps[i];
		tong += ps[i];
	}
	cout << endl << "Tong cac phan so la: "; cout << tong;
	string filename;
	cout << "Dat ten cho file.txt: "; getline(cin,filename);
	filename = filename + ".txt";
	ofstream fout(filename);
	fout << "        Cac Phan So vua nhap la." << endl;
	max = ps[0];
	for (int i = 0; i < n; i++){
		fout << "Phan So thu " << i + 1 << " la:";
		fout << ps[i] << endl;
		if (max < ps[i]) max = ps[i];
	}
	fout << endl << "Tong cac phan so la: "; fout << tong;
	fout << endl << "Phan So lon nhat la: " << max << endl;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (ps[i] < ps[j]){
				temp = ps[i];
				ps[i] = ps[j];
				ps[j] = temp;
			}
		}
	}
	fout << endl << "       Sap xep cac Phan So." << endl << endl;
	for (int i = 0; i < n; i++){
		fout << "Phan So lon thu " << i + 1 << " la:";
		fout << ps[i] << endl;
	}

	fout.close();


	return 0;
}
*/

//Ky su
int main(){
	int n;
	Engineer *en, max;
	cout << "Ban muon nhap bao nhieu Ky su: "; cin >> n;
	en = new Engineer[n];
	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "        Nhap thong tin Ky su thu " << i + 1 << ": "; cin >> en[i];
		cout << endl;
	}
	max = en[0];
	for (int i = 0; i < n; i++) if (max.getNamTotNghiep() < en[i].getNamTotNghiep()) max = en[i];
	cout << "            Danh sach " << n << " Ky su." << endl << endl;
	for (int i = 0; i < n; i++){
		cout << "Ky su thu " << i + 1 << ": " << endl;
		cout << en[i] << endl;
	}
	cout << endl << "Ky su tot nghiep gan nhat la: " << endl << max;
	string filename;
	cout << "Dat ten cho file.txt: "; getline(cin,filename);
	filename = filename + ".txt";
	ofstream fout(filename);
	fout << "            Danh sach " << n << " Ky su." << endl << endl;
	for (int i = 0; i < n; i++){
		fout << "Ky su thu " << i + 1 << ": " << endl;
		fout << en[i] << endl;
	}
	fout << endl << "Ky su tot nghiep gan nhat la: " << endl << max;
	fout.close();


	return 0;
}


//Ngan hang
/* int main(){
	Bank bank;
	int a;
	do{
		cout << "1.Them tai khoan. " << endl;
		cout << "2.Xem thong tin khach hang. " << endl;
		cout << "3.Tai khoan am tien. " << endl;
		cout << "4.Tai khoan nhieu tien nhat. " << endl;
		cout << "5.Ban muon Nap tien. " << endl;
		cout << "6.Ban muon Rut tien. " << endl;
		cout << "7.Thoat." << endl;
		cout << "Ban chon: _"; cin >> a;
		cin.ignore();
		switch (a){
		case 1:{
				   bank.AddTK();
				   break;
		}
		case 2:{
				   int i;
				   cout << "Khach hang muon xem: "; cin >> i;
				   cin.ignore();
				   bank.InTK(i);
				   break;
		}
		case 3:{
				   cout << "Tai khoan am tien la: " << endl;
				   bank.TKAmTien();
				   break;
		}
		case 4:{
				   cout << "Tai khoan nhieu tien nhat la: " << endl;
					bank.TKMaxTien();
					break;
		}
		case 5:{
				   int n;
				   long long x;
				   cout << "Ban muon Nap tien cho TK thu may: "; cin >> n;
				   cout << "Tai khoan thu " << n << " la:";
				   bank.InTK(n);
				   cout << "Ban muon Nap bao nhieu tien: "; cin >> x;
				   cin.ignore();
				   bank.NapTien(n, x);
				   cout << "Tai khoan hien nay la: " << endl;
				   bank.InTK(n);
				   
		}
		case 6:{
				   int n;
				   long long x;
				   cout << "Ban muon Rut tien cho TK thu may: "; cin >> n;
				   cout << "Tai khoan thu " << n << " la:";
				   bank.InTK(n);
				   cout << "Ban muon Rut bao nhieu tien: "; cin >> x;
				   cin.ignore();
				   bank.RutTien(n, x);
				   cout << "Tai khoan hien nay la: " << endl;
				   bank.InTK(n);
		}

		}
	} while (a != 7);


	return 0;
} */

//Sach
/*
int main(){
	double n;
	Sach* sach;
	SachTinHoc sth;
	cout << "Nhap thong tin" << endl;
	cin >> sth;
	cout << "Nhap gia nhap: "; cin >> n;
	sth.setGiaNhap(n);
	sach = &sth;
	sach->GiaBan();
	cout << sth;
	cout << sth.GiaBan();


	return 0;
}
*/

