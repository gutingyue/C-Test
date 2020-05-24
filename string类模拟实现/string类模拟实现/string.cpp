#include <iostream>
using namespace std;

#include <assert.h>

namespace Str
{
	class String{
	public:
		String(const char* s = "") //若用户未传参，默认构造空字符串
		{
			if (s == nullptr) //用户传递空指针
			{
				_str = new char[1]; //与析构时的delete[]对应，用new[]申请一个字符空间
				*_str = '\0'; //存放'\0'
			}
			else
			{
				_str = new char[strlen(s) + 1]; //多申请一个空间来保存'\0'
				strcpy(_str, s); //将s拷贝到_str指向的空间
			}

			_size = strlen(_str);
			_capacity = _size;
		}


		//String(const String& s) //拷贝构造函数(传统写法）
		//	:_str(new char[strlen(s._str)+1]) //用指向开辟空间的指针初始化_str
		//{
		//	strcpy(_str, s._str); //深拷贝
		//}
		String(const String& s) //拷贝构造函数（新写法）
			:_str(nullptr), _size(0), _capacity(0)
		{
			String StrTmp(s._str);//使用s中的字符串构造新字符串
			this->Swap(StrTmp);//swap(_str, StrTmp._str); //（仅交换指针指向）
		}


		//String& operator=(const String& s) //（传统写法）
		//{
		//	if (this != &s){
		//		delete[] _str; //释放原空间
		//		_str = new char[strlen(s._str) + 1]; //给_str重新依照s._str开辟新空间
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
		String& operator=(String s) //不传引用，会对实进行临时拷贝，参调用构造函数形成形参s
		{
			//例：s2=s1; s是s1的临时拷贝，函数结束被析构
			this->Swap(s); //交换两个指针指向
			return *this;
		}

		/////////////////////////////////////////////////////////////
		//iterator 迭代器
		typedef char* iterator; //此处可以写成模板形式

		iterator begin(){ return _str; }  //begin和end 区间左闭右开[ )
		iterator end(){ return _str + _size; }


		//////////////////////////////////////////////
		//capacity 容量操作
		size_t Size()const{ return  _size; }
		size_t Capacityz()const{ return _capacity; }

		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity){
				auto Tmpstr = new char[newCapacity + 1];
				strcpy(Tmpstr, _str); //申请新空间，拷贝原有字符串

				delete _str; //释放旧空间
				_str = Tmpstr;
				_capacity = newCapacity;
			}
		}

		void Resize(size_t newSize, char* c);


		//////////////////////////////////////////////////////////////
		//modify 修改操作
		//尾插
		void push_back(const char c)
		{
			if (_size >= _capacity) //检测是否需要扩容
				Reserve(_capacity * 2);

			_str[_size++] = c;
			_str[_size] = '\0'; //将最后一个字符置为'\0'
		}

		void push_back(const char* s)
		{

			const char* cur = s;
			while (*cur != '\0'){
				if (_size >= _capacity)
					Reserve(_capacity * 2);

				_str[_size++] = *cur++;
				_str[_size] = '\0';
			}
		}


		//在pos位置插入字符c/字符串str
		String& insert(size_t pos, char c){
			if (_size >= _capacity) //检测是否需要扩容
				Reserve(_capacity * 2);

			_str[_size + 1] = '\0';
			for (size_t cur = _size; cur != pos; cur--)
				_str[cur] = _str[cur - 1];
			_str[pos] = c;
			_size++;

			return *this;
		}

		String& insert(size_t pos, const char* s){
			Reserve(_capacity+strlen(s)+1);

			size_t cur = _size + strlen(s);
			size_t prev = _size - 1;
			_str[cur--] = '\0';
			while (prev != pos)
				_str[cur--] = _str[prev--];
			_str[cur] = _str[prev];

			cur = 0;
			while (s[cur] != '\0')
				_str[prev++] = s[cur++];

			_size += strlen(s);
			return *this;
		}

		//交换
		void Swap(String& s){
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		///////////////////////////////////////////////////////////
		//运算符重载
		String& operator+=(const char c);

		bool operator<(const String& s);
		bool operator>(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);

		//下标运算符
		char& operator[](size_t index)
		{
			assert(index < _size); //下标要小于有效元素个数
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		~String()
		{
			if (_str){
				delete[] _str; //释放空间
				_str = nullptr; //指针指向空
			}
		}

		friend std::ostream& operator<<(std::ostream& _cout, const Str::String& s);
		friend std::istream& operator>>(std::istream& _cin, Str::String& s);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};
}

ostream& Str::operator<<(std::ostream& _cout, const Str::String& s)
{
	for (size_t i = 0; i < s._size; i++)
		_cout << s[i];
	return _cout;
}

istream& Str::operator>>(std::istream& _cin, Str::String& s);



//构造函数测试
void Test1(){ 
	Str::String s1; //无参构造，不用带括号
	cout << "s1:" << s1 << endl;

	Str::String s2("123456");
	cout << s2 << endl;
	s2 = s1;
	cout << s2 << endl;
}

//修改操作测试
void Test2(){
	Str::String s1 = "123";
	s1.push_back(';');
	s1.push_back("456");
	cout << s1 << endl;

	s1.insert(0, '0');
	cout << s1 << endl;

	Str::String s2("123");
	s2.insert(1, "000");
	cout << s2 << endl;

}


int main(){
	//Test1();
	Test2();


	return 0;
}