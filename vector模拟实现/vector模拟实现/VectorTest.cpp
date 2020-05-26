#include <iostream>
using namespace std;

#include "Vector.h"


//构造函数测试
void vectorTest1(){
	vec::Vector<int> v1;

	vec::Vector<int> v2(5, 1);
	size_t i = 0;
	for (; i < v2.size(); i++){
		cout << v2[i] << " ";
	}
	cout << endl;

	string s = "123";
	vec::Vector<char> v3(s.begin(), s.end());
	auto it = v3.begin();
	while (it != v3.end())
		cout << *it++ << " ";
	cout << endl;

	vec::Vector<char> v4(v3);
	for (auto e : v4) //范围for最终是通过迭代器的方式打印的，如果没有定义迭代器，就会报错
		cout << e << " ";
	cout << endl;
}

//访问操作测试
void vectorTest2(){

	string s = "12345";
	vec::Vector<char> v1(s.begin(), s.end());

	cout << v1[0] << endl;

	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;

	cout << "front:" << v1.front() << endl;
	cout << "back:" << v1.back() << endl;

}

//修改操作测试
void vectorTest3(){
	vec::Vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1.pop_back();

	v1.insert(v1.begin()+3, 4);
	v1.erase(v1.end() - 1);
}


int main(){
	//vectorTest1();
	//vectorTest2();
	vectorTest3();

	return 0;
}