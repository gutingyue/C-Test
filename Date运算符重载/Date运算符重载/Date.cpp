#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int year=2020, int month=5, int day=5)
:_year(year), _month(month), _day(day)
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//��ֵ���������
Date& Date::operator=(const Date& d){
	if (&d != this){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//Ϊ����������ֵ������ֵӦΪ�Զ�������
}

//����+=����
Date& Date::operator+=(int day){
	_day += day;
	while (_day > GetDay()){ //GetDay()���ص�ǰ�·ݵ�����
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}
	return *this;
}

//����-=����
Date& Date::operator-=(int day){
	_day -= day;
	while (_day <= 0){ //GetDay()���ص�ǰ�·ݵ�����
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}
	return *this;
}

//���� ����+���� ��ʵ�����ڲ��䣩 
Date Date::operator+(int day){
	Date d(*this);
	d += day;

	return d;
}

//����-����
Date Date::operator-(int day){
	Date d(*this);
	d -= day;

	return d;

}

//ǰ��++ ++d��++��ʹ��
Date& Date::operator++(){
	_day += 1;

	while (_day > GetDay()){ //GetDay()���ص�ǰ�·ݵ�����
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}
	return *this;
}

//ǰ��--
Date& Date::operator--(){
	_day -= 1;

	while (_day <= 0){ //GetDay()���ص�ǰ�·ݵ�����
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}
	return *this;
}

//����++
Date Date::operator++(int){ //���ܷ������ã�ӦΪd��ջ֡�Ͽ��ٿռ䣬�������ý�����ջ֡�����գ����ã�ָ��)ָ����Ч�ռ�
	Date d(*this);

	_day += 1;
	while (_day > GetDay()){ //GetDay()���ص�ǰ�·ݵ�����
		_day -= GetDay();
		_month++;
		if (_month > 12){
			_month -= 12;
			_year++;
		}
	}

	return d;
}

//����--
Date Date::operator--(int){
	Date d(*this);

	_day -= 1;
	while (_day <= 0){ //GetDay()���ص�ǰ�·ݵ�����
		_month--;
		_day += GetDay();

		if (_month < 1){
			_month += 12;
			_year--;
		}
	}

	return d;
}

// >����
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

// <����
bool Date::operator<(const Date& d){
	if (_year == d._year&&_month == d._month&&_day == d._day){
		return false;
	}
	return !(*this>d);
}

// ==����
bool Date::operator==(const Date& d){
	if (_year == d._year&&_month == d._month&&_day == d._day){
		return true;
	}
	return false;
}

// !=����
bool Date::operator!=(const Date& d){
	if (_year != d._year || _month != d._month || _day != d._day){
		return true;
	}
	return false;
}

// ����-���ڣ��������������������
//δ���
int Date::operator-(const Date& d){ // *this�Ǵ����� ,d��С����
	int DifferDay = 0;
	if (_day > d._day){
		DifferDay += (_day - d._day); //day�Ĳ�ֵ
	}
	else if (_day < d._day){
		DifferDay = DifferDay + _day + (d.GetDay() - d._day); //day�Ĳ�ֵ
	}

	return 0;
}

