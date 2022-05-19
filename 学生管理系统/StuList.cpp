#include "StudentList.h"


void AbstractStudent::Input()//�������ݳ�ʼ���ӿ�
{
	char* temp = new char[MAX_SIZE20];
	cout << "������ѧ��ѧ�ţ�";
	cin >> temp;
	strcpy_s(StdNum, temp);
	cout << "\n������ѧ��������";
	cin >> temp;
	strcpy_s(name, temp);
	cout << "\n������ѧ���Ա�";
	cin >> temp;
	strcpy_s(sex, temp);
	cout << "\n������ѧ�����䣺";
	cin >> age;
	cout << "\n������ѧ���༶��";
	cin >> temp;
	strcpy_s(Class, temp);
	delete[] temp;
}

void AbstractStudent::Output()
{
	cout << "ѧ��ѧ��\t" << "ѧ������\t" << "ѧ���Ա�\t" << "ѧ������\t" << "ѧ���༶\t" << endl;
	cout << StdNum << "\t" << name << "\t" << sex << "\t" << age << "\t" << Class << "\t\n";
}

void XStudent::Input()
{
	AbstractStudent::Input();
	cout << "\n������Ӣ��ɼ���";
	cin >> EnglishG;
	cout << "\n��������ѧ�ɼ���";
	cin >> MathG;
	cout << "\n���������ĳɼ���";
	cin >> ChineseG;
}

void XStudent::Output()
{
	AbstractStudent::Output();
	cout << "Ӣ��ɼ�\t" << "��ѧ�ɼ�\t" << "���ĳɼ�\t\n";
	cout << EnglishG << "\t" << MathG << "\t" << ChineseG << "\t\n";
}

void ZStudent::Input()
{
	XStudent::Input();
	system("cls");
	char* temp = new char[MAX_SIZE50];
	cout << "\n���������ɼ���";
	cin >> DiLiG;
	cout << "\n��������ʷ�ɼ���";
	cin >> HistoryG;
	cout << "\n�������ͥ��ַ��";
	cin >> temp;
	strcpy_s(Adress, temp);
	delete[] temp;
}

void ZStudent::Output()
{
	XStudent::Output();
	cout << "����ɼ�\t" << "��ʷ�ɼ�\t" << "��ͥ��ַ\t\n";
	cout << DiLiG << "\t" << HistoryG << "\t" << Adress << "\t\n";
}

void DStudent::Input()
{
	AbstractStudent::Input();
	char* temp = new char[MAX_SIZE50];
	cout << "\n������רҵ��";
	cin >> temp;
	strcpy_s(ZhuanYe, temp);
	cout << "\n�������ͥ��ַ��";
	cin >> temp;
	strcpy_s(Adress, temp);
	cout << "\n������绰���룺";
	cin >> temp;
	strcpy_s(Tel, temp);
	delete[] temp;
}

void DStudent::Output()
{
	AbstractStudent::Output();
	cout << "רҵ\t" << "��ͥ��ַ\t\t" << "�绰����\t\n";
	cout << ZhuanYe << "\t" << Adress << "\t\t" << Tel << "\t\n";
}

StudentSystem::StudentSystem() {}

void StudentSystem::AddStu()
{
	char num;
	AbstractStudent* stu;
	cout << "������������ӵ�ѧ����1��Сѧ��  2����ѧ��  3����ѧ��(������1��2��3)  ";
	cin >> num;
	while (num)
	{
			switch (num)
			{
			case '1':
				stu = new XStudent;
				stu->Input();
				break;
			case '2':
				stu = new ZStudent;
				stu->Input();
				break;
			case '3':
				stu = new DStudent;
				stu->Input();
				break;
			default:
				cout << "��������������룡" << endl;
				cout << "������������ӵ�ѧ����1��Сѧ��  2����ѧ��  3����ѧ��(������1��2��3)  ";
				cin >> num;
				system("cls");
				continue;
			}
			StuList.push_back(stu);
			cout << "�洢�ɹ���" << endl;
			break;
	}
}

void StudentSystem::Check()
{
	char num;
	char* temp = new char[MAX_SIZE20];
	cout << "ѡ������Ҫ��ѯ�ķ�ʽ����1��ѧ�� 2��������";
	cin >> num;
	while (num)
	{
		switch (num)
		{
		case '1':
			cout << "��������Ҫ��ѯ��ѧ�ţ�";
			cin >> temp;
			if (StuList.size() == 0)
			{
				cout << "��Ϊ������������ݣ�" << endl;
				break;
			}
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->GetStdNum(),temp))
				{
					cout << "���ҵ���ѧ������Ϣ��\n";
					(*it)->Output();
					cout << "�Ƿ��޸Ļ�ɾ����ѧ����Ϣ����1�޸� 2ɾ�� ����������˳���";
					cin >> num;
					if (num == '1')
					{
						system("cls");
						cout << "�����Ǹ�ѧ����Ϣ��" << endl;
						(*it)->Output();
						cout << "ѡ����Ҫ�޸ĵ���Ŀ��\n";
						cout << "1 �޸�ѧ�� 2 �޸����� 3�޸İ༶ ������Ϣ�����޸ġ�";
						cin >> num;
						while (num != 'q')
						{
							switch (num)
							{
							case '1':
							{
								char* temp1 = new char[MAX_SIZE20];
								cout << "�������޸ĺ��ѧ��ѧ�ţ�";
								cin >> temp1;
								(*it)->set_StdNum(temp1);
								delete [] temp1;
								break;
							}
							case '2':
							{
								cout << "�������޸ĺ��ѧ�����䣺";
								short agetemp;
								cin >> agetemp;
								(*it)->set_age(agetemp);
								break;
							}
							case '3':
							{
								char* temp2 = new char[MAX_SIZE20];
								cout << "�������޸ĺ��ѧ���༶��";
								cin >> temp2;
								(*it)->set_class(temp);
								delete [] temp2;
								break;
							}
							default:
							{
								cout << "�������������1\2\3,q�뿪��";
								cin >> num;
								continue;
							}
							}
							cout << "�޸ĳɹ����Ƿ�����޸ģ�1 �޸�ѧ�� 2 �޸����� 3�޸İ༶ q����";
							cin >> num;
						}
					}
					else if (num == '2')
					{
						system("cls");
						(*it)->Output();
						cout << "��ɾ����ѧ����Ϣ����ȷ�� ��1ɾ�� q�˳���" << endl;
						cin >> num;
						if (num == '1')
						{
							StuList.erase(it);
							cout << "ɾ����ϣ�";
							return;
						}
						else if (num == 'q')
							return;
					}
					break;
				}
				if (it == StuList.end() - 1)
				{
					cout << "���޴��ˣ�";
					break;
				}
			}
			break;
		case '2':
			if (StuList.size() == 0)
			{
				cout << "��Ϊ������������ݣ�" << endl;
				break;
			}
			cout << "��������Ҫ��ѯ��������";
			cin >> temp;
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->GetName(),temp))
				{
					cout << "���ҵ���ѧ������Ϣ��\n";
					(*it)->Output();
					break;
				}
				if (it == StuList.end() - 1)
				{
					cout << "���޴��ˣ�";
					break;
				}
			}
			break;
		default:
			cout << "���벻��ȷ��������1��2��";
			cin >> num;
			system("cls");
			continue;
		}
		break;
	}

}

void StudentSystem::Display()
{
	char flag = '1';
	if (StuList.size() == 0)
	{
		cout << "��Ϊ������������ݣ�" << endl;
	}
	while (flag != 'q')
	{
		for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
		{
			(*it)->Output();
		}
		cout << "����q���뿪";
		cin >> flag;
	}
}

void StudentSystem::Delete()
{
	if (StuList.size() == 0)
	{
		cout << "��Ϊ�գ��޷�ɾ��" << endl;
		return;
	}
	int num;
	cout << "����ɾ�����е�ѧ����Ϣ(1��ȷ�� q�뿪)��";
	cin >> num;
	if (num == 1)
	{
		cout << "�ٴ�ȷ���Ƿ�ɾ��ȫ��ѧ����Ϣ��(1��ȷ�� q���뿪)��";
		cin >> num;
		if (num == 1)
		{
			int length = StuList.size();
			for (int i = 0; i < length; i++)
			{
				StuList.pop_back();
			}
			cout << "ɾ���ɹ���" << endl;
			cout << "����3���Ӻ�����������" << endl;
			Sleep(3000);
		}
		else
			return;
	}
	else
		return;
}

void StudentSystem::Count()
{
	char num;

	int low = 0;//10~13
	int mid = 0;//14~16
	int high = 0;//17~20

	int man = 0;
	int male = 0;
	if (StuList.size() == 0)
	{
		cout << "��Ϊ�գ���������ݣ�" << endl;
		return;
	}
	cout << "�ɰ����Ա��������ͳ�ƣ�����ѡ��1�������Ա�2���������䣩����";
	cin >> num;
	while (num != 'q')
	{
		if (num == '1')
		{
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->Get_Sex(),"��"))
				{
					man++;
				}
				else if (!strcmp((*it)->Get_Sex(), "Ů"))
				{
					male++;
				}
			}
			cout << "ͳ�ƽ����" << "�У�" << man << " ��" << "\tŮ" << male << "��\n";
		}
		else if (num == '2')
		{
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if ((*it)->Get_Age()>=10 && (*it)->Get_Age() <= 13)
				{
					low++;
				}
				else if ((*it)->Get_Age() >= 14 && (*it)->Get_Age() <= 16)
				{
					mid++;
				}
				else if ((*it)->Get_Age() >= 17 && (*it)->Get_Age() <= 20)
				{
					high++;
				}
			}
			cout << "ͳ�ƽ����" << "�����䣺" << low << " ��" << "\t������" << mid << "��"<< "\t������" << high << "��\n";
		}
		else
		{
			cout << "�����������������:(1��2),q�뿪";
			cin >> num;
		}
		cout << "�ɰ����Ա��������ͳ�ƣ�����ѡ��1�������Ա�2���������䣩q�˳�����";
		cin >> num;
	}
}
