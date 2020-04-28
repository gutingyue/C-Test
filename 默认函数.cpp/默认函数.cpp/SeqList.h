#include <iostream>
#include <assert.h>
#include <malloc.h>
using namespace std;

typedef int DataType;

class SeqList{
public:
	//默认构造函数
	SeqList(int capacity=10){
		_array = (int *)malloc(sizeof(DataType)*capacity);
		assert(_array);

		_capacity = capacity;
		_size = 0;
	}

	//析构函数
	~SeqList(){
		if (_array){
			free(_array);
		}
		
		_array = nullptr;
		_size = 0;
		_capacity = 0;
	}

	int* _array;
	int _size;
	int _capacity;
};