#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Method-1: SearchMin first, and then do binary search.
//这个方法不是很好，最坏的情况下要先后做两次O(n)的查找。
class Solution_1 {
public:
	int findMin(vector<int> nums){
		int M = nums.size();
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
		return low;
	}

	bool search(vector<int>& nums, int target) {
		int M = nums.size();
		if (M == 0) return false;

		int idx = findMin(nums);
		int low = 0, mid = 0, up = M - 1;

		//idx would be duplicated value. 
		//so it is a bit tricky to find the start of target value. Do we need to do that?
		//Determine an asceding sub array to find it.
		if (target == nums[idx])
			return true;
		if (idx >0 && target >= nums[low] && target <= nums[idx - 1])
			up = idx - 1;
		else
			low = idx + 1;
		
		//Do a binary Search
		while (low <= up){
			mid = (low + up) / 2;
			if (target == nums[mid])
				return true;
			else if (target > nums[mid])
				low = mid + 1;
			else
				up = mid - 1;
		}
		return false;
	}
};




int main()
{
	Solution so;	
	vector<int> nums = { 1,1,1,1,1,1,1,1,2,1,1,1};
	cout << so.search(nums, 2) << endl;
	return 0;
}
