#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Odd Palindrom and Even Palindrome is different.

class Solution {
public:
	//Brute Force. Pay atention to the odd/even Palindrome.
	//There is a way to avoid the repeated search of odd/even case.
	string longestPalindrome_On2(string str) {
		int N = str.size();
		int MaxPos = 0, MaxLen = 0;
		int i = 0;
		int offset = 1;
		int low = i - offset;
		int up = i + offset;
		int curLen = 1;
		if (N == 0)
			return "";
		for (i = 0; i < N; i++){
			offset = 1;
			low = i - offset;
			up = i + offset;
			curLen = 1;
			//Odd Palindrome
			while (low >= 0 && up < N && str[low]==str[up]){
					//symmetric char found.
					curLen = curLen + 2;
					offset++;
					up = i + offset;
					low = i - offset;
			}
			if (MaxLen < curLen){
				MaxLen = curLen;
				MaxPos = low + 1; //MaxPos is the start of the target substring.
			}
			//Even Palindrome: rught forward. -->

			if (i < N - 1 && str[i] == str[i + 1]){
				offset = 1;
				low = i - offset;
				up = i + 1 + offset;
				curLen = 2;
				while (low >= 0 && up < N && str[up] == str[low]){
					curLen = curLen + 2;
					offset++;
					low = i - offset;
					up = i + 1 + offset;
				}
				if (MaxLen < curLen){
					MaxLen = curLen;
					MaxPos = low + 1;
				}
			}
		}

		//Assign
		//cout << MaxLen  << endl;
		return str.substr(MaxPos, MaxLen);
	}

	//The Optimal solution with O(N) time complexity
	//Manache Algorithm
	string longestPalindrome(string s){
		//convert s to str with '#' . 
		if (s.size() == 0)
			return "";
		string str="#";
		int i = 0;
		for (i = 0; i < s.size(); i++)
			str = str + s[i] + "#";

		//Find P(i) for all the positions
		int M = str.size();
		vector<int> P(M, 0);
		int id = 1, mx = 1;
		
		int j = 0;
		for (i = 1; i < M-1; i++){
			j = 2 * id - i;
			P[i] = min(P[j], mx - i);
			//no info. then look up to get P[i]
			while ( (i-P[i])>0 && (i+P[i])<M && str[i + P[i]] == str[i - P[i]])
				P[i]++;
			//update mx and id.
			if (i + P[i] > mx){
				mx = i + P[i]; //Here mx should be -1
				id = i;
			}
		}
		//Find the Max of P[i]
		int MaxP = 0, MaxPos = 0;
		
		for (i = 0; i < M; i++){
			if (MaxP < P[i]){
				MaxP = P[i];
				MaxPos = i;
			}
		}
		MaxP = MaxP - 1;
		//recover to original string remove '#'
		string res="";
		for (i = MaxPos - MaxP; i <= MaxPos + MaxP; i++)
			if (str[i] != '#')
				res = res + str[i];
		return res;
		
	}

};

int main()
{
	Solution so;
	string s = "321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123";
	//string s = "abccbabc";
	string str;
	str = so.longestPalindrome_On2(s);
	cout << str.size() << "-" << str << endl;
	str = so.longestPalindrome(s);
	cout << str.size() << "-" << str << endl;
	return 1;
}