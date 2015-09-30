#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	// This Method is not correct: cannot solve "()(()(()", 
	// need to memorize the index of left parenthese
	int longestValidParentheses_Wrong(string s) {
		int M = s.size();
		if (M <= 1)
			return 0;
		stack<char> stk;
		int i = 0, maxLen = 0, curLen = 0;
		for (i = 0; i < M; i++){
			if (s[i] == '('){
				stk.push('(');
			}
			else{ //s[i]==')'
				if (stk.empty()){
					maxLen = max(maxLen, curLen);
					curLen = 0;
					continue;
				}
				if (stk.top() == '('){
					//get a match
					curLen = curLen + 2;
					stk.pop();
				}
				else{
					//mismatch
					maxLen = max(maxLen, curLen);
					curLen = 0;
					while (!stk.empty())
						stk.pop();
				}
			}
		}
		maxLen = max(maxLen, curLen);
		return maxLen;
	}


};


int main()
{
	Solution so;
	string s(")(()(()");
	cout << so.longestValidParentheses(s);
	return 0;
}
