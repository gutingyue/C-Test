#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int main() {
//	int n, m;
//
//	vector<int> nums;
//	cin >> n;
//	vector<int> nums1(n, 0);
//	for (int i = 0; i < n && cin >> nums1[i]; i++){}
//
//	cin >> m;
//	vector<int> nums2(m, 0);
//	for (int i = 0; i < m && cin >> nums2[i]; i++){}
//
//	int x = 0;
//	int y = 0;
//	for (; x < nums1.size() && y < nums2.size();){
//		if (nums1[x] == nums2[y]){
//			nums.push_back(nums1[x]);//公共数字尾插
//			x++;
//			y++;
//		}
//		else if (nums1[x]>nums2[y]){
//			x++;
//		}
//		else{
//			y++;
//		}
//	}
//	for (auto e : nums){
//		cout << e << " ";
//	}
//}
//
//
//int& median(vector<int>& nums){
//	sort(nums.begin(), nums.end());//排序
//	return nums[nums.size() / 2];
//}
//
//
//int main(){
//	int n;
//
//	cin >> n;
//	vector<int> nums(n, 0);
//	for (int i = 0; i < n && cin >> nums[i]; i++){}
//
//	for (int j = 0; j < nums.size();j++){
//		vector<int> num = nums;
//		num.erase(num.begin()+j);
//		cout << median(num) << endl;
//	}
//
//	return 0;
//}

int main(){
	int n;//总人数
	int m;//团体数
	cin >> n;
	cin >> m;
	vector<vector<int>> team(m,vector<int>(0));
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		for (int j = 0; j < x ; j++){
			int n;
			cin >> n;
			team[i].push_back(n);
		}
	}

	vector<int> num;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < team[i].size(); j++){
			if (team[i][j]==0){
				num.push_back(i);
			}
		}
	}
	for (int i = 0; i < num.size(); i++){//抽出num中的数组号
		for (int y = 0; y < team[i].size(); y++){//取出除0外的元素
			for (int j = 0; j < m&&j != i;j++){//遍历其他小团队
				for (int x = 0; x < team[j].size(); x++){
					if (team[j][x] == team[x][y]){
						num.push_back(j);
					}
				}

			}

		}
	}
	int sum = 0;
	for (int i = 0; i < num.size(); i++){
		sum += team[num[i]].size();
	}

	cout << sum << endl;
	return 0;
}