#include <fstream>
using namespace std;

class DoThi
{
private:
	int a[100][100];
	int N;
	void DFSDeQuy(int v, bool dx[], int dsd[], int &k){
		dx[v - 1] = true;
		dsd[k++] = v;
		for (int i = 1; i <= N; i++){
			if (a[i - 1][v - 1] == 1 && !dx[i - 1]){
				DFSDeQuy(i, dx, dsd, k);
			}
		}
	}
public:
	DoThi(){
		N = 0;
	}


	DoThi(const char *fileName, char type){
		ifstream fin(fileName);

		if (type == 'M' || type == 'm'){
			fin >> N;
			for (int i = 0; i< N; i++)
				for (int j = 0; j< N; j++)
					fin >> a[i][j];
		}
		else{
			fin >> N;
			for (int i = 0; i< N; i++)
				for (int j = 0; j< N; j++)
					a[i][j] = 0;
			int x, y;
			while (fin >> x >> y){
				a[x - 1][y - 1] = 1;
				a[y - 1][x - 1] = 1;
			}
		}
		fin.close();
	}

	void InDoThiDangMaTranKe() const{
		cout << "So dinh: " << N << endl;
		for (int i = 0; i< N; i++){
			for (int j = 0; j< N; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}

	void DFS(int s, int dsd[], int &k){
		bool *dx = new bool[N];
		for (int i = 0; i<N; i++)
			dx[i] = false;
		DFSDeQuy(s, dx, dsd, k);
	}

	int GetSoDinh()const{
		return N;
	}

	void xetEuler(){
		int bacle = 0;
		for (int i = 0; i < N; i++){
			int dem = 0;
			for (int j = 0; j < N; j++){
				if (a[i][j] = 1){
					dem++;
				}
			}
			if (dem % 2 != 0){
				bacle++;
			}
		}
		if (bacle == 0){
			cout << "Co chu trinh Euler." << endl;
		}
		else{
			if (bacle == 2){
				cout << "Co duong di Euler." << endl;
			}
			else{
				cout << "Khong co duong di va chu trinh Euler." << endl;
			}
		}
	}
};