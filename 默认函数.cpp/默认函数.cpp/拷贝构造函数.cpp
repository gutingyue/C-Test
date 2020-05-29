#include <iostream>
#include <assert.h>
#include <malloc.h>

using namespace std;

class Date{
public:
	Date(int year = 2020, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void PrintDate(){
		cout << "Date " << _year << "/" << _month << "/" << _day << endl;
	}


private:
	int _year;
	int _month;
	int _day;
};

void Test01(){
	Date d1(2020,4);
	d1.PrintDate();

	Date d2(d1);
	d2.PrintDate();
}

//int main(){
//	Test01();
//
//	return 0;
//}