#ifndef GRAPH
#define GRAPH
#include "Lib.h"

class Graphics
{
private:

	int _n;
	int _matrix[100][100];
	int _way[100]; //Start from position 1
	bool _tick[100]; //Start from position 1

	struct Paint
	{
		int vertices;
		int color = 0;
		int degree = 0;
	};

	struct Edges{
		int vertices_1;
		int vertices_2;
		int degree;
	};

public:

	Graphics(){
		_n = 0;
	}
	
	Graphics(const char* fileName, char type){
		ifstream fin(fileName);
		if (!fin.is_open()){
			cout << "Can't open file." << endl;
		}
		else{
			fin >> _n;
			if (type == 'M' || type == 'm'){ //Read Matrix files.
				for (int i = 0; i < _n; i++){
					for (int j = 0; j < _n; j++){
						fin >> _matrix[i][j];
					}
				}
			}
			if (type == 'L' || type == 'l'){ //Read List files.
				for (int i = 0; i < _n; i++){
					for (int j = 0; j < _n; j++){
						_matrix[i][j] = 0;
					}
				}
				int x, y;
				while (fin >> x >> y){
					_matrix[x - 1][y - 1] = 1;
					_matrix[y - 1][x - 1] = 1;
				}
			}
			if (type == 'W' || type == 'w'){ //Read List and Weight files.
				for (int i = 0; i < _n; i++){
					for (int j = 0; j < _n; j++){
						_matrix[i][j] = 0;
					}
				}
				int x, y, z;
				while (fin >> x >> y >> z){
					_matrix[x - 1][y - 1] = z;
					_matrix[y - 1][x - 1] = z;
				}
			}
		}
		fin.close();
	}

	void displayMatrix(){ //Display Matrix
		cout << "Ma tran co " << _n << " dinh." << endl;
		for (int i = 0; i < _n; i++){
			for (int j = 0; j < _n; j++){
				cout << _matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void displayFindTheWay(int start, int end, int way[], string display, string tempstr){
		int end1, end2;
		while (end != start && end != -1){
			if (end >= 10){
				end1 = end / 10;
				end2 = end % 10;
				display = tempstr + (char)(end1 + 48) + (char)(end2 + 48) + display;
			}
			else{
				display = tempstr + (char)(end + 48) + display;
			}
			end = way[end];
		}
		display = (char)(end + 48) + display;
		cout << display << endl;
	}

	void createDefaultItems(){
		for (int i = 0; i <= _n; i++){
			_tick[i] = false;
			_way[i] = -1;
		}
	}

	void DFS(int start, int end){
		string display;
		string tempstr;
		tempstr = " -> ";
		createDefaultItems();
		mainDFS(start, _way, _tick);
		displayFindTheWay(start, end, _way, display, tempstr);
	}

	void mainDFS(int s, int _way[], bool _tick[]){
		_tick[s] = true;
		for (int i = 0; i < _n; i++){
			if (_matrix[s - 1][i] != 0 && _tick[i + 1] == false){
				_way[i + 1] = s;
				mainDFS(i + 1,_way,_tick);
			}
		}
	}

	void BFS(int start, int end){
		int temp = end;
		string display;
		string tempstr;
		tempstr = " -> ";
		createDefaultItems();
		mainBFS(start, _way, _tick);
		displayFindTheWay(start, end, _way, display, tempstr);
	}

	void mainBFS(int s, int _way[], bool _tick[]){
		_tick[s] = true;
		Queue <int> q;
		q.Push(s);
		while (!q.isEmpty()){
			s = q.Pop();
			for (int i = 0; i < _n; i++){
				if (_matrix[s - 1][i] != 0 && _tick[i + 1] == false){
					_tick[i + 1] = true;
					_way[i + 1] = s;
					q.Push(i + 1);
				}
			}
		}
	}

	void Painting(){
		int colors = 0;
		bool check;
		Paint color[100];
		for (int i = 0; i < _n; i++){
			int count = 0;
			for (int j = 0; j < _n; j++){
				if (_matrix[i][j] != 0){
					count++;
				}
			}
			color[i].vertices = i;
			color[i].degree = count;
		}

		for (int i = 0; i < _n; i++){
			for (int j = i + 1; j < _n; j++){
				if (color[i].degree < color[j].degree){
					Paint temp = color[i];
					color[i] = color[j];
					color[j] = temp;
				}
			}
		}
		for (int i = 0; i < _n; i++){
			if (color[i].color == 0){
				colors++;
				color[i].color = colors;
			}
			for (int j = i + 1; j < _n; j++){
				check = true;
				if (color[j].color == 0 && _matrix[color[i].vertices][color[j].vertices] == 0){
					for (int k = j - 1; k > i; k--){
						if (color[k].color == colors && _matrix[color[j].vertices][color[k].vertices] != 0){
							check = false;
						}
					}
					if (check){
						color[j].color = colors;
					}
				}
			}

		}
		cout << "To mau do thi: " << endl;
		for (int i = 0; i < _n; i++){
			cout << "Dinh " << color[i].vertices + 1 << " co bac " << color[i].degree << " co mau " << color[i].color << endl;
		}
	}

	int Dijkstra(int start, int end){
		int weight[100], min = 1000000, a = start, count_ver = 0;
		string display;
		string tempstr;
		tempstr = " -> ";
		createDefaultItems();
		for (int i = 0; i <= _n; i++){
			weight[i] = 1000000;
		}
		weight[a] = 0;
		_tick[a] = true;
		count_ver++;
		while (count_ver != _n){
			for (int i = 1; i <= _n; i++){
				if (_matrix[a - 1][i - 1] != 0 && _tick[i] == false){
					if (weight[i] > (_matrix[a - 1][i - 1] + weight[a])){
						weight[i] = _matrix[a - 1][i - 1] + weight[a];
						_way[i] = a;
					}
				}
			}
			int temp;
			bool flag = true;
			for (int i = 1; i <= _n; i++){
				if (_tick[i] == false && flag == true){
					flag = false;
					min = weight[i];
					temp = i;
				}
				else{
					if (_tick[i] == false && weight[i] < min){
						min = weight[i];
						temp = i;
					}
				}
			}
			_tick[temp] = true;
			a = temp;
			count_ver++;
		}
		displayFindTheWay(start, end, _way, display, tempstr);
		return weight[end];
	}

	bool checkConnectedGraph(){
		createDefaultItems();
		mainDFS(_n, _way, _tick);
		for (int i = 1; i <= _n; i++){
			if (_way[i] == false){
				return false;
			}
		}
		return true;
	}

	void Prim(){
		Edges edge[100];
		int min = 1000000, count_ver = 2;
		createDefaultItems();
		for (int i = 0; i < _n; i++){
			for (int j = 0; j < _n; j++){
				if (min > _matrix[i][j] && _matrix[i][j] != 0){
					min = _matrix[i][j];
					edge[0].vertices_1 = i;
					edge[0].vertices_2 = j;
					edge[0].degree = min;
				}
			}
		}
		_tick[edge[0].vertices_1 + 1] = true;
		_tick[edge[0].vertices_2 + 1] = true;
		while (count_ver < _n){
			min = 1000000;
			for (int i = 0; i < _n; i++){
				if (_tick[i + 1] == true){
					for (int j = 0; j < _n; j++){
						if (_matrix[i][j] != 0 && _tick[j + 1] == false){
							if (min > _matrix[i][j]){
								min = _matrix[i][j];
								edge[count_ver - 1].vertices_1 = i;
								edge[count_ver - 1].vertices_2 = j;
								edge[count_ver - 1].degree = min;
							}
						}
					}
				}
			}
			_tick[edge[count_ver - 1].vertices_2 + 1] = true;
			count_ver++;
		}
		cout << "Prim: " << endl;
		for (int i = 0; i < _n - 1; i++){
			cout << "Canh (" << edge[i].vertices_1 + 1<< ", " << edge[i].vertices_2 + 1<< ") co bac: " << edge[i].degree << endl;
		}
	}

	void Kruskal(){
		Edges edge[100];
		int min = 1000000, count_ver = 0, count_edge = 0;
		createDefaultItems();
		while (count_ver < _n){
			min = 1000000;
			for (int i = 0; i < _n; i++){
				for (int j = i + 1; j < _n; j++){
					if (_matrix[i][j] != 0 && (_tick[i + 1] == false || _tick[j + 1] == false)){
						if (min > _matrix[i][j]){
							min = _matrix[i][j];
							edge[count_edge].vertices_1 = i;
							edge[count_edge].vertices_2 = j;
							edge[count_edge].degree = min;
						}
					}
				}
			}
			if (_tick[edge[count_edge].vertices_1 + 1] == false){
				_tick[edge[count_edge].vertices_1 + 1] = true;
				count_ver++;
			}
			if (_tick[edge[count_edge].vertices_2 + 1] == false){
				_tick[edge[count_edge].vertices_2 + 1] = true;
				count_ver++;
			}
			count_edge++;
		}
		cout << "Kruskal: " << endl;
		for (int i = 0; i < count_edge; i++){
			cout << "Canh (" << edge[i].vertices_1 + 1 << ", " << edge[i].vertices_2 + 1 << ") co bac: " << edge[i].degree << endl;
		}
	}

	~Graphics(){

	}


};


#endif