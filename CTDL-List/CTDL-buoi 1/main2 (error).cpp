//#include <iostream>
//using namespace std;
////
////struct Node{
////	int data;
////	Node *pNext;
////}; //kiểu của một phần tử trong danh sách
////
////struct List{
////	Node *pHead;
////	Node *pTail;
////}; //kiểu danh sách liên kết
////
////Node* getNode(int x);
////void Inist(List &l);
////void addHead(List &l, Node *new_node);
////
////int main() {
////	/*Node n1;
////	n1.data = 10;
////	Node n2;
////	n2.data = 20;
////	n1.pNext = &n2;
////	Node n3;
////	n2.pNext = &n3;
////	n3.data = 30;*/
////
////	//// Nhập dữ liệu cho X
////	//int x;
////	//cout << "Nhap X = ";
////	//cin >> x;
////	//// Tạo nút mới
////	//Node* new_node = getNode(x);
////	//List l;
////	//// Gắn nút vào đầu ds
////	//if (new_node != NULL)
////	//	addHead(l, new_node);
////
////
////	return 0;
////}
////
////Node* getNode(int x){
////	Node *p;
////	p = new Node;
////	p->data = x; //gán dữ liệu cho phần tử
////	p->pNext = NULL;
////	return p;
////} //tạo nút mới
////
////void Inist(List &l){
////	l.pHead = l.pTail = NULL;
////} //tạo một danh sách rỗng
////
////void addHead(List &l, Node *new_node){
////	if (l.pHead == NULL){
////		l.pHead = l.pTail = new_node;
////	}
////	else {
////		new_node->pNext = l.pHead;
////		l.pHead = new_node;
////	}
////} //gắn nút vào đầu danh sách
//
//class BanCo
//{
//public:
//	BanCo(int m,int n){
//		M = m; N = n;
//		a = new int *[M];
//		for (int i = 0; i < M; i++){
//			a[i] = new int[N];
//			for (int j = 0; j < N; j++) a[i][j] = i*N + j + 1;
//		}
//		a[M - 1][N - 1] = 0;
//		x = M - 1; y = N - 1;
//	}
//	void inBanCo(){
//		for (int i = 0; i < M; i++){
//			for (int j = 0; j < N; j++) cout<< a[i][j] << " ";
//			cout << endl;
//		}
//	}
//	bool coDiDuoc(char huong){
//		if (huong == 'B') return x > 0;
//		if (huong == 'D') return y < N;
//		if (huong == 'N') return x < M;
//		if (huong == 'T') return y > 0;
//	}
//	BanCo Di(char huong){
//		BanCo m(M, N);
//		for (int i = 0; i < M; i++)
//			for (int j = 0; j < N; j++)
//				m.a[i][j] = a[i][j];
//		if (huong == 'B'){
//			m.a[x][y] = m.a[x - 1][y];
//			m.a[x - 1][y] = 0;
//			m.x = x - 1;
//			m.y = y;
//		}
//		if (huong == 'D'){
//			m.a[x][y] = m.a[x][y + 1];
//			m.a[x][y + 1] = 0;
//			m.x = x;
//			m.y = y + 1;
//		}
//		if (huong == 'N'){
//			m.a[x][y] = m.a[x + 1][y];
//			m.a[x + 1][y] = 0;
//			m.x = x + 1;
//			m.y = y;
//		}
//		if (huong == 'T'){
//			m.a[x][y] = m.a[x][y - 1];
//			m.a[x][y - 1] = 0;
//			m.x = x;
//			m.y = y - 1;
//		}
//	}
//	bool Check(BanCo bc){
//		for (int i = 0; i < M; i++)
//			for (int j = 0; j < N; j++)
//				if (a[i][j] != bc.a[i][j])
//					return false;
//	}
//	~BanCo();
//
//private:
//	int **a;
//	int M;
//	int N;
//	int x;
//	int y;
//};
//
//void main(){
//	BanCo bc(3, 3);
//	bc.inBanCo();
//	BanCo t = bc.Di('B');
//	cout << "-----------------" << endl;
//	t.inBanCo();
//
//}