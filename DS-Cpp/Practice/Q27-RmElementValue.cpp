#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;
		int i = 0, j = 0;
		for (i = 0; i < nums.size(); i++){
			if (nums[i] != val){
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}
};

int main()
{
	vector<int> nums = { 1,2,3,4,5,3,6,7,3 };
	Solution so;
	int N = so.removeElement(nums, 3);
	cout << N;
	return 1;
}