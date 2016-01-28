#include <iostream>
using namespace std;

#include "DoThi.h"
int main(){
	DoThi dt("input_1.dat", 'm');

	dt.InDoThiDangMaTranKe();

	int dsd[100], k = 0;

	dt.DFS(2, dsd, k);
	for (int i = 0; i < 6; i++){
		cout <<i+1<<" to "<< dsd[i] << "; ";
	}
	cout << endl;
	if (k < dt.GetSoDinh())
		cout << "Do thi khong lien thong\n";
	else
		cout << "Do thi lien thong\n";

	dt.xetEuler();


	return 0;
}