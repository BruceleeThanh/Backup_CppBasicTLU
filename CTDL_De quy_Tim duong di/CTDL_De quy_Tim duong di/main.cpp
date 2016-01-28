#include <iostream>
using namespace std;

int sum = 0, a[1000][1000], b[1000],  c = 0;

void main(){

}
void Move(int i, int j){
	if (i > 3){
		b[c++] = sum;
		sum = 0;
		return;
	}
	else{
		sum += a[i][j];
	}
	Move(i + 1, j); // Đi xuống
	if (j <= 3){
		Move(i + 1, j + 1); // Đi sang phải
	}
	if (j >= 0){
		Move(i + 1, j - 1); //Đi sang trái
	}
}