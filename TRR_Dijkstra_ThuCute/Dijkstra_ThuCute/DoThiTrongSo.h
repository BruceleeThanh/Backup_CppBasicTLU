#ifndef DOTHITRONGSO
#define DOTHITRONGSO

#include<iostream>
#include<fstream>
using namespace std;

int const Max = 100;
int const VoCung = 10000;
class DoThiTrongSo
{

private:
	int N;
	int a[Max][Max];
public:
	DoThiTrongSo() :N(0){}

	DoThiTrongSo(char *filename, char type)
	{
		ifstream fin(filename);
		fin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				a[i][j] = VoCung;
			}
		}
		if (type == 'W' || type == 'w'){ //Doc ma tran co trong so.
			int x, y, z;
			while (fin >> x >> y >> z){
				a[x - 1][y - 1] = z;
				a[y - 1][x - 1] = z;
			}
			fin.close();
		}
	}

	int getN(){
		return N;
	}

	int Dijkstra(int x, int y, bool dx[], int truoc[]){
		int duyetTrongSo[100]; // duyetTrongSo dung de luu lai do dai quang duong di toi 1 dinh
		int min; // min dung de luu lai do dai quang duong nho nhat trong 1 lan xet
		int demSoDinh = 0; // demSoDinh dung de dem so dinh da duyet duoc
		int dinhDuocDuyet = 0; // dinhDangXet dung de luu lai dinh vua duoc duyet

		for (int i = 0; i < N; i++){
			duyetTrongSo[i] = VoCung;
		}

		duyetTrongSo[x - 1] = 0; // Dinh dau tien co do dai quang duong = 0

		while (demSoDinh != N){
			min = VoCung;

			for (int i = 0; i < N; ++i){
				if (min > duyetTrongSo[i] && !dx[i]) {   // Tim dinh co do dai quang duong nho nhat va chua duoc duyet
					min = duyetTrongSo[i]; // Luu lai do dai quang duong (nho nhat) cua dinh duoc duyet
					dinhDuocDuyet = i; // Luu lai dinh duoc duyet
				}
			}
			dx[dinhDuocDuyet] = true; // Dinh duoc duyet trong mang dx (Da xet) = true
			demSoDinh++; // demSoDinh tang them 1 don vi

			// Luu y: tai lan thuc hien dau tien cua vong lap While, cong viec tim dinh co do dai quang duong nho nhat chinh la viec duyet lai diem bat dau (diem x)

			for (int i = 0; i < N; i++){ // Duyet qua tat ca cac dinh giao voi dinhDuocDuyet va thuc hien cong do dai quang duong
				if (!dx[i]){ // Cac dinh dang xet phai la cac dinh chua duoc duyet
					if ((min = duyetTrongSo[dinhDuocDuyet] + a[dinhDuocDuyet][i]) < duyetTrongSo[i]){ 
						// Tim dinh giao voi dinhDuocDuyet va co do dai quang duong (sau khi cong voi do dai quang duong cua dinhDuocDuyet) < trong so cua chinh no
						duyetTrongSo[i] = min; // Neu tim duoc thi gan do dai quang duong cua dinh tim duoc bang do dai quang duong (sau khi cong voi do dai quang duong cua dinhDuocDuyet)
						truoc[i] = dinhDuocDuyet + 1; // Them dinh vua tim duoc vao mang truoc
					}
				}
			}

		}
		return duyetTrongSo[y - 1]; // Tra ve do dai cua duong di tu x den y
	}

	void timduongdi(int x, int y, int truoc[])
	{
		int tim = y;
		while (tim != x && tim != -1)
		{
			cout << tim << "<-";
			tim = truoc[tim - 1];
		}
		cout << x;
	}

};

#endif