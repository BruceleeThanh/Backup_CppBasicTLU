#include <iostream>
#include <string>
#include "large_number.h"
using namespace std;
int main(){
	LargeNumber a = "123", b = "999", c;
	c = a + b;
	cout << c.getLargeNumber() << endl;

	return 0;
}
