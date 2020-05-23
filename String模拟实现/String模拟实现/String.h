#include <iostream>
using namespace std;


namespace str{
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
				_str = new char[strlen(s)+1]; //������һ���ռ�������'\0'
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
		String& operator=( String s) //�������ã����ʵ������ʱ�������ε��ù��캯���γ��β�s
		{
			//����s2=s1; s��s1����ʱ��������������������
			this->Swap(s); //��������ָ��ָ��
			return *this;
		}

		/////////////////////////////////////////
		//iterator ������
		typedef char* iterator; //�˴�����д��ģ����ʽ
		iterator begin(){ return _str; }  //begin��end ��������ҿ�[ )
		iterator end(){ return _str + _size; }

		/////////////////////////////////////////
		//modify �޸Ĳ���
		//β��
		void push_back(char c);
		void push_back(const char* s);
		void push_back(String& s);
		
		String& operator+=(char c);

		void Swap(String& s);

		~String()
		{
			if (_str){
				delete[] _str; //�ͷſռ�
				_str = nullptr; //ָ��ָ���
			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};
}
