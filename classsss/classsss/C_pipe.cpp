#include"Header.h"

	Pipe::Pipe()
	{
		 id = 0;
		 lenth = 0;
		 diam = 0;
		 ready = 0;
	}

	int Pipe::True_id(int& count_id, vector<Pipe>&pipe_vec)
	{
		for (auto &p : pipe_vec) {
			if (p.id+1 > count_id) {count_id = p.id+1; };
		}
		return count_id;
	}
	
	void Pipe::Create(int& count_id,vector<Pipe>&pipe_vec)
	{
		Pipe pipe;
		pipe.id = True_id(count_id, pipe_vec);
		cout << "����� ->  " << endl;
		pipe.lenth = get_digit();
		cout << "������� ->  " << endl;
		pipe.diam = get_digit();
		cout << "������ ->  " << endl;
		pipe.ready = get_digit();
		pipe_vec.push_back(pipe);

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