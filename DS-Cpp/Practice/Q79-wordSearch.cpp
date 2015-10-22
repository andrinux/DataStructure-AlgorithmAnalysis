#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Why it is so slow? 312ms.
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int Len = word.size(); if (Len == 0) return false;
		int M = board.size(); if (M == 0) return false;
		int N = board[0].size(); if (N == 0) return false;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++){
				if (board[i][j] == word[0]){
					char back = board[i][j];
					board[i][j] = 0;
					if (do_Search(board, i, j, word, 1))
						return true;
					board[i][j] = back;
				}
			}
		return false;
	}

	bool do_Search(vector<vector<char>>& board, int i, int j, string &word, int k){
		if (k == word.length())
			return true;
		int M = board.size(); 
		int N = board[0].size();
		vector<vector<int> > Dir = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int d = 0; d < 4; d++){
			int i_n = i + Dir[d][0];
			int j_n = j + Dir[d][1];
			if (i_n>=0 && i_n<M && j_n>=0 && j_n<N && board[i_n][j_n] == word[k]){
				char back = board[i_n][j_n];
				board[i_n][j_n] = 0;
				if (do_Search(board, i_n, j_n, word, k + 1))
					return true;
				board[i_n][j_n] = back;
			}
		}
		return false;
	}
};


int main()
{
	Solution so;
	vector < vector<char> >  board;
	string word = "AAA";
	//board.push_back({ 'A', 'B', 'C', 'E' });
	//board.push_back({ 'S', 'F', 'C', 'P' });
	//board.push_back({ 'A', 'D', 'E', 'E' });
	board.push_back({ 'A', 'A' });
	cout << so.exist(board, word);
	return 0;

}