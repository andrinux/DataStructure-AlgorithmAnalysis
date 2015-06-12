/*
* Design an algorithm and write code to remove the duplicate characters in a string without 
* using any additional buffer. NOTE: One or two additional variables are fine. An extra copy 
* of the array is not. FOLLOW UP Write the test cases for this method.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//use for setw
#include <iomanip>
using namespace std;

void removeDup(string& str)
{
	if (str.size()==0)
		return;
	int i=0, j=1; //Fast and slow indices
	char curChar=str[0];
	for(int i=1; i != str.size(); i++){
		if (curChar != str[i])
		{
			str[j++]=str[i];
			curChar=str[i];
		}
	}
	str=str.substr(0, j); 
}
int main()
{
	string s1 = "aabcccccaaabbb";
	string s2 = "aaaabbbbfccddddsss";
	// This is not correct, note the execute order of cout command
	//Computation is from right to left
	//Out put is from left to right
	//Like a stack
	//cout << s1 << "-" << removeDup(s1) << endl;
	//cout << s2 << "-" << removeDup(s2) << endl;
	cout <<s1 <<" - ";
	removeDup(s1);
	cout <<s1 <<endl;

	cout <<s2 <<" - ";
	removeDup(s2);
	cout <<s2 <<endl;

	return EXIT_SUCCESS;
}