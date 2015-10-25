#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
public:
	//the helper function.
	void findComb(int k, int target, int start, vector<vector<int>>& res, vector<int> cur){
		int i = 0;
		if (k == 0)
			return;
		for (i = start; i <= 9; i++){
			vector<int> curComb = cur;
			if (target == i && k == 1){
				curComb.push_back(i);
				res.push_back(curComb);
				return;
			}
			else if (target > i){
				curComb.push_back(i);
				findComb(k - 1, target - i, i+1, res, curComb);
			}
			else{
				return;
			}
		}
	}

	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > res;
		//corner cases
		if (n > 45 || k <= 0)
			return res;
		vector<int> cur;
		findComb(k, n, 1, res, cur);
		return res;
	}
};



int main()
{
	Solution so;
	vector<vector<int>> res;
	res = so.combinationSum3(3, 7);
	for (auto comb : res){
		for (auto x : comb){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}