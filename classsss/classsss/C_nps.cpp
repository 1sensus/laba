#include"Header.h"

Nps::Nps()
{
	count_id = 0;
	id = 0;
	work_stations = 0;
	all_stations = 0;
	loading = 0;
	name = "";
}
int Nps::True_id(int count_id, vector<Nps> nps_vec)
{
	for (auto n : nps_vec)
	{
		if (n.id + 1 > count_id) { count_id = n.id + 1; }
	}return count_id;
}

void Nps::Create(Nps& nps, vector<Nps>& nps_vec)
{
	nps.id = True_id(count_id, nps_vec);
	cout << "������� �������� �������" << endl;
	cin.ignore();
	getline(cin, nps.name);
	cout << "������� ���������� ���������� �������" << endl;
	nps.work_stations = get_digit();
	cout << "������� ����� ���������� �������" << endl;
	nps.all_stations = get_digit();
	while (nps.work_stations > nps.all_stations)
	{
		cout << "������ �����: ����� ���������� ������� ������ ���� ������ ��� ���������� ���������� �������" << endl;
		nps.work_stations = get_digit();
		nps.all_stations = get_digit();
	}
	nps.loading = nps.work_stations / nps.all_stations * 100;
	nps_vec.push_back(nps);
}
void Nps::Print()
{
	cout << "Id: " << id << "\t��������: " << name << "\t�������������: " << loading << " %" << "( " << work_stations << " / " << all_stations << " )" << endl;
}
void Nps::Change_n(int& l_bord, Nps& nps, vector<Nps>& nps_vec)
{
	int x; do
	{

		cout << "��������:" << endl << "1.��������" << endl << "2.���������� �������" << endl << "3.����� ���������� �������" << endl << "0.�����" << endl;
		x = get_digit();
		switch (x)
		{

		case 1:
		{
			cout << "��������->" << endl;
			cin.ignore();
			getline(cin, nps.name);
			break;
		}
		case 2:
		{
			cout << "������� ���������� ���������� �������" << endl;
			nps.work_stations = get_digit();
			break;
		}
		case 3:
		{
			cout << "������� ����� ���������� �������" << endl;
			nps.all_stations = get_digit();
			break;
		}
		while (nps.work_stations > nps.all_stations)
		{
			cout << "������ �����: ����� ���������� ������� ������ ���� ������ ��� ���������� ���������� �������" << endl;
			nps.work_stations = get_digit();
			nps.all_stations = get_digit();
		}
		nps.loading = nps.work_stations / nps.all_stations * 100;
		}
	} while (x != 0);
	nps_vec.erase(nps_vec.begin() + l_bord);
	nps_vec.insert(nps_vec.begin() + l_bord, nps);
}
bool Nps::Search_n(int s_id, vector<Nps>& nps_vec)
{
	for (auto n : nps_vec) { if (n.id == s_id) { return true; } }
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
