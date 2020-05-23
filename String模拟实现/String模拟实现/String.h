#include <iostream>
using namespace std;


namespace str{
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
				_str = new char[strlen(s)+1]; //多申请一个空间来保存'\0'
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
		String& operator=( String s) //不传引用，会对实进行临时拷贝，参调用构造函数形成形参s
		{
			//例：s2=s1; s是s1的临时拷贝，函数结束被析构
			this->Swap(s); //交换两个指针指向
			return *this;
		}

		/////////////////////////////////////////
		//iterator 迭代器
		typedef char* iterator; //此处可以写成模板形式
		iterator begin(){ return _str; }  //begin和end 区间左闭右开[ )
		iterator end(){ return _str + _size; }

		/////////////////////////////////////////
		//modify 修改操作
		//尾插
		void push_back(char c);
		void push_back(const char* s);
		void push_back(String& s);
		
		String& operator+=(char c);

		void Swap(String& s);

		~String()
		{
			if (_str){
				delete[] _str; //释放空间
				_str = nullptr; //指针指向空
			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};
}
