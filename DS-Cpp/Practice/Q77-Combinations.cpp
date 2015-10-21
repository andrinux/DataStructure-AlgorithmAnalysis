#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
//Recursion Method: Easy to stack overflow.
class Solution {
public:
	void findComb(int n, int k, int start, vector<vector<int>>& res, vector<int> cur){
		if (k == 0)
			return;
		int i = start;
		for (i = start; i <= n; i++){
			vector<int> curComb = cur;
			if (k == 1){
				curComb.push_back(i);
				res.push_back(curComb);
				//return;
			}
			else{
				curComb.push_back(i);
				findComb(n, k - 1, i + 1, res, curComb);
			}
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (n <1 || k>n) return res;
		vector<int> cur;
		findComb(n, k, 1, res, cur);
		return res;
	}
};

//iterative Solution, seems a bit tricky.
//http://tech-wonderland.net/blog/leetcode-combinations.html
class Solution_1 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (n <1 || k>n) return res;
		vector<int> cur;
		

		return res;
	}
};


int main()
{
	vector<vector<int> > res;
	Solution so;
	res = so.combine(5, 3);
	for (auto comb : res){
		for (auto x : comb){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}