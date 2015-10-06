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



int main()
{
	vector<int> nums = { 2, 3 , 1, 1, 4 };
	Solution so;
	cout << so.jump(nums) << endl;
	return 0;
}
