#include <iostream>
using namespace std;

#include "String.h"
using namespace str;

/////////////////////////////////////////
//modify �޸Ĳ���
//β��
void String::push_back(char c){}
void String::push_back(const char* s){}
void String::push_back(String& s){}
//+=����
String& String::operator+=(char c)
{

}


//����
void String::Swap(String& s){
	swap(_str, s._str);
	swap(_size, s._size);
	swap(_capacity, s._capacity);
}

