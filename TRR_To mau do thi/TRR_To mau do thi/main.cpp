#include <iostream>
#include <fstream>
using namespace std;
struct ToMau
{	
	int dinh;
	int mau = 0;
	int sobac = 0;
};

int main(){
	int n, a[100][100], mau = 0;
	bool check;
	ToMau color[100];
	ifstream fin("input.txt");
	fin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = 0;
		}
	}
	int x, y;
	while (fin >> x >> y){
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 0; i < n; i++){
		int count = 0;
		for (int j = 0; j < n; j++){
			if (a[i][j] == 1){
				count++;
			}
		}
		color[i].dinh = i;
		color[i].sobac = count;
	}
		
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (color[i].sobac < color[j].sobac){
				ToMau temp = color[i];
				color[i] = color[j];
				color[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++){
		
		if (color[i].mau == 0){
			mau++;
			color[i].mau = mau;
		}
		for (int j = i + 1; j < n; j++){
			check = true;
			if (color[j].mau == 0 && a[color[i].dinh][color[j].dinh] == 0){
				for (int k = j - 1; k > i; k--){
					if (color[k].mau == mau && a[color[j].dinh][color[k].dinh] == 1){
						check = false;
					}
				}
				if (check){
					color[j].mau = mau;
				}
			}
		}
		
	}
	for (int i = 0; i < n; i++){
		cout << "Dinh " << color[i].dinh << " co bac " << color[i].sobac << " co mau " << color[i].mau << endl;
	}


	fin.close();
	return 0;
}