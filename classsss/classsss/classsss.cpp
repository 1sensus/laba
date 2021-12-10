#include <iostream>
#include"Header.h"

int main()
{
	int count_id_p = 0;
	int count_id_n = 0;
	setlocale(LC_ALL, "ru");
	Pipe pipe;
	Nps nps;
	vector<Pipe> pipe_vec = {};
	vector<Nps> nps_vec = {};
	int x;
	do
	{
		Main_menu();
		x = get_digit();
		switch (x)
		{
		case 1:
		{
			pipe.Create(count_id_p, pipe_vec);
			break;
		}
		case 2:
			nps.Create(count_id_n, nps_vec);
			break;
		case 3:
		{
			Print_all(pipe_vec,nps_vec);
			break;
		}
		case 4:
		{
			Change_pipes(pipe_vec);
			break;
		}
		case 5:
		{
			Change_npss(nps_vec);
			break;
		}
		case 6:
		{
			File_outer(pipe_vec, nps_vec);
			break;
		}
		case 7:
		{
			File_reader(pipe_vec, nps_vec);
			break;
		}
		case 8:
		{
			Delete_p(pipe_vec);
			system("pause");
			break;
		}
		case 9:
		{
			Delete_n(nps_vec);
			system("pause");
			break;
		}
		}
	} while (x != 0);
}

