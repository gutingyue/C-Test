#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, Date& d);// <<的重载是Date的友元函数
	friend void TestFriend(Date& d);

public:
	Date(int year = 2020, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{ }
private:
	void DatePrint(){
		Time t1(9, 1, 30);
		t1.TimePrint();//Date是Time的友元类，所以可以访问Time中的所有成员（变量和方法）
	}
private:
	
	int _year;
	int _month;
	int _day;

};

class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour), _minute(minute), _second(second)
	{ }

private:
	void TimePrint(){
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

void TestFriend(Date& d)
{
	d._year = 2000;
}

Date d3(1999, 1, 17);
ostream& operator<<(ostream& _cout, Date& d)//第一个参数是ostream类对象
{
	//_cout << d3; //注意此处会形成无穷递归，造成栈溢出
	_cout << d._year << "/" << d._month << "/" << d._day;
	

	return _cout;
}

void Test1(){
	Date d1(2020, 4, 27);
	Date d2(2020, 5);
	cout << d1 << endl << d2 << endl;

	TestFriend(d2);
	cout << d2 << endl;
}

int main(){
	Test1();//友元函数测试

	return 0;
}