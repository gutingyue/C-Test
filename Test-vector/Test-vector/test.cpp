#include <iostream>
using namespace std;

#include <vector>

void TestVector1(){
	vector<int> v1;

	vector<char> v2(5, '1'); //5��1
	vector<int> v3(10); //�ڶ�������û����Ĭ����0���

	int array[] = { 1, 2, 3, 4 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 0, 1, 2, 3 };
	for (auto e : v5)
		cout << e;
	cout << endl;
}

//����vector������ز���
void TestVector2(){

	vector<int> v1{ 1, 2, 3, 4 };
	v1.reserve(5); //size=4 , capacity=5
	//v1.reserve(20); //capacity=20

	v1.resize(6, 5); //size=6 , capacity=7  1,2,3,4,5,5
	v1.resize(10); //�ڶ�������û����Ĭ����0��� size=10 , capacity=10
	v1.resize(4); //size=4 , capacity=10 1,2,3,4


	//���ÿ���Զ����ݵĴ�С
	vector<int> v2{ 0 };
	v2.reserve(100);// ��֪�����Ҫ�������Ԫ�أ����ֱ�Ӹ������������������ݣ�Ӱ��Ч��

	size_t sz = v2.capacity();//��ȡ����
	for (int i = 1; i < 100; i++){
		v2.push_back(0);
		if (sz != v2.capacity())//����������
		{
			cout << "Capacity:" << v2.capacity() << endl;
			sz = v2.capacity();
		}
	}
}

//����vector��ɾ�Ĳ���ز���
void TestVector3(){
	vector<int> v1{ 1, 2, 3, 4 };
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it++;
	}
	cout << endl;

	v1.pop_back();

	v1.push_back(5);

	auto pos = find(v1.begin(), v1.end(), 5);
	v1.insert(pos, 4);

	int array[] = { 0, 0, 0, 0 };
	v1.insert(v1.begin(), array, array + sizeof(array) / sizeof(array[0]));

	v1.insert(v1.end(), 3, 1); //β��3��1

	//C++11���ṩ�б�ʽ�Ĳ���
	v1.insert(v1.end(), { 7, 8, 9 });

}

void TestVector4(){
	vector<int> v1 = { 1, 2, 3, 4 };
	
	//v1.erase(v1.end());//end()��û����ЧԪ��
	v1.erase(v1.begin());

	//v1.clear(); //���Ԫ��
	v1.erase(v1.begin(), v1.end());

}

//������ʧЧ
void TestVector5(){
	vector<int> v1{ 0, 1, 2, 3, 4 };
	vector<int>::iterator pos = v1.begin() + 1;
	cout << *pos << endl; // 1
	
	//v1.erase(pos); //erase()��ʹ������ʧЧ
	pos=v1.erase(pos); //ʹ��erase()��Ҫ���¸�pos��ֵ
	cout << *pos << endl;

}

//vector��ά����
void TestVector6(){
	vector<vector<char>> cv;
	cv.resize(5,vector<char>(7,'*'));
	for (size_t i = 0;i<cv.size();i++){
		for (size_t j = 0;j<cv[i].size();j++){
			cout << cv[i][j] ;
		}
		cout << endl;
	}
}

//�������
vector<vector<int>> generate(int numRows){
	vector<vector<int>> vv;
	vv.resize(numRows);

	for (size_t row = 0; row < numRows ; row++){
		vv[row].resize(row + 1);//ÿһ��Ԫ�ظ���Ϊ�кż�1

		vv[row][0] = 1;
		vv[row][row] = 1;
	}

	for (size_t row = 2; row < numRows ; row++){ //�ӵ����п�ʼ��������Ԫ�ظ�ֵ
		for (size_t i = 1; i < vv[row].size() - 1; i++){ //ÿ�дӵڶ���Ԫ�ؿ�ʼ��ֵ
			vv[row][i] = vv[row - 1][i] + vv[row - 1][i - 1]; //����Ԫ�ص�ֵΪ�� ��һ��Ԫ�� + ��һ��Ԫ�ص���һ��Ԫ��
		}
	}

	return vv;
}

int main(){

	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();

	vector<vector<int>> vv=generate(5);
	for (size_t i = 0; i < vv.size(); i++){
		for (size_t j = 0; j < vv[i].size(); j++){
			cout << vv[i][j];
		}
		cout << endl;
	}

	return 0;
}