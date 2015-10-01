#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

/*
* Very Ugly Code. Not clear to figure out.
*/
class Solution_1 {
public:
	int BinSearch(vector<int> & nums, int target, int low, int up){
		int M = nums.size();
		int  mid = 0;
		while (low <= up){
			mid = (low + up) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				up = mid - 1;
		}
		return -1;
	}
	//search a value recursively
	int do_search(vector<int> &v, int target, int low, int up){
		if (low > up)
			return -1;
		if (low == up && target != v[low])
			return -1;
		int mid = (low + up) / 2;
		if (v[low] == target){
			return low;
		}
		if (v[low] < target){
			if (v[mid] >= target)
				return BinSearch(v, target, low + 1, mid);
			else if (v[up] >= target)
				return do_search(v, target, mid + 1, up);
			else
				return do_search(v, target, low + 1, mid - 1);
		}
		if(v[low]>target){//v[low]>target
			if (v[mid] <= target)
				return BinSearch(v, target, mid, up);
			else if (v[low] > v[mid])
				return do_search(v, target, low + 1, mid);
			else
				return do_search(v, target, mid + 1, up);
		}
	}
	int search(vector<int>& nums, int target) {
		int M = nums.size();
		if (M < 1)
			return -1;
		return do_search(nums, target, 0, M-1);
	}
	
};


class Solution_2 {
public:
	/*
	* No duplicated elements.
	*/

	int BinSearch(vector<int> & nums, int target, int low, int up){
		int M = nums.size();
		int  mid = 0;
		while (low <= up){
			mid = (low + up) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				up = mid - 1;
		}
		return -1;
	}

	int do_search(vector<int>& v, int target, int low, int up){
		int mid = 0 ;
		//First Case: 
		while (low <= up){
			if (v[low] <= v[up])
				//Binary Search
				return BinSearch(v, target, low, up);
			if (v[low] > v[up]){
				mid = (low + up) / 2;
				if (target == v[low]) return low;
				if (target == v[up]) return up;
				if (target == v[mid]) return mid;
				if (v[mid] >= v[low]){
					if (target > v[low] && target < v[mid]){
						low = low + 1; up = mid - 1;
					}
					else{
						low = mid + 1; up = up - 1;
					}
				}
				else{
					if (target > v[mid] && target < v[up]){
						low = mid + 1; up = up - 1;
					}
					else{
						low = low + 1; up = mid - 1;
					}
				}
			}
		}

		return -1;
	}

	int search(vector<int>& nums, int target) {
		int M = nums.size();
		if (M < 1)
			return -1;
		return do_search(nums, target, 0, M - 1);
	}
};

//Find The Min first
class Solution {
public:
	int findMin(vector<int>& nums) {
		int M = nums.size();
		if (M == 0) return 0;
		if (M == 1) return M-1;
		int low = 0, mid = 0, up = M - 1;
		while (up - low > 1){
			mid = (up + low) / 2;
			if (nums[mid] < nums[up]) //Here should be < up.
				up = mid;
			else
				low = mid;
		}
		return (nums[up] < nums[low]) ? up : low;
	}

	int do_search(vector<int>& v, int target, int low, int up){
		int idx = findMin(v);
		//Determine the range to search
		if (idx > 0){
			if (target >= v[low] && target <= v[idx - 1])
				up = idx - 1;
			else
				low = idx;
		}
		//Do a binary Search
		int mid = 0;
		while (low <= up){
			mid = (low + up) / 2;
			if (target == v[mid])
				return mid;
			else if (target>v[mid])
				low = mid + 1;
			else
				up = mid - 1;
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int M = nums.size();
		if (M < 1)
			return -1;
		return do_search(nums, target, 0, M - 1);
	}
};


int main()
{ 
	Solution so;	// ,
	vector<int> nums = { 24, 25, 28, 30, 32, 34, 43, 46, 48, 53, 55, 57, 58, 59, 60 ,1,2,3,4,5,6,9,12,15,18,22};
	int target = 3;
	for (int k = 0; k <60 ; k++){
		target = k;
		cout << target << ":" << so.search(nums, target) << " - ";
		for (int i = 0; i < nums.size(); i++){
			if (target == nums[i])
				cout << i;
		}
		cout << endl;
	}
	
	return 0;
}
