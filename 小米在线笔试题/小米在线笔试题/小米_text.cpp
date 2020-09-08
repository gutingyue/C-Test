//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//vector < char > pokersort(vector < char > pokers) {
//	vector<int> poker(76, 0);
//	for (int i = 0; i < pokers.size(); i++){
//		poker[pokers[i]]++;//以ascii码为下标
//	}
//	vector<char> ret(poker.size());
//	for (int j = 51; j < 59; j++){
//		while (poker[j]){
//			ret.push_back(j);
//			poker[j]--;
//		}
//	}
//	for (int j = 74; j < 77; j++){
//		while (poker[j]){
//			ret.push_back(j);
//			poker[j]--;
//		}
//	}
//	while (poker[65]){
//		ret.push_back(65);
//		poker[65]--;
//	}
//	while (poker[50]){
//		ret.push_back(50);
//		poker[50]--;
//	}
//	return ret;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//	vector < char > res;
//
//	int size = 0;
//	cin >> size;
//	for (int i = 0; i<size; i++) {
//		char poker;
//		cin >> poker;
//
//		res.push_back(poker);
//	}
//
//	res = pokersort(res);
//	for (int res_i = 0; res_i < res.size(); res_i++) {
//		cout << res[res_i] << endl;;
//	}
//
//	return 0;
//
//}


#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; i++){
		cin >> vs[i];
	}
	string s;
	getline(cin, s);

	vector<string> encode;
	auto frist = s.begin();
	auto last = frist;
	int i = 0;
	while (last!=s.end()){
		if (*last != ' '){
			last++;
		}
		string s(frist, last);
		encode[i]=s;
	}

	



	return 0;
}

