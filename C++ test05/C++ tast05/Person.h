#pragma once

#include <iostream>
using namespace std;

//ÀàµÄÉùÃ÷
class Person{
public:
	void SetPerson(char* name, char* gender, int age);
private:
	char _name[10];
	char _gender[10];
	int _age;
};