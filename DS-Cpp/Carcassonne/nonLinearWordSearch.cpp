//Program: Non-linear word search problem
//letters could be zigzag

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
};

//wordSearch core function
bool wordSearch(std::vector<std::string> &board, std::string word, std::vector<loc> &path){

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