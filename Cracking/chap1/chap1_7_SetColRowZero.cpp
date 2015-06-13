/*
* Write an algorithm such that if an element in an MxN matrix is 0, 
* its entire row and column is set to 0.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//use for setw
#include <iomanip>
using namespace std;

#define M 20
#define N 15

void printMatrix(int Data[N][N])
{
	cout << "========================" << endl;
	for (int i = 0; i != N; i++){
		for (int j = 0; j != N; j++){
			cout << setw(3) << Data[i][j] << " ";
			if (j == (N - 1))
				cout << endl;
		}
	}
}

void do_setRow(int Data[M][N], int row){
	for (int i = 0; i != N; i++)
		Data[row][i] = 0;
}

void do_setCol(int Data[M][N], int col){
	for (int i = 0; i != M; i++)
		Data[i][col] = 0;
}

/*
* find all the locations and set zero one by one
*/
void setZero_1(int Data[M][N]){
	//Step 1: find the locations of 0
	vector<int> row;
	vector<int> col;
	for (int i = 0; i != M; i++){
		for (int j = 0; j != N; j++){
			if (Data[i][j] == 0){
				row.push_back(i);
				col.push_back(j);
			}
		}
	}
	//Step 2: Set zeros to Cols and Rows
	for (int i = 0; i != row.size(); i++){
		do_setRow(Data, row[i]);
		do_setCol(Data, col[i]);
	}
}

/*
* Try to reduce the repeated actions
* We don't need to exactly know where is the 0, just the row/col is OK
*/
void setZero_2(int Data[M][N]){
	bool row[M] = { 0 };
	bool col[N] = { 0 };
	for (int i = 0; i != M; i++){
		for (int j = 0; j != N; j++){
			if (Data[i][j] == 0){
				row[i] = true;
				col[j] = true;
			}
		}
	}
	//Set zeros
	for (int i = 0; i != M; i++)
		if (row[i])
			do_setRow(Data, i);
	for (int i = 0; i != N; i++)
		if (col[i])
			do_setCol(Data, i);
}

int main()
{
	int Data[M][N] = { 0 };
	for (int i = 0; i != M; i++){
		for (int j = 0; j != N; j++)
			Data[i][j] = i*N + j;
	}
	Data[0][0] = 0; Data[1][5] = 0; Data[7][13] = 0;
	printMatrix(Data);
	setZero_2(Data);
	printMatrix(Data);
	return 0;
}