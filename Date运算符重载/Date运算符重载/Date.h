#include <iostream>
#include <stdio.h>
using namespace std;


class Date{
friend ostream& operator<<(ostream& _cout, const Date& d);//����<<�����غ�����Date�����Ԫ����

public:
	//ȫȱʡ���캯��
	Date(int year, int month, int day);
	//	:_year(year), _month(month), _day(day)
	//{ }

	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ȡ�·�����
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


	//��ֵ���������
	Date& operator=(const Date& d);

	////��������
	//~Date();

	//����+=����
	Date& operator+=(int day);

	//����-=����
	Date& operator-=(int day);

	//���� ����+���� ��ʵ�����ڲ��䣩 
	Date operator+(int day);

	//����-����
	Date operator-(int day);

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
	Date operator--(int);

	// >����
	bool operator>(const Date& d);

	// <����
	bool operator<(const Date& d);

	// ==����
	bool operator==(const Date& d);

	// !=����
	bool operator!=(const Date& d);

	// ����-���ڣ��������������������
	int operator-(const Date& d);

	void DayPrint(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

////���ڴ�ӡ
//ostream& operator<<(ostream& _cout, const Date& d){
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;//Ϊ֧��������ӡ
//}