#include<iostream>
#include<vector>
#include<windows.h>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

#define MAX_SIZE50 50
#define MAX_SIZE20 20
#define MAX_SIZE10 10
#define MAX_SIZE5 5

class AbstractStudent {
private:
	char StdNum[MAX_SIZE20];
	char name[MAX_SIZE10];
	char sex[MAX_SIZE10];
	short age;
	char Class[MAX_SIZE20];
public:
	virtual void Input() = 0;
	virtual void Output() = 0;
	char* GetStdNum() { return StdNum; }
	char* GetName() { return name; }
	void set_StdNum(char c[]) { strcpy_s(StdNum, c); }
	void set_age(short s) { age = s; }
	void set_class(char c[]) { strcpy_s(Class, c); }
	char* Get_Sex() { return sex; }
	short Get_Age() { return age; }
};

class XStudent : public AbstractStudent {
private:
	int EnglishG;
	int MathG;
	int ChineseG;
public:
	virtual void Input();
	virtual void Output();
};

class ZStudent : public XStudent {
private:
	int DiLiG;
	int HistoryG;
	char Adress[MAX_SIZE50];
public:
	virtual void Input();
	virtual void Output();
};

class DStudent : public AbstractStudent {
private:
	char ZhuanYe[MAX_SIZE20];
	char Adress[MAX_SIZE50];
	char Tel[MAX_SIZE20];
public:
	virtual void Input();
	virtual void Output();
};

typedef vector<AbstractStudent*> StuArr;

class StudentSystem {
private:
	StuArr StuList;
public:
	StudentSystem();
	void AddStu();
	void Check();
	void Display();
	void Delete();
	void Count();
	//void Save();
	//void Read();
};
