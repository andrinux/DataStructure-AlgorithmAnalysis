#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//One way DP Method.
class Solution_1 {
public:
	int maxSubArray(vector<int>& nums) {
		int M = nums.size();
		//max value will be negative, so we need to intialize it as INT_MIN
		int curSum = 0, maxSum = INT_MIN;
		for (int i = 0; i < M; i++){
			curSum = curSum + nums[i];
			if (curSum > maxSum)
				maxSum = curSum;
			if (curSum <= 0)
				curSum = 0;
		}
		return maxSum;
	}
};

//Divide and Conquer Method.
class Solution {
public:
	int maxSubArray(vector<int>& nums) {

	}
};

int main()
{
	vector<int> nums = { -2, -1};
	Solution so;
	cout << so.maxSubArray(nums) << endl;
	return 0;
}