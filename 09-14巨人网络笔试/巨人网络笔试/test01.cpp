//将矩阵逆时针旋转90度
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
	string s;
	getline(cin, s);
	
	//[[0,1,2],[3,4,5],[6,7,8]]
	int i = 0;
	for (int n = 0; n < s.size(); n++){
		if (s[n] == '['){
			i++;
		}
	}
	i -= 1;
	int j = (s.size() - 2 - i * 2 - (i - 1))/i;
	if (j!=1) j = j - j / 2;

	vector<vector<int>> nums(i, vector<int>(j, 0));
	int n = 0;
	i = 0;
	j = 0;
	for (; n < s.size(); n++){
		if (s[n] >= 48 && s[n] < 58){
			if (j>=nums[0].size()){
				j = 0;
				i++;
			}
			nums[i][j] = s[n] - 48;
			j++;
		}
	}
	
	vector<vector<int>> ret(nums[0].size(), vector<int>(nums.size(), 0));
	int rx = ret.size();
	int ry = ret[0].size();
	for (int y = 0; y < nums.size(); y++){
		for (int x = 0; x < nums[0].size(); x++){
			ret[ry - x][rx-y] = nums[x][y];
		}
	}


	return 0;
}