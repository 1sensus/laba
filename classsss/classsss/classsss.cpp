#include <iostream>
#include"Header.h"
#include<unordered_map>
//unordered_map,разбивка по файлам, статические id;

int main()
{
	unordered_map<int, Pipe> pipe_umap = {};
	unordered_map<int, Nps> nps_umap = {};
	setlocale(LC_ALL, "ru");
	int x;
	do
	{
		Main_menu();
		x = get_digit();
		switch (x)
		{
			case 1:
			{
				Pipe::Create(pipe_umap);
				break;
			}
			case 2:
				Nps::Create(nps_umap);
				break;
			case 3:
			{
				Print_all(pipe_umap,nps_umap);
				break;
			}
			case 4:
			{
				//Change_pipes();
				break;
			}
			case 5:
			{
				//Change_npss();
				break;
			}
			case 6:
			{
				File_outer(pipe_umap, nps_umap);
				break;
			}
			case 7:
			{
				File_reader(pipe_umap,nps_umap);
				break;
			}
			case 8:
			{
				//Delete_p();
				system("pause");
				break;
			}
			case 9:
			{
				//Delete_n();
				system("pause");
				break;
			}
			case 10:
			{
				//All_Filter();
				system("pause");
				break;
			}
		}
	} while (x!= 0);
}

