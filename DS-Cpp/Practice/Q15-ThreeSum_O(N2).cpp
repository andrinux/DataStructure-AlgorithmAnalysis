/* 
* This Version is to use the sorted attribute to do the 3SUM problem.
* 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//Double-side Approximate Method.
	vector<vector<int>> threeSum_1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int M = nums.size();
		vector<vector<int> > res;
		vector<int> one_res;
		if (M < 3)
			return res;
		int i = 0, j = 0, k = 0;
		for (i = 0; i < M; i++){
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			j = i + 1; k = M - 1;
			while (j < k){	
				//-check
				if (nums[i] + nums[j] + nums[k] == 0){
					res.push_back({ nums[i], nums[j], nums[k] });
					//cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
					//Dedup Needed !
					while (j< k && nums[j] == nums[j + 1])
						j++;
					while (j<k && nums[k] == nums[k - 1])
						k--;
					j++;
					k--;
				}
				else if (nums[j] + nums[k] + nums[i] < 0)
					j++;
				else
					k--;
			}
		}
		return res;
	}
	
	//Hash Function Based Method...
	vector<vector<int>> threeSum(vector<int>& nums){
		vector< vector<int> > res;
		int M = nums.size();
		if (M < 3)
			return res;
		unordered_map<int, int> Maps;
		unordered_map<int, int>::const_iterator itr;
		int i = 0, j = 0;
		sort(nums.begin(), nums.end());
		for (i = 0; i < M; i++){
			Maps.clear();
			//Dedup for i.
			while (i>0 && i + 1 < M && nums[i] == nums[i - 1]){
				i++;
			}
			j = i + 1;
			while (j < M){
				//错误的j去重的地方。
				//while (j + 1 < M && nums[j] == nums[j + 1])
				//	j++;
				itr = Maps.find(0 - nums[i] - nums[j]);
				if (itr != Maps.end() && itr->second < j){
					res.push_back({ nums[i], itr->first, nums[j] });
					//cout << nums[i] << " " << itr->first << " " << nums[j] << endl;
					//Dedup for j: easy to mistake here.
					//可能后两个数是相等的，所以必须确定这种情况不work才能跳过重复的
					while (j+1 < M && nums[j] == nums[j + 1])
						j++;
				}
				Maps[nums[j]] = j;
				j++;
			}
			
		}
		return res;
	}
};


int main()
{
	vector<int> nums;
	vector<vector<int> > res;
	Solution so;
	nums = { -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1,
		4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9 };
	//nums = { -1, -1, -1, -1, 0, 1, 2, 2, 2, 2, 2, -1, -4 };
	res = so.threeSum(nums);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++)
			cout  << res[i][j] << " ";
		cout << endl;
	}
	return 1;
}