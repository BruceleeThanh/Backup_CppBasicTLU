#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

char a[100][100];
void Display1(){
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 26; j++){
			a[i][j] = (char)46;
			cout << a[i][j]<<"  ";
		}
		cout << endl << endl;
	}
}
void Display2(){
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 20; j++){
			cout << " ";
		}
		cout << endl;
	}
}

int main(){

	Display1();
	//while (1){

	//	int a = _getch();
	//	cout << a << endl;
	//}
	

	return 0;
}