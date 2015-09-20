#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//O(N^2), simple extended from ThreeSum, check each combination
	int threeSumClosest_v1(vector<int>& nums, int target) {
		int M = nums.size();
		int sum = 0, curSum = 0;
		int minDiff = INT_MAX;
		sort(nums.begin(), nums.end());
		int i = 0, j = 0, k = 0;
		for (i = 0; i < M-2; i++){
			j = i + 1;
			k = M - 1;
			while (j < k){
				curSum = nums[i] + nums[j] + nums[k];
				//check the closest
				if (minDiff > abs(curSum - target)){
					minDiff = abs(curSum - target);
					sum = curSum;
				}
				//iterating for next time.
				if (curSum - target == 0)
					return target;
				else if (curSum - target < 0)
					j++;
				else
					k--;					
			}
		}
		return sum;
	}
	//Two Optimize
	int threeSumClosest(vector<int>& nums, int target){
		int M = nums.size();
		int sum = 0, curSum = 0;
		int minDiff = INT_MAX;
		int flag = 0;
		sort(nums.begin(), nums.end());
		int i = 0, j = 0, k = 0;
		for (i = 0; i < M - 2; i++){
			j = i + 1;
			k = M - 1;
			while (j < k){
				curSum = nums[i] + nums[j] + nums[k];
				cout << "check: " << i << ", " << j << ", " << k << ": "<< curSum<< endl;
				//check the closest
				if (minDiff > abs(curSum - target)){
					minDiff = abs(curSum - target);
					sum = curSum;
				}
				flag = 0;
				//iterating for next time.
				if (curSum - target == 0)
					return target;
				else if (curSum - target < 0){
					if (flag == 1)
						break;
					flag = -1;
					j++;
				}
				else{
					//If the synbol changes from negative to positive, then we can end. change to 12ms.
					if (flag == -1)
						break;
					flag = 1;
					k--;
				}
					
			}
			//Optimize: This two lines of code can reduce the runtime from 24ms ->16ms
			if (sum>target && i < M)
				break;
		}
		return sum;
	}
};

int main()
{
	Solution so;
	int target = 0;
	vector<int>  nums = { 87, 6, -100, -19, 10, -8, -58, 56, 14, -1, -42, -45, -17, 10, 20, -4, 13, -17, 0, 11, -44, 
		65, 74, -48, 30, -91, 13, -53, 76, -69, -19, -69, 16, 78, -56, 27, 41, 67, -79, -2, 30, -13, -60, 39, 95, 64,
		-12, 45, -52, 45, -44, 73, 97, 100, -19, -16, -26, 58, -61, 53, 70, 1, -83, 11, -35, -7, 61, 30, 17, 98, 29, 
		52, 75, -73, -73, -23, -75, 91, 3, -57, 91, 50, 42, 74, -7, 62, 17, -91, 55, 94, -21, -36, 73, 19, -61, -82, 
		73, 1, -10, -40, 11, 54, -81, 20, 40, -29, 96, 89, 57, 10, -16, -34, -56, 69, 76, 49, 76, 82, 80, 58, -47, 12,
		17, 77, -75, -24, 11, -45, 60, 65, 55, -89, 49, -19, 4 };
	//nums = { 0, 0, 0 };
	//nums = { -1, 2, 1, -4 }; 
	nums = { 1, 2, 4, 8, 16, 32, 64, 128 }; target = 82;
	cout << so.threeSumClosest(nums, 82) << endl;
	return 1;
}
