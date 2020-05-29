#include <iostream>
using namespace std;

#include <list>
#include<vector>

void listTest1(){
	list<int> l1;

	list<char> l2(10, '-');
	list<char>::iterator it = l2.begin();
	while (it != l2.end()){
		cout << *it++;
	}
	cout << endl;


	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> l3(v.begin(), v.end());
	for (auto e : l3) //也可以通过范围for来遍历
		cout << e;
	cout << endl;

	list<int> l4(l3);

	list<int> list{ 1, 2, 3, 4, 5 }; //C++11

}

void listTest2(){
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	cout << l.size() << endl;

	l.pop_back();

	auto it = l.begin();
	while (it != l.end()){
		cout << *it++;
	}
	cout << endl;

	l.push_front(0);

	cout << l.front() << " " << l.back();

}

void listTest3(){
	list<int> l{ 1, 1, 1, 1, 1, 1, };
	l.assign(10, 0); //0000000000

	for (auto e : l)
		cout << e << " ";
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	l.assign(array, array + 3); //123

	for (auto e : l)
		cout << e << " ";
	cout << endl;

	//C++11 可以列表方式赋值
	l.assign({3,2,1});
}

int main(){
	//listTest1();
	//listTest2();
	listTest3();



	return 0;
}
