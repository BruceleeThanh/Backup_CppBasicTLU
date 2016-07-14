#pragma once
#include <iostream>
#include <vector>
using namespace std;

class HocSinh
{
private:
	vector<double> DauVao;
	double DauRa;
public:
	HocSinh(){

	}
	HocSinh(vector<double> DauVao, double DauRa){
		for (int i = 0; i < DauVao.size(); i++){
			this->DauVao.push_back(DauVao[i]);
		}
		this->DauRa = DauRa;
	}

	vector<double> getDauVao(){
		return DauVao;
	}

	double getDauRa(){
		return DauRa;
	}
};