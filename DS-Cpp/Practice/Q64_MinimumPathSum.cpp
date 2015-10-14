#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int M = grid.size(); if (M == 0) return 0;
		int N = grid[0].size();
		vector<vector<int>> D(M, vector<int>(N, 0));
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (i == 0 && j == 0){
					D[i][j] = grid[i][j]; continue;
				}
				if (i == 0 && j>0){
					D[i][j] = grid[i][j] + D[i][j - 1];
					continue;
				}
				if (i>0 && j == 0){
					D[i][j] = grid[i][j] + D[i - 1][j];
					continue;
				}
				if (i > 0 && j > 0){
					D[i][j] = grid[i][j] + min(D[i - 1][j], D[i][j - 1]);
					continue;
				}
			}
		}
		return D[M - 1][N - 1];
	}
};

int main()
{
	vector<vector<int>> grid;
	Solution so;
	grid.push_back({ 1, 2, 3, 4, 5 });
	grid.push_back({ 11, 12, 13, 14, 15 });
	grid.push_back({ 21, 22,23, 24, 25 });
	grid.push_back({ 31, 32, 33, 34, 35 });
	cout << so.minPathSum(grid) << endl;
	return 0;
}