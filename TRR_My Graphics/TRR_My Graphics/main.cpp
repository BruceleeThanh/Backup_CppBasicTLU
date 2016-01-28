#include "Lib.h"

int main(){
	char type;
	int start, end, press, weight;
	cout << "Nhap loai file dau vao tuong ung:\n1. Ma tran ke: Nhap M hoac m.\n2. Danh sach dinh: Nhap L hoac l.\n3. Danh sach dinh co trong so: Nhap W hoac w.\n";
	cout << "Ban nhap loai do thi: ";
	cin >> type;
	Graphics gra("input_1.dat", type);
	gra.displayMatrix();
	while (1){
		cout << "---------------------------------------------------" << endl;
		cout << "1. Nhap 1 de duyet theo DFS.\n2. Nhap 2 de duyet theo BFS.\n3. Nhap 3 de duyet theo Dijkstra.\n4. Nhap 4 de duyet theo Prim.\n5. Nhap 5 de duyet theo Kruskal.\n6. Nhap 6 de kiem tra Lien thong.\n7. Nhap 7 de To mau do thi.\n8. Nhap 0 de Thoat khoi chuong trinh." << endl;
		cout << "Ban nhap lua chon: ";
		cin >> press;
		cout << "-------------------------" << endl;
		if (press == 0){
			cout << "Thoat khoi chuong trinh." << endl;
			break;
		}
		switch (press){
			case 1:
				cout << "Ban da chon duyet theo DFS." << endl;
				cout << "Nhap diem dau: ";
				cin >> start;
				cout << "Nhap dinh cuoi: ";
				cin >> end;
				gra.DFS(start, end);
				break;
			case 2:
				cout << "Ban da chon duyet theo BFS." << endl;
				cout << "Nhap diem dau: ";
				cin >> start;
				cout << "Nhap dinh cuoi: ";
				cin >> end;
				gra.BFS(start, end);
				break;
			case 3:
				cout << "Ban da chon duyet theo Dijkstra." << endl;
				cout << "Nhap diem dau: ";
				cin >> start;
				cout << "Nhap dinh cuoi: ";
				cin >> end;
				weight = gra.Dijkstra(start, end);
				cout << "Do lon cua duong di la: " << weight << endl;
				break;
			case 4:
				cout << "Ban da chon duyet theo Prim." << endl;
				gra.Prim();
				break;
			case 5:
				cout << "Ban da chon duyet theo Kruskal." << endl;
				gra.Kruskal();
				break;
			case 6:
				cout << "Ban da chon kiem tra tinh Lien thong." << endl;
				if (gra.checkConnectedGraph()){
					cout << "Do thi Lien thong" << endl;
				}
				else{
					cout << "Do thi KHONG Lien thong." << endl;
				}
				break;
			case 7:
				cout << "Ban da chon To mau do thi." << endl;
				gra.Painting();
				break;
			default:
				cout << "Ban nhap sai roi. Hay nhap lai." << endl;
				break;
		}
	}
	


	return 0;
}