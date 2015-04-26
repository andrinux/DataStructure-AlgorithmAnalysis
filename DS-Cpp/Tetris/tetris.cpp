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
	//Calculate the new version board size
	//Update data[][] by copy and delete old ones

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
	switch (type){
	case 'I':
		if (angle == 0 || angle == 180){
			W = 1; H = 4; 
			content = new char[W*H];
			fillContent(content, type, angle);
		}
		else{
			W = 4; H = 1; 
		}
	}
}