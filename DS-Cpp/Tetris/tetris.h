#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <assert.h>

//#define INIT_HEIGHT 2

class Tetris{
public:
	//Constructor
	Tetris();
	Tetris(int num) : width(num) { this->init(width); } 
	~Tetris();

	//Member Functions
	int get_width() const;
	int get_max_height() const;
	int count_squares() const;
	bool add_piece(char type, int angle, int pos);
	void print() const;
	bool remove_full_rows();


private:
	int     width;
	int *   heights; //The Height of each column
	char ** data;
	//Init the Tetris class by allocating memory
	void init(int width);

};


class Piece{
public:
	char *content;
	Piece();
	Piece(char type, int angle);

	int getW() const{ return W; }
	int getH() const{ return H; }
	char getType() const { return type; }
	void fillContent(char *, char, int);
private:
	int W;
	int H;
	char type;

};
#endif
