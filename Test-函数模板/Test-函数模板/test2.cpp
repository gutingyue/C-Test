#include <iostream>
using namespace std;

template <class T>
T Add(T left, T right){
	cout << "����ģ�����ɺ���Add:  ";
	cout << (left + right) << endl;
	return left + right;
}

template <class T1,class T2>
T1 Add(T1 left, T2 right){
	return left + right;
}


int Add(int left, int right){
	cout << "����ȫ�ֺ���Add" << endl;
	return left + right;
}


int main(){
	int num1 = Add(1, 2); //���ģ�庯��ƥ�䣬����������ͨ��ģ������
	Add<int>(1, 1); //���ñ������ػ���Add�汾

	int num2 = Add('1', '2'); //��������ģ����ʽʵ���� Add<char>()

	//int num3 = Add(1, 2.0); //ģ�岻���������ת��

	int num4 = Add<int>(1, 3.0); //��ʾʵ����
	int num5 = Add(1, (int)4.0);

	return 0;
}
