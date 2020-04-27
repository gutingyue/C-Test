#include <iostream>
using namespace std;

class Date{
	
public:
	//构造方法
	Date(int year,int month,int day) {
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int ,int)" << endl;
	}

	//构造方法可以重载
	Date(int year, int month){
		_year = year;
		_month = month;
		_day = 1;
		cout << "Date(int,int)" << endl;
	}
 
	//默认构造函数
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
	Date d; //调用默认构造函数，注意默认构造函数只能有一个
	//此处不能写为： Date d(); 这种相当于函数声明

	Date d1(2020,4,27);
	Date d2(2020, 4);

	d1.DatePrint();
	d2.DatePrint();
	return 0;
}