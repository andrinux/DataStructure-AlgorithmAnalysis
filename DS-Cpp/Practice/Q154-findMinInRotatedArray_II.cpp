#include <iostream>
#include <vector>
#include <algorithm>

//Ref: http://bangbingsyb.blogspot.com/2014/11/leecode-find-minimum-in-rotated-sorted.html

using namespace std;

//A cleaner method.
class Solution{
public:
	int findMin(vector<int> nums){
		int M = nums.size();
		if (M == 0) return 0;
		if (M == 1) return nums[M - 1];
		int low = 0, mid = 0, up = M - 1;
		while (up > low){
			mid = (up + low) / 2;
			if (nums[mid] < nums[up])
				up = mid;
			else if (nums[mid] > nums[up])
				low = mid + 1;
			else
				up = up - 1;
		}
		return nums[low];
	}
};



int main()
{
	Solution so;
	//
	vector<int> nums = { 24, 25, 28, 30, 32, 34, 43, 46, 48, 53, 55, 57, 58, 59, 60, 1, 3, 4, 5, 6, 7, 13, 16, 17, 19, 21, 23 };
	cout << so.findMin(nums) << endl;
	return 0;
}