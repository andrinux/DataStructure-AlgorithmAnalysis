/*
* You are given two 32-bit numbers, N and M, and two bit positions, i and j  Write a 
* method to set all bits between i and j in N equal to M (e g , M becomes a substring of 
* N located at i and starting at j)   
*/

#include <iostream>

//The key is to generate a mask to clear the bits of N through i to j.
//My method is to AND 1111111000011
//To get it, we generate 000000111100  <-- 000000001111 <-- 000000010000-1 

//The methid in the solution is to generate two masks:
//M1: 111111100000  <-- all ones shift
//M2: 000000000011
//Mask=M1|M2;
void changeBits(int &N, int M, int i, int j){
	int m2 = ((1 << (j - i + 1)) - 1) << i;
	int m3 = ~m2;
	N = N&m3;
	M = M << i;
	N = M|N;

	return;
}

int main()
{
	int N = 1024, M = 21;
	changeBits(N, M, 2, 6);
	std::cout << N;
	return 0;
}