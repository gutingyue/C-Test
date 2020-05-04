#include <iostream>
#include <stdio.h>

class Date{
public:
	//全缺省构造函数
	Date(int year = 2000, int month = 1, int day = 1);

	//拷贝构造函数
	Date(const Date& d);

	//赋值运算符重载
	Date& operator=(const Date& d);

	//析构函数
	~Date();

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

private:
	int _year;
	int _month;
	int _day;
};