#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_1 {
public:
	//Recursively Calling.
	void doSpiral(vector<vector<int>>& matrix, int round, vector<int>& res){
		int M = matrix.size();
		int N = matrix[0].size();
		//corner case
		if (M - 2 * round <= 0 || N - 2*round <= 0)
			return;
		//one line
		if (M - 2 * round == 1){
			for (int i = round; i < N - round; i++)
				res.push_back(matrix[round][i]);
			return;
		}

		//one column
		if (N - 2 * round == 1){
			for (int i = round; i < M - round; i++)
				res.push_back(matrix[i][round]);
			return;
		}

		//general case:
		// four edges:
		for (int i = round; i < N - round; i++)
			res.push_back(matrix[round][i]);
		for (int i = round + 1; i < M - round; i++)
			res.push_back(matrix[i][N - round - 1]);
		for (int i = N - round - 2; i >= round; i--)
			res.push_back(matrix[M - round - 1][i]);
		for (int i = M - round - 2; i > round; i--)
			res.push_back(matrix[i][round]);
		//next round
		doSpiral(matrix, round + 1, res);

	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int M = matrix.size();
		//corner case: blank.
		if (M == 0) return vector<int>();
		int N = matrix[0].size();
		vector<int> res;
		doSpiral(matrix, 0, res);
		return res;
	}
};

//A cleaner Method: But need to be very careful.
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int M = matrix.size(); if (M == 0) return res;
		int N = matrix[0].size(); if (N == 0) return res;
		vector<vector<int> > iDir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
		int i = 0, j = 0;
		int c = -1, r = 0;
		int nSteps[2] = { N, M-1 }; //初始值很容易弄错，顺序和忘记减去1
		while (nSteps[i%2]){
			int d_c = iDir[i % 4][0];
			int d_r = iDir[i % 4][1];
			for (j = 0; j < nSteps[i % 2]; j++){
				c = c + d_c; r = r + d_r;
				res.push_back(matrix[r][c]);
			}
			nSteps[i % 2]--;//easy to forget to update nSteps here.
			i++;
		}
		return res;
	}
};


int main()
{
	vector<vector<int> > matrix;
	matrix.push_back({ 1, 2,3,4});
	matrix.push_back({ 5,6,7,8  });
	matrix.push_back({ 9, 10, 11, 12 });
	matrix.push_back({ 13, 14, 15, 16 });
	matrix.push_back({ 17, 18, 19, 20 });
	matrix.push_back({ 21, 22, 23, 24 });
	Solution so;
	vector<int> res;
	res = so.spiralOrder(matrix);
	for (auto d : res)
		cout << d << " ";
	cout << endl;
	return 0;
}
