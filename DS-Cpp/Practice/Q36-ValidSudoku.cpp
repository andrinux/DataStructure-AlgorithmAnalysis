#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Method -1: Brute Force, by checking row, colum, and each sub matrix
class Solution_1 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9) return false;
		if (board[0].size() != 9) return false;
		//check all the rows
		const int M = 9;
		for (int i = 0; i < M; i++){
			int count[M+1] = { 0 };
			for (int j = 0; j < M; j++){
				if (board[i][j] == '.')
					continue;
				else{
					if (board[i][j] <'0' || board[i][j] >'9')
						return false;
					int cur = board[i][j] - '0';
					if (count[cur] > 0)
						return false;
					else
						count[cur]++;
				}
			}
		}

		//check all the column
		for (int i = 0; i < M; i++){
			int count[M+1] = { 0 };
			for (int j = 0; j < M; j++){
				if (board[j][i] == '.')
					continue;
				else{
					if (board[j][i] <'0' || board[j][i] >'9')
						return false;
					int cur = board[j][i] - '0';
					if (count[cur] > 0)
						return false;
					else
						count[cur]++;
				}
				
			}
		}
		const int N = 3;
		//check all the sub-array.
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				//now we have the i and j
				int count[M+1] = { 0 };
				for (int m = N*i; m < N*(i + 1); m++){
					for (int n = N*j; n < N*(j + 1); n++){
						if (board[m][n] == '.')
							continue;
						else{
							if (board[m][n] <'0' || board[m][n] >'9')
								return false;
							int cur = board[m][n] - '0';
							if (count[cur] > 0)
								return false;
							else
								count[cur]++;
						}
					}
				}
			}
		}

		return true;
	}
};




int main()
{
	Solution so;
	vector<vector<char>> board;
	board.push_back({ '.', '8', '7', '6', '5', '4', '3', '2', '1' });
	board.push_back({ '2', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '3', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '4', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '5', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '6', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '7', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '8', '.', '.', '.', '.', '.', '.', '.', '.' });
	board.push_back({ '9', '.', '.', '.', '.', '.', '.', '.', '.' });
	cout << so.isValidSudoku(board) << endl;
	return 0;
}
