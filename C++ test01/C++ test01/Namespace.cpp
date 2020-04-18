#include <stdio.h>
#include <Windows.h>

namespace N1{
	int a = 1;
	int b = 1;
	int c = 1;
}

namespace N2{
	int a = 2;
	int b = 2;

	namespace N3{
		int a = 3;
		int b = 3;
		int d = 3;
		int Add(int x, int y){
			return x + y;
		}
	}
	//int c = a + b + d;  �˴�N3�е�d�޷�ʹ��
}

int test1(){ //��֤using�ں�����ʹ�õ�Ч��
	using namespace N2::N3;
	int add = Add(a, b);
	return add;
}

void test2(){
	using namespace N2;
	//int add2 = Add(a, b);
	//����N2�޷�ʹ��N2��Ƕ�׵�N3�е�����
}

using N1::c;

int main(){
	int a = 10;
	printf("main: a=%d\n", a);//�ͽ�ԭ��a����main()�еı���a

	printf("��N1�������ȫ�ֱ���c��%d\n", c);

	printf("N2::N3 ��a=%d\n", N2::N3::a);
	printf("N3 Add:1+2=%d\n", N2::N3::Add(1, 2));//ʹ��N3�ռ��е�Add()

	printf("(ͨ���������ã�N3: a+b=%d\n", test1());

	system("pause");
	return 0;
}