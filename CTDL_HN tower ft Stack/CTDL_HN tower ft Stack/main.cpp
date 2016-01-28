#include "Stack.h"

int n, dem = 0, pos, max;
string value;
char ch;
Stack<string> *s1 = new Stack<string>;
Stack<string> *s2 = new Stack<string>;
Stack<string> *s3 = new Stack<string>;

void thapHN(int n, Stack <string> &A, Stack <string> &B, Stack <string> &C);

int main(){
	//Stack <string> s1, s2, s3;
	cout << "Nhap ten Cot thu nhat: "; s1->setName();
	cout << "Nhap ten Cot thu hai: "; s2->setName();
	cout << "Nhap ten Cot thu ba: "; s3->setName();
	cout << "Nhap so dia: "; cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++){
		cout << "Nhap gia tri dia cho Cot " << s1->getName() << ": "; getline(cin, value);
		s1->Push(value);
	}
	cout << "Nhap trang thai can kiem tra: "; cin >> pos;
	thapHN(n, *s1, *s2, *s3);
	cin.get(ch);
	cout << endl << "Tat ca cac dia da duoc chuyen toi cot " << s3->getName() << endl;
	system("pause");
}

void thapHN(int n, Stack <string> &A, Stack <string> &B, Stack <string> &C){

	if (n == 1){
		//cout << "Chuyen dia " << A.getTop() << " tu Cot " << A.getName() << " sang Cot " << C.getName() << endl;
		C.Push(A.getTop());
		A.Pop();
		dem++;
		if (dem == pos){
			cin.get(ch);
			cout << "---------------------------------------------" << endl;
			cout << "Buoc thu " << pos << " la: " << endl << endl;
			max = s1->Count();
			if (max < s2->Count()){
				max = s2->Count();
			}
			if (max < s3->Count()){
				max = s3->Count();
			}

			s1->displayAll();
			s2->displayAll();
			s3->displayAll();
			cout << endl << "Ban co muon tiep tuc kiem tra.?";
			++pos;
		}
	}
	else{
		thapHN(n - 1, A, C, B);
		thapHN(1, A, B, C);
		thapHN(n - 1, B, A, C);
	}
}

//void Move(Stack <string> A, Stack <string> C){
//	cout << "Chuyen dia " << A.getTop() << " tu " << A.getName() << " sang " << C.getName() << endl;
//	C.Push(A.getTop());
//	A.Pop();
//}
//
//void thapHN_smart(int n, Stack <string> A, Stack <string> C, Stack <string> B){
//	if (n == 1){
//		Move(A, C);
//	}
//	else{
//		thapHN_smart(n - 1, A, B, C);
//		Move(A, C);
//		thapHN_smart(n - 1, B, C, A);
//	}
//}

