#include <iostream>
using namespace std;

#include <vector>

void TestVector1(){
	vector<int> v1;

	vector<char> v2(5, '1'); //5个1
	vector<int> v3(10); //第二个参数没给，默认用0填充

	int array[] = { 1, 2, 3, 4 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 0, 1, 2, 3 };
	for (auto e : v5)
		cout << e;
	cout << endl;
}

//测试vector容量相关操作
void TestVector2(){

	vector<int> v1{ 1, 2, 3, 4 };
	v1.reserve(5); //size=4 , capacity=5
	//v1.reserve(20); //capacity=20

	v1.resize(6, 5); //size=6 , capacity=7  1,2,3,4,5,5
	v1.resize(10); //第二个参数没给，默认用0填充 size=10 , capacity=10
	v1.resize(4); //size=4 , capacity=10 1,2,3,4


	//检测每次自动扩容的大小
	vector<int> v2{ 0 };
	v2.reserve(100);// 若知道大概要插入多少元素，最好直接给好容量，避免多次扩容，影响效率

	size_t sz = v2.capacity();//获取容量
	for (int i = 1; i < 100; i++){
		v2.push_back(0);
		if (sz != v2.capacity())//若发生扩容
		{
			cout << "Capacity:" << v2.capacity() << endl;
			sz = v2.capacity();
		}
	}
}

//测试vector增删改查相关操作
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

	v1.insert(v1.end(), 3, 1); //尾插3个1

	//C++11中提供列表方式的插入
	v1.insert(v1.end(), { 7, 8, 9 });

}

void TestVector4(){
	vector<int> v1 = { 1, 2, 3, 4 };
	
	//v1.erase(v1.end());//end()处没有有效元素
	v1.erase(v1.begin());

	//v1.clear(); //清空元素
	v1.erase(v1.begin(), v1.end());

}

//迭代器失效
void TestVector5(){
	vector<int> v1{ 0, 1, 2, 3, 4 };
	vector<int>::iterator pos = v1.begin() + 1;
	cout << *pos << endl; // 1
	
	//v1.erase(pos); //erase()会使迭代器失效
	pos=v1.erase(pos); //使用erase()后，要重新给pos赋值
	cout << *pos << endl;

}

//vector二维数组
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

//杨辉三角
vector<vector<int>> generate(int numRows){
	vector<vector<int>> vv;
	vv.resize(numRows);

	for (size_t row = 0; row < numRows ; row++){
		vv[row].resize(row + 1);//每一行元素个数为行号加1

		vv[row][0] = 1;
		vv[row][row] = 1;
	}

	for (size_t row = 2; row < numRows ; row++){ //从第三行开始，给其他元素赋值
		for (size_t i = 1; i < vv[row].size() - 1; i++){ //每行从第二个元素开始赋值
			vv[row][i] = vv[row - 1][i] + vv[row - 1][i - 1]; //其他元素的值为： 上一行元素 + 上一行元素的上一个元素
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