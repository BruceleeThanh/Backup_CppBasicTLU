#include <iostream>
using namespace std;

int main(){
	int i = -5, sum = 0;
	while (i <= 10){
		cout << i << endl;
		sum += i;
		i++;
	}
	cout << "Tong la: " << sum << endl;


	return 0;
}