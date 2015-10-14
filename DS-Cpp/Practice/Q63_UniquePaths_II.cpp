#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
		int M = Grid.size(); if (M == 0) return 0;
		int N = Grid[0].size(); if (N == 0) return 0;
		if (Grid[0][0]) return 0;
		//initialize
		vector<vector<int> > D(M, vector<int>(N, 0));
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (i == 0 && j == 0 && Grid[i][j] != 1){
					D[i][j] = 1;
					continue;
				}
				if (i == 0 && j>0 && Grid[i][j] != 1){
					D[i][j] = D[i][j-1];
					continue;
				}
				if (i>0 && j == 0 && Grid[i][j] != 1){
					D[i][j] = D[i - 1][j];
					continue;
				}
				if (i > 0 && j > 0 && Grid[i][j] != 1){
					D[i][j] = D[i - 1][j] + D[i][j - 1];
					continue;
				}
			}
		}
		return D[M - 1][N - 1];
	}
};

int main()
{
	vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
	obstacleGrid[0][0] = 1;
	Solution so;
	cout << so.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}