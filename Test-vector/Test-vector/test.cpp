#include <iostream>
using namespace std;

#include <vector>

void TestVector1(){
	vector<int> v1;

	vector<char> v2(5, '1'); //5个1
	vector<int> v3(10); //第二个参数没给，默认用0填充

	int array[] = { 1, 2, 3, 4 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 0, 1, 2, 3 };
	for (auto e : v5)
		cout << e;
	cout << endl;
}

//测试vector容量相关操作
void TestVector2(){

	vector<int> v1{ 1, 2, 3, 4 };
	v1.reserve(5); //size=4 , capacity=5
	//v1.reserve(20); //capacity=20

	v1.resize(6, 5); //size=6 , capacity=7  1,2,3,4,5,5
	v1.resize(10); //第二个参数没给，默认用0填充 size=10 , capacity=10
	v1.resize(4); //size=4 , capacity=10 1,2,3,4


	//检测每次自动扩容的大小
	vector<int> v2{ 0 };
	v2.reserve(100);// 若知道大概要插入多少元素，最好直接给好容量，避免多次扩容，影响效率

	size_t sz = v2.capacity();//获取容量
	for (int i = 1; i < 100; i++){
		v2.push_back(0);
		if (sz != v2.capacity())//若发生扩容
		{
			cout << "Capacity:" << v2.capacity() << endl;
			sz = v2.capacity();
		}
	}
}

//测试vector增删改查相关操作
void TestVector3(){
	vector<int> v1{ 1, 2, 3, 4 };
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it++;
	}
	cout << endl;

	v1.pop_back();

	v1.push_back(5);

	auto pos = find(v1.begin(), v1.end(), 5);
	v1.insert(pos, 4);

	int array[] = { 0, 0, 0, 0 };
	v1.insert(v1.begin(), array, array + sizeof(array) / sizeof(array[0]));

	v1.insert(v1.end(), 3, 1); //尾插3个1

	//C++11中提供列表方式的插入
	v1.insert(v1.end(), { 7, 8, 9 });

}

void TestVector4(){
	vector<int> v1 = { 1, 2, 3, 4 };
	
	//v1.erase(v1.end());//end()处没有有效元素
	v1.erase(v1.begin());

	//v1.clear(); //清空元素
	v1.erase(v1.begin(), v1.end());

}

//迭代器失效
void TestVector5(){
	vector<int> v1{ 0, 1, 2, 3, 4 };
	vector<int>::iterator pos = v1.begin() + 1;
	cout << *pos << endl; // 1
	
	//v1.erase(pos); //erase()会使迭代器失效
	pos=v1.erase(pos); //使用erase()后，要重新给pos赋值
	cout << *pos << endl;

}
int main(){

	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	TestVector5();

	return 0;
}