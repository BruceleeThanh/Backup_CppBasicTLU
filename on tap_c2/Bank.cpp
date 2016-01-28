#include "Bank.h"


Bank::Bank(){
	n++;
}

void Bank::AddTK(){
	cin >> acc[n];
}

void Bank::TKAmTien(){
	for (int i = 1; i <= n; i++){
		if (acc[i].getSoTien() < 0) cout << acc[i];
	}
}
void Bank::TKMaxTien(){
	long long max, x;
	max = acc[1].getSoTien();
	for (int i = 1; i <= n; i++){
		if (acc[i].getSoTien() > max){
			max = acc[i].getSoTien();
			x = i;
		}
		cout << acc[x];
	}
}

void Bank::InTK(int n){
	cout << acc[n];
}

void Bank::NapTien(int n, long long naptien){
	acc[n] += naptien;
}

void Bank::RutTien(int n, long long ruttien){
	acc[n] -= ruttien;
}

Bank::~Bank(){

}
