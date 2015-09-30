#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//Do swap in-place.
	void inline swap(vector<int>&nums, int pos1, int pos2){
		int tmp = 0;
		tmp = nums[pos1];
		nums[pos1] = nums[pos2];
		nums[pos2] = tmp;
	}
	//reverse a sub vector
	void reverse(vector<int> &nums, int start, int end){
		while (start < end){
			swap(nums, start, end);
			start++;
			end--;
		}
	}
	//Main Function.
	void nextPermutation(vector<int>& nums) {
		int M = nums.size();
		if (M <= 1)
			return;
		int a = M - 2, b = M - 1;
		while (a >= 0 && nums[a] >= nums[b] ){ //Here we need to use >=, corner case: 5-1-1
			a--;
			b--;
		}
		cout << a << endl;
		if (a == -1){
			reverse(nums, 0, nums.size() - 1);
			return;
		}
		// find a and b. Then try to find the c: 
		// the smallest number which is larger than a on the right side of a
		int c = M - 1;
		//the right side would be sorter reversely.
		while (c > a){
			if (nums[c] > nums[a])
				break;
			else
				c--;
		}
		//Swap a and c
		swap(nums, a, c);
		//Reverse
		reverse(nums, a + 1, M - 1);
		return;
	}
};


int main()
{
	Solution so;
	vector<int> nums = { 5,1,1 };
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " - ";
	cout << endl;
	for (int K = 0; K < 1; K++){
		so.nextPermutation(nums);
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " - ";
		cout << endl;
	}
	
	return 1;
}