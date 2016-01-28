#include <iostream>
#include <ctime>

using namespace std;

void mergeSort(int x[], int a, int b);
void Merge(int x[], int a, int c, int b);
void sapXepChen(int x[], int n);

int main(){

	//int x[200000], n;
	int *x = new int[30000000], n;
	srand(time(NULL));
	cout << "Nhap so phan tu: "; cin >> n;
	cout << "Nhap cac phan tu: ";
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			x[i] = rand() % 1000000 + 1;
		}
		else{
			x[i] = rand() % 10000 + 1;
		}
	}
	cout << "---------------------------" << endl;
	mergeSort(x, 0, n - 1);
	//sapXepChen(x, n);
	char ch;
	cin.get(ch);
	cout << "Done.!";
	/*for (int i = 0; i < n; i++){
		cout << x[i] << endl;
	}*/


	return 0;
}

void mergeSort(int x[], int a, int b){
	int c;
	if (a < b){
		c = (b + a) / 2;
		mergeSort(x, a, c);
		mergeSort(x, c + 1, b);
		Merge(x, a, c, b);
	}
}

void Merge(int x[], int a, int c, int b){
	int i = a, j = c + 1, n = b - a + 1, k = 0;
	int *y = new int[n];
	while (i <= c && j <= b){
		if (x[i] < x[j]){
			y[k++] = x[i++];
		}
		else{
			y[k++] = x[j++];
		}
	}
	while (i <= c){
		y[k++] = x[i++];
	}
	while (j <= b){
		y[k++] = x[j++];
	}
	i = a;
	for (int k = 0; k < n;k++){
		x[i++] = y[k];
	}
	delete y;
}

void sapXepChen(int x[], int n){
	for (int i = 1; i < n; i++){
		for (int j = i; j >= 0; j--){
			if (x[j] < x[j - 1]){
				int temp = x[j];
				x[j] = x[j - 1];
				x[j - 1] = temp;
			}
		}
	}
}