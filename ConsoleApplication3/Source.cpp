#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
	int n, a, b, c, d;
	string t, t1, t2, t3;
	cout << "\n         CHUONG TRINH DOI SO THANH CHU";
	cout << "\n\n Moi ban nhap so 4 chu so: ";
	cin >> n;
	a = n % 10;
	n = n / 10;
	b = n % 10;
	n = n / 10;
	c = n % 10;
	n = n / 10;
	d = n % 10;
	switch (a)
	{
	case 0:
	{
			  t = "";
			  break;
	}
	case 1:
	{
			  t = "mot";
			  break;
	}
	case 2:
	{
			  t = "hai";
			  break;
	}
	case 3:
	{
			  t = "ba";
			  break;
	}
	case 4:
	{
			  t = "bon";
			  break;
	}
	case 5:
	{
			  t = "nam";
			  break;
	}
	case 6:
	{
			  t = "sau";
			  break;
	}
	case 7:
	{
			  t = "bay";
			  break;
	}
	case 8:
	{
			  t = "tam";
			  break;
	}
	case 9:
	{
			  t = "chin";
			  break;
	}
	}
	if (b == 0)
	{
		t1 = "linh";
	}
	else
		switch (b)
	{
		case 1:
		{
				  t1 = "muoi";
				  break;
		}
		case 2:
		{
				  t1 = "hai muoi";
				  break;
		}
		case 3:
		{
				  t1 = "ba muoi";
				  break;
		}
		case 4:
		{
				  t1 = "bon muoi";
				  break;
		}
		case 5:
		{
				  t1 = "nam muoi";
				  break;
		}
		case 6:
		{
				  t1 = "sau muoi";
				  break;
		}
		case 7:
		{
				  t1 = "bay muoi";
				  break;
		}
		case 8:
		{
				  t1 = "tam muoi";
				  break;
		}
		case 9:
		{
				  t1 = "chin muoi";
				  break;
		}

	}
	if (b == 0 && c == 0)
	{
		t2 = "";
	}
	else if (c == 0)
	{
		t2 = "khong tram ";
	}
	else
		switch (c)
	{
		case 1:
		{
				  t2 = "mot tram ";
				  break;
		}
		case 2:
		{
				  t2 = "hai tram ";
				  break;
		}
		case 3:
		{
				  t2 = "ba tram ";
				  break;
		}
		case 4:
		{
				  t2 = "bon tram ";
				  break;
		}
		case 5:
		{
				  t2 = "nam tram ";
				  break;
		}
		case 6:
		{
				  t2 = "sau tram ";
				  break;
		}
		case 7:
		{
				  t2 = "bay tram ";
				  break;
		}
		case 8:
		{
				  t2 = "tam tram ";
				  break;
		}
		case 9:
		{
				  t2 = "chin tram ";
				  break;
		}
	}
	if (d == 0)
	{
		t3 = "";
	}
	else
		switch (d)
	{
		case 1:
		{
				  t3 = "mot nghin ";
				  break;
		}
		case 2:
		{
				  t3 = "hai nghin ";
				  break;
		}
		case 3:
		{
				  t3 = "ba nghin ";
				  break;
		}
		case 4:
		{
				  t3 = "bon nghin ";
				  break;
		}
		case 5:
		{
				  t3 = "nam nghin ";
				  break;
		}
		case 6:
		{
				  t3 = "sau nghin ";
				  break;
		}
		case 7:
		{
				  t3 = "bay nghin ";
				  break;
		}
		case 8:
		{
				  t3 = "tam nghin ";
				  break;
		}
		case 9:
		{
				  t3 = "chin nghin ";
				  break;
		}
	}
	cout << "\n So " << n << " viet bang chu la: " << t3 << t2 << "" << t1 << " " << t;
	_getch();
	return 0;
}
