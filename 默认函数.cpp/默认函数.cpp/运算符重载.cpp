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

	Date(Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator>(const Date& d){
		if (_year > d._year || (_year == d._year&&_month > d._month) || (_year == d._day&&_month == d._month&&_day > d._day)){
			return true;
		}
		else{
			return false;
		}
	}

	bool operator==(const Date& d){
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	//前置++
	Date& operator++(){
		_day += 1;
		return *this;
	}

	//后置++
	Date operator++(int){
		Date temp(*this);
		_day += 1;
		return temp;
	}

	void PrintDate(){
		cout << _year << "/ " << _month << "/ " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


// >和==的测试
void Test02(){ 
	Date d1(2020, 3, 10);
	Date d2(2020, 4, 25);
	Date d3(1999);

	if (d1 > d2){
		cout << "d1 ";
		d1.PrintDate();
	}
	else{
		cout << "d2 ";
		d2.PrintDate();
	}
	cout << endl;

	if (d1 == d2){
		cout << "d1==d2" << endl;
	}else{
		cout << "d1!=d2" << endl;
	}

}

//前置++ 后置++ 测试
void Test03(){
	Date d1(2020, 4, 25);
	d1.PrintDate();

	Date d2(d1++);
	d2.PrintDate();

	Date d3(++d1);
	d3.PrintDate();

}


class String{
public:
	String(char* str){
		_str = (char*)malloc(sizeof(str)+1);
		assert(_str);
		strcpy(_str, str);
	}

	~String(){
		free(_str);
		_str = nullptr;
	}

	//String& operator=(const String& s){
	//	strcpy(_str, s._str);
	//	return *this;
	//}


private:
	char* _str;
};

////赋值运算符重载测试
//void Test04(){
//	String s1("holle");
//	String s2("word!");
//
//	s1 = s2;
//
//}

int main(){
//	Test02();
//	Test03();


	return 0;
}