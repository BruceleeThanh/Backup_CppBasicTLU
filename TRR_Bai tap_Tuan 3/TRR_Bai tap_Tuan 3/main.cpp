#include <iostream>
#include <fstream>
using namespace std;

bool danhdau[100];
int duongdi[100], dem = 0;
int x, a[100][100];

void DFS(int s);
void khoitao();
void TimDuong(int dinhdau, int dinhcuoi);

int main(){

	int s;
	ifstream fin("input_1.dat");
	ofstream fout("output_1.dat");
	if (!fin.is_open()){
		cout << "Khong mo duoc file." << endl;
	}
	else{
		fin >> x;
		khoitao();
		for (int i = 0; i < x; i++){
			for (int j = 0; j < x; j++){
				fin >> a[i][j];
			}
		}
		TimDuong(2,6);
	}

	return 0;
}

void DFS(int s){
	danhdau[s] = true;
	for (int i = 0; i < x; i++){
		if (a[s-1][i] == 1 && danhdau[i + 1] == false){
			danhdau[i + 1] = true;
			duongdi[i + 1] = s;
			DFS(i+1);
		}
	}
}
void khoitao(){
	for (int i = 0; i < x; i++){
		danhdau[i] = false;
		duongdi[i] = -1;
	}
	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			a[i][j] = 0;
		}
	}
}
void TimDuong(int dinhdau, int dinhcuoi){
	DFS(dinhdau);
	int i = dinhcuoi;
	while (i != dinhdau && i != -1){
		cout << i << " <- ";
		i = duongdi[i];
	}
	cout << i << endl;

}