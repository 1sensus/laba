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
void Nps::Change_n()
{
	int x; do
	{
		system("cls");
		Print();
		cout << "��������:" << endl << "1.��������" << endl << "2.���������� �������" << endl << "3.����� ���������� �������" << endl << "0.�����" << endl;
		x = get_digit();
		
		switch (x)
		{

		case 1:
		{
			cout << "��������->" << endl;
			cin.ignore();
			getline(cin, name);
			break;
		}
		case 2:
		{
			cout << "������� ���������� ���������� �������" << endl;
			work_stations = get_digit();
			while (work_stations > all_stations)
			{
				cout << "������ �����: ����� ���������� ������� ������ ���� ������ ��� ���������� ���������� �������" << endl;
				cout << "������� ���������� ���������� �������" << endl;
				work_stations = get_digit();
			}
			loading = work_stations / all_stations * 100;
			break;
		}
		case 3:
		{
			cout << "������� ����� ���������� �������" << endl;
			all_stations = get_digit();

		
		while (work_stations > all_stations)
		{
			cout << "������ �����: ����� ���������� ������� ������ ���� ������ ��� ���������� ���������� �������" << endl;
			cout << "������� ����� ���������� �������" << endl;
			all_stations = get_digit();
		}
		loading = work_stations / all_stations * 100;
		break;
		}
		}
	} while (x != 0);
}