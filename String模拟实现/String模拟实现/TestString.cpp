#include <iostream>
using namespace std;

#include "String.h"
using namespace str;

void Test1(){
	String s1;//�޲ι��캯���ĵ��ò���д�� String s1(); ���ַ�ʽ������������֪���Ƕ���������Ǻ�������
	String s2("hello");
	String s3(s2);
	s3 = s1;
}

int main(){
	Test1();

	return 0;
}