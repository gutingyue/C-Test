#include <iostream>
using namespace std;


class B
{
public:
	B(int b){
		_b = b;
	}

	int _b;
};

int Print(int num){
	cout << "����ȱʡֵ" << endl;
	return num;
}

//C++11 ��ʼ��������ʱ����ֵ��
class A
{
public:
	A(int a)
		:_a(a)
		,c(10)
	{
		a = 30;
	}

private:
	int _a = Print(10);
	int* b = (int*)malloc(sizeof(int));
	B c;
};

//int main(){
//	A test(20);
//
//	return 0;
//}