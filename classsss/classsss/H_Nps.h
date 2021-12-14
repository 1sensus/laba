#pragma once
#include <iostream>
#include<unordered_map>
using namespace std;
class Nps
{
public:
	static int max_id;
	
	string name;
	Nps();
	static void Create(unordered_map<int, Nps>& nps_umap);
	void Print();
	void Change_n();
	int Get_id()const;
	double Get_work_stations()const;
	double Get_all_stations()const;
	double Get_loading()const;
private:
	int id;
	double work_stations;
	double all_stations;
	double loading;
};
ostream& operator<<(ostream& out, const Nps& n);
istream& operator>>(istream& in, Nps& n);