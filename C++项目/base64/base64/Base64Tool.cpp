#include "Base64.h"
#include <iostream>
#include <string>
using namespace std;

//����
void Test_Encode(){
	string enData;

	cout << "enData:";
	getline(cin, enData);
	Base64 str;
	string enstr = str.Encode(enData);
	cout << enstr << endl;
}

//����
void Test_Decode(){
	string deData;

	cout << "deData:";
	getline(cin, deData);
	Base64 str;
	string destr = str.Decode(deData);
	cout << destr << endl;
}

int main(){
	Test_Encode();
	Test_Decode();


	return 0;
}