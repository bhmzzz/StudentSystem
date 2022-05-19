#include<iostream>
#include "StudentList.h"
using namespace std;


char yournum;//用户输入符，作为全局变量
void System_Meu();//开始界面
void UserInterface();//用户界面

int main()
{
	System_Meu();
	StudentSystem* ss = new StudentSystem;
	while (1)
	{
		UserInterface();
		while (yournum != 'q')
		{
			switch (yournum)
			{
			case '1':
				cout << "添加学生信息：" << endl;
				ss->AddStu();
				break;
			case '2':
				cout << "查询功能：(可通过输入学号或者姓名查询，可做数据修改,删除)" << endl;
				ss->Check();
				break;
			case '3':
				cout << "所有的学生信息：" << endl;
				ss->Display();
				break;
			case '4':
				cout << "可对学生一键删除" << endl;
				ss->Delete();
				break;
			case '5':
				cout << "统计的学生信息：（通过输入进行不同的统计表显示人数）";
				ss->Count();
				break;
			default:
				cout << "请输入1-5" << endl;
				break;
			}
			if (yournum == '1')
			{
			FLAG:
				cout << "是否需要继续添加？（1、是 q离开）";
				cin >> yournum;
				if (yournum == '1')
				{
					system("cls");
					continue;
				}
				else if (yournum == 'q')
				{
					system("cls");
					break;
				}
				else
				{
					cout << "输入错误，（1、继续添加 q离开）";
					goto FLAG;
				}
			}
			if (yournum == '2')
			{
			FLAG1:
				cout << "是否需要继续查询？（2、是 q离开）";
				cin >> yournum;
				if (yournum == '2')
				{
					system("cls");
					continue;
				}
				else if (yournum == 'q')
				{
					system("cls");
					break;

				}
				else
				{
					cout << "输入错误，（1、继续添加 q离开）";
					goto FLAG1;
				}
			}
			if (yournum == '3')
			{
				system("cls");
				break;
			}
			if (yournum == '4')
			{
				system("cls");
				break;
			}
			if (yournum == '5')
			{
				system("cls");
				break;
			}
		}
	}
	delete ss;
	return 0;
}

void System_Meu()
{
	int i; int j;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 80; j++)
		{
			if (j < 30)
			{
				cout << " ";
				continue;
			}
			if (i == 0 || i == 5)
			{
				if (j >= 30 && j < 80)
					cout << "-";
			}
			else 
			{
				if (j == 30 || j == 79)
				{
					cout << ".";
				}
				if (j < 79)
				{
					cout << " ";
					if (j == 48 && i == 3)
					{
						cout << "学生管理系统";
						j += 12;
					}
					continue;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << " ";
	}
	char ch;
	cout << "按任意键进入系统......";
	if (cin >> ch)
	{
		system("cls");
	}
}

void UserInterface()
{
	cout << "欢迎进入本系统，本系统提供学生信息管理服务。" << endl;
	cout << "请按下列指示进行操纵：" << endl;
	cout << "1、添加学生信息。" << "\t\t2、查询学生信息。（可做修改信息，删除）" << endl;
	cout << "3、显示当前系统所有学生。" << "\t4、删除学生信息。" << endl;
	cout << "5、统计。" << endl;
	cout << "请做出您的选择：";
	cin >> yournum;
	system("cls");
}