#include"Header.h"

	Pipe::Pipe()
	{
		 id = 0;
		 lenth = 0;
		 diam = 0;
		 ready = 0;
		 count_id = 0;
	}

	int Pipe:: True_id(int& count_id, vector<Pipe> pipe_vec)
	{
		for (auto &p : pipe_vec)
		{
			if (p.id + 1 > count_id) { count_id = p.id + 1; }
		}return count_id;
	}
	void Pipe::Create(Pipe& pipe, vector<Pipe>& pipe_vec, int &count_id)
	{
		pipe.id = True_id(count_id, pipe_vec);
		cout << "Длина ->  " << endl;
		pipe.lenth = get_digit();
		cout << "Диаметр ->  " << endl;
		pipe.diam = get_digit();
		cout << "Статус ->  " << endl;
		pipe.ready = get_digit();
		pipe_vec.push_back(pipe);
	}
	void Pipe::Print()
	{
		cout << "Id: " << id << "\tДлина: " << lenth << "\tДиаметр: " << diam << "\tСтатус: " << ready << endl;
	}

	bool Pipe:: Search_p(int& s_id, vector<Pipe>& pipe_vec)
	{
		for (auto &p : pipe_vec) { if (p.id == s_id) { return true; } else { return false; } }
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
	 void Pipe::Change_pipe()
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
		
	
