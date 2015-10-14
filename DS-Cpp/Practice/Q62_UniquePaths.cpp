#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0)
			return 0;
		vector<vector<int> > D;
		//initialize 
		for (int i = 0; i < m; i++)
			D.push_back(vector<int>(n, 1));
		//Use DP to get the ways for each position.
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				D[i][j] = D[i - 1][j] + D[i][j - 1];
		return D[m-1][n-1];
	}
};

int main()
{
	Solution so;
	cout << so.uniquePaths(1, 1) << endl;
	return 0;
}