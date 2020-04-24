#include "Person.h"

/*
void ForTest(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	范围for
	for (auto& a : arr){
		a++;
		cout << a << " ";
	}
} 
*/

struct Student{ //学生类
	//学生对象初始化
	void SetStudent(char* name,int age){
		strcpy(_name, name);
		_age = age;
	}

	void StudentPrint(){
		cout << "my name is " << _name << endl;
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