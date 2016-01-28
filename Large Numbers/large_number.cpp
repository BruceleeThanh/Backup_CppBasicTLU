#include <iostream>
#include <math.h>
#include <string.h>
#include "large_number.h"
using namespace std;

LargeNumber::LargeNumber(){
	a = '0';
}

LargeNumber::LargeNumber(string _a){
	a = _a;
}

void LargeNumber::setLargeNumber(string _a){
	a = _a;
}

string LargeNumber::getLargeNumber(){
	return ans;
}

int LargeNumber::Length() const{
	return a.length();
}

LargeNumber LargeNumber::operator +(LargeNumber x){
	int n1 = a.length(), n2 = x.Length(), sum, mem = 0;
	if (n2 > n1) void temp();
	ans = a;
	for (int i = a.length() - 1, j = x.Length() - 1; (i >= 0) || (j >= 0); i--, j--){
		if (j >= 0) sum = ((int)a[i] - 48) + ((int)b[j] - 48) + mem;
		else sum = ((int)a[i] - 48) + mem;
		if (sum >= 10){
			sum = sum % 10;
			mem = 1;
		}
		else mem = 0;
		ans[j] = (char)sum + 48;
		if (mem == 0 && j < 0) break;
	}
	if (mem == 1) ans = '1' + ans;
	//cout << "Sum of two large numbers is: " << ans << endl;
	return LargeNumber(ans);
}