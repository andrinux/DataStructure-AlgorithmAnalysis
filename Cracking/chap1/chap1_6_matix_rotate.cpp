/*
* Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, 
* write a method to rotate the image by 90 degrees. Can you do this in place? 
*/

//Rotate clockwise by 90 degrees here.

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//use for setw
#include <iomanip>

using namespace std;

#define N 5

void swap(int& x, int & y)
{
	x = x^y;
	y = x^y;
	x = x^y;
}

void rotate(int Data[N][N])
{
	//Step-1: Data[i][j] <-> Data[j][i]
	for (int i = 0; i != N; i++){
		for (int j = 0; j < i; j++){
			swap(Data[i][j], Data[j][i]);
		}
	}
	//Step-2
	//Pay attention to the temination condition
	for (int i = 0; i != N; i++){
		for (int j = 0; j < N/2; j++){
			swap(Data[i][j], Data[i][N-1-j]);
		}
	}
}

void printMatrix(int Data[N][N])
{
	cout << "========================" << endl;
	for (int i = 0; i != N; i++){
		for (int j = 0; j != N; j++){
			cout << setw(2) << Data[i][j] << " ";
			if (j == (N - 1))
				cout << endl;
		}
	}
}
int main()
{
	int Data[N][N] = { 0 };
	for (int i = 0; i != N; i++){
		for (int j = 0; j != N; j++)
			Data[i][j] = i*N + j;
	}
	printMatrix(Data);
	rotate(Data);
	printMatrix(Data);
	return 0;
}
