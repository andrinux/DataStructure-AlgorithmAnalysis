//Using Map to solve Problem twoSum
//https://leetcode.com/problems/two-sum/


//Comment: No need to loop for twice.
//Map can add automatically

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int len = numbers.size();
		map<int, int> data;
		map<int, int>::const_iterator itr;
		vector<int> res(2);
		for (int i = 0; i < len; i++){
			data[numbers[i]] = i;
		}
		for (int i = 0; i < len; i++){
			int tmp = target - numbers[i];
			itr = data.find(tmp);
			if (itr != data.end() && (itr->second!=i)){
				res[0] = 1 + i;
				res[1] = 1 + itr->second;
				cout << "index1=" << res[0]+1 << ", index2=" << res[1]+1 << endl;
				return res;
			}
		}
		return res;
	}


};


int main()
{
	vector<int> numbers;
	numbers = { 3, 2, 4 };
	int target =6;
	Solution so;
	so.twoSum(numbers, target);
	return 1;
}