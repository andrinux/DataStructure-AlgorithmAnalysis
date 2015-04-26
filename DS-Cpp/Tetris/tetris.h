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
	//Constructor& Destructor
	Tetris();
	Tetris(int num) : width(num) { this->init(width); } 
	~Tetris();

	//member variables
	static int totalScore;

	//Member Functions
	int get_width() const;
	int get_max_height() const;
	int count_squares() const;
	bool add_piece(char type, int angle, int pos);
	void print() const;
	int remove_full_rows();
	
	void setHeight(int w, int newHeight) { this->heights[w] = newHeight; }
	void destroy();
	int find_full_row();

private:
	int     width;
	int *   heights; //The Height of each column
	char ** data;
	//Init the Tetris class by allocating memory
	void init(int width);
	int minHeight();
	void remove_one_row(int fullRow);

};


class Piece{
public:
	char *content;
	Piece();
	Piece(char type, int angle);
	static int  pieceCnt;

	int getW() const{ return W; }
	int getH() const{ return H; }
	char getType() const { return type; }
	void fillContent(char *, char, int);
	int getHeight(int w) const;
	
private:
	int W;
	int H; //This is the max H
	int *Hs;//This is the array contains the final added heights
	char type;
	

};

#endif
