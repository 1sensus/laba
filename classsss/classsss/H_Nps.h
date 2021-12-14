#pragma once
#include <iostream>
#include<unordered_map>
using namespace std;
class Nps
{
public:
	static int max_id;
	int id;
	double work_stations;
	double all_stations;
	double loading;
	string name;
	Nps();
	static void Create(unordered_map<int, Nps>& nps_umap);
	void Print();
	void Change_n();
private:
};
ostream& operator<<(ostream& out, const Nps& n);
istream& operator>>(istream& in, Nps& n);