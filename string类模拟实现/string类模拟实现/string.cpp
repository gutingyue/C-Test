#include <iostream>
using namespace std;

#include <assert.h>

namespace Str
{
	class String{
	public:
		String(const char* s = "") //���û�δ���Σ�Ĭ�Ϲ�����ַ���
		{
			if (s == nullptr) //�û����ݿ�ָ��
			{
				_str = new char[1]; //������ʱ��delete[]��Ӧ����new[]����һ���ַ��ռ�
				*_str = '\0'; //���'\0'
			}
			else
			{
				_str = new char[strlen(s) + 1]; //������һ���ռ�������'\0'
				strcpy(_str, s); //��s������_strָ��Ŀռ�
			}

			_size = strlen(_str);
			_capacity = _size;
		}


		//String(const String& s) //�������캯��(��ͳд����
		//	:_str(new char[strlen(s._str)+1]) //��ָ�򿪱ٿռ��ָ���ʼ��_str
		//{
		//	strcpy(_str, s._str); //���
		//}
		String(const String& s) //�������캯������д����
			:_str(nullptr), _size(0), _capacity(0)
		{
			String StrTmp(s._str);//ʹ��s�е��ַ����������ַ���
			this->Swap(StrTmp);//swap(_str, StrTmp._str); //��������ָ��ָ��
		}


		//String& operator=(const String& s) //����ͳд����
		//{
		//	if (this != &s){
		//		delete[] _str; //�ͷ�ԭ�ռ�
		//		_str = new char[strlen(s._str) + 1]; //��_str��������s._str�����¿ռ�
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}
		String& operator=(String s) //�������ã����ʵ������ʱ�������ε��ù��캯���γ��β�s
		{
			//����s2=s1; s��s1����ʱ��������������������
			this->Swap(s); //��������ָ��ָ��
			return *this;
		}

		/////////////////////////////////////////////////////////////
		//iterator ������
		typedef char* iterator; //�˴�����д��ģ����ʽ

		iterator begin(){ return _str; }  //begin��end ��������ҿ�[ )
		iterator end(){ return _str + _size; }


		//////////////////////////////////////////////
		//capacity ��������
		size_t Size()const{ return  _size; }
		size_t Capacityz()const{ return _capacity; }

		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity){
				auto Tmpstr = new char[newCapacity + 1];
				strcpy(Tmpstr, _str); //�����¿ռ䣬����ԭ���ַ���

				delete _str; //�ͷžɿռ�
				_str = Tmpstr;
				_capacity = newCapacity;
			}
		}

		void Resize(size_t newSize, char* c);


		//////////////////////////////////////////////////////////////
		//modify �޸Ĳ���
		//β��
		void push_back(const char c)
		{
			if (_size >= _capacity) //����Ƿ���Ҫ����
				Reserve(_capacity * 2);

			_str[_size++] = c;
			_str[_size] = '\0'; //�����һ���ַ���Ϊ'\0'
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


		//��posλ�ò����ַ�c/�ַ���str
		String& insert(size_t pos, char c){
			if (_size >= _capacity) //����Ƿ���Ҫ����
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

		//����
		void Swap(String& s){
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		///////////////////////////////////////////////////////////
		//���������
		String& operator+=(const char c);

		bool operator<(const String& s);
		bool operator>(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);

		//�±������
		char& operator[](size_t index)
		{
			assert(index < _size); //�±�ҪС����ЧԪ�ظ���
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
				delete[] _str; //�ͷſռ�
				_str = nullptr; //ָ��ָ���
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



//���캯������
void Test1(){ 
	Str::String s1; //�޲ι��죬���ô�����
	cout << "s1:" << s1 << endl;

	Str::String s2("123456");
	cout << s2 << endl;
	s2 = s1;
	cout << s2 << endl;
}

//�޸Ĳ�������
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