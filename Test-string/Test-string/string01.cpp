#include <iostream>
#include <string>

using namespace std;

//string�еĹ��캯��
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
	s.resize(10); //size=10,capacity���� =31
}

//�ַ����޸Ĳ���
void Test3(){ 
	string s;
	const string s1("I love you");
	
	s.push_back('I');//push_back׷�ӵ����ַ�
	s.append(" "); //append׷���ַ���
	s.append(s1, 2, 5); //׷��s1�дӵ������ַ���ʼ��4���ַ�
	s += "China";
	s.append(2, '!');//׷��2��'!'

	cout << s << endl;
}




int main(){
	//Test1();
	//Test2();
	Test3();

	return 0;
}