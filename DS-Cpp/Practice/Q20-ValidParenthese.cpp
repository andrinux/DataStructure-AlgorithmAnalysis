#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
	bool isMatch(char src, char cur){
		if (cur == ']')
			return src == '[';
		if (cur == '}')
			return src == '{';
		if (cur == ')')
			return src == '(';
	}

	bool isValid(string s) {
		stack<char> stk;
		if (s.length() == 0)
			return false;
		for (unsigned int i = 0; i < s.length(); i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stk.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
				if ((!stk.empty()) && isMatch(stk.top(),s[i]))
					stk.pop();
				else
					return false;
			}
				else
					continue;
		}
		if (stk.empty())
			return true;
		else
			return false;
	}
};


int main()
{
	string str;
	Solution so;
	str = "()[]{}"; cout << str << " -> " << so.isValid(str) << endl;
	str = "({[]})"; cout << str << " -> " << so.isValid(str) << endl;
	str = "([)]"; cout << str << " -> " << so.isValid(str) << endl;
	str = "(()[]{}"; cout << str << " -> " << so.isValid(str) << endl;
	str = "("; cout << str << " -> " << so.isValid(str) << endl;
	str = ""; cout << str << " -> " << so.isValid(str) << endl;
	return 1;
}