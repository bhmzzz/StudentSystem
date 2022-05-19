#include "StudentList.h"


void AbstractStudent::Input()//抽象数据初始化接口
{
	char* temp = new char[MAX_SIZE20];
	cout << "请输入学生学号：";
	cin >> temp;
	strcpy_s(StdNum, temp);
	cout << "\n请输入学生姓名：";
	cin >> temp;
	strcpy_s(name, temp);
	cout << "\n请输入学生性别：";
	cin >> temp;
	strcpy_s(sex, temp);
	cout << "\n请输入学生年龄：";
	cin >> age;
	cout << "\n请输入学生班级：";
	cin >> temp;
	strcpy_s(Class, temp);
	delete[] temp;
}

void AbstractStudent::Output()
{
	cout << "学生学号\t" << "学生姓名\t" << "学生性别\t" << "学生年龄\t" << "学生班级\t" << endl;
	cout << StdNum << "\t" << name << "\t" << sex << "\t" << age << "\t" << Class << "\t\n";
}

void XStudent::Input()
{
	AbstractStudent::Input();
	cout << "\n请输入英语成绩：";
	cin >> EnglishG;
	cout << "\n请输入数学成绩：";
	cin >> MathG;
	cout << "\n请输入语文成绩：";
	cin >> ChineseG;
}

void XStudent::Output()
{
	AbstractStudent::Output();
	cout << "英语成绩\t" << "数学成绩\t" << "语文成绩\t\n";
	cout << EnglishG << "\t" << MathG << "\t" << ChineseG << "\t\n";
}

void ZStudent::Input()
{
	XStudent::Input();
	system("cls");
	char* temp = new char[MAX_SIZE50];
	cout << "\n请输入地理成绩：";
	cin >> DiLiG;
	cout << "\n请输入历史成绩：";
	cin >> HistoryG;
	cout << "\n请输入家庭地址：";
	cin >> temp;
	strcpy_s(Adress, temp);
	delete[] temp;
}

void ZStudent::Output()
{
	XStudent::Output();
	cout << "地理成绩\t" << "历史成绩\t" << "家庭地址\t\n";
	cout << DiLiG << "\t" << HistoryG << "\t" << Adress << "\t\n";
}

void DStudent::Input()
{
	AbstractStudent::Input();
	char* temp = new char[MAX_SIZE50];
	cout << "\n请输入专业：";
	cin >> temp;
	strcpy_s(ZhuanYe, temp);
	cout << "\n请输入家庭地址：";
	cin >> temp;
	strcpy_s(Adress, temp);
	cout << "\n请输入电话号码：";
	cin >> temp;
	strcpy_s(Tel, temp);
	delete[] temp;
}

void DStudent::Output()
{
	AbstractStudent::Output();
	cout << "专业\t" << "家庭地址\t\t" << "电话号码\t\n";
	cout << ZhuanYe << "\t" << Adress << "\t\t" << Tel << "\t\n";
}

StudentSystem::StudentSystem() {}

void StudentSystem::AddStu()
{
	char num;
	AbstractStudent* stu;
	cout << "请输入您向添加的学生：1、小学生  2、中学生  3、大学生(请输入1、2、3)  ";
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
				cout << "输入错误！重新输入！" << endl;
				cout << "请输入您向添加的学生：1、小学生  2、中学生  3、大学生(请输入1、2、3)  ";
				cin >> num;
				system("cls");
				continue;
			}
			StuList.push_back(stu);
			cout << "存储成功！" << endl;
			break;
	}
}

void StudentSystem::Check()
{
	char num;
	char* temp = new char[MAX_SIZE20];
	cout << "选择您想要查询的方式：（1、学号 2、姓名）";
	cin >> num;
	while (num)
	{
		switch (num)
		{
		case '1':
			cout << "请输入您要查询的学号：";
			cin >> temp;
			if (StuList.size() == 0)
			{
				cout << "表为空请先添加数据！" << endl;
				break;
			}
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->GetStdNum(),temp))
				{
					cout << "查找到该学生的信息：\n";
					(*it)->Output();
					cout << "是否修改或删除该学生信息？（1修改 2删除 其它任意键退出）";
					cin >> num;
					if (num == '1')
					{
						system("cls");
						cout << "以下是该学生信息：" << endl;
						(*it)->Output();
						cout << "选择你要修改的项目：\n";
						cout << "1 修改学号 2 修改年龄 3修改班级 其他信息不可修改。";
						cin >> num;
						while (num != 'q')
						{
							switch (num)
							{
							case '1':
							{
								char* temp1 = new char[MAX_SIZE20];
								cout << "请输入修改后的学生学号：";
								cin >> temp1;
								(*it)->set_StdNum(temp1);
								delete [] temp1;
								break;
							}
							case '2':
							{
								cout << "请输入修改后的学生年龄：";
								short agetemp;
								cin >> agetemp;
								(*it)->set_age(agetemp);
								break;
							}
							case '3':
							{
								char* temp2 = new char[MAX_SIZE20];
								cout << "请输入修改后的学生班级：";
								cin >> temp2;
								(*it)->set_class(temp);
								delete [] temp2;
								break;
							}
							default:
							{
								cout << "输入错误，请输入1\2\3,q离开：";
								cin >> num;
								continue;
							}
							}
							cout << "修改成功！是否继续修改？1 修改学号 2 修改年龄 3修改班级 q键否：";
							cin >> num;
						}
					}
					else if (num == '2')
					{
						system("cls");
						(*it)->Output();
						cout << "将删除该学生信息，请确认 （1删除 q退出）" << endl;
						cin >> num;
						if (num == '1')
						{
							StuList.erase(it);
							cout << "删除完毕！";
							return;
						}
						else if (num == 'q')
							return;
					}
					break;
				}
				if (it == StuList.end() - 1)
				{
					cout << "查无此人！";
					break;
				}
			}
			break;
		case '2':
			if (StuList.size() == 0)
			{
				cout << "表为空请先添加数据！" << endl;
				break;
			}
			cout << "请输入您要查询的姓名：";
			cin >> temp;
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->GetName(),temp))
				{
					cout << "查找到该学生的信息：\n";
					(*it)->Output();
					break;
				}
				if (it == StuList.end() - 1)
				{
					cout << "查无此人！";
					break;
				}
			}
			break;
		default:
			cout << "输入不正确，请输入1或2：";
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
		cout << "表为空请先添加数据！" << endl;
	}
	while (flag != 'q')
	{
		for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
		{
			(*it)->Output();
		}
		cout << "输入q键离开";
		cin >> flag;
	}
}

void StudentSystem::Delete()
{
	if (StuList.size() == 0)
	{
		cout << "表为空！无法删除" << endl;
		return;
	}
	int num;
	cout << "可以删除所有的学生信息(1、确认 q离开)：";
	cin >> num;
	if (num == 1)
	{
		cout << "再次确认是否删除全体学生信息？(1、确认 q、离开)：";
		cin >> num;
		if (num == 1)
		{
			int length = StuList.size();
			for (int i = 0; i < length; i++)
			{
				StuList.pop_back();
			}
			cout << "删除成功！" << endl;
			cout << "将在3秒钟后跳回主界面" << endl;
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
		cout << "表为空，请添加数据！" << endl;
		return;
	}
	cout << "可按照性别，年龄进行统计：（请选择1（按照性别）2（按照年龄））：";
	cin >> num;
	while (num != 'q')
	{
		if (num == '1')
		{
			for (StuArr::iterator it = StuList.begin(); it != StuList.end(); it++)
			{
				if (!strcmp((*it)->Get_Sex(),"男"))
				{
					man++;
				}
				else if (!strcmp((*it)->Get_Sex(), "女"))
				{
					male++;
				}
			}
			cout << "统计结果：" << "男：" << man << " 人" << "\t女" << male << "人\n";
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
			cout << "统计结果：" << "低年龄：" << low << " 人" << "\t中年龄" << mid << "人"<< "\t大年龄" << high << "人\n";
		}
		else
		{
			cout << "输入错误，请重新输入:(1或2),q离开";
			cin >> num;
		}
		cout << "可按照性别，年龄进行统计：（请选择1（按照性别）2（按照年龄）q退出）：";
		cin >> num;
	}
}
