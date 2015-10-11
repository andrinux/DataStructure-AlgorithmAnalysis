#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		if (n == 0)
			return res;
		//allocate and initialize
		for (int i = 0; i < n; i++)
			res.push_back(vector<int>(n, 0));
		//change values
		int val = 0;
		vector<vector<int> > iDir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };// r-c
		int c = -1, r = 0;
		int nSteps[2] = { n, n - 1 };
		int i = 0, j = 0; // i is the index of lines.
		while (nSteps[i % 2]){
			int d_r = iDir[i % 4][0];
			int d_c = iDir[i % 4][1];
			for (j = 0; j < nSteps[i % 2]; j++){
				c = c + d_c; r = r + d_r;
				res[r][c] = ++val;
			}
			nSteps[i % 2]--;
			i++;
		}
		return res;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> matrix;
	matrix = so.generateMatrix(8);
	for (auto vec : matrix){
		for (auto num : vec)
			cout << setw(2) << num << " ";
		cout << endl;
	}
}