#include <iostream>
#include <fstream>
using namespace std;

bool KT_Doixung(int x, int a[100][100]);

int main(){

	//Exercise 1

	/*int n, m, a[100][100];
	ifstream fin("input_1.dat");
	ofstream fout("output_1.dat");
	if (!fin.is_open()){
		cout << "Can not open file." << endl;
	}
	else{
		fin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++){
			int x, y;
			fin >> x >> y;
			a[x - 1][y - 1] = 1;
			a[y - 1][x - 1] = 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				fout << a[i][j] << " ";
			}
			fout << endl;
		}
	}
	fin.close();*/

	//Exercise 2

	/*int x, a[100][100];
	ifstream fin("input_2.dat");
	ofstream fout("output_2.dat");
	if (!fin.is_open()){
		cout << "Khong mo duoc file." << endl;
	}
	else{
		fin >> x;
		for (int i = 0; i < x; i++){
			for (int j = 0; j < x; j++){
				fin >> a[i][j];
			}
		}
		if (KT_Doixung(x, a)){
			fout << "graph dothi" << endl << "{";
			for (int i = 0; i < x; i++){
				for (int j = 0; j <= i; j++){
					if (a[i][j] == 1){
						fout << endl << "\t" << i + 1 << " -- " << j + 1 << ";";
					}
				}
			}
			fout << endl << "}";
		}
		else{
			fout << "digraph output" << endl << "{";
			for (int i = 0; i < x; i++){
				for (int j = 0; j < x; j++){
					if (a[i][j] == 1){
						fout << endl << "\t" << i + 1 << " -> " << j + 1 << ";";
					}
				}
			}
			fout << endl << "}";
		}
	}
	

	fin.close();
	fout.close();*/

	//Exercise 3

	/*int n, a[100][100], b[100][100];
	fstream fin("input_3.dat");
	ofstream fout("output_3.dat");

	if (!fin.is_open()){
		cout << "Khong mo duoc file." << endl;
	}
	else{
		fin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				b[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++){
			int x;
			fin >> x;
			a[i][0] = x;
			for (int j = 1; j <= x; j++){
				fin >> a[i][j];
			}
		}
		for (int i = 0; i < n - 1; i++){
			for (int j = 1; j <= a[i][0]; j++){
				for (int k = i + 1; k < n; k++){
					for (int h = 1; h < a[k][0]; h++){
						if (a[i][j] == a[k][h]){
							b[i][k] = 1;
							b[k][i] = 1;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				fout << b[i][j] << " ";
			}
			fout << endl;
		}
	}

	fin.close();
	fout.close();*/

	return 0;
}

bool KT_Doixung(int x, int a[100][100]){ //Function of Exercise 2
	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			if (a[i][j] == 1){
				if (a[i][j] != a[j][i]){
					return false;
				}
			}
		}
	}
	return true;
}