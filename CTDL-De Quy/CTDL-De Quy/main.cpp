#include <iostream>
using namespace std;

int Tong(int n);
long giaiThua(int n);
long luyThua(int x, int n);
int Fibonaci(int n);
void thapHN_stupid(int n, char A, char B, char C);
void thapHN_smart(int n, char A, char B, char C);

void chuyen(int sodia, char CotNguon, char CotDich, char CotTG);

int main(){
	int n, x;

	/*cout << "Nhap n de tinh Tong cac so: "; cin >> n;
	cout << Tong(n) << endl;

	cout << "Nhap n giai thua: "; cin >> n;
	cout << giaiThua(n) << endl;

	cout << "Nhap co so: "; cin >> x;
	cout << "Nhap so mu: "; cin >> n;
	cout << luyThua(x, n) << endl;

	cout << "Fibonaci tai vi tri: "; cin >> n;
	cout << Fibonaci(n) << endl;*/

	cout << "Nhap so dia cua Thap Ha Noi: "; cin >> n;
	thapHN_stupid(n, 'A', 'B', 'C');

	return 0;
}

int Tong(int n){
	if (n == 1) return 1;
	return n + Tong(n - 1);
}

long giaiThua(int n){
	if (n == 1) return 1;
	return n * giaiThua(n - 1);
}

long luyThua(int x, int n){
	if (x == 0) return 0;
	if (x == 1 || n == 0) return 1;
	if (x > 1 && n == 1) return x;
	return x * luyThua(x, n - 1);
}

int Fibonaci(int n){
	if (n == 1 || n == 2) return 1;
	return Fibonaci(n - 1) + Fibonaci(n - 2);
}

void thapHN_stupid(int n, char A, char B, char C){
	if (n == 1){
		cout << "Chuyen dia tu Coc " << A << " sang Coc " << C << endl;
	}
	else{
		thapHN_stupid(n - 1, A, C, B);
		thapHN_stupid(1, A, B, C);
		thapHN_stupid(n - 1, B, A, C);
	}
}

void chuyen(int sodia, char CotNguon, char CotDich, char CotTG)
{
	if (sodia>0)
	{
		chuyen(sodia - 1, CotNguon, CotTG, CotDich);
		cout << CotNguon << "->" << CotDich << "\n";
		chuyen(sodia - 1, CotTG, CotDich, CotNguon);
	}
}

void Move(int n, char A, char C){
	cout << "Chuyen dia thu " << n << " tu " << A << " sang " << C << endl;
}

void thapHN_smart(int n, char A, char C, char B){
	if (n == 1){
		Move(1, A, C);
	}
	else{
		thapHN_smart(n - 1, A, B, C);
		Move(n, A, C);
		thapHN_smart(n - 1, B, C, A);
	}
}