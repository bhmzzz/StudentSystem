#include<iostream>
#include "StudentList.h"
using namespace std;


char yournum;//�û����������Ϊȫ�ֱ���
void System_Meu();//��ʼ����
void UserInterface();//�û�����

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
				cout << "���ѧ����Ϣ��" << endl;
				ss->AddStu();
				break;
			case '2':
				cout << "��ѯ���ܣ�(��ͨ������ѧ�Ż���������ѯ�����������޸�,ɾ��)" << endl;
				ss->Check();
				break;
			case '3':
				cout << "���е�ѧ����Ϣ��" << endl;
				ss->Display();
				break;
			case '4':
				cout << "�ɶ�ѧ��һ��ɾ��" << endl;
				ss->Delete();
				break;
			case '5':
				cout << "ͳ�Ƶ�ѧ����Ϣ����ͨ��������в�ͬ��ͳ�Ʊ���ʾ������";
				ss->Count();
				break;
			default:
				cout << "������1-5" << endl;
				break;
			}
			if (yournum == '1')
			{
			FLAG:
				cout << "�Ƿ���Ҫ������ӣ���1���� q�뿪��";
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
					cout << "������󣬣�1��������� q�뿪��";
					goto FLAG;
				}
			}
			if (yournum == '2')
			{
			FLAG1:
				cout << "�Ƿ���Ҫ������ѯ����2���� q�뿪��";
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
					cout << "������󣬣�1��������� q�뿪��";
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
						cout << "ѧ������ϵͳ";
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
	cout << "�����������ϵͳ......";
	if (cin >> ch)
	{
		system("cls");
	}
}

void UserInterface()
{
	cout << "��ӭ���뱾ϵͳ����ϵͳ�ṩѧ����Ϣ�������" << endl;
	cout << "�밴����ָʾ���в��ݣ�" << endl;
	cout << "1�����ѧ����Ϣ��" << "\t\t2����ѯѧ����Ϣ���������޸���Ϣ��ɾ����" << endl;
	cout << "3����ʾ��ǰϵͳ����ѧ����" << "\t4��ɾ��ѧ����Ϣ��" << endl;
	cout << "5��ͳ�ơ�" << endl;
	cout << "����������ѡ��";
	cin >> yournum;
	system("cls");
}