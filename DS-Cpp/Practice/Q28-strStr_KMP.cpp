#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
	/*
	*    the K-M-P algorithm for string matching
	*    Complexity is O(m+n)
	*/
	void getNext(string p, vector<int> & next){
		next[0] = -1;
		int j = 0, k = -1;
		while (j < p.size()-1){
			if (k == -1 || p[j] == p[k]){
				j++;
				k++;
				next[j] = k;
			}
			else
				k = next[k];
		}		
	}

	int strStr(string str, string pattern) {
		if (pattern.size() == 0)
			return 0;
		if (str.size() == 0)
			return -1;
		int i = 0, j = 0;
		int M = str.size(), N = pattern.size(); // MUST use int here., or will cause bug in the loop.
		vector<int> Next(pattern.size(), 0);
		//pre-process
		getNext(pattern, Next);
		//search.
		while (i < M && j < N){
			if (j == -1 || str[i] == pattern[j]){
				i++;
				j++;
			}
			else{
				j = Next[j];
			}
		}
		if (j == pattern.size())
			return i - j;
		else
			return -1;
	}

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
