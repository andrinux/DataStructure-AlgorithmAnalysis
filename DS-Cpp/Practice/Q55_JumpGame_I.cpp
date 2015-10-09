#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//only needs to check if reachable
class Solution_1 {
public:
	bool canJump(vector<int>& nums) {
		int i = 0, curMax = 0, lastMax = 0;
		int N = nums.size();
		while (curMax < N - 1){
			lastMax = curMax;
			while (i <= lastMax){
				curMax = max(curMax, i + nums[i]);
				i++;
			}
			if (lastMax == curMax)
				return false;
		}
		return true;
	}
};


int main()
{
	vector<int> nums;
	Solution so;
	nums = { 2, 3, 1, 1, 4 }; cout << so.canJump(nums) << endl;
	nums = { 3, 2, 1, 0, 4 }; cout << so.canJump(nums) << endl;
	return 0;
}
