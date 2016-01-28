#include <iostream>
using namespace std;

int main(){
	int div = 1, count;
	while (1){
		count = 0;
		for (int i = 1; i < div; i++){
			if (div%i == 0){
				count++;
			}
		}
		if (count == 501){
			cout << div << endl;
			break;
		}
		div++;
	}


	return 0;
}