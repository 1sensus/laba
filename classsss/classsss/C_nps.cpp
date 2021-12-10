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
int Nps::True_id(int& count_id, vector<Nps> nps_vec)
{
	for (auto n : nps_vec)
	{
		if (n.id + 1 > count_id) { count_id = n.id + 1; }
	}return count_id;
}

void Nps::Create( int& count_id,vector<Nps>& nps_vec)
{
	Nps nps;
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
void Nps::Change_n()
{
	int x; do
	{
		system("cls");
		Print();
		cout << "Изменить:" << endl << "1.Название" << endl << "2.Работающие станции" << endl << "3.Общее количество станция" << endl << "0.Выход" << endl;
		x = get_digit();
		
		switch (x)
		{

		case 1:
		{
			cout << "Название->" << endl;
			cin.ignore();
			getline(cin, name);
			break;
		}
		case 2:
		{
			cout << "Введите количество работающих станций" << endl;
			work_stations = get_digit();
			while (work_stations > all_stations)
			{
				cout << "Ошибка ввода: общее количество станций должно быть меньше чем количество работающих станций" << endl;
				cout << "Введите количество работающих станций" << endl;
				work_stations = get_digit();
			}
			loading = work_stations / all_stations * 100;
			break;
		}
		case 3:
		{
			cout << "Введите общее количество станций" << endl;
			all_stations = get_digit();

		
		while (work_stations > all_stations)
		{
			cout << "Ошибка ввода: общее количество станций должно быть меньше чем количество работающих станций" << endl;
			cout << "Введите общее количество станций" << endl;
			all_stations = get_digit();
		}
		loading = work_stations / all_stations * 100;
		break;
		}
		}
	} while (x != 0);
}