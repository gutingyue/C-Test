#include <iostream>
using namespace std;

#include "String.h"
using namespace str;

/////////////////////////////////////////
//modify 修改操作
//尾插
void String::push_back(char c){}
void String::push_back(const char* s){}
void String::push_back(String& s){}
//+=重载
String& String::operator+=(char c)
{

}


//交换
void String::Swap(String& s){
	swap(_str, s._str);
	swap(_size, s._size);
	swap(_capacity, s._capacity);
}

