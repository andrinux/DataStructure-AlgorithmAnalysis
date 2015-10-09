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

//A easier code.
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int curMax = 0, i = 0;
		int N = nums.size();
		for (i = 0; i < N; i++){
			if (i> curMax || curMax >= N - 1) //i>curMax 很关键.说明curMax走不动了.
				break;
			curMax = max(curMax, i + nums[i]);
		}
		if (curMax >= N - 1)
			return true;
		else
			return false;
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
