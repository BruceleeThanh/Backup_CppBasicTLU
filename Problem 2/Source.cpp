#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	long long f1 = 1, f2 = 1, sum = 0;
	while ((f1 < 4000000) || (f2 < 4000000))
	{
		if ((f1 % 2) == 0) sum += f1;
		f1 = f1 + f2;
		if ((f2 % 2) == 0) sum += f2;
		f2 = f1 + f2;
	}
	cout << "KQ: " << sum;
	return 0;
}