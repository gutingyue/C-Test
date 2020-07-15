#include <iostream>
#include <vector>
#include <assert.h>

//����40�ڸ��޷���������δ���򣬼��һ���޷��������Ƿ����
//ʹ��λͼ���


//�Զ����λ����
namespace mybitset
{
	template <size_t N> //NΪλ��
	class bitset{
	public:
		bitset()
			:_bit(N/8+1)
		{}

		//����λΪ1������
		size_t count(){
			return _count;
		}

		//����λ����
		size_t size(){ 
			return N;
		}

		//��posλ����1
		void set(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //�ĸ��ֽ�
			size_t bit = pos % 8; //�ĸ�����λ

			_bit[byte] |= (1 << bit); //1������bitλ
			_count++;
		}

		//��posλ����0
		void reset(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //�ĸ��ֽ�
			size_t bit = pos % 8; //�ĸ�����λ
											//1100 1010
											//0000 1000  1����bitλ
			_bit[byte] &= (!(1 << bit)); //1111 0111  ȡ��
			_count--;
		}

		//���posλ�ñ���λ�Ƿ�Ϊ1
		bool test(size_t pos){
			assert(pos < N);
			size_t byte = pos / 8; //�ĸ��ֽ�
			size_t bit = pos % 8; //�ĸ�����λ
											//1100 1010
			if (_bit[byte] &= (1 << bit)){ //0000 1000 
				return true;
			}
			return false;
		}

	private:
		std::vector<char> _bit; //һ��charռһ������λ
		size_t _count; //����λΪ1������
	};
}

void taseMyBitset(){
	size_t array[] = { 1, 6, 55, 23, 11, 12, 13 };
	mybitset::bitset<56> bt;

	for (auto e : array){ //�����������ݱ���ͳ�ƣ���Ӧ����λ��1
		bt.set(e);
	}

	std::cout << "count: " << bt.count() << std::endl;
	std::cout << "size: " << bt.size() << std::endl;

	if (bt.test(6)){
		std::cout << "6 can find" << std::endl;
	}
	bt.reset(23);

}

//ʹ�ÿ��е�bitset��
#include <bitset>

void test_bitset(){
	size_t array[] = { 1, 6, 55, 23, 11, 12, 13 };
	std::bitset<56> bt;
	for (auto e : array){ //�����������ݱ���ͳ�ƣ���Ӧ����λ��1
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