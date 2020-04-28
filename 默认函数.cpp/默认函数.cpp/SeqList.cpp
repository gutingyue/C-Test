#include "SeqList.h"
#include <stdio.h>

class String{
public:
	//构造函数
	String(const char* str = "null"){
		_str = (char*)malloc(sizeof(str)+1);  //注意字符串以\0结尾
		strcpy(_str, str);
	}

	char* _str;
};

class student{
public:
	String _name;
	int age;
};

void TestStudent(){
	student stu1;
}

void TestSeqList(){
	SeqList s(5);

}

int main(){
	//TestSeqList();

	TestStudent();
	return 0;
}