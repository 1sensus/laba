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
		cout << "Длина ->  " << endl;
		pipe.lenth = get_digit();
		cout << "Диаметр ->  " << endl;
		pipe.diam = get_digit();
		cout << "Статус ->  " << endl;
		pipe.ready = get_digit();
		pipe_umap.emplace(pipe.id,pipe);
	}
	void Pipe::Print()
	{
		cout<<"Id:"<<id << "\tДлина: " << lenth << "\tДиаметр: " << diam << "\tСтатус: " << ready << endl;
	}
	void Pipe::Change_p()
	{
		 int x;
		 do {
			 system("cls");
			 cout << "Изменить:" << endl;
			 Print();
			 cout << "1.Длину" << endl << "2.Диаметр" << endl << "3.Стутус" << endl << "0.Выход" << endl;
			 x = get_digit();
			 switch (x)
			 {
			 case 1:
			 {
				 cout << "Длина->" << endl;
				 lenth = get_digit();
				 break;
			 }
			 case 2:
			 {
				 cout << "Диаметр->" << endl;
				 diam = get_digit();
				 break;
			 }
			 case 3:
			 {
				 cout << "Статус" << endl;
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
