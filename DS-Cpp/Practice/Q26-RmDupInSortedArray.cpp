#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

//Need a set to restore the existing element
class Solution {
public:
	//Random sequence
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		unordered_set<int> exist;
		int i = 0, j = 0;
		while (i < nums.size()){
			if (exist.count(nums[i]) == 0){
				nums[j] = nums[i];
				exist.insert(nums[i]);
				j++;
			}
			i++;
		}
		nums.resize(j);
		return j;
	}

};


int main()
{
	vector<int> nums = { 1 };
	Solution so;
	int N = so.removeDuplicates_2(nums);
	cout << N << ":";
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	//vector<int> tmp;
	
	cout << endl;
	return 1;
}
