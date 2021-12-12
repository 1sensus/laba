#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Pipe {
public:
	int id;
	double lenth;
	double diam;
	bool ready;
	Pipe();
	int True_id(int& count_id, vector<Pipe>&pipe_vec);
	void Create(int& count_id,vector<Pipe>&pipe_vec);
	void Print();
	void Change_p();
private: 
}; 
istream& operator >>(istream& in, Pipe& p);
ostream& operator<<(ostream& out, const Pipe& p);

class Nps
{
public:
	int count_id;
	int id;
	double work_stations;
	double all_stations;
	double loading;
	string name;
	Nps();
	int True_id(int& count_id, vector<Nps> nps_vec);
	void Create(int& count_id, vector<Nps>& nps_vec);
	void Print();
	void Change_n();
private:
};
ostream& operator<<(ostream& out, const Nps& n);
istream& operator>>(istream& in, Nps& n);

//////////////////////////////////////////////////////////////////////////////
void File_outer(const vector <Pipe>& pipe_vec, const vector<Nps>& nps_vec);
void File_reader(vector <Pipe>& pipe_vec, vector<Nps>& nps_vec);
double get_digit();
void Change_pipes(vector<Pipe>& pipe_vec);
void Change_npss(vector<Nps>& nps_vec);
void Print_all(vector<Pipe>& pipe_vec,vector<Nps>& nps_vec);
void Main_menu();
void Delete_p(vector<Pipe>& pipe_vec);
void Delete_n(vector<Nps>& nps_vec);
void All_Filter(vector<Pipe>& pipe_vec, vector<Nps>& nps_vec);