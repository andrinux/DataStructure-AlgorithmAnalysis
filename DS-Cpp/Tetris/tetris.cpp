// You will write the tetris.h and tetris.cpp files to implement the
// Tetris class.

#include "tetris.h"
//Implementation of member functions in Tetris class

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
	return 0;
}

//Add a new piece to the board
bool Tetris::add_piece(char type, int angle, int pos) {
	int W = 0, H = 0;
	//Construct the new 
	Piece P(type, angle);
	//Update data[][] by copy and delete old ones
	for (int i = 0; i != P.getW(); i++){ 
		//i is the col index within the Piece
		int curHeight = this->heights[pos + i];
		int addHeight = P.getHeight(i);
		//Update New Heights
		this->setHeight(pos + i, curHeight + addHeight);
		//copy
		char *newAddr = new char(curHeight + addHeight);
		int j = 0, k = 0;
		for (j = 0; j != curHeight; j++)
			newAddr[j] = this->data[pos + i][j];
		for (k = 0; k != addHeight; j++, k++){
			int index = P.getH()*i + k;
			newAddr[j] = P.content[index];
		}
		//Delete old and Copy new
		//delete[] this->data[pos + i];
		this->data[pos + i] = new char(curHeight + addHeight);
		for (k = 0; k < curHeight + addHeight; k++)
			this->data[pos + i][k] = newAddr[k];
		//delete[] newAddr;  //<===Error Here.???
	}
	

	//check if there is complete rows to remove

	return true;
}

bool Tetris::remove_full_rows(){
	return true;
}

Piece::Piece()
{
	//empty constructor
}

Piece::Piece(char type, int angle){
	this->type = type;

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
