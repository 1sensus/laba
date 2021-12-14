#include"Header.h"
#include"H_Nps.h"
#include"H_pipe.h"
#include<iostream>

void Main_menu()
{
	system("cls");
	cout << "��� �� ����� ������?" << endl;
	cout << "1. ������� �����" << endl;
	cout << "2. ������� �������" << endl;
	cout << "3. �������� ��� �������" << endl;
	cout << "4. �������� �����" << endl;
	cout << "5. �������� �������" << endl;
	cout << "6. ��������� � ����" << endl;
	cout << "7. ��������� �� �����" << endl;
	cout << "8. ������� ����� " << endl;
	cout << "9. ������� ������� " << endl;
	cout << "10. �����������" << endl;
	cout << "0. �����" << endl;
}
void Filter_menu() 
{
	system("cls");
	cout << "��� �� ����� ������?" << endl;
	cout << "1.���������� ����" << endl;
	cout << "2.���������� �������" << endl;
	cout << "0.�����" << endl;
}
void Filter_m_p()
{
	system("cls");
	cout << "��� �� ����� ������?" << endl;
	cout << "1.���������� �� Id(>=)" << endl;
	cout << "2.���������� �� Id(<=)" << endl;
	cout << "3.���������� �� �����(>=)" << endl;
	cout << "4.���������� �� �����(<=)" << endl;
	cout << "5.���������� �� ��������(>=)" << endl;
	cout << "6.���������� �� ��������(<=)" << endl;
	cout << "7.���������� �� �������" << endl;
	cout << "0.�����" << endl;	
}
void Filter_m_n()
{
	system("cls");
	cout << "��� �� ����� ������?" << endl;
	cout << "1.���������� �� Id(>=)" << endl;
	cout << "2.���������� �� Id(<=)" << endl;
	cout << "3.���������� �� ���������� �������(>=)" << endl;
	cout << "4.���������� �� ���������� �������(<=)" << endl;
	cout << "5.���������� �� �������������(>=)" << endl;
	cout << "6.���������� �� �������������(<=)" << endl;
	cout << "0.�����" << endl;
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
	cout << "������� �������� ����� ��� ����������" << endl;
	string file;
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	file_out.open(file, fstream::out);
	if (!file_out.is_open())
	{
		cout << "������!!!" << endl;
	}
	else
	{
		size_t a = pipe_umap.size();
		size_t b = nps_umap.size();
		file_out << a << endl;
		file_out << b << endl;
		file_out << Pipe::max_id<<endl;
		file_out << Nps::max_id<<endl;
		for (auto&[id,pipe] : pipe_umap)
		{
			file_out << pipe;
		}
		for (auto&[id,nps] : nps_umap)
		{
			file_out << nps;
		}

	}
	file_out.close();
}
void File_reader(unordered_map<int, Pipe>& pipe_umap, unordered_map<int, Nps>& nps_umap)
{

	ifstream read_file;
	cout << "������� �������� ����� ��� ������" << endl;
	string file;
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	read_file.open(file, ifstream::in);
	if (!read_file.is_open()) { cout << "������!!!"; }
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
				pipe_umap.emplace(pipe.Get_id(),pipe);
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
void Change_pipes(unordered_map<int, Pipe>& pipe_umap)
{
	cout << "������� ����� ������ ��������� ���������" << endl;
	int l_bord = get_digit();
	cout << "������� ������ ������ ��������� ���������" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "������ �����" << endl;
		cout << "������� ����� ������ ��������� ���������" << endl;
		int l_bord = get_digit();
		cout << "������� ������ ������ ��������� ���������" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{		
		for (auto&[id,pipe] : pipe_umap)
		{
			if (id == l_bord) { pipe.Change_p(); }
		}
	}
}
void Change_npss(unordered_map<int, Nps>& nps_umap)
{
	cout << "������� ����� ������ ��������� ���������" << endl;
	int l_bord = get_digit();
	cout << "������� ������ ������ ��������� ���������" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "������ �����" << endl;
		cout << "������� ����� ������ ��������� ���������" << endl;
		int l_bord = get_digit();
		cout << "������� ������ ������ ��������� ���������" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{
		for (auto& [id,nps] :nps_umap)
		{
			if (id == l_bord) { nps.Change_n(); }
		}
	}
}
void Delete_p(unordered_map<int, Pipe>& pipe_umap)
{
	cout << "������� ����� ������ ��������� ��������" << endl;
	int l_bord = get_digit();
	cout << "������� ������ ������ ��������� ��������" << endl;
	int r_bord = get_digit();
	while (l_bord > r_bord)
	{
		cout << "������ �����" << endl;
		cout << "������� ����� ������ ��������� ��������" << endl;
		int l_bord = get_digit();
		cout << "������� ������ ������ ��������� ��������" << endl;
		int r_bord = get_digit();
	}
	for (int i = l_bord; l_bord <= r_bord; l_bord++)
	{
		int j = -1;
		for (auto& [id,pipe] : pipe_umap)
		{
			++j;
			if (id == l_bord) {
				pipe_umap.erase(l_bord);				
				break;
			}
		}
	}
}
void Delete_n(unordered_map<int, Nps>& nps_umap)
	{
		cout << "������� ����� ������ ��������� ��������" << endl;
		int l_bord = get_digit();
		cout << "������� ������ ������ ��������� ��������" << endl;
		int r_bord = get_digit();
		while (l_bord > r_bord)
		{
			cout << "������ �����" << endl;
			cout << "������� ����� ������ ��������� ��������" << endl;
			int l_bord = get_digit();
			cout << "������� ������ ������ ��������� ��������" << endl;
			int r_bord = get_digit();
		}
		for (int i = l_bord; l_bord <= r_bord; l_bord++)
		{
			//int j = -1;
			for (auto& [id,nps] : nps_umap)
			{
				//++j;
				if (id == l_bord) {
					nps_umap.erase(l_bord);
					break;
				}
			}
		}
	}

//Pipe
template<typename T>
using Filter = bool(*)(const Pipe& p, T param);
bool Check_id_up(const Pipe& p, int param) { return p.Get_id() >= param; }
bool Check_id_down(const Pipe& p, int param) { return p.Get_id() <= param; }
bool Check_lenth_up(const Pipe& p, double param) { return p.Get_lenth() >= param; }
bool Check_lenth_down(const Pipe& p, double param) { return p.Get_lenth() <= param; }
bool Check_diam_up(const Pipe& p, double param) { return p.Get_diam() >= param; }
bool Check_diam_down(const Pipe& p, double param) { return p.Get_diam() <= param; }
bool Check_ready(const Pipe& p, bool param) { return p.Get_ready() == param; }
template<typename T>
vector <int> FindFilter(const unordered_map<int, Pipe>& pipe_umap, Filter<T> f, T param)
{
	vector <int> result;
	int i = 0;
	for (auto& [id,pipe] : pipe_umap)
	{
		if (f(pipe, param))
		{
			result.push_back(i);
		}++i;
	}
	return result;
}
void Filter_p(unordered_map<int, Pipe>& pipe_umap)
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
					cout<<"������� Id(>=)" << endl;
					cin >> id_;
					for (int i : FindFilter(pipe_umap, Check_id_up, id_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 2:
				{
					int id_;
					cout << "������� Id(<=)" << endl;
					cin >> id_;
					for (int i : FindFilter(pipe_umap, Check_id_down, id_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 3:
				{
					double lenth_;
					cout << "������� �����(>=)" << endl;
					cin >> lenth_;
					for (int i : FindFilter(pipe_umap, Check_lenth_up, lenth_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 4:
				{
					double lenth_;
					cout << "������� �����(<=)" << endl;
					cin >> lenth_;
					for (int i : FindFilter(pipe_umap, Check_lenth_down, lenth_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 5:
				{
					double diam_;
					cout << "������� �������(>=)" << endl;
					cin >> diam_;
					for (int i : FindFilter(pipe_umap, Check_diam_up, diam_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 6:
				{
					double diam_;
					cout << "������� �������(<=)" << endl;
					cin >> diam_;
					for (int i : FindFilter(pipe_umap, Check_diam_down, diam_))
					{
						pipe_umap[i].Print();
					}
					system("pause");
					break;
				}
			case 7:
				{
					bool ready_;
					cout << "������� ������(� ������� = 0)" << endl;
					cin >> ready_;
					for (int i : FindFilter(pipe_umap, Check_ready, ready_))
					{
						pipe_umap[i].Print();
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
vector<int>FindFilte(const unordered_map<int, Nps>& nps_umap, Filter_<B>f, B param)
{
	vector <int> result;
	int i = 0;
	for (auto& [id,nps] : nps_umap)
	{
		if (f(nps, param))
		{
			result.push_back(i);
		}++i;
	}
	return result;
}
void Filter_n(unordered_map<int, Nps>& nps_umap)
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
				cout << "������� Id(>=)" << endl;
				cin >> id_;
				for (int i : FindFilte(nps_umap,Check_id_up_n, id_))
				{
					nps_umap[i].Print();
				}
				system("pause");
				break;
			}
		}
	} while (var != 0);
}
void All_Filter(unordered_map<int, Pipe>& pipe_umap,unordered_map<int, Nps>& nps_umap)
{
	int var;
	do 
	{
		Filter_menu();
		var = get_digit();
		switch (var)
		{
			case 1:
			{Filter_p(pipe_umap); }
			break;
			case 2:
			{Filter_n(nps_umap); }
		}
	} while (var != 0);
}

void Print_all(unordered_map<int,Pipe>& pipe_umap, unordered_map<int,Nps>& nps_umap)
{
	cout << "Pipes->" << endl;
	//
	for (auto& it: pipe_umap)
	{
		it.second.Print();
	}
	cout << "Npss->" << endl;
	//
	for (auto& it :nps_umap) 
	{
		it.second.Print();
	}
	system("pause");
}
ostream& operator<<(ostream& out, const Nps& n)
{
	out << n.Get_id() << endl << n.name << endl << n.work_stations << endl << n.all_stations << endl << n.loading << endl;
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
