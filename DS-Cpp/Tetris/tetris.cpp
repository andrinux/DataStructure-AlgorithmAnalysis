// You will write the tetris.h and tetris.cpp files to implement the
// Tetris class.

#include "tetris.h"
//Implementation of member functions in Tetris class
//This is initialization of pieceCount, which is a static variable
int Piece::pieceCnt = 0;
int Tetris::totalScore = 0;
int Tetris::removedCnt = 0;

Tetris::~Tetris(){
	if (heights!=NULL){
		delete[] heights;
		heights = NULL;
	}
	for (int i = 0; i != width; i++){
		if (data[i] != NULL){
			delete[] data[i];
			data[i] = NULL;
		}
			
	}
	if (data!=NULL){
		delete[] data;
		data = NULL;
	}
	
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
	int count=0;
	for (int i = 0; i < this->get_width(); i++){
		for (int j = 0; j < heights[i]; j++){
			if (data[i][j] != ' ')
				count++;
		}
	}
	return count;
}

//Add a new piece to the board
bool Tetris::add_piece(char type, int angle, int pos) {
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
		if (data[pos + i] != NULL){
			delete[] data[pos + i];
			data[pos + i] = NULL;
		}
		data[pos + i] = new char[totalHeight];
		for (k = 0; k < totalHeight; k++)
			data[pos + i][k] = *(newAddr + k);

		if (newAddr != NULL){
			delete[] newAddr;
			newAddr = NULL;
		}
		//update current height
		heights[col] = locMaxHgt + P.getHeight(i);
	}
	P.destroy();
	return true;
}


int Tetris::minHeight(){
	int min=this->get_max_height();
	for (int i = 0; i < this->get_width(); i++){
		if (heights[i] < min)
			min = heights[i];
	}
	return min;
}

int Tetris::find_full_row(){
	int W = this->get_width();
	//int H = this->get_max_height();
	int col = 0, row = 0, fullRow = -1;
	//look for the full rows
	for (row = 0; row < this->minHeight(); row++){
		for (col = 0; col < W; col++){
			if (heights[col] < row || heights[col] == 0)
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
	//Didn't find: return -1
	return fullRow;
}

void Tetris::remove_one_row(int fullRow){
	int W = this->get_width();
	//int H = this->get_max_height();
	int col = 0, row = 0;

	//Update the data[][]
	int i;
	for (col = 0; col < W; col++){
		char * newAddr = new char[heights[col] - 1];
		for (i = 0, row = 0; row < heights[col]; row++){
			if (row != fullRow){
				newAddr[i] = data[col][row];
				i++;
			}
		}
		if (data[col] !=NULL){
			delete[] data[col];
			data[col] = NULL;
		}
		
		data[col] = new char[heights[col] - 1];
		for (i = 0; i < heights[col] - 1; i++)
			data[col][i] = newAddr[i];
		if (newAddr!=NULL){
			delete[] newAddr;
			newAddr = NULL;
		}
		//update heights
		heights[col] = heights[col] - 1;
	}
	//Check if there full column of ' ', then set this col as blank
	for (col = 0; col < W; col++){
		for (row = 0; row < heights[col]; row++){
			if (data[col][row] != ' ')
				break;
		}
		if (row == heights[col] ){
			//std::cout << col << "An empty column is detected" << std::endl;
			heights[col] = 0;
			//if (data[col] !=NULL){
				delete[] data[col];
				data[col] = NULL;
			//}
		}
	}
	return;
}


int Tetris::remove_full_rows(){
	int fullRow=-1;
	int curScore = 0;

	while ((fullRow = find_full_row()) != -1){
		//Update Data and heights
		remove_one_row(fullRow);
		//Update Scores
		curScore++;
		totalScore++;
	}
		return curScore;
}

void Tetris::destroy(){
	int col = 0;
	//for (col = 0; col < this->get_width() && heights[col] != 0; col++){
	for (col = 0; col < this->get_width(); col++){
		delete[] data[col];
		data[col] = NULL;
	}
	delete[] data;
	data = NULL;
	delete[] heights;
	heights = NULL;
	totalScore = 0;
	Piece::pieceCnt = 0;
	removedCnt = 0;
	width = 0;
}

//Is there any cleaner ways to do so?
void Tetris::add_left_column(){
	int curW = this->get_width();
	//Update Heights
	int *new_heights = new int[curW + 1];
	new_heights[0] = 0;
	for (int i = 0; i < curW; i++)
		new_heights[i + 1] = heights[i];
	delete[] heights;
	heights = NULL;
	heights = new int[curW + 1];
	for (int i = 0; i < curW + 1; i++)
		heights[i] = new_heights[i];
	delete[] new_heights;
	new_heights = NULL;
	//Updates data
	char **new_data = new char*[curW + 1];
	new_data[0] = NULL;
	for (int i = 0; i < curW; i++)
		new_data[i + 1] = data[i];
	delete[] data;
	data = NULL;
	data = new char*[curW + 1];
	for (int i = 0; i < curW + 1; i++)
		data[i] = new_data[i];
	delete[] new_data;
	new_data = NULL;

	//Update Width
	this->add_width(1);
	return;
}

void Tetris::add_right_column(){
	int curW = this->get_width();
	//Update Heights
	int *new_heights = new int[curW + 1];
	new_heights[curW] = 0;
	for (int i = 0; i < curW; i++)
		new_heights[i] = heights[i];
	delete[] heights;
	heights = NULL;
	heights = new int[curW + 1];
	for (int i = 0; i < curW + 1; i++)
		heights[i] = new_heights[i];
	delete[] new_heights;
	new_heights = NULL;
	//Update Data
	char **new_data = new char*[curW + 1];
	new_data[curW] = NULL;
	for (int i = 0; i < curW; i++)
		new_data[i] = data[i];
	delete[] data;
	data = NULL;
	data = new char*[curW + 1];
	for (int i = 0; i < curW + 1; i++)
		data[i] = new_data[i];
	delete[] new_data;
	new_data = NULL;

	//Update Width
	this->add_width(1);
	return;
}

void Tetris::remove_left_column(){
	int curW = this->get_width();
	//Count the non-empty squares in the left column
	for (int i = 0; i < heights[0]; i++){
		if (data[0][i] != ' ' && data[0][i] != 'X')
			removedCnt++;
	}
	//Update heights
	int * new_heights = new int[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		new_heights[i] = heights[i + 1];
	delete[] heights;
	heights = NULL;
	heights = new int[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		heights[i] = new_heights[i];
	delete[] new_heights;
	new_heights = NULL;
	//Update Data
	char **new_data = new char*[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		new_data[i] = data[i + 1];
	delete[] data;
	data = NULL;
	data = new char*[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		data[i] = new_data[i];
	delete[] new_data;
	new_data = NULL;
	//Update Width
	this->add_width(-1);
	return;
}

void Tetris::remove_right_column(){
	int curW = this->get_width();
	int * new_heights = new int[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		new_heights[i] = heights[i];
	delete[] heights;
	heights = NULL;
	heights = new int[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		heights[i] = new_heights[i];
	delete[] new_heights;
	new_heights = NULL;
	//Update Data
	char **new_data = new char*[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		new_data[i] = data[i];
	delete[] data;
	data = NULL;
	data = new char*[curW - 1];
	for (int i = 0; i < curW - 1; i++)
		data[i] = new_data[i];
	delete[] new_data;
	new_data = NULL;
	//Update Width
	this->add_width(-1);
	return;
}


//============================================================
//========================Piece===============================
//============================================================
Piece::Piece()
{
	//empty constructor
	return;
}

Piece::~Piece(){
	if (content != NULL){
		delete[] content;
		content = NULL;
	}
	if (Hs != NULL){
		delete[] Hs;
		Hs = NULL;
	}
	W = 0; H = 0;
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
			content[0] = ' '; content[2] = 'X';
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
			Hs[0] = 1; Hs[1] = 3;
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

void Piece::destroy(){
	//Delete content
	if (content!=NULL){
		delete[] content;
		content = NULL;
	}
	if (Hs!=NULL){
		delete[] Hs;
		Hs = NULL;
	}
}