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
		if (start == N-1 && isValid(A, start)){
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
	//generate the board
	void convert(vector<vector<string>>& boards, vector<vector<int>> res){
		int count = res.size();
		if (count == 0)
			return;
		int bSize = res[0].size();
		
		vector<string> curBoard;
		string curLine;
		for (int i = 0; i < count; i++){
			for (int j = 0; j < bSize; j++){
				curLine = string(bSize, '.');
				curLine[res[i][j]] = 'Q';
				curBoard.push_back(curLine);
			}
			boards.push_back(curBoard);
			curBoard.clear();
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<int> A(n, 0);
		// initialize
		for (int i = 0; i < n; i++)
			A[i] = i;
		// Permute and checkValid
		vector<vector<int>> res;
		solver(A, 0, res);
		//comvert to board.
		vector<vector<string>> boards;
		convert(boards, res);
		return boards;
		
	}
};


int main()
{
	int n = 2;
	Solution so;
	vector<vector<string>> res = so.solveNQueens(n);
	int i = 0;
	for (auto vec : res){
		for (auto line : vec)
			cout << line << endl;
		cout << ++i << " ---------" << endl;
	}
}