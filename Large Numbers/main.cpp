//#include <iostream>
//#include <math.h>
//#include <string>
//using namespace std;
//
////sum=Sum (Addition), pro=Product (Multiplication), dif=Difference (Subtraction), quo=Quotient (Division)
//
//string a, b, ans;
//char ans1[10000];
//
//void temp();
//void Addition_LargeNumbers();
//void Powerof_two();
//void Multiplication_LargeNumbers();
//void Subtraction_LargeNumbers();
//
//void temp(){
//	string temp = a;
//	a = b;
//	b = temp;
//}
//
//void Addition_LargeNumbers(){
//	int n1 = a.length(), n2 = b.length(), sum, mem = 0;
//	if (n2 > n1) void temp();
//	ans = a;
//	for (int i = a.length() - 1, j = b.length() - 1; (i >= 0) || (j >= 0); i--, j--){
//		if (j >= 0) sum = ((int)a[i] - 48) + ((int)b[j] - 48) + mem;
//		else sum = ((int)a[i] - 48) + mem;
//		if (sum >= 10){
//			sum = sum % 10;
//			mem = 1;
//		}
//		else mem = 0;
//		ans[j] = (char)sum + 48;
//		if (mem == 0 && j < 0) break;
//	}
//	if (mem == 1) ans = '1' + ans;
//	cout << "Sum of two large numbers is: " << ans << endl;
//}
//
//void Powerof_two(){
//	int pro, mem = 0, sum = 0;
//	long long n;
//	cout << "Enter Exponent of 2: "; cin >> n;
//	ans = '1';
//	for (int i = 0; i < n; i++){
//		for (int j = ans.length()-1; j >= 0; j--){
//			pro = ((int)ans[j] - 48) * 2 + mem;
//			if (pro >= 10){
//				pro = pro % 10;
//				mem = 1;
//			}
//			else mem = 0;
//			ans[j] = (char)pro + 48;
//		}
//		if (mem == 1){
//			ans = '1' + ans;
//			mem = 0;
//		}
//	}
//	for (int i = ans.length() - 1; i >= 0; i--) sum += (int)ans[i] - 48;
//	cout << "2^" << n << " = " << ans << endl;
//	cout << "Length answers: " << ans.length() << endl;
//	cout << "Sum of digits: " << sum << endl;
//}
//
//void Multiplication_LargeNumbers(){
//	int x[350][350], y[350][350], pro, sum = 0, z = 0, mem = 0, k;
//	for (int i = 0; i < a.length(); i++){
//		x[0][i + 1] = (char)a[i] - 48;
//	}
//	for (int i = 0, j = b.length(); j > 0, i < b.length(); i++, j--){
//		x[j][0] = (char)b[i] - 48;
//	}
//	for (int i = 1; i <= b.length(); i++){
//		for (int j = 1; j <= a.length(); j++){
//			pro = x[0][j] * x[i][0];
//			if (pro >= 10){
//				x[i][j] = pro % 10;
//				y[i][j] = pro / 10;
//			}
//			else{
//				x[i][j] = pro;
//				y[i][j] = 0;
//			}
//		}
//	}
//	//Horizontal row
//	for (int i = a.length(); i > 0; i--){
//		k = i;
//		for (int j = 1; j <= b.length(); j++){
//			if (k == a.length()){
//				sum += x[j][k] + mem;
//				mem = 0;
//				break;
//			}
//			sum += x[j][k] + y[j][k + 1] + mem;
//			mem = 0;
//			k++;
//		}
//		if (sum >= 10){
//			mem = sum / 10;
//			sum = sum % 10;
//		}
//		else mem = 0;
//		ans1[z++] = (char)sum + 48;
//		sum = 0;
//	}
//	//Vertical row
//	for (int i = 1; i <= b.length(); i++){
//		int k = i;
//		for (int j = 1; j <= a.length(); j++, k++){
//			if (k == b.length()){
//				sum += y[k][j] + mem;
//				mem = 0;
//				break;
//			}
//			sum += y[k][j] + x[k + 1][j] + mem;
//			mem = 0;
//		}
//		if (sum >= 10){
//			mem = sum / 10;
//			sum = sum % 10;
//		}
//		else mem = 0;
//		ans1[z++] = (char)sum + 48;
//		sum = 0;
//	}
//	if (mem >= 10){
//		while (mem >= 10){
//			ans1[z++] = (char)(mem % 10) + 48;
//			mem = mem / 10;
//		}
//	}
//	if ((mem < 10) && (mem != 0)) ans1[z] = (char)mem + 48;
//	cout << "Mul of two large numbers is: ";
//	for (int i = z - 1; i >= 0; i--) cout << ans1[i];
//	cout << endl;
//}
//
//void Subtraction_LargeNumbers(){
//	int n1 = a.length(), n2 = b.length(), dif, mem = 0;
//	
//}
//
//int main(){
//
//	cout << "Enter the first number: "; getline(cin, a);
//	cout << "Enter the second number: "; getline(cin, b);
//
//	//Subtraction_LargeNumbers();
//
//	Multiplication_LargeNumbers();
//
//	//Addition_LargeNumbers();
//
//	//Powerof_two();
//
//	return 0;
//}