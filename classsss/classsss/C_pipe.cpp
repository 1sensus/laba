#include"Header.h"
#include"H_pipe.h"

	Pipe::Pipe()
	{
		 id = 0;
		 lenth = 0;
		 diam = 0;
		 ready = 0;
	}	
	int Pipe::max_id = -1;
	void Pipe::Create(unordered_map<int, Pipe>& pipe_umap)
	{
		Pipe pipe;
		pipe.id = ++max_id;
		cout << "����� ->  " << endl;
		pipe.lenth = get_digit();
		cout << "������� ->  " << endl;
		pipe.diam = get_digit();
		cout << "������ ->  " << endl;
		pipe.ready = get_digit();
		pipe_umap.emplace(pipe.id,pipe);
	}
	void Pipe::Print()
	{
		cout<<"Id:"<<id << "\t�����: " << lenth << "\t�������: " << diam << "\t������: " << ready << endl;
	}
	void Pipe::Change_p()
	{
		 int x;
		 do {
			 system("cls");
			 cout << "��������:" << endl;
			 Print();
			 cout << "1.�����" << endl << "2.�������" << endl << "3.������" << endl << "0.�����" << endl;
			 x = get_digit();
			 switch (x)
			 {
			 case 1:
			 {
				 cout << "�����->" << endl;
				 lenth = get_digit();
				 break;
			 }
			 case 2:
			 {
				 cout << "�������->" << endl;
				 diam = get_digit();
				 break;
			 }
			 case 3:
			 {
				 cout << "������" << endl;
				 ready = get_digit();
				 break;
			 }
			 }
		 } while (x != 0);
	}

	bool Pipe::Get_ready() const
	{
		return ready;
	}

	double Pipe::Get_diam() const
	{
		return diam;
	}

	double Pipe::Get_lenth() const
	{
		return lenth;
	}

	int Pipe::Get_id() const
	{
		return id;
	}
