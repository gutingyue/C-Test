#include <iostream>
#include <vector>
#include <assert.h>

namespace mybitset
{
	template <size_t N> //N为位数
	class bitset{
	public:
		bitset()
			:array(N/8+1)
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

			array[byte] |= (1 << bit); //1向左移bit位
			_count++;
		}

		//将pos位置置0
		void reset(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //哪个字节
			size_t bit = pos % 8; //哪个比特位
											//1100 1010
											//0000 1000  1左移bit位
			array[byte] &= (!(1 << bit)); //1111 0111  取反
			_count--;
		}

		//检测pos位置比特位是否为1
		bool test(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //哪个字节
			size_t bit = pos % 8; //哪个比特位
											//1100 1010
			if (array[byte] &= (1 << bit)){ //0000 1000 
				return true;
			}
			return false;
		}

	private:
		std::vector<char> array; //一个char占一个比特位
		size_t _count; //比特位为1的总数
	};
}

void taseBit(){
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

int main(){
	taseBit();

	return 0;
}