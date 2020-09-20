#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	* @param nums int����vector
	* @return int����
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

//��������
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