#include <iostream>
using namespace std;

void ForTest(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	//·¶Î§for
	for (auto& a : arr){
		a++;
		cout << a << " ";
	}
}


int main(){
	ForTest();
	return 0;
}