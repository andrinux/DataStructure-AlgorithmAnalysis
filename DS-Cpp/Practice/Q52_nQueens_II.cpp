#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isValid(vector<int> & A, int place){
		for (int i = 0; i < place; i++){
			if (abs(place - i) == abs(A[place] - A[i]))
				return false;
		}
		return true;
	}
	void solver(vector<int> & A, int start, vector<vector<int>> &res){
		int N = A.size();
		if (start == N - 1 && isValid(A, start)){
			res.push_back(A);
			return;
		}
		for (int i = start; i < N; i++){
			swap(A[start], A[i]);
			if (isValid(A, start))//here need to check Valid.
				solver(A, start + 1, res);
			swap(A[start], A[i]);
		}
	}
	int totalNQueens(int n) {
		vector<int> A(n, 0);
		// initialize
		for (int i = 0; i < n; i++)
			A[i] = i;
		// Permute and checkValid
		vector<vector<int>> res;
		solver(A, 0, res);
		//comvert to board.
		int count = res.size();
		return count;
	}

};


int main()
{
	int n = 2;
	Solution so;
	int res = so.totalNQueens(n);
	cout << res << endl;
}