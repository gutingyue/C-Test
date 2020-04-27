#include "Person.h"


void Person::SetPerson(char* name, char* gender, int age){
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}