//
//EXERCISE 2
//
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

string f;
double n;
int _count, count0 = 0, count1 = 0;

string changeBinary(int i, int n);
void CTT();
void CTH();
bool check();

int main(){
	ifstream fin("input.txt");
	if (!fin.is_open()){
		cout << "Can't open file." << endl;
	}
	else{
		while (!fin.eof()){
			string x;
			fin >> x;
			f += x;
		}
		cout << f << endl;
		_count = f.length();
		n = log2(_count);
		if (check()){
			for (int i = 0; i < _count; i++){
				if (f[i] == '1'){
					count1++;
				}
				else{
					count0++;
				}
			}
			if (count0 > count1){
				CTH();
			}
			else{
				CTT();
			}
		}
	}
	cout << endl;

	return 0;
}

string changeBinary(int i){
	string binary;
	int k = 0;
	while (i != 0){
		binary = (char)(i % 2 + 48) + binary;
		i = i / 2;
		k++;
	}
	for (k; k < n; k++){
		binary = '0' + binary;
	}
	return binary;
}

void CTT(){
	string binary;
	for (int i = 0; i < _count; i++){
		if (f[i] == '1'){
			binary = changeBinary(i);
			if (count1 == 1){
				cout << "[";
				for (int j = 0; j < n; j++){
					if (j < n - 1){
						if (binary[j] == '0'){
							cout << "(X" << j + 1 << " NAND X" << j + 1 << ") NAND ";
						}
						else{
							cout << "X" << j + 1 << " NAND ";
						}
					}
					else{
						if (binary[j] == '0'){
							cout << "(X" << j + 1 << " NAND X" << j + 1 << ")]";
						}
						else{
							cout << "X" << j + 1 << "]";
						}
					}
				}
			}
			else{
				cout << "[";
				for (int j = 0; j < n; j++){
					if (j < n - 1){
						if (binary[j] == '0'){
							cout << "(X" << j + 1 << " NAND X" << j + 1 << ") NAND ";
						}
						else{
							cout << "X" << j + 1 << " NAND ";
						}
					}
					else{
						if (binary[j] == '0'){
							cout << "(X" << j + 1 << " NAND X" << j + 1 << ")]";
						}
						else{
							cout << "X" << j + 1 << "]";
						}
					}
				}
				cout << " NAND ";
			}
			count1--;
		}
	}
}

void CTH(){
	string binary;
	for (int i = 0; i < _count; i++){
		if (f[i] == '0'){
			binary = changeBinary(i);
			if (count0 == 1){
				cout << "[";
				for (int j = 0; j < n; j++){
					if (j < n - 1){
						if (binary[j] == '1'){
							cout << "(X" << j + 1 << " NOR X" << j + 1 << ") NOR ";
						}
						else{
							cout << "X" << j + 1 << " NOR ";
						}
					}
					else{
						if (binary[j] == '1'){
							cout << "(X" << j + 1 << " NOR X" << j + 1 << ")]";
						}
						else{
							cout << "X" << j + 1 << "]";
						}
					}
				}
			}
			else{
				cout << "[";
				for (int j = 0; j < n; j++){
					if (j < n - 1){
						if (binary[j] == '1'){
							cout << "(X" << j + 1 << " NOR X" << j + 1 << ") NOR ";
						}
						else{
							cout << "X" << j + 1 << " NOR ";
						}
					}
					else{
						if (binary[j] == '1'){
							cout << "(X" << j + 1 << " NOR X" << j + 1 << ")]";
						}
						else{
							cout << "X" << j + 1 << "]";
						}
					}
				}
				cout << " NOR ";
			}
			count0--;
		}
	}
}

bool check(){
	for (int q = 0; q < _count; q++){
		if (f[q] != '1' && f[q] != '0'){ //error1: type of character is incorrect
			cout << "Error: type of character is incorrect." << endl;
			return false;
		}
	}
	if (n != (int)n || _count == 1){ //error2: the number of input characters is incorrect
		cout << "Error: the number of input characters is incorrect." << endl;
		return false;
	}
	return true;
}