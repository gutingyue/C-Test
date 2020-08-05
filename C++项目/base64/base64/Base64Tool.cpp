#include "Base64.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	string enData;
	while (getline(cin, enData)){
		Base64 str;
		string enstr=str.Encode(enData);
		cout << enstr << endl;

	}

	return 0;
}