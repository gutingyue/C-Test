#pragma once
#include <string>

using namespace std;

class Base64{
public:
	//����
	string Encode(const string& strData);
	//����
	string Decode(const string& strData);

};