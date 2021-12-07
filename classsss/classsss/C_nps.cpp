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
	cout << "Введите название станции" << endl;
	cin.ignore();
	getline(cin, nps.name);
	cout << "Введите количество работающих станций" << endl;
	nps.work_stations = get_digit();
	cout << "Введите общее количество станций" << endl;
	nps.all_stations = get_digit();
	while (nps.work_stations > nps.all_stations)
	{
		cout << "Ошибка ввода: общее количество станций должно быть меньше чем количество работающих станций" << endl;
		nps.work_stations = get_digit();
		nps.all_stations = get_digit();
	}
	nps.loading = nps.work_stations / nps.all_stations * 100;
	nps_vec.push_back(nps);
}
void Nps::Print()
{
	cout << "Id: " << id << "\tНазвание: " << name << "\tЗагруженность: " << loading << " %" << "( " << work_stations << " / " << all_stations << " )" << endl;
}
void Nps::Change_n(int& l_bord, Nps& nps, vector<Nps>& nps_vec)
{
	int x; do
	{

		cout << "Изменить:" << endl << "1.Название" << endl << "2.Работающие станции" << endl << "3.Общее количество станция" << endl << "0.Выход" << endl;
		x = get_digit();
		switch (x)
		{

		case 1:
		{
			cout << "Название->" << endl;
			cin.ignore();
			getline(cin, nps.name);
			break;
		}
		case 2:
		{
			cout << "Введите количество работающих станций" << endl;
			nps.work_stations = get_digit();
			break;
		}
		case 3:
		{
			cout << "Введите общее количество станций" << endl;
			nps.all_stations = get_digit();
			break;
		}
		while (nps.work_stations > nps.all_stations)
		{
			cout << "Ошибка ввода: общее количество станций должно быть меньше чем количество работающих станций" << endl;
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
