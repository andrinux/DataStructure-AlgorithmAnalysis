/*
* Assume you have a method isSubstring which checks if one word is a substring 
* of another. Given two strings, s1 and s2, write code to check if s2 is a rotation 
* of s1 using only one call to isSubstring 
* ( i.e., ¡°waterbottle¡± is a rotation of ¡°erbottlewat¡±).
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//use for setw
#include <iomanip>

using namespace std;

bool checkRotate(string s1, string s2){
	string s = s1 + s1;
	return s.isSubString(s2);
}

int main()
{
	string s2 = "waterbottle";
	string s1 = "erbottlewat";
	cout << checkRotate(s1, s2);
	return EXIT_SUCCESS;
}