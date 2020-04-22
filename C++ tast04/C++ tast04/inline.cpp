#include<iostream>
using namespace std;

inline int Add(int a, int b){
	int c = a + b;
	return c;
}

int main(){
	int a = 1;
	int b = 2;

	int ret = Add(a, b);
	cout << ret << endl;

	return 0;
}