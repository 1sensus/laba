#include"Header.h"
#include"H_Nps.h"
#include"H_pipe.h"
#include<iostream>
typedef std::unordered_map<int, Pipe> UMap_p;
typedef std::unordered_map<int, Nps> UMap_n;

void Main_menu()
{
	system("cls");
	cout << "Что мы хотим делать?" << endl;
	cout << "1. Создать турбу" << endl;
	cout << "2. Создать станцию" << endl;
	cout << "3. Показать все объекты" << endl;
	cout << "4. Изменить трубу" << endl;
	cout << "5. Изменить станцию" << endl;
	cout << "6. Сохранить в файл" << endl;
	cout << "7. Загрузить из файла" << endl;
	cout << "8. Удалить трубу " << endl;
	cout << "9. Удалить станцию " << endl;
	cout << "10. Фильтровать" << endl;
	cout << "0. Выход" << endl;
}
void Filter_menu() 
{
	system("cls");
	cout << "Что мы хотим делать?" << endl;
	cout << "1.Сортировка труб" << endl;
	cout << "2.Сортировка станций" << endl;
	cout << "0.Назад" << endl;
}
void Filter_m_p()
{
	system("cls");
	cout << "Что мы хотим делать?" << endl;
	cout << "1.Сортировка по Id(>=)" << endl;
	cout << "2.Сортировка по Id(<=)" << endl;
	cout << "3.Сортировка по длине(>=)" << endl;
	cout << "4.Сортировка по длине(<=)" << endl;
	cout << "5.Сортировка по диаметру(>=)" << endl;
	cout << "6.Сортировка по диаметру(<=)" << endl;
	cout << "7.Сортировка по статусу" << endl;
	cout << "0.Назад" << endl;	
}
void Filter_m_n()
{
	system("cls");
	cout << "Что мы хотим делать?" << endl;
	cout << "1.Сортировка по Id(>=)" << endl;
	cout << "2.Сортировка по Id(<=)" << endl;
	cout << "3.Сортировка по количеству станций(>=)" << endl;
	cout << "4.Сортировка по количеству станций(<=)" << endl;
	cout << "5.Сортировка по загруженности(>=)" << endl;
	cout << "6.Сортировка по загруженности(<=)" << endl;
	cout << "0.Назад" << endl;
}
double get_digit()
{
	double number;
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input " << endl;
		}
		else
			break;
		cout << "Try again" << endl;
	}
	return number;
}


void File_outer(unordered_map<int, Pipe>& pipe_umap,unordered_map<int, Nps>& nps_umap)
{
	fstream file_out;
	cout << "Введите название файла для сохранения" << endl;
	string file;
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	file_out.open(file, fstream::out);
	if (!file_out.is_open())
	{
		cout << "Ошибка!!!" << endl;
	}
	else
	{
		size_t a = pipe_umap.size();
		size_t b = nps_umap.size();
		file_out << a << endl;
		file_out << b << endl;
		file_out << Pipe::max_id<<endl;
		file_out << Nps::max_id<<endl;
		for (UMap_p::iterator it = pipe_umap.begin(); it != pipe_umap.end(); ++it)
		{
			file_out << (it->second);
		}
		for (UMap_n::iterator it = nps_umap.begin(); it != nps_umap.end(); ++it)
		{
			file_out << (it->second);
		}

	}
	file_out.close();
}
void File_reader(unordered_map<int, Pipe>& pipe_umap, unordered_map<int, Nps>& nps_umap)
{

	ifstream read_file;
	cout << "Введите название файла для чтения" << endl;
	string file;
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	read_file.open(file, ifstream::in);
	if (!read_file.is_open()) { cout << "Ошибка!!!"; }
	else
	{
		pipe_umap.clear();
		nps_umap.clear();
		int kol_vo_pipes, kol_vo_npss;
		read_file >> kol_vo_pipes;
		read_file >> kol_vo_npss;
		read_file >> Pipe::max_id;
		read_file >> Nps::max_id;
		while (!read_file.eof())
		{
			for (int i = 0; i < kol_vo_pipes; ++i)
			{
				Pipe pipe;
				read_file >> pipe;
				pipe_umap.emplace(pipe.id,pipe);
			}
			for (int i = 0; i < kol_vo_npss; ++i)
			{
				Nps nps;
				read_file >> nps;
				nps_umap.emplace(nps.id,nps);
			}break;
		}cout << "file read" << endl; read_file.close();
	}
}
void Change_pipes(vector<Pipe>& pipe_vec)
{
	cout << "Введите левую гранцу диапозона изменения" << endl;
	int l_bord = get_digit();
	cout << "Введите правую гранцу диапозона изменения" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "Ошибка ввода" << endl;
		cout << "Введите левую гранцу диапозона изменения" << endl;
		int l_bord = get_digit();
		cout << "Введите правую гранцу диапозона изменения" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{
		for (auto& p : pipe_vec)
		{
			if (p.id == l_bord) { p.Change_p(); }
		}
	}
}
void Change_npss(vector<Nps>& nps_vec)
{
	cout << "Введите левую гранцу диапозона изменения" << endl;
	int l_bord = get_digit();
	cout << "Введите правую гранцу диапозона изменения" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "Ошибка ввода" << endl;
		cout << "Введите левую гранцу диапозона изменения" << endl;
		int l_bord = get_digit();
		cout << "Введите правую гранцу диапозона изменения" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{
		for (auto& n : nps_vec)
		{
			if (n.id == l_bord) { n.Change_n(); }
		}
	}
}
void Delete_p(vector<Pipe>& pipe_vec) 
{
	cout << "Введите левую гранцу диапозона удаления" << endl;
	int l_bord = get_digit();
	cout << "Введите правую гранцу диапозона удаления" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "Ошибка ввода" << endl;
		cout << "Введите левую гранцу диапозона удаления" << endl;
		int l_bord = get_digit();
		cout << "Введите правую гранцу диапозона удаления" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{
		int j = -1;
		for (auto& p : pipe_vec)
		{
			++j;
			if (p.id == l_bord) {
				pipe_vec.erase(pipe_vec.begin() + j);				
				break;
			}
		}
	}
	cout << "Deleted!" << endl << "Razmer spiska: " << pipe_vec.size() << endl;
}
void Delete_n(vector<Nps>&nps_vec)
	{
		cout << "Введите левую гранцу диапозона удаления" << endl;
		int l_bord = get_digit();
		cout << "Введите правую гранцу диапозона удаления" << endl;
		int r_bord = get_digit();
		while (l_bord > r_bord)
		{
			cout << "Ошибка ввода" << endl;
			cout << "Введите левую гранцу диапозона удаления" << endl;
			int l_bord = get_digit();
			cout << "Введите правую гранцу диапозона удаления" << endl;
			int r_bord = get_digit();
		}
		for (int i = l_bord; l_bord <= r_bord; l_bord++)
		{
			int j = -1;
			for (auto& n : nps_vec)
			{
				++j;
				if (n.id == l_bord) {
					nps_vec.erase(nps_vec.begin() + j);
					break;
				}
			}
		}
		cout << "Deleted!" << endl << "Razmer spiska: " << nps_vec.size() << endl;
	}

//Pipe
template<typename T>
using Filter = bool(*)(const Pipe& p, T param);
bool Check_id_up(const Pipe& p, int param) { return p.id >= param; }
bool Check_id_down(const Pipe& p, int param) { return p.id <= param; }
bool Check_lenth_up(const Pipe& p, double param) { return p.lenth >= param; }
bool Check_lenth_down(const Pipe& p, double param) { return p.lenth <= param; }
bool Check_diam_up(const Pipe& p, double param) { return p.diam >= param; }
bool Check_diam_down(const Pipe& p, double param) { return p.diam <= param; }
bool Check_ready(const Pipe& p, bool param) { return p.ready == param; }
template<typename T>
vector <int> FindFilter(const vector<Pipe>& pipe_vec, Filter<T> f, T param)
{
	vector <int> result;
	int i = 0;
	for (auto& p : pipe_vec)
	{
		if (f(p, param))
		{
			result.push_back(i);
		}++i;
	}
	return result;
}
void Filter_p(vector<Pipe>& pipe_vec)
{
	int var;
	do {
		Filter_m_p();
		var = get_digit();
		switch (var)
		{
			case 1:
				{
					int id_;
					cout<<"Введите Id(>=)" << endl;
					cin >> id_;
					for (int i : FindFilter(pipe_vec, Check_id_up, id_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 2:
				{
					int id_;
					cout << "Введите Id(<=)" << endl;
					cin >> id_;
					for (int i : FindFilter(pipe_vec, Check_id_down, id_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 3:
				{
					double lenth_;
					cout << "Введите длину(>=)" << endl;
					cin >> lenth_;
					for (int i : FindFilter(pipe_vec, Check_lenth_up, lenth_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 4:
				{
					double lenth_;
					cout << "Введите длину(<=)" << endl;
					cin >> lenth_;
					for (int i : FindFilter(pipe_vec, Check_lenth_down, lenth_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 5:
				{
					double diam_;
					cout << "Введите диаметр(>=)" << endl;
					cin >> diam_;
					for (int i : FindFilter(pipe_vec, Check_diam_up, diam_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 6:
				{
					double diam_;
					cout << "Введите диаметр(<=)" << endl;
					cin >> diam_;
					for (int i : FindFilter(pipe_vec, Check_diam_down, diam_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}
			case 7:
				{
					bool ready_;
					cout << "Введите Статус(В ремонте = 0)" << endl;
					cin >> ready_;
					for (int i : FindFilter(pipe_vec, Check_ready, ready_))
					{
						pipe_vec[i].Print();
					}
					system("pause");
					break;
				}			
		}

	} while (var != 0);
}

//Nps
template<typename B>
using Filter_= bool(*)(const Nps&, B param);
bool Check_id_up_n(const Nps& n, int param) { return n.id >= param; }
bool Check_id_down_n(const Nps& n, int param) { return n.id <= param; }
bool Check_allstation_count_up(const Nps& n, double param) { return n.all_stations >= param; }
bool Check_allstation_count_down(const Nps& n, double param) { return n.all_stations <= param; }
bool Check_load_up(const Nps& n, double param) { return n.loading >= param; }
bool Check_load_down(const Nps& n, double param) { return n.loading <= param; }
template<typename B>
vector<int>FindFilte(const vector<Nps>& nps_vec, Filter_<B>f, B param)
{
	vector <int> result;
	int i = 0;
	for (auto& n : nps_vec)
	{
		if (f(n, param))
		{
			result.push_back(i);
		}++i;
	}
	return result;
}
void Filter_n(vector<Nps>& nps_vec) 
{
	int var;
	do 
	{
		Filter_m_n();
		var = get_digit();
		switch (var)
		{
			
		case 1:
			{
				int id_;
				cout << "Введите Id(>=)" << endl;
				cin >> id_;
				for (int i : FindFilte(nps_vec,Check_id_up_n, id_))
				{
					nps_vec[i].Print();
				}
				system("pause");
				break;
			}
		}
	} while (var != 0);
}
void All_Filter(vector<Pipe>& pipe_vec, vector<Nps>& nps_vec)
{
	int var;
	do 
	{
		Filter_menu();
		var = get_digit();
		switch (var)
		{
			case 1:
			{Filter_p(pipe_vec); }
			break;
			case 2:
			{Filter_n(nps_vec); }
		}
	} while (var != 0);
}
//typedef std::unordered_map<int, Pipe> UMap_p;
//typedef std::unordered_map<int, Nps> UMap_n;
void Print_all(unordered_map<int,Pipe>& pipe_umap, unordered_map<int,Nps>& nps_umap)
{
	cout << "Pipes->" << endl;
	//
	for (UMap_p::iterator it = pipe_umap.begin(); it != pipe_umap.end();++it)
	{
		it->second.Print();
	}
	cout << "Npss->" << endl;
	//
	for (UMap_n::iterator it = nps_umap.begin(); it != nps_umap.end(); ++it) { it->second.Print(); }
	system("pause");
}
ostream& operator<<(ostream& out, const Nps& n)
{
	out << n.id << endl << n.name << endl << n.work_stations << endl << n.all_stations << endl << n.loading << endl;
	return out;
}
istream& operator>>(istream& in, Nps& n)
{
	in >> n.id;
	in >> n.name;
	in >> n.work_stations;
	in >> n.all_stations;
	in >> n.loading;
	return in;
}
ostream&  operator <<(ostream& out, const Pipe& p)
{
	out << p.id << endl << p.lenth << endl << p.diam << endl << p.ready << endl;
	return out;
}
istream& operator >>(istream& in, Pipe& p)
{
	in >> p.id;
	in >> p.lenth;
	in >> p.diam;
	in >> p.ready;
	return in;
}
