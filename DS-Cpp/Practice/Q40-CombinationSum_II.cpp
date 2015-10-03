#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
	void findComb(vector<int>& C, int T, int idx, vector<vector<int>>& res, vector<int> cur){
		int i = idx;
		int M = C.size();
		for (i = idx; i < M; i++){
			// skip the same element.
			// Here made a mistake. i > 'idx' is the key here.
			if (i > idx && C[i] == C[i - 1]) 
				continue;
			vector<int> curComb = cur; //curComb must be placed here,
			if (T == C[i]){
				curComb.push_back(C[i]);
				res.push_back(curComb);
				return;
			}
			else if (T > C[i]){
				curComb.push_back(C[i]);
				findComb(C, T - C[i], i + 1, res, curComb); 
			}
			else{
				//sorted, so if come to here, then impossible to find another one in the future
				return;
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& C, int T) {
		vector<vector<int> > res;
		int M = C.size();
		if (M == 0 || T < 0)
			return res;
		//sort
		sort(C.begin(), C.end());
		//call help function
		vector<int> cur;
		findComb(C, T, 0, res, cur);
		return res;
	}
};

int main()
{
	vector<int> Candidates = { 10, 1, 2, 7, 6, 1, 5 };
	//Candidates = { 4, 4, 4, 4};
	Solution so;
	vector<vector<int>> res;
	res = so.combinationSum2(Candidates, 8);
	for (auto comb : res){
		for (auto x : comb){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}