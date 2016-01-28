#include"DoThi.h"

int main()
{
	DoThi a("DoThi.txt",'M');
	/*a.PrintMaTranKe();
	if (a.KiemTraVoHuong())
		cout << "Vo huong.\n";
	else
		cout << "Co huong.\n";
	a.PrintDanhSachCanh();
	a.DuyetDoThiTheoChieuSau(2);
	if (a.LaDoThiLienThong())
		cout << "lien thong.\n";
	else
		cout << "Khong lien thong.\n";*/
	//cout<<a.SoThanhPhanLienThong();

	//a.InThanhPhanLienThong();
	int truoc[100];
	bool dx[100];
	int queue[100];
	for (int i = 0; i < a.getN(); i++)
	{
		truoc[i] = -1;
		dx[i] = false;
	}
	//a.dfs(1, truoc, dx);
	//a.timduongdi(1, 5, truoc);
	a.bfs(3, truoc, dx, queue);
	a.timduongdi(3, 1, truoc);
	return 0;
}