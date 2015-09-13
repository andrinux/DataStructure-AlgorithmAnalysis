#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

//Res is 16ms. Top 50%.
using namespace std;

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
       vector<int> res;
       unordered_map<int, int> maps;
       unordered_map<int, int>::iterator itr;
       unsigned int i=0;
       for(i = 0; i != nums.size(); i++){
           itr = maps.find(target - nums[i]);
           if(itr == maps.end())
               maps.insert(pair<int,int>(nums[i], i));
           else{
               cout<<"index1="<< 1+itr->second <<", index2="<< 1+i <<endl;
               res.push_back(1+itr->second);
               res.push_back(1+i);
               return res;
           }
       }
       return res;
    }
	// Another method: Double side approximate.
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> num = nums;
		sort(num.begin(), num.end());
		vector<int> res;
		int i = 0, j = num.size() - 1;
		while (i < j){
			if (num[i] + num[j] < target)
				i++;
			else if (num[i] + num[j] > target)
				j--;
			else
				break;
		}
		int k = 0;
		while (k < nums.size()){
			if (nums[k] == num[i]){
				res.push_back(1 + k);
				break;
			}
			k++;
		}
		k = nums.size() - 1;
		while (k >=0 ){
			if (nums[k] == num[j]){
				res.push_back(1 +k);
				break;
			}
			k--;
		}
		if (res[0] > res[1]){
			k = res[1];
			res[1] = res[0];
			res[0] = k;
		}
		cout << "index1=" << res[0] << ", index2=" << res[1] << endl;
		return res;
	}
};

int main()
{
	vector<int> nums = {-1, -2, -3, -4, -5};
    Solution so;

    so.twoSum(nums, -8);
	so.twoSum_1(nums, -8);
	
    return 1;
}
