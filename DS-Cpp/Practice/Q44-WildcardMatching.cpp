#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Method-1: Recursion.
class Solution_1 {
public:
	//p1 is the pointer in source and p2 is for pattern.
	bool checkMatch(string& s, string& p, int p1, int p2){
		//base case to return
		int M = s.size(), N = p.size();
		if (p1 == M ){
			if (p2 == N ) return true;
			if (p[p2] != '*') return false;
		}
		//general case
		if (p[p2] == '?')
			return checkMatch(s, p, p1+1, p2+1);
		else if (p[p2] == '*'){
			while (p[p2] == '*')
				p2++;
			for (; p1 < M; p1++){
				if (checkMatch(s, p, p1, p2)) 
					return true;
			}
			return checkMatch(s, p, p1, p2);
		}
		else{
			if (s[p1] == p[p2]){
				return checkMatch(s, p, p1 + 1, p2 + 1);
			}
			else
				return false;
		}
		return false;
	}

	bool isMatch(string s, string p) {
		if (p.size() == 0)
			return false;
		return checkMatch(s, p, 0, 0);
	}
};

class Solution {
public:
	bool isMatch(string str, string ptn) {
		int s = 0, p = 0;
		int M = str.size(), N = ptn.size();
		int match = -1, star = -1;
		while (s < M){
			if (p < N && (ptn[p] == '?' || ptn[p] == str[s])){
				s++; p++;
			}
			else if (p < N && ptn[p] == '*'){
				star = p;
				p++;
				match = s;
			}
			else if (star != -1){
				p = star + 1;
				s = ++match;
			}
			else
				return false;
		}

		//
		while (p < N && ptn[p] == '*')
			p++;
		return p == N;
	}
};

int main()
{
	Solution so;
	cout << so.isMatch("aaa", "a*a") << endl;
	
	return 0;
}
