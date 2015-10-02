#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* 
* Typical NP Problem. Search all the possibibilties using recursion. 
*/
class Solution {
public:
	// The validity checking function can be different 
	// with last problem because we only need to check the current row, column and sub-matrix
	/*
	*  Just try to find if there exists a same char with [i][j], if found, return false;
	*/
	bool isValid(vector<vector<char>>& board, int r, int c) {
		int cur = board[r][c];
		if (cur < '0' || cur>'9')
			return false;
		//check the row
		for (int i = 0; i < 9; i++){
			if (i != r && board[i][c] == cur){
				return false;
			}
		}
		//check the column
		for (int i = 0; i < 9; i++){
			if (i != c && board[r][i] == cur)
				return false;
		}
		//check the subBox
		for (int i = r / 3 * 3; i < r / 3 * 3 + 3; i++){
			for (int j = c / 3 * 3; j < c / 3 * 3 + 3; j++){
				if (i != r && j != c && board[i][j] == cur)
					return false;
			}
		}
		return true;
	}

	//the helper function to find the solution. DFS.
	bool solver(vector<vector<char>>& board, int r, int c){
		const int M = 9;
		//base case
		if (r == M)
			return true;
		int rNext = r, cNext = c;
		if (c == M-1){
			rNext = r + 1;
			cNext = 0;
		}
		else{
			rNext = r;
			cNext = c + 1;
		}
		//general case
		//if cur is  not blank.
		if (board[r][c] != '.'){
			if (!isValid(board, r, c))
				return false;
			else
				return solver(board, rNext, cNext);
		}

		//i =1,2,....9
		for (int i = 1; i <= M; i++){
			board[r][c] = i + '0';
			if (isValid(board, r, c) && solver(board, rNext, cNext))
				return true;
		}
		//Reset the grid to original
		board[r][c] = '.';
		return false;
	}
	
	void solveSudoku(vector<vector<char>>& board) {
		const int M = 9;
		if (board.size() != M || board[0].size() != M)
			return;
		bool res = solver(board, 0, 0);
		if (res)
			cout << "Get a solution." << endl;
		else
			cout << "Cannot find a solution." << endl;
	}

};





// A cleaner solution:
/*
void solveSudoku(vector<vector<char>>& board) {
	solve(board, 0);
}
bool solve(vector<vector<char>>& board, int ind){
	if (ind == 81) return true;
	int i = ind / 9, j = ind % 9;
	if (board[i][j] != '.') return solve(board, ind + 1);
	else{
		for (char f = '1'; f <= '9'; f++)
		{
			if (isValidFill(board, i, j, f))
			{
				board[i][j] = f;
				if (solve(board, ind + 1)) return true;
				board[i][j] = '.';
			}
		}
		return false;
	}
}
bool isValidFill(vector<vector<char>>& board, int i, int j, char fill) {
	for (int k = 0; k<9; k++)
	{
		if (board[i][k] == fill) return false; //check the row
		if (board[k][j] == fill) return false; //check the column
		int r = i / 3 * 3 + j / 3;   //select the block
		if (board[r / 3 * 3 + k / 3][r % 3 * 3 + k % 3] == fill) return false; //check the block
	}
	return true;
}
*/

int main()
{
	Solution so;
	vector<vector<char> > board;
	board.push_back({ '5', '3', '.', '.', '7', '.', '.', '.', '.' });
	board.push_back({ '6', '.', '.', '1', '9', '5', '.', '.', '.' });
	board.push_back({ '.', '9', '8', '.', '.', '.', '.', '6', '.' });
	board.push_back({ '8', '.', '.', '.', '6', '.', '.', '.', '3' });
	board.push_back({ '4', '.', '.', '8', '.', '3', '.', '.', '1' });
	board.push_back({ '7', '.', '.', '.', '2', '.', '.', '.', '6' });
	board.push_back({ '.', '6', '.', '.', '.', '.', '2', '8', '.' });
	board.push_back({ '.', '.', '.', '4', '1', '9', '.', '.', '5' });
	board.push_back({ '.', '.', '.', '.', '8', '.', '.', '7', '9' });
	so.solveSudoku(board);
	//cout << so.isValid(board, 0, 0);

	return 0;
}
