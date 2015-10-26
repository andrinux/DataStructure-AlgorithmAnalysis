#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution{
public:
	bool do_Check(vector<vector<int> > & board, int i, int j){
		int M = board.size();
		int N = board.size();
		if (j + 3 < N && board[i][j] && board[i][j + 1] && board[i][j + 2] && board[i][j + 3])
			return true;
		if (i + 3 < M && board[i][j] && board[i+1][j] && board[i+2][j] && board[i+3][j])
			return true;
		if (i + 3 < M && j + 3 < N && board[i][j] && board[i + 1][j + 1] && board[i + 2][j + 2] && board[i + 3][j + 3])
			return true;
		return false;
	}
	bool checkWin(vector<vector<int> > & board){
		//Corner cases
		int M = board.size(); if (M == 0) return false;
		int N = board[0].size(); if (N == 0) return false;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++){
				if (do_Check( board,i, j))
					return true;
			}
		return false;
	}
};

int main()
{
	Solution so;
	vector<vector<int> > board;
	board.push_back({ 0, 0, 0, 0, 0, 0 });
	board.push_back({ 0, 0, 1, 0, 0, 0 });
	board.push_back({ 0, 0, 0, 1, 0, 0 });
	board.push_back({ 0, 0, 0, 0, 0, 0 });
	board.push_back({ 0, 0, 0, 0, 0, 1 });
	board.push_back({ 0, 0, 0, 0, 0, 0 });
	cout << so.checkWin(board);
	return 0;
}