#include <iostream>
#include <fstream>
using namespace std;

ofstream file("HoanVi.txt");

void sinhHoanVi(int a[], int n);
void bienDoi(int a[], int n);

int main(){
	int a[1000], n;
	cout << "Nhap n: "; cin >> n;
	for (int i = 0; i < n; i++){
		a[i] = i + 1;
	}
	sinhHoanVi(a, n);
	file.close();
	cout << "------------------------------" << endl << "Ban hay kiem tra file HoanVi.txt" << endl;
	return 0;
}

void sinhHoanVi(int a[], int n){
	int m = n, dem = 0;
	for (int i = 0; i < n; i++){
		file << a[i];
	}
	file << endl;
	bool flag = true;
	for (int i = 0; i < n; i++){
		if (a[i] == m){
			dem++;
		}
		else{
			break;
		}
		m--;
	}
	if (dem == n){
		flag = false;
	}
	if (flag){
		bienDoi(a, n);
		sinhHoanVi(a, n);
	}
}

void bienDoi(int a[], int n){
	int b[1000];
	int k, h, min, j = 0 ;
	for (int i = n - 1; i >= 0; i--){
		if (a[i] > a[i - 1]){
			k = i - 1;
			break;
		}
	}
	min = a[k + 1];
	h = k + 1;
	//tìm số nhỏ nhất trong các số bên phải k nhưng phải lớn hơn a[k]
	for (int i = k + 1; i < n; i++){
		if (a[i] < min && a[i] > a[k]){
			min = a[i];
			h = i;
		}
	}
	int temp = a[k];
	a[k] = a[h];
	a[h] = temp;
	for (int i = n - 1; i > k; i--){
		b[j++] = a[i];
	}
	for (int i = n - 1; i > k; i--){
		a[i] = b[--j];
	}
}
