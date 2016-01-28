#include <iostream>
#include <fstream>
using namespace std;

ofstream file("NhiPhan.txt");

void sinhXauNP(char a[], int n);
void bienDoi(char a[], int n);

int main(){
	char a[10];
	int n;
	cout << "Nhap n: "; cin >> n;
	for (int i = 0; i < n; i++){
		a[i] = '0';
	}
	sinhXauNP(a, n);
	file.close();
	return 0;
}

void sinhXauNP(char a[], int n){
	for (int i = 0; i < n; i++){
		file << a[i];
	}
	file << endl;
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (a[i] == '0'){
			flag = true;
			break;
		}
	}
	if (flag){
		bienDoi(a, n);
		sinhXauNP(a, n);
	}
}

void bienDoi(char a[], int n){
	for (int i = n - 1; i >= 0; i--){
		if (a[i] == '1'){
			a[i] = '0';
		}
		else{
			a[i] = '1';
			break;
		}
	}
}
