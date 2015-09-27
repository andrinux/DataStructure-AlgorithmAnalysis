#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:


	/*
	*    the Brute Force Method of string matching.
	*    Complexity is O(mn)
	*/
	int strStr_Brute(string str, string pattern){
		if (pattern.size() == 0)
			return 0;
		if (str.size() == 0)
			return -1;
		int i = 0, j = 0;
		int M = str.size(), N = pattern.size();
		int start = 0;
		while (start < M){
			i = start;
			while (str[i] == pattern[j] && i < M && j < N){
				i++;
				j++;
			}
			if (j == N)
				return start;
			else{
				start++;
				j = 0;
			}
		}
		return -1;
	}
};


int main()
{
	string str = "gpg";
	string pattern = "p";
	int pos = 0;
	Solution so;
	pos = so.strStr(str, pattern);
	cout << pattern << endl;
	cout << pos << endl;
	return 1;
}
