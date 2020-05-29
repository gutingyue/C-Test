#include "Date.h"

#include <iostream>
using namespace std;

void Test1(){
	Date d1(2019,12,30);
	d1 += 20;
	//cout << d1 << endl;
	d1.DayPrint();

	Date d2(2020, 1, 1);
	d2 -= 20;
	//cout << d2 << endl;
	d2.DayPrint();

}

void Test2(){
	Date d1(2020, 5, 20);
	Date d2 = d1 + 20;
	//cout << d2 << endl;
	cout << "d1" << " :";
	d1.DayPrint();

	cout << "d2 :";
	d2.DayPrint();

	d2 = d2 - 20;
	cout << "d2 :";
	d2.DayPrint();
}

void Test3(){
	Date d1(2019, 12, 31);

	Date d2 = ++d1;
	cout << "d2 (++d1) :";
	d2.DayPrint();

	d2 = --d2;
	cout << "d2 (--d2)" << " :";
	d2.DayPrint();
}

void Test4(){
	Date d1(2020, 1, 1);

	Date d2 = d1++;
	cout << "d2(=d1++):";
	d2.DayPrint();
	cout << "d1(d1++):";
	d1.DayPrint();

}

void Test5(){
	Date d1(1999, 1, 17);
	Date d2(1998, 11, 2);
	Date d3(d2);

	if (d1 > d2){ // >表示离日期越新
		cout << "d1>d2" << endl;
	}
	if (d2 < d1){
		cout << "d2<d1" << endl;
	}
	if (d2 == d3){
		cout << "d2==d3" << endl;
	}
	if (d2 != d3){
		cout << "d2!=d3" << endl;
	}
	if (d1 != d3){
		cout << "d1!=d3" << endl;
	}
}

int main(){
	//Test1(); // += , -=
	//Test2(); // = , -
	//Test3(); // 前置--/++
	//Test4(); //后置--/++
	Test5(); // > , < , == , !=

	return 0;
}