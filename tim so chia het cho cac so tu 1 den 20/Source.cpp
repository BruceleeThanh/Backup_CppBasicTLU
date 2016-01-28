#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int n = 20, count;
	while (1){
		count = 0;
		for (int i = 1; i <= 20; i++){
			if (n%i == 0){
				count++;
			}
		}
		if (count == 20){
			cout << "So can tim la: " << n << endl;
			break;
		}
		n += 20;
	}

	_getch();
	return 0;
}