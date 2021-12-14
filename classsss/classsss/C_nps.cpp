#include"Header.h"
#include"H_Nps.h"
Nps::Nps()
{
	id = 0;
	work_stations = 0;
	all_stations = 0;
	loading = 0;
	name = "";
}
int Nps::max_id = -1;
void Nps::Create(unordered_map<int, Nps>& nps_umap)
{
	Nps nps;
	nps.id =++max_id ;
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
	nps_umap.emplace(nps.id,nps);
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