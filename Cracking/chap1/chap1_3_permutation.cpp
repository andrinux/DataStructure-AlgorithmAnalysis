/*
* Write a method to decide if two strings are permutation or not.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


bool checkPermutation(string &s1, string &s2){
	int stat1[256] = { 0 };
	int stat2[256] = { 0 };
	for (int i = 0; i != s1.size(); i++){
		int val = s1[i];
		stat1[val]++;
	}
	for (int i = 0; i != s2.size(); i++){
		int val = s2[i];
		stat2[val]++;
	}
	for (int i = 0; i != 256; i++){
		if (stat1[i] == stat2[i])
			continue;
		else
			return false;
	}
	return true;
}

//Save storage space and running time.
//Think: No need to use set or map, etc
bool checkPermutation_2(string &s1, string &s2){
	int stat[256] = { 0 };
	if (s1.size() != s2.size())
		return false;
	for (int i = 0; i != s1.size(); i++){
		int val = s1[i];
		stat[val]++;
	}
	//Then must be same size, if there is differece,
	//must be some stat[] smaller than 0
	for (int i = 0; i != s2.size(); i++){
		int val = s2[i];
		if ((--stat[val]) < 0)
			return false;
	}
	return true;
}




int main()
{
	string s1 = "HelloWorld";
	string s2 = "WorldHello";
	string s3 = "ComputerScience    ";
	string s4 = "Science Computer    ";
	cout << checkPermutation(s1, s2) << checkPermutation_2(s1, s2) << endl;
	cout << checkPermutation(s3, s4) << checkPermutation_2(s3, s4) << endl;
	cout << checkPermutation(s1, s3) << checkPermutation_2(s1, s3) << endl;
	return 1;
}