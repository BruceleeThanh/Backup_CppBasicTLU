#include<iostream>
#include<fstream>
using namespace std;
int const Max=100;
class DoThi
{
private:
	int N;
	int a[Max][Max];
public:
	DoThi() :N(0){}
	DoThi(char *filename,char type)
	{
		ifstream fin(filename);
		fin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = 0;
		if (type == 'M')
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
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
				a[x - 1][y - 1] = 1;
				a[y - 1][x - 1] = 1;
			}
			fin.close();
		}
		if (type == 'C')
		{
			int e; fin >> e;
			for (int i = 0; i < e; i++)
			{
				int x, y;
				fin >> x >> y;
				a[x - 1][y - 1] = 1;
			}
			fin.close();
		}
	}

	void PrintMaTranKe()
	{
		cout << N << endl;
		for(int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}

	bool KiemTraVoHuong()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[i][j] != a[j][i])
					return false;
			}
		}
		return true;
	}

	int GetSoCanh()
	{
		int tong = 0;
		if (KiemTraVoHuong())
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					tong += a[i][j];
				}
			}
			return tong / 2;
		}
		else
		{
			for(int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					tong += a[i][j];
			}
			return tong;
		}
	}

	void PrintDanhSachCanh()
	{
		cout << N << " " << GetSoCanh() << endl;
		if (KiemTraVoHuong())
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = i+1; j < N; j++)
				{
					if (a[i][j] == 1)
						cout << i + 1 << " " << j + 1 << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < N;i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (a[i][j] == 1)
						cout << i + 1 << " " << j + 1 << endl;
				}
			}
		}
	}

	void DuyetDoThiTheoChieuSau(int s)
	{
		bool dx[100];
		for (int i = 0; i < N; i++)
		{
			dx[i] = false;
		}
		DFS(s, dx);
	}

	void DFS(int s,bool dx[])
	{
		dx[s - 1] = true;
		cout << s << " ";
		for (int i = 1; i <= N; i++)
		{
			if (a[s - 1][i - 1] == 1 && dx[i - 1] == false)
				DFS(i, dx);
		}
	}

	void DFS_KhongIn(int s, bool dx[])
	{
		dx[s - 1] = true;
		for (int i = 1; i <= N; i++)
		{
			if (a[s - 1][i - 1] == 1 && dx[i - 1] == false)
				DFS_KhongIn(i, dx);
		}
	}

	void DFS1(int s, int dx[], int dem)
	{
		dx[s - 1] = dem;
		for (int i = 1; i <= N; i++)
		{
			if (a[s - 1][i - 1] == 1 && dx[i - 1] == 0)
				DFS1(s, dx, dem);
		}
	}

	bool LaDoThiLienThong()
	{
		bool dx[100];
		for (int i = 0; i < N; i++)
			dx[i] = false;
		DFS_KhongIn(1, dx);
		for(int i = 0; i < N; i++)
		{
			if (dx[i] == false)
				return false;
		}
		return true;
	}

	int SoThanhPhanLienThong()
	{
		int dem = 0;
		bool dx[100];
		bool tt=true;
		for (int i = 0; i < N; i++)
			dx[i] = false;
		do
		{
			int i;
			for (i = 1; i <= N; i++)
			{
				if(dx[i] == false)
				break;
			}
			if (i <= N)
			{
				dem++;
				DFS_KhongIn(i, dx);
			}
			else
				tt = false;
		} while (tt);
		return dem;
	}

	void InThanhPhanLienThong()
	{
		int dem;
		int dx[100];
		bool tt;
		for (int i = 0; i < N; i++)
			dx[i] = 0;
		do
		{
			int i;
			for (int i = 1; i <= N; i++)
			{
				if (dx[i] == 0)
					break;
			}
			if (i <= N)
			{
				dem++;
				DFS1(i, dx, dem);
			}
			else
				tt = false;
		} while (tt);

		for (int i = 0; i < SoThanhPhanLienThong(); i++)
		{
			for (int j = 0; j < N; j++)
				if (dx[j - 1] == i)
					cout << j << " ";
		}
	}

	int getN()
	{
		return N;
	}

	void dfs(int s, int truoc[], bool dx[])
	{
		dx[s - 1] = true;
		for (int i = 1; i <= N; i++)
		{
			if (a[s - 1][i - 1] == 1 && dx[i - 1] == false)
			{
				truoc[i - 1] = s;
				dfs(i, truoc, dx);
			}
		}
	}

	void bfs(int s, int truoc[], bool dx[],int queue[])
	{
		int u;
		int dau, cuoi;
		dau = cuoi = 0;
		queue[cuoi] = s;
		dx[s - 1] = true;
		truoc[s - 1] = -1;
		while (dau <= cuoi)
		{
			u = queue[dau];
			dau++;
			for (int i = 1; i <= N; i++)
			{
				if (a[u-1][i - 1] == 1 && dx[i - 1] == false)
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
		int tim=y;
		while (tim != x && tim != -1)
		{
			cout << tim << "<-";
			tim = truoc[tim - 1];
		}
		cout << x;
	}

};
