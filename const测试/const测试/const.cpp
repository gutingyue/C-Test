#include <iostream>

using namespace std;

void Test1(){
	const int a = 10;

	const int* _pa = &a; //a����Ϊconst int ,const int* _pa ��ʾָ����ָ������ݲ��ɱ��޸�
	//int* const _pa ��ʾָ��ָ�򲻿ɱ��޸�

	int* pa = (int*)&a;
	*pa = 20;

	printf("%d\n", a);
	cout << a << endl; //a��const���Σ��ڱ���׶α��滻,�൱��cout << 10 << endl;
	cout << *pa << endl;
}

void Test2(){
	class Test
	{
	public:
		void PrintTest()const //const Test* const this ��thisָ�����ݲ��ɱ��޸�,��thisָ�򲻿ɱ�
		{
			cout << "a:" << a << endl;
		}
	private:
		int a;
	};

}
void Test3(){
	//������
	class Date
	{
	public:
		Date(int year, int month, int day)
			:_year(year), _month(month), _day(day)
		{}
		void Reset() //Reset()���޸��˳�Ա����
		{
			_year = 2020;
			_month = 1;
			_day = 1;
		}

		void PrintDate()const //��ӡ����(const��Ա������
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
	d1.PrintDate(); //��const������Ե���const��Ա����
	//d2.Reset(); //const�����ܵ��÷�const��Ա����
	d2.PrintDate(); 

}

void Test4(){
	//������
	class Date
	{
	public:
		Date* operator&() //this������Ϊ Date* const this
		{
			return this;
		}

		const Date* operator&()const //this������Ϊ const Date* const this 
		//����ֵ����ҲΪconst Date* 
		{
			return this;
		}
		//������������ʵ�ʵ�thisָ����������Ͳ�ͬ�������ǹ������ص�
	private:
		int _year;
		int _month;
		int _day;
	};

	Date d1();
	const Date d2();
	cout << &d1 << endl;//&d1���� Date* operator&()
	cout << &d2 << endl;//d2��const���� ����&d2���� const Date* operator&()const
						//��&d2������ͨ& ���ܻ���ɳ�Ա�������޸�


}
int main(){
	//Test3();

	return 0;
}
