#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
* Method-1: Use three times of Binary Search.
//Ref: (1) http://www.cnblogs.com/springfor/p/3857704.html
*/
class Solution_1 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = { -1, -1 };
		int M = nums.size();
		if (M == 0)
			return res;
		//Search target first
		int low = 0, up = M - 1, mid = 0;
		int pos = 0;
		while (low <= up){
			mid = (low + up) / 2;
			if (target == nums[mid]){
				pos = mid;
				break;
			}
			else if (target > nums[mid])
				low = mid + 1;
			else
				up = mid - 1;
		}
		if (low > up)
			return vector<int>(2, -1);
		//Now we get a position of target @ pos.
		//Determine the left boundary
		int left = 0;
		low = 0; up = pos;
		while (low <= up){
			mid = (low + up) / 2;
			if (nums[mid] == target)
				up = mid - 1;
			else
				low = mid + 1;
		}
		left = up + 1;

		//Determine the right boundary
		int right = 0;
		low = pos; up = M - 1;
		while (low <= up){
			mid = (low + up) / 2;
			if (target == nums[mid])
				low = mid + 1;
			else
				up = mid - 1;
		}

		right = low - 1;
		res[0] = left; res[1] = right;
		return res;
	}
};




//   M A I N Function here.
int main()
{
	vector<int> nums = { 1, 2, 7, 7, 7, 7, 7, 8, 9, 10 };
	int target = 1;
	Solution so;
	cout << so.searchRange(nums, target)[0] << " " << so.searchRange(nums, target)[1] << endl;
	return 0;
}
