#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int year=2020, int month=5, int day=5)
:_year(year), _month(month), _day(day)
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//赋值运算符重载
Date& Date::operator=(const Date& d){
	if (&d != this){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//为满足连续赋值，返回值应为自定义类型
}

//日期+=天数
Date& Date::operator+=(int day){
	_day += day;
	while (_day > GetDay()){ //GetDay()返回当前月份的天数
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}
	return *this;
}

//日期-=天数
Date& Date::operator-=(int day){
	_day -= day;
	while (_day <= 0){ //GetDay()返回当前月份的天数
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}
	return *this;
}

//返回 日期+天数 （实际日期不变） 
Date Date::operator+(int day){
	Date d(*this);
	d += day;

	return d;
}

//日期-天数
Date Date::operator-(int day){
	Date d(*this);
	d -= day;

	return d;

}

//前置++ ++d先++再使用
Date& Date::operator++(){
	_day += 1;

	while (_day > GetDay()){ //GetDay()返回当前月份的天数
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}
	return *this;
}

//前置--
Date& Date::operator--(){
	_day -= 1;

	while (_day <= 0){ //GetDay()返回当前月份的天数
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}
	return *this;
}

//后置++
Date Date::operator++(int){ //不能返回引用，应为d在栈帧上开辟空间，函数调用结束，栈帧被回收，引用（指针)指向无效空间
	Date d(*this);

	_day += 1;
	while (_day > GetDay()){ //GetDay()返回当前月份的天数
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}

	return d;
}

//后置--
Date Date::operator--(int){
	Date d(*this);

	_day -= 1;
	while (_day <= 0){ //GetDay()返回当前月份的天数
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}

	return d;
}

// >重载
bool Date::operator>(const Date& d){
	if (_year > d._year){
		return true;
	}
	else if (_year == d._year&&_month > d._month){
		return true;
	}
	else if (_year == d._year&&_month == d._month&&_day > d._day){
		return true;
	}
	else{
		return false;
	}
}

// <重载
bool Date::operator<(const Date& d){
	if (_year == d._year&&_month == d._month&&_day == d._day){
		return false;
	}
	return !(*this>d);
}

// ==重载
bool Date::operator==(const Date& d){
	if (_year == d._year&&_month == d._month&&_day == d._day){
		return true;
	}
	return false;
}

// !=重载
bool Date::operator!=(const Date& d){
	if (_year != d._year || _month != d._month || _day != d._day){
		return true;
	}
	return false;
}

// 日期-日期（计算两日期相差天数）
//未完成
int Date::operator-(const Date& d){ // *this是大日期 ,d是小日期
	int DifferDay = 0;
	if (_day > d._day){
		DifferDay += (_day - d._day); //day的差值
	}
	else if (_day < d._day){
		DifferDay = DifferDay + _day + (d.GetDay() - d._day); //day的差值
	}

	return 0;
}

