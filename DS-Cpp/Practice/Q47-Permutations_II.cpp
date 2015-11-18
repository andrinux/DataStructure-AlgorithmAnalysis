#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool checkExist(vector<int>& nums, int start, int end){
		for (int i = start; i < end; i++){
			if (nums[end] == nums[i])
				return true;
		}
		return false;
	}
	// Find all Permutations.
	void findPermute(vector<int>& nums, int start, vector<vector<int>> &res){
		int N = nums.size();
		if (start == N){
			res.push_back(nums);
			return;
		}
		else{
			for (int i = start; i < N; i++){
				if (!checkExist(nums, start, i)){
					swap(nums[i], nums[start]);
					findPermute(nums, start + 1, res);
					swap(nums[i], nums[start]);
				}
			}
		}
	}
	// All unique permutations.
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;
		//sort(nums.begin(), nums.end());
		findPermute(nums, 0, res);
		return res;
	}
};


int main()
{
	vector<int> nums = { 1, 2, 2, 4 };
	Solution so;
	int i = 1;
	vector<vector<int> > res = so.permuteUnique(nums);
	for (auto vec : res){
		cout << i++ << " : ";
		for (auto val : vec)
			cout << val << " ";
		cout << endl;
	}
}