#include <iostream>
#include <stdio.h>

class Date{
public:
	//ȫȱʡ���캯��
	Date(int year = 2000, int month = 1, int day = 1);

	//�������캯��
	Date(const Date& d);

	//��ֵ���������
	Date& operator=(const Date& d);

	//��������
	~Date();

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

private:
	int _year;
	int _month;
	int _day;
};