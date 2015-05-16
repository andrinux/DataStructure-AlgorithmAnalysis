//WordSearch Problem using Recursion
//Input is a string and a letter grid
//Target is in8 directions(col, row, diagonal)

//Usage: wrdSearch file.txt [string]

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class loc{
public:
	int row;
	int col;
	//constructor
	loc() : row(0), col(0) {}
	loc(int r, int c) : row(r), col(c) {}
	//overloading of operator
	bool operator==(loc& rht) const{
		if (this->col == rht.col && this->row == rht.row)
			return true;
		else
			return false;
	}
	loc operator+(loc& rht){
		int r = this->row + rht.row;
		int c = this->col + rht.col;
		return loc(r, c);
	}
};

//Check the current location is inside the board
bool insideBoard(int row, int col, std::vector<std::string> &board){
	if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
		return true;
	else
		return false;
}

//Linear Search, firstly to determine the constant Diff
bool searchFromLoc(loc start, std::string &word, std::vector<std::string> &board, std::vector<loc> &path){
	//std::cout << "Local Search" << std::endl;
	loc locDiff = loc();
	int row, col;
	for (int r = -1; r != 2; r++){
		for (int c = -1; c != 2; c++){
			row = r + start.row;
			col = c + start.col;
			if (insideBoard(row, col, board) && board[row][col] == word[1])
				locDiff = loc(r, c);
			else
				continue;
		}
	}
	path.push_back(start);
	//Found the locDiff, search continue the same direction
	int cur = 1;
	row = start.row; col = start.col;
	while (cur < word.size()){
		row += locDiff.row;
		col += locDiff.col;
		if (insideBoard(row, col, board) && board[row][col] == word[cur]){
			cur++;
			path.push_back(loc(row, col));
		}
		else{
			path.clear();
			return false;
		}
	}
	return true;
}

void printPath(std::vector<loc> &path){
	std::cout << "Found: ";
	std::vector<loc>::const_iterator itr = path.begin();
	for (; itr != path.end(); itr++)
		std::cout << "( " << itr->row << ", " << itr->col << " ) -> ";
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	std::ifstream infile(argv[1]);
	if (argc != 3 || !infile){
		std::cout << "Incorrect input arguments." << std::endl;
		return EXIT_FAILURE;
	}

	std::string word = argv[2];
	std::vector<std::string> board;
	std::string curLine;
	while (infile >> curLine){
		board.push_back(curLine);
	}
	std::vector<loc> path;
	bool found = false;
	char tmp;
	for (int r = 0; r < board.size(); r++){
		for (int c = 0; c < board[r].size(); c++){
			//std::cout << "check: " << r << " - " << c << std::endl;
			if ((tmp=board[r][c]) == word[0]){
				loc start = loc(r, c);
				found=searchFromLoc(start, word, board, path);
				if (found)
					printPath(path);
				found = false;
			}
		}
	}
	std::cout << board.size();
	return EXIT_SUCCESS;
}