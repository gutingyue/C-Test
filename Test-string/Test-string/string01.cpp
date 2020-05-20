#include <iostream>
#include <string>

using namespace std;

//string中的构造函数
void Test1(){ 

	string s1();
	string s2("hello ");
	string s3 = "word!";
	string s4(5, '!');

	
	cout << s2 << s3 << s4 << endl;
}

//resize()/reserve()
void Test2(){  
	string s = "little";

	s.reserve(20);

	s.resize(20, '!');
	s.resize(10); //size=10,capacity不变 =31
}

//字符串修改操作
void Test3(){ 
	string s;
	const string s1("I love you");
	
	s.push_back('I');//push_back追加单个字符
	s.append(" "); //append追加字符串
	s.append(s1, 2, 5); //追加s1中从第三个字符开始的4个字符
	s += "China";
	s.append(2, '!');//追加2个'!'

	cout << s << endl;
}




int main(){
	//Test1();
	//Test2();
	Test3();

	return 0;
}