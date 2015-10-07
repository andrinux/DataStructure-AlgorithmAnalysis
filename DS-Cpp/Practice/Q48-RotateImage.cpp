#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& M) {
		int n = M.size();
		//step 1: mirror
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n / 2; j++)
				swap(M[i][j], M[i][n - 1 - j]);
		//step: reverse (i, j) -> (n-1-j, n-i)
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1 - i; j++)
				swap(M[i][j], M[n - 1- j][n - 1 - i]);
	}
};


int main()
{
	vector<vector<int>>  M;
	M.push_back({ 0, 1, 2, 3 });
	M.push_back({ 4, 5, 6, 7 });
	M.push_back({ 8, 9,10,11 });
	M.push_back({12,13,14,15 });

	Solution so;
	so.rotate(M);
	for (auto line : M){
		for (auto num : line)
			cout <<setw(2)<< num << " ";
		cout << endl;
	}
	return 0;
}