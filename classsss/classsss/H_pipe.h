#pragma once
#include <iostream>
#include<unordered_map>
using namespace std;
class Pipe {
public:
	static int max_id;
	int id;
	double lenth;
	double diam;
	bool ready;
	Pipe(); 
	static void Create(unordered_map<int, Pipe>& pipe_umap);
	void Print();
	void Change_p();
private:
};
istream& operator >>(istream& in, Pipe& p);
ostream& operator<<(ostream& out, const Pipe& p);