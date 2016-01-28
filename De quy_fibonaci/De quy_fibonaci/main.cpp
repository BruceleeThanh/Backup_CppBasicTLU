#include <iostream>
using namespace std;

int Fibonacci(int n);

int main(){
	int n;
	cout << "Nhap gioi han day fibonaci: ";
	cin >> n;
	cout << Fibonacci(n) << endl;


	return 0;
}

int Fibonacci(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	else{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}