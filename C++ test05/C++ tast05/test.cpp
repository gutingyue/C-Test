#include "Person.h"

/*
void ForTest(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	��Χfor
	for (auto& a : arr){
		a++;
		cout << a << " ";
	}
} 
*/

struct Student{ //ѧ����
	//ѧ�������ʼ��
	void SetStudent(char* name,int age){
		cout << this << endl;//��֤���ز���this

		strcpy(_name, name);
		_age = age;
	}

	void StudentPrint(){ //ʵ�ʴ˴�����һ�����ز���Student* count this
		cout << "my name is " << _name << endl; //�˴� _name ʵ��Ϊ this->_name
		cout << "I am " << _age << " years old." << endl;
	}

	char _name[10];
	int _age;
};
int main(){
	Student s1;
	s1.SetStudent("Toin", 21);
	s1._age = 22;
	s1.StudentPrint();

	Person p1;
	p1.SetPerson("Bear", "man", 16);
	p1.SetPerson("Toin", "man", 20);

	int Size_p1=sizeof(p1);
	cout << "size of p1 " << Size_p1 << endl;//10+10+4 = 24
	return 0;
}