//Program: Non-linear word search problem
//letters could be zigzag

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

class loc{
public:
	int row;
	int col;
	//constructor
	loc() : row(0), col(0) {}
	loc(int r, int c) : row(r), col(c) {}
};

//check the position is already on the path
bool onPath(loc Pos, std::vector<loc> &path){
	std::vector<loc>::const_iterator itr;
	for (itr = path.begin(); itr != path.end(); itr++){
		if (itr->col == Pos.col && itr->row == Pos.row)
			return true;
		else
			continue;
	}
	return false;
}

//Recursive or Iterative
bool searchFromLoc(loc Pos, std::string word, std::vector<std::string>& board, std::vector<loc> &path){
	//The start point should be no problem
	assert(board[Pos.row][Pos.col] == word[0]);
	path.push_back(Pos);
	if (word.size() == 0)
		return true;
	int r, c;
	//Search the adjacent 8 positions to check if there is any matching with the second letter
	for (r = -1; r <= 1; r++){
		for (c = -1; c <= 1; c++){
			int row = Pos.row + r;
			int col = Pos.col + c;
			if (row < 0 || row > board.size()) continue;
			if (col < 0 || col > board[row].size()) continue;
			if (onPath(loc(row, col), path)) continue;
			if (board[row][col] != word[1]){
				continue;
			}
			else{
				//matching
				word.erase(word.begin());
				path.push_back(loc(row, col));
				searchFromLoc(loc(row, col), word, board, path);
			}
		}
	}
	//reach here indicates loops all the 8 points
	if (r == 1 && c == 1){
		path.clear();
		return false;
	}
		
}

//wordSearch core function
bool wordSearch(std::vector<std::string> &board, std::string word, std::vector<loc> &path){
	int row = 0, col = 0;
	bool found;
	for (row = 0; row != board.size(); row++){
		for (col = 0; col != board[row].size(); col++){
			if (board[row][col] == word[0])
			found = searchFromLoc(loc(row, col), word, board, path);
		}
	}
	return found;
}

//Print the Path coordinates
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
	bool found = wordSearch(board, word, path);
	if (found)
		printPath(path);
	else
		std::cout << "404 Not Found." << std::endl;
	return EXIT_SUCCESS;
}