#include<iostream>
#include"DoThi.h"
using namespace std;
int main()
{
	DoThi a("DoThi.txt",'M');
	bool dx[100];
	int truoc[100];
	int queue[100];
	for (int i = 0; i < a.getn(); i++)
	{
		dx[i] = false;
		truoc[i] = -1;
	}
	//a.dfs(1, truoc,dx);
	//a.timduongdi(1, 5, truoc);
	a.bfs(1, truoc, dx, queue);
	a.timduongdi(1, 3, truoc);


	return 0;
}