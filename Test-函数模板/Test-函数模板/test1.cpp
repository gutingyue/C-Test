#include <iostream>
using namespace std;

//一个并没有什么用的测试

class Student
{
public:
	Student(char* name, int age)
		:_name(name), _age(age)
	{}

	void Printf()
	{
		cout << "I am a student ,";
		cout << "my name is " << _name << endl;
	}
private:
	char* _name;
	int _age;
};

class Teacher
{
public:
	Teacher(char* name, int age)
		:_name(name), _age(age)
	{}

	void Printf()
	{
		cout << "I am a teacher ,";
		cout << "my name is " << _name << endl;
	}
private:
	char* _name;
	int _age;
};

template<class T> //打印模板
void Printf(T& people){
		people.Printf();
}



//int main(){
//	Student s1("Tom", 19);
//	Printf(s1);
//
//	Teacher t1("Li", 35);
//	Printf(t1);
//
//	return 0;
//}