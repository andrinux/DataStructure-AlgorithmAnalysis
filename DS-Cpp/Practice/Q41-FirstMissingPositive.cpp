#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
* Ref: https://leetcodenotes.wordpress.com/2013/07/17/first-missing-positive/
* Ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-first-missing-positive.html
*/
using namespace std;

class Solution {
public:
	//swap number.
	void swapNum(vector<int>& nums, int i, int j){
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	int firstMissingPositive(vector<int>& nums) {
		int M = nums.size();
		if (M <= 0) return 1;
		//adjust the positions
		for (int i = 0; i < M; i++){
			while (!(nums[i] == i + 1 || nums[i] <= 0 || nums[i] >= M || nums[nums[i]-1] == nums[i])){
				swapNum(nums, i, nums[i]-1);
			}
		}
		int i = 0;
		//find the first unmatched.
		for (i = 0; i < M; i++)
			if (nums[i] != (i + 1) )
				return i + 1;
		//finally
		return i+1;
	}
};


int main()
{
	vector<int> nums = {1};
	Solution so;
	cout << so.firstMissingPositive(nums) << endl;
	return 0;
}