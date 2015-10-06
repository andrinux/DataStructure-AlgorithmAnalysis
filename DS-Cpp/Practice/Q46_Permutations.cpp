#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//Recursion method: Use too much space. Simple to understand.
class Solution_1 {
public:
	//insert val to position p
	vector<int> insVal(vector<int>& cur, int pos, int val){
		vector<int> res;
		int i = 0;
		for (i = 0; i < pos; i++)
			res.push_back(cur[i]);
		res.push_back(val);
		for (; i < cur.size(); i++)
			res.push_back(cur[i]);
		return res;
	}

	vector<vector<int>> findPermute(vector<int>& nums, int start){
		vector<int> cur;
		vector<vector<int>> res;
		//base case
		int N = nums.size();
		if (start == N - 1){
			cur.push_back(nums[start]);
			res.push_back(cur);
			return res;
		}
		//general cases.
		vector<vector<int> > last;
		last = findPermute(nums, start + 1);
		//insert nums[start] to all the results
		for (int i = 0; i < last.size(); i++){
			for (int j = 0; j <= last[i].size(); j++){
				res.push_back(insVal(last[i], j, nums[start]));
			}
		}
		return res;

	}
	//main function
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;
		res = findPermute(nums, 0);
		return res;
	}
};

//Use the swap method.
class Solution {
public:
	//Core function
	void findPermute(vector<int>& nums, int start, vector<vector<int>> &res){
		int N = nums.size();
		if (start == N){
			res.push_back(nums);
		}
		else{
			for (int i = start; i < N; i++){
				swap(nums[start], nums[i]);
				findPermute(nums, start + 1, res);
				swap(nums[start], nums[i]);
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;
		findPermute(nums, 0, res);
		return res;
	}
};


int main()
{
	vector<int> nums = { 1, 2, 3, 4};
	Solution so;
	int i = 1;
	vector<vector<int> > res = so.permute(nums);
	for (auto vec : res){
		cout << setw(2) << i++ << " : ";
		for (auto val : vec)
			cout << val << " ";
		cout << endl;
	}
	return 0;
}
