#include "list.h"
using namespace lis;

#include<iostream>
using namespace std;

#include<vector>

void Test1(){
	List<int> L1;

	List<int> L2(5, 1);

	auto it = L2.begin();
	while (it != L2.end())
		cout << *it++ << " "; 
	cout << endl;

	vector<int> v{ 9, 8, 7, 6, 5, 4 };
	List<int> L3(v.begin(), v.end());

	it = L3.begin();
	while (it != L3.end())
		cout << *it++ << " ";
	cout << endl;

	List<int> L4(L3);
	
}


void Test2(){
	List<int> L1;
	
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);

	auto it = L1.begin();
	while (it != L1.end())
		cout << *it++ << " "; //尽可能选择前置++ ，效率较高
	cout << endl;

	L1.pop_back();

	L1.insert(L1.begin(), 0);

	it = L1.begin();
	while (it != L1.end())
		cout << *it++ << " ";
	cout << endl;

	L1.push_front(0);

	L1.resize(2);

	it = L1.begin();
	while (it != L1.end())
		cout << *it++ << " ";
	cout << endl;

	//auto cur = find(L1.begin(), L1.end(), 2); //自己写的迭代器，无法配合find()算法

	L1.insert(L1.begin(), 0);

	it = L1.begin();
	while (it != L1.end())
		cout << *it++ << " ";
	cout << endl;

}

void Test3(){

}

int main(){
	Test1();
	//Test2();

	return 0;
}