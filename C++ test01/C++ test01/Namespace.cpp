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
	//int c = a + b + d;  此处N3中的d无法使用
}

int test1(){ //验证using在函数中使用的效果
	using namespace N2::N3;
	int add = Add(a, b);
	return add;
}

void test2(){
	using namespace N2;
	//int add2 = Add(a, b);
	//引入N2无法使用N2中嵌套的N3中的内容
}

using N1::c;

int main(){
	int a = 10;
	printf("main: a=%d\n", a);//就近原则，a就是main()中的变量a

	printf("从N1中引入的全局变量c：%d\n", c);

	printf("N2::N3 ：a=%d\n", N2::N3::a);
	printf("N3 Add:1+2=%d\n", N2::N3::Add(1, 2));//使用N3空间中的Add()

	printf("(通过函数调用）N3: a+b=%d\n", test1());

	system("pause");
	return 0;
}