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
	nps_umap.emplace(nps.id,nps);
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