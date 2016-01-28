#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	do{
		cout << "An 1 de tinh dien tich HCN." << endl;
		cout << "An 2 de tinh dien tich HV." << endl;
		cout << "An 3 de thoat" << endl;
		cin >> n;
		switch (n){
		case 1:
			cout << "Nhap chieu dai "; cin >> a;
			cout << "Nhap chieu rong: "; cin >> b;
			cout << "Dien tich HCN la: " << a*b << endl;
			break;
		case 2:
			cout << "Nhap canh: "; cin >> a;
			cout << "Dien tich HV la: " << a*a << endl;
			break;
		case 3:
			break;
		}
	} while (n != 3);
	



	return 0;
}