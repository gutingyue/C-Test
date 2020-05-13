#include <iostream>

using namespace std;

void Test1(){
	const int a = 10;

	const int* _pa = &a; //a类型为const int ,const int* _pa 表示指针所指向的内容不可被修改
	//int* const _pa 表示指针指向不可被修改

	int* pa = (int*)&a;
	*pa = 20;

	printf("%d\n", a);
	cout << a << endl; //a被const修饰，在编译阶段被替换,相当于cout << 10 << endl;
	cout << *pa << endl;
}

void Test2(){
	class Test
	{
	public:
		void PrintTest()const //const Test* const this 即this指向内容不可被修改,且this指向不可变
		{
			cout << "a:" << a << endl;
		}
	private:
		int a;
	};

}
void Test3(){
	//日期类
	class Date
	{
	public:
		Date(int year, int month, int day)
			:_year(year), _month(month), _day(day)
		{}
		void Reset() //Reset()中修改了成员变量
		{
			_year = 2020;
			_month = 1;
			_day = 1;
		}

		void PrintDate()const //打印日期(const成员函数）
		{
			cout << _year << _month << _day << endl;
		}
	private:
		int _year;
		int _month;
		int _day;
	};

	Date d1(2020, 5, 1);
	const Date d2(2020, 5, 2);
	d1.Reset(); 
	d1.PrintDate(); //非const对象可以调用const成员函数
	//d2.Reset(); //const对象不能调用非const成员函数
	d2.PrintDate(); 

}

void Test4(){
	//日期类
	class Date
	{
	public:
		Date* operator&() //this的类型为 Date* const this
		{
			return this;
		}

		const Date* operator&()const //this的类型为 const Date* const this 
		//返回值类型也为const Date* 
		{
			return this;
		}
		//由于两个函数实际的this指针参数的类型不同，所以是构成重载的
	private:
		int _year;
		int _month;
		int _day;
	};

	Date d1();
	const Date d2();
	cout << &d1 << endl;//&d1调用 Date* operator&()
	cout << &d2 << endl;//d2被const修饰 所以&d2调用 const Date* operator&()const
						//若&d2调用普通& 可能会造成成员变量被修改


}
int main(){
	//Test3();

	return 0;
}
