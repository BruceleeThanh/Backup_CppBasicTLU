#pragma once;
#include<iostream>
#include<fstream>
using namespace std;
const int max = 100;
class DoThi
{
private:
	int n;
	int a[max][max];
public:
	DoThi() :n(0){}
	DoThi(char *filename, char type)
	{
		ifstream fin(filename);
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}
		if (type == 'M')
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					fin >> a[i][j];
			}
			fin.close();
		}
		if (type == 'V')
		{
			int e;
			fin >> e;
			for (int i = 0; i < e; i++)
			{
				int x, y;
				fin >> x >> y;
				a[x - 1][y - 1] == 1;
				a[y - 1][x - 1] == 1;
			}
			fin.close();
		}
		if (type == 'C')
		{
			int e;
			fin >> e;
			for (int i = 0; i < e; i++)
			{
				int x, y;
				fin >> x >> y;
				a[x - 1][y - 1] == 1;
			}
			fin.close();
		}
	}

	void dfs(int s, int truoc[], bool dx[])
	{
		dx[s - 1] = true;
		for (int i = 1; i <= n; i++)
		{
			if (a[s - 1][i - 1] == 1 && dx[i - 1] == false)
			{
				truoc[i - 1] = s;
				dfs(i, truoc, dx);
			}
		}
	}

	void bfs(int s, int truoc[], bool dx[], int queue[])
	{
		int u;
		int dau,cuoi;
		dau = cuoi = 0;
		queue[cuoi] = s;
		truoc[s - 1] = -1;
		dx[s - 1] = true;
		while (dau <= cuoi)
		{
			u = queue[dau];
			dau++;
			for (int i = 1; i <= n; i++)
			{
				if (a[u - 1][i - 1] == 1 && dx[i - 1] == false)
				{
					cuoi++;
					queue[cuoi] = i;
					truoc[i - 1] = u;
					dx[i - 1] = true;
				}
			}

		}

	}

	void timduongdi(int x, int y, int truoc[])
	{
		int tim = y;
		while (tim != x && tim != -1)
		{
			cout << tim << "<-";
			tim = truoc[tim - 1];
		}
		cout << x;
	}

	int getn()
	{
		return n;
	}

};