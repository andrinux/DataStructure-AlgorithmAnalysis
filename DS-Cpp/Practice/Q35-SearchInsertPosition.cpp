#include <iostream>
#include <vector>
#include <string>


using namespace std;

//This is for duplicates
class Solution {
public:
	//Same with last problem. Search the range: left and right.
	//If left,right not equal to target, then this is the insert position.
	// Do we need to assume NO-DUPLICATES?
	int searchInsert(vector<int>& nums, int target) {
		int M = nums.size();
		if (M == 0)
			return 0;
		//Search for the right position
		int low = 0, up = M - 1, mid = 0;
		while (low <= up){
			mid = (low + up) / 2;
			if (target >= nums[mid])
				low = mid + 1;
			else
				up = mid - 1;
		}
		int right = low - 1;

		//If with duplicates: place target before right.
		//If found
		if (right >=0 && target == nums[right])
			return right;
		else
			return right+1;

	}
};

int main()
{
	vector<int> nums = { 1, 3,3,3,3,3, 5, 6 };
	Solution so;
	cout << so.searchInsert(nums, 7) << endl;
	return 0;
}