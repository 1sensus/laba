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
void Change_pipes(unordered_map<int, Pipe>& pipe_umap);
void Change_npss(unordered_map<int, Nps>& nps_umap);
void Print_all(unordered_map<int,Pipe>& pipe_umap, unordered_map<int,Nps>& nps_umap);
void Main_menu();
void Delete_p(unordered_map<int, Pipe>& pipe_umap);
void Delete_n(unordered_map<int, Nps>& nps_umap);
void All_Filter(unordered_map<int, Pipe>& pipe_umap ,unordered_map<int, Nps>& nps_umap);