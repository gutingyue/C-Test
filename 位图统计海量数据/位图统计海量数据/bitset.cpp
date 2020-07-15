#include <iostream>
#include <vector>
#include <assert.h>

//给定40亿个无符号整数，未排序，检测一个无符号整数是否存在
//使用位图解决


//自定义的位操作
namespace mybitset
{
	template <size_t N> //N为位数
	class bitset{
	public:
		bitset()
			:_bit(N/8+1)
		{}

		//比特位为1的总数
		size_t count(){
			return _count;
		}

		//比特位总数
		size_t size(){ 
			return N;
		}

		//将pos位置置1
		void set(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //哪个字节
			size_t bit = pos % 8; //哪个比特位

			_bit[byte] |= (1 << bit); //1向左移bit位
			_count++;
		}

		//将pos位置置0
		void reset(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //哪个字节
			size_t bit = pos % 8; //哪个比特位
											//1100 1010
											//0000 1000  1左移bit位
			_bit[byte] &= (!(1 << bit)); //1111 0111  取反
			_count--;
		}

		//检测pos位置比特位是否为1
		bool test(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //哪个字节
			size_t bit = pos % 8; //哪个比特位
											//1100 1010
			if (_bit[byte] &= (1 << bit)){ //0000 1000 
				return true;
			}
			return false;
		}

	private:
		std::vector<char> _bit; //一个char占一个比特位
		size_t _count; //比特位为1的总数
	};
}

void taseMyBitset(){
	size_t array[] = { 1, 6, 55, 23, 11, 12, 13 };
	mybitset::bitset<56> bt;

	for (auto e : array){ //将数组中数据遍历统计，相应比特位置1
		bt.set(e);
	}

	std::cout << "count: " << bt.count() << std::endl;
	std::cout << "size: " << bt.size() << std::endl;

	if (bt.test(6)){
		std::cout << "6 can find" << std::endl;
	}
	bt.reset(23);

}

//使用库中的bitset类
#include <bitset>

void test_bitset(){
	size_t array[] = { 1, 6, 55, 23, 11, 12, 13 };
	std::bitset<56> bt;
	for (auto e : array){ //将数组中数据遍历统计，相应比特位置1
		bt.set(e);
	}

	std::cout << "count: " << bt.count() << std::endl;
	std::cout << "size: " << bt.size() << std::endl;

	if (bt.test(6)){
		std::cout << "6 can find" << std::endl;
	}
	bt.reset(23);
}

int main(){
	//taseMyBitset();
	test_bitset();
	return 0;
}