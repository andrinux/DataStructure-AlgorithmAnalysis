#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

/*
* Note that the Candidates would be any order....
// Method-1: Sort First
// 36ms.
*/

class Solution {
public:
	void findComb(vector<int>& C, int T, int idx, vector<vector<int>>& res, vector<int> cur){
		int i = idx;
		for (i = idx; i < C.size(); i++){
			// Skip the duplicated one?-> Not necessary because input is a S-E-T.
			if (i> idx && C[i] == C[i - 1]) 
				continue;
			vector<int> curComb = cur;
			if (T == C[i]){
				//find one solution.
				curComb.push_back(C[i]);
				res.push_back(curComb);
				return;//No need to go further because right side would be larger.
			}
			else if (T > C[i]){
				curComb.push_back(C[i]);
				findComb(C, T - C[i], i, res, curComb);
			}
			else{
				return;
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& C, int T) {
		int M = C.size();
		vector<vector<int>> res;
		if (M == 0)
			return res;
		vector<int> cur;
		sort(C.begin(), C.end());
		findComb(C, T, 0, res, cur);
		return res;
	}
};


int main()
{
	vector<int> Candidates = {2,2,2,2};
	Solution so;
	vector<vector<int>> res;
	res = so.combinationSum(Candidates, 4);
	for (auto comb : res){
		for (auto x : comb){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}