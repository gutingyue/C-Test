#include <iostream>
using namespace std;

template <class T>
T Add(T left, T right){
	cout << "调用模板生成函数Add:  ";
	cout << (left + right) << endl;
	return left + right;
}

template <class T1,class T2>
T1 Add(T1 left, T2 right){
	return left + right;
}


int Add(int left, int right){
	cout << "调用全局函数Add" << endl;
	return left + right;
}


int main(){
	int num1 = Add(1, 2); //与非模板函数匹配，编译器不再通过模板生成
	Add<int>(1, 1); //调用编译器特化的Add版本

	int num2 = Add('1', '2'); //编译器对模板隐式实例化 Add<char>()

	//int num3 = Add(1, 2.0); //模板不会进行类型转化

	int num4 = Add<int>(1, 3.0); //显示实例化
	int num5 = Add(1, (int)4.0);

	return 0;
}
