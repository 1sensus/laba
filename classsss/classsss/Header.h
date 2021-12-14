#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include"H_Nps.h"
#include"H_pipe.h"
#include<unordered_map>
//свойхедер для класса
// 
//////////////////////////////////////////////////////////////////////////////
void File_outer(unordered_map<int, Pipe>& pipe_umap,unordered_map<int, Nps>& nps_umap);
void File_reader(unordered_map<int, Pipe>& pipe_umap, unordered_map<int, Nps>& nps_umap);
double get_digit();
void Change_pipes(vector<Pipe>& pipe_vec);
void Change_npss(vector<Nps>& nps_vec);
void Print_all(unordered_map<int,Pipe>& pipe_umap, unordered_map<int,Nps>& nps_umap);
void Main_menu();
void Delete_p(vector<Pipe>& pipe_vec);
void Delete_n(vector<Nps>& nps_vec);
void All_Filter(vector<Pipe>& pipe_vec, vector<Nps>& nps_vec);