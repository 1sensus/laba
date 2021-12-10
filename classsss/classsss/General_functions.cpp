#include"Header.h"

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
void File_outer(const vector <Pipe>& pipe_vec, const vector<Nps>& nps_vec)
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
		size_t a = size(pipe_vec);
		size_t b = size(nps_vec);
		file_out << a << endl;
		file_out << b << endl;
		for (auto& pipe : pipe_vec)
		{
			file_out << pipe;
		}
		for (auto& nps : nps_vec)
		{
			file_out << nps;
		}
		cout << "writen" << endl;

	}
	file_out.close();
}
void File_reader(vector <Pipe>& pipe_vec, vector<Nps>& nps_vec)
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
		pipe_vec.clear();
		nps_vec.clear();
		int kol_vo_pipes, kol_vo_npss;
		read_file >> kol_vo_pipes;
		read_file >> kol_vo_npss;
		while (!read_file.eof())
		{
			for (int i = 0; i < kol_vo_pipes; ++i)
			{
				Pipe pipe = {};
				read_file >> pipe;
				pipe_vec.push_back(pipe);

			}
			for (int i = 0; i < kol_vo_npss; ++i)
			{
				Nps nps = {};
				read_file >> nps;
				nps_vec.push_back(nps);
			}break;
		}cout << "file read" << endl; read_file.close();
	}
}
void Change_pipes(vector<Pipe>& pipe_vec)
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
		for (auto& p : pipe_vec)
		{
			if (p.id == l_bord) { p.Change_p(); }
		}
	}
}
void Change_npss(vector<Nps>& nps_vec)
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
		for (auto& n : nps_vec)
		{
			if (n.id == l_bord) { n.Change_n(); }
		}
	}
}
void Delete_p(vector<Pipe>& pipe_vec) 
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

void Print_all(vector<Pipe>& pipe_vec, vector<Nps>& nps_vec)
{
	cout << "Pipes->" << endl;
	for (Pipe& p : pipe_vec)
	{
		p.Print();
	}
	cout << "Npss->" << endl;
	for (Nps& n : nps_vec)
	{
		n.Print();
	}
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
