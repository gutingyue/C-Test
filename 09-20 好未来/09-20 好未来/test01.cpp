#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	* @param nums int整型vector
	* @return int整型
	*/
	int thirdMax(vector<int>& nums) {
		// write code here
		int one = nums[0];
		int two = one;
		int there = one;
		for (int i = 1; i<nums.size(); i++){
			if (nums[i]>there){
				swap(there, nums[i]);
				if (there>two){
					swap(there, two);
					if (two>one){
						swap(two, one);
					}
				}
			}
		}
		if (nums.size()<3){
			return one;
		}
		else{
			return there;
		}
	}
};

//最大子序和
int maxSubArray(int* nums, int numsLen) {
	if (numsLen == 0){ return NULL; }
	if (numsLen == 1){ return nums[0]; }

	int max = nums[0];
	for (int i = 1; i < numsLen; i++){
		int count = nums[i-1];
		for (int j = i+1; j < numsLen; j++){
			count += nums[j];
			if (count>max){
				max = count;
			}
		}
	}
	return max;


}