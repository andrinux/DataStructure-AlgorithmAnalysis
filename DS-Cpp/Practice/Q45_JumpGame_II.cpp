#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Very ugly code: TLE. O(N^2)
class Solution_1 {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		int cur = 0;
		int step = 0;
		int M = nums.size();
		while (cur < M - 1){

		}
		return step;
	}
};

// A cleaner method.
class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0, curMax = 0, lastMax = 0;
		int i = 0;
		int N = nums.size();
		while (curMax < N - 1){
			lastMax = curMax;
			while (i <= lastMax){
				curMax = max(curMax, i + nums[i]);
				i++;
			}
			step++;
		}
		return step;
	}
};

int main()
{
	vector<int> nums = { 2, 3 , 1, 1, 4 };
	Solution so;
	cout << so.jump(nums) << endl;
	return 0;
}
