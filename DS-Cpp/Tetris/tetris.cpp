// You will write the tetris.h and tetris.cpp files to implement the
// Tetris class.
#include "tetris.h"

int Tetris::get_max_height() const{
	return 1;
}

void Tetris::init(int width){
	heights = new int[width];
	for (int i = 0; i < width; i++)
		data[i] = new char[curHeight];
}