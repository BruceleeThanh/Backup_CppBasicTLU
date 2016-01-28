#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int count = 2, n = 3;
	bool check;
	while (count < 10001){
		n += 2;
		check = true;
		for (int i = 2; i <= sqrt((double)n); i++){
			if (n % i == 0){
				check = false;
				break;
			}
		}
		if (check){
			count++;
		}
	}
	cout << "So nguyen to thu 10001 la: " << n << endl;


	return 0;
}