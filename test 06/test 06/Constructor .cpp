#include <iostream>
using namespace std;

class Date{
	
public:
	//���췽��
	Date(int year,int month,int day) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int ,int)" << endl;
	}

	//���췽����������
	Date(int year, int month){
		_year = year;
		_month = month;
		_day = 1;
		cout << "Date(int,int)" << endl;
	}
 
	//Ĭ�Ϲ��캯��
	Date(){
		_year = 2000;
		_month = 1;
		_day = 1;
	}
	Date(int year = 2000, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}

	void DatePrint(){
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main(){
	Date d; //����Ĭ�Ϲ��캯����ע��Ĭ�Ϲ��캯��ֻ����һ��
	//�˴�����дΪ�� Date d(); �����൱�ں�������

	Date d1(2020,4,27);
	Date d2(2020, 4);

	d1.DatePrint();
	d2.DatePrint();
	return 0;
}