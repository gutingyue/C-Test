#include <iostream>
using namespace std;

#include "String.h"
using namespace str;

void Test1(){
	String s1;//无参构造函数的调用不能写成 String s1(); 这种方式编译器报错，不知道是定义变量还是函数声明
	String s2("hello");
	String s3(s2);
	s3 = s1;
}

int main(){
	Test1();

	return 0;
}