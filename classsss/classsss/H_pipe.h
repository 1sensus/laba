#pragma once
#include <iostream>
#include<unordered_map>

class Pipe {
public:
	static int max_id;	
	Pipe(); 
	static void Create(unordered_map<int, Pipe>& pipe_umap);
	void Print();
	void Change_p();
	int Get_id()const;
	double Get_diam()const;
	double Get_lenth()const;
	bool Get_ready()const;
	friend istream& operator >>(istream& in, Pipe& p);
	friend ostream& operator<<(ostream& out, const Pipe& p);
private:
	int id;
	double lenth;
	double diam;
	bool ready;
};

