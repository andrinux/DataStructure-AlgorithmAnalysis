#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <assert.h>

#define INIT_HEIGHT 2


class Tetris{
public:
	//Constructor
	Tetris();
	Tetris(int num) : width(num), curHeight(INIT_HEIGHT) { this->init(width); } 
	~Tetris() {};

	//Member Functions
	int get_width() const { return 1; }
	int get_max_height() const;
	int count_squares() const { return 1; }
	bool add_piece(char type, int angle, int pos) { return true; }
	void print() const;


private:
	int     width;
	int *   heights;
	char ** data;
	int curHeight;
	//Init the Tetris class by allocating memory
	void init(int width);

};
#endif
