#include <iostream>
using namespace std;
int main()
{
	long long x = 1, dem = 0, s = 1;
	for (int i = 3; i <= 1001; i += 2)
	{
		for (int j = 1; j <= 4; j++)
		{
			x = x + dem + 2;
			s = s + x;
		}
		dem += 2;
	}
	cout << "Ket qua la: " << s << endl;

	return 0;
}