// You will write the tetris.h and tetris.cpp files to implement the
// Tetris class.

#include "tetris.h"
//Implementation of member functions in Tetris class
//This is initialization of pieceCount, which is a static variable
int Piece::pieceCnt = 0;
int Tetris::totalScore = 0;

Tetris::~Tetris(){

}

Tetris::Tetris(){
	//empty
}


void Tetris::init(int width){
	heights = new int[width]; //still here after init()?
	data = new char*[width];  //define a pointer array.
	//Tricky to initialize data[][]
	for (int i = 0; i < width; i++){
		heights[i] = 0;
		data[i] = NULL;
	}
		
}

//Get the width of the board
int Tetris::get_width() const { 
	return this->width;
}

//get the current maxium board height
int Tetris::get_max_height() const{
	int maxheight = 0;
	for (int i = 0; i < width; i++){
		if (maxheight < heights[i])
			maxheight = heights[i];
	}
	return maxheight;
}

//Count the total squares in the board
int Tetris::count_squares() const {
	return (Piece::pieceCnt * 4-totalScore*6);
}

//Add a new piece to the board
bool Tetris::add_piece(char type, int angle, int pos) {
	int W = 0, H = 0;
	//Construct the new 
	Piece P(type, angle);
	//Find local max Height
	int locMaxHgt = 0;
	for (int i = 0; i != P.getW(); i++){
		if (locMaxHgt < heights[pos + i])
			locMaxHgt = heights[pos + i];
	}

	//Update data[][] by copy and delete old ones
	for (int i = 0; i != P.getW(); i++){ 
		int col = pos + i;
		int curHeight = heights[col];
		int addHeight = P.getHeight(i);
		int totalHeight = locMaxHgt + addHeight; //Not the final height
		char * newAddr = new char[totalHeight];
		//Three steps: copy existing-> complement blanks -> copy new added
		int j = 0, k = 0;
		for (j = 0; j < curHeight; j++)
			newAddr[j] = this->data[pos + i][j];
		for (; j < locMaxHgt; j++) //blanks higher than curHeight but lower than locMax
			newAddr[j] = ' ';
		for (; j < totalHeight; j++){
			int index = P.getH()*i + j - locMaxHgt;
			newAddr[j] = P.content[index];
		}
		//Copy to data[][]
		delete[] data[pos + i];
		data[pos + i] = new char[totalHeight];
		for (k = 0; k < totalHeight; k++)
			data[pos + i][k] = *(newAddr + k);
		delete[] newAddr;
		//update current height
		heights[col] = locMaxHgt + P.getHeight(i);
	}
	
	return true;
}

int Tetris::remove_full_rows(){
	int W = this->get_width();
	int H = this->get_max_height();
	int col = 0, row = 0, fullRow=0;
	//i is the index of Height
	for (row = 0; row < H; row++){
		for (col = 0; col < W; col++){
			if (heights[col] < row)
				break;
			else if (data[col][row] == ' ' || data[col][row] == 'X')
				break;
			else
				continue;
		}
		if (col == W){
			//std::cout << row << "Full Row Detected" << std::endl;
			fullRow = row;
			break;
		}	
	}
	//Update the data[][]
	int i;
	for (col = 0; col < W; col++){
		char * newAddr = new char[heights[col] - 1];
		for (i=0, row = 0; row < heights[col]; row++){
			if (row != fullRow){
				newAddr[i] = data[col][row];
				i++;
			}
		}
		delete[] data[col];
		data[col] = new char[heights[col] - 1];
		for (i = 0; i < heights[col] - 1; i++)
			data[col][i] = newAddr[i];
		delete[] newAddr;

		//update heights
		heights[col] = heights[col] - 1;
	}
	//Check if there full column of ' ', then set this col as blank
	for (col = 0; col < W; col++){
		for (row = 0; row < heights[col]; row++){
			if (data[col][row] != ' ')
			   break;
		}
		if (row == heights[col]){
			//std::cout << col << "An empty column is detected" << std::endl;
			heights[col] = 0;
			delete data[col];
		}
	}
	//Calculate the scores
	totalScore++;
	return totalScore;
}

Piece::Piece()
{
	//empty constructor
	return;
}

Piece::Piece(char type, int angle){
	this->type = type;
	++pieceCnt;
	switch (type){
	case 'I':
		if (angle == 0 || angle == 180){
			W = 1; H = 4;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 4;
			for (int i = 0; i < W*H; i++) content[i] = 'I';
		}
		else{
			W = 4; H = 1;
			content = new char[W*H];
			Hs = new int[W]; 
			Hs[0] = 1; Hs[1] = 1; Hs[2] = 1; Hs[3] = 1;
			for (int i = 0; i < W*H; i++) content[i] = 'I';
		}
		break;

	case 'O':
		W = 2; H = 2;
		content = new char[W*H];
		Hs = new int[W];
		Hs[0] = 2; Hs[1] = 2; 
		for (int i = 0; i < W*H; i++) content[i] = 'O';
		break;

	case 'T':
		if (angle == 0){
			W = 3; H = 2;
			content = new char[W*H];
			Hs = new int[W];
			Hs[0] = 2; Hs[1] = 2; Hs[2] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'T';
			content[0] = content[4] = ' ';
		}
		else if (angle == 90){
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 3;
			for (int i = 0; i < W*H; i++) content[i] = 'T';
			content[0] = ' '; content[4] = 'X';
		}
		else if (angle == 180){
			W = 3; H = 2;
			content = new char[W * H]; Hs = new int[W];
			Hs[0] = 1; Hs[1] = 2; Hs[2] = 1;
			for (int i = 0; i < W*H; i++) content[i] = 'T';
			content[1] = content[5] = 'X';
		}
		else { //270
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 3; Hs[1] = 2; 
			for (int i = 0; i < W*H; i++) content[i] = 'T';
			content[3] = ' '; content[5] = 'X';
		}
		break;

	case 'Z':
		if (angle == 0 || angle == 180){
			W = 3; H = 2;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 2; Hs[2] = 1;
			for (int i = 0; i < W*H; i++) content[i] = 'Z';
			content[0] = ' '; content[5] = 'X';
		}
		else{
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 3; 
			for (int i = 0; i < W*H; i++) content[i] = 'Z';
			content[2] = 'X'; content[3] = ' ';
		}
		break;
	case 'S':
		if (angle == 0 || angle == 180){
			W = 3; H = 2;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 1; Hs[1] = 2; Hs[2] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'S';
			content[1] = 'X'; content[4] = ' ';
		}
		else{
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 3; Hs[1] = 2; 
			for (int i = 0; i < W*H; i++) content[i] = 'S';
			content[0] = ' '; content[5] = 'X';
		}
		break;
	case 'L':
		if (angle == 0){
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 3; Hs[1] = 1;
			for (int i = 0; i < W*H; i++) content[i] = 'L';
			content[4] = content[5] = 'X';
		}
		else if (angle == 90){
			W = 3; H = 2;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 2; Hs[2] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'L';
			content[2] = content[4] = ' ';
		}
		else if (angle == 180){
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 3; Hs[1] = 3; 
			for (int i = 0; i < W*H; i++) content[i] = 'L';
			content[0] = content[1] = ' ';
		}
		else {
			W = 3; H = 2;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 1; Hs[1] = 1; Hs[2] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'L';
			content[1] = content[3] = 'X';
		}
		break;
	case 'J':
		if (angle == 0){
			W = 2; H = 3;
			content = new char[W * H]; Hs = new int[W];
			Hs[0] = 1; Hs[1] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'J';
			content[1] = content[2] = 'X';
		}
		else if (angle == 90){
			W = 3; H = 2;
			content = new char[W * H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 1; Hs[2] = 1;
			for (int i = 0; i < W * H; i++) content[i] = 'J';
			content[3] = content[5] = 'X';
		}
		else if (angle == 180){
			W = 2; H = 3;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 3; Hs[1] = 3; 
			for (int i = 0; i < W*H; i++) content[i] = 'J';
			content[3] = content[4] = ' ';
		}
		else{
			W = 3; H = 2;
			content = new char[W*H]; Hs = new int[W];
			Hs[0] = 2; Hs[1] = 2; Hs[2] = 2;
			for (int i = 0; i < W*H; i++) content[i] = 'J';
			content[0] = content[1] = ' ';
		}
		break;
	default:
		std::cout << "Invalid argument in AddPiece()." << std::endl;
	}
}

int Piece::getHeight(int w) const{
	return this->Hs[w];
}
