#ifndef CARO_H
#define CARO_H
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
using namespace std;

class Caro{
private:
	char caro[100][100];
public:
	//Tạo bàn cờ trống
	Caro(int n){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				caro[i][j] = (char)22;
			}
			cout << endl;
		}
	}

	//In bàn cờ ra màn hình
	void Display(int n, int x, int y){
		system("cls");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == x&&j == y){
					cout << "_  ";
				}
				else{
					cout << caro[i][j] << "  ";
				}
			}
			cout << endl << endl;
		}
	}

	//Di chuyển
	void Move(int &x, int &y, char &point, int n){
		switch (_getch()){
			//Lên
		case 72:
			if (x > 0){
				x--;
				Display(n,x,y);
			}
			else{
				x = n - 1;
				Display(n, x, y);
			}
			break;
			//Xuống
		case 80:
			if (x < n - 1){
				x++;
				Display(n,x,y);
			}
			else{
				x = 0;
				Display(n,x,y);
			}
			break;
			//Phải
		case 77:
			if (y < n - 1){
				y++;
				Display(n,x,y);
			}
			else{
				y = 0;
				Display(n,x,y);
			}
			break;
			//Trái
		case 75:
			if (y > 0){
				y--;
				Display(n,x,y);
			}
			else{
				y = n - 1;
				Display(n,x,y);
			}
			break;
			//Space
		case 32:
			if (caro[x][y] == 'x' && caro[x][y] == 'o'){
				break;
			}
			else{
				if (point == 'x'){
					point = caro[x][y] = 'o';
					Display(n, x, y);
					finallyTest(x, y, n, point);
				}
				else{
					point = caro[x][y] = 'x';
					Display(n, x, y);
					finallyTest(x, y, n, point);
				}
				break;
			}
		default:
			cout << "An phim Di chuyen de di chuyen, an phim Cach de danh." << endl;
		}
	}

	//Kiểm tra theo hàng Dọc
	bool verticalTest(int x, int y, int n, char point){
		int count_down = 0, count_up = 0, a = x + 1, block = 0;

		//Kiểm tra bên dưới
		while (count_down < 4){
			if (a < n){
				if (caro[a][y] == point){
					count_down++;
					a++;
				}
				else{
					//Kiểm tra gặp quân chặn bên dưới
					if (caro[a][y] - point == 9 || point - caro[a][y] == 9){
						count_down--;
						block++;
						break;
					}
					//Kiểm tra bên dưới (không có quân chặn)
					if (point - caro[a][y] == 98 || point - caro[a][y] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		//Kiểm tra bên trên
		a = x - 1;
		while (count_up < 4){ 
			if (a >= 0){
				if (caro[a][y] == point){
					count_up++;
					a--;
				}
				else{
					//Kiểm tra gặp quân chặn bên trên
					if (caro[a][y] - point == 9 || point - caro[a][y] == 9){
						count_up--;
						block++;
						break;
					}
					//Kiểm tra bên trên(không có quân chặn)
					if (point - caro[a][y] == 98 || point - caro[a][y] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		if (count_down + count_up > 2 && block == 0){
			return 1;
		}
		else{
			if (count_down + count_up > 3 && block == 1){
				return 1;
			}
			else{
				if (count_down + count_up > 4 && block == 2){
					return 1;
				}
				else{
					if (count_down + count_up == 4 && block == 2){
						return 0;
					}
					else{
						return 0;
					}
				}
			}

		}
	}

	//Kiểm tra theo hàng Ngang
	bool horizontalTest(int x, int y, int n, char point){
		int count_right = 0, count_left = 0, a = y + 1, block = 0;

		//Kiểm tra bên phải
		while (count_right < 4){
			if (a < n){
				if (caro[x][a] == point){
					count_right++;
					a++;
				}
				else{
					//Kiểm tra gặp quân chặn bên phải
					if (caro[x][a] - point == 9 || point - caro[x][a] == 9){
						count_right--;
						block++;
						break;
					}
					//Kiểm tra bên phải (không có quân chặn)
					if (point - caro[x][a] == 98 || point - caro[x][a] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		//Kiểm tra bên trái
		a = y - 1;
		while (count_left < 4){
			if (a >= 0){
				if (caro[x][a] == point){
					count_left++;
					a--;
				}
				else{
					//Kiểm tra gặp quân chặn bên trái
					if (caro[x][a] - point == 9 || point - caro[x][a] == 9){
						count_left--;
						block++;
						break;
					}
					//Kiểm tra bên trái(không có quân chặn)
					if (point - caro[x][a] == 98 || point - caro[x][a] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		if (count_right + count_left > 2 && block == 0){
			return 1;
		}
		else{
			if (count_right + count_left > 3 && block == 1){
				return 1;
			}
			else{
				if (count_right + count_left > 4 && block == 2){
					return 1;
				}
				else{
					if (count_right + count_left == 4 && block == 2){
						return 0;
					}
					else{
						return 0;
					}
				}
			}

		}
	}

	//Kiểm tra theo hàng Chéo Phải
	bool right_diagonalTest(int x, int y, int n, char point){
		int count_down = 0, count_up = 0, a = x + 1, b = y - 1, block = 0;

		//Kiểm tra bên dưới
		while (count_down < 4){
			if (a < n){
				if (caro[a][b] == point){
					count_down++;
					a++;
					b--;
				}
				else{
					//Kiểm tra gặp quân chặn bên dưới
					if (caro[a][b] - point == 9 || point - caro[a][b] == 9){
						count_down--;
						block++;
						break;
					}
					//Kiểm tra bên dưới (không có quân chặn)
					if (point - caro[a][b] == 98 || point - caro[a][b] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		//Kiểm tra bên trên
		a = x - 1;
		b = y + 1;
		while (count_up < 4){
			if (a >= 0){
				if (caro[a][b] == point){
					count_up++;
					a--;
					b++;
				}
				else{
					//Kiểm tra gặp quân chặn bên trên
					if (caro[a][b] - point == 9 || point - caro[a][b] == 9){
						count_up--;
						block++;
						break;
					}
					//Kiểm tra bên trên(không có quân chặn)
					if (point - caro[a][b] == 98 || point - caro[a][b] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		if (count_down + count_up > 2 && block == 0){
			return 1;
		}
		else{
			if (count_down + count_up > 3 && block == 1){
				return 1;
			}
			else{
				if (count_down + count_up > 4 && block == 2){
					return 1;
				}
				else{
					if (count_down + count_up == 4 && block == 2){
						return 0;
					}
					else{
						return 0;
					}
				}
			}

		}
	}

	//Kiểm tra theo hàng Chéo Trái
	bool left_diagonalTest(int x, int y, int n, char point){
		int count_down = 0, count_up = 0, a = x + 1, b = y + 1, block = 0;

		//Kiểm tra bên dưới
		while (count_down < 4){
			if (a >= 0 && a < n){
				if (caro[a][b] == point){
					count_down++;
					a++;
					b++;
				}
				else{
					//Kiểm tra gặp quân chặn bên dưới
					if (caro[a][b] - point == 9 || point - caro[a][b] == 9){
						count_down--;
						block++;
						break;
					}
					//Kiểm tra bên dưới (không có quân chặn)
					if (point - caro[a][b] == 98 || point - caro[a][b] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		//Kiểm tra bên trên
		a = x - 1;
		b = y - 1;
		while (count_up < 4){
			if (a >= 0 && a < n){
				if (caro[a][b] == point){
					count_up++;
					a--;
					b--;
				}
				else{
					//Kiểm tra gặp quân chặn bên trên
					if (caro[a][b] - point == 9 || point - caro[a][b] == 9){
						count_up--;
						block++;
						break;
					}
					//Kiểm tra bên trên(không có quân chặn)
					if (point - caro[a][b] == 98 || point - caro[a][b] == 89){
						break;
					}
				}
			}
			else{
				break;
			}
		}
		if (count_down + count_up > 2 && block == 0){
			return 1;
		}
		else{
			if (count_down + count_up > 3 && block == 1){
				return 1;
			}
			else{
				if (count_down + count_up > 4 && block == 2){
					return 1;
				}
				else{
					if (count_down + count_up == 4 && block == 2){
						return 0;
					}
					else{
						return 0;
					}
				}
			}

		}
	}

	//Kiểm tra Chung cuộc
	void finallyTest(int x, int y, int n, char point){
		if (verticalTest(x, y, n, point) || horizontalTest(x, y, n, point) || right_diagonalTest(x, y, n, point) || left_diagonalTest(x, y, n, point)){
			cout << endl << "Chuc mung " << point << " da Chien Thang." << endl << endl;
			system("pause");
		}
		else{
			if (point == 'x'){
				cout << endl << "Den luot O di." << endl;
			}
			else{
				cout << endl << "Den luot X di." << endl;
			}
		}
	}

	~Caro(){}

};

#endif