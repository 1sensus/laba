#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
class Pipe {
public:
	int count_id;
	int id;
	double lenth;
	double diam;
	bool ready;
	Pipe();
	int True_id(int &count_id, vector<Pipe> pipe_vec);
	void Create(Pipe& pipe, vector<Pipe>& pipe_vec, int& count_id);
	void Print();
	bool Search_p(int& s_id, vector<Pipe>& pipe_vec);
	void Change_pipe();
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
	int True_id(int count_id, vector<Nps> nps_vec);
	void Create(Nps& nps, vector<Nps>& nps_vec);
	void Print();
	void Change_n(int& l_bord, Nps& nps, vector<Nps>& nps_vec);
	bool Search_n(int s_id, vector<Nps>& nps_vec);
private:
};
ostream& operator<<(ostream& out, const Nps& n);
istream& operator>>(istream& in, Nps& n);
void File_outer(const vector <Pipe>& pipe_vec, const vector<Nps>& nps_vec);
void File_reader(vector <Pipe>& pipe_vec, vector<Nps>& nps_vec);
double get_digit();