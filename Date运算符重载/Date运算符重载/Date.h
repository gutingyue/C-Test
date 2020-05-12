#include <iostream>
#include <stdio.h>
using namespace std;


class Date{
friend ostream& operator<<(ostream& _cout, const Date& d);//声明<<的重载函数是Date类的友元函数

public:
	//全缺省构造函数
	Date(int year, int month, int day);
	//	:_year(year), _month(month), _day(day)
	//{ }

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//获取月份天数
	int GetDay()const
	{
		if (_month == 2){
			if ((_year % 4 == 0) && (_year % 100 != 0)||(_year % 400 == 0)){
				return 29;
			}
			return 28;
		}
		else if (_month ==4||_month==6||_month==9||_month==11){
			return 30;
		}
		else{
			return 31;
		}
	}


	//赋值运算符重载
	Date& operator=(const Date& d);

	////析构函数
	//~Date();

	//日期+=天数
	Date& operator+=(int day);

	//日期-=天数
	Date& operator-=(int day);

	//返回 日期+天数 （实际日期不变） 
	Date operator+(int day);

	//日期-天数
	Date operator-(int day);

	//前置++
	Date& operator++();

	//后置++
	Date operator++(int);

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);

	// >重载
	bool operator>(const Date& d);

	// <重载
	bool operator<(const Date& d);

	// ==重载
	bool operator==(const Date& d);

	// !=重载
	bool operator!=(const Date& d);

	// 日期-日期（计算两日期相差天数）
	int operator-(const Date& d);

	void DayPrint(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

////日期打印
//ostream& operator<<(ostream& _cout, const Date& d){
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;//为支持连续打印
//}