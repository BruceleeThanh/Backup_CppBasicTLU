#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	long long i = 2, n;
	n = (long long)sqrt(600851475143);

	while (n > 1)
	{
		while (i <= (int)sqrt((double)n))
		{
			if (n%i == 0)
			{
				break;
			}
			else
			{
				i++;
				if (i > (int)sqrt((double)n))
				{
					if ((600851475143 % n) == 0)
					{
						cout << "KQ: " << n;
					}
				}

			}
		}
		n--;
		i = 2;
	}
	cout << endl;
}