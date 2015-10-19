#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//A typical DP problem.

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		vector<int> D(n+1, 0);
		D[1] = 1; D[2] = 2;
		for (int i = 3; i < n + 1; i++){
			D[i] = D[i - 1]+ D[i - 2];
		}
		return D[n];
	}
};

int main()
{
	Solution so;
	cout << so.climbStairs(20) << endl;
	return 0;
}