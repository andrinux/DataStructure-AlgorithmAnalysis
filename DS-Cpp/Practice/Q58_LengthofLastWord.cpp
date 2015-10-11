#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int N = s.size(); if (N == 0) return 0;
		int i = N-1;
		while (s[i] == ' ')
			i--;
		int mark = i; 

		for (; i >= 0; i--){
			if (s[i] == ' ')
				break;
		}
		return mark  - i;
	}
};


int main()
{
	Solution so;
	cout << so.lengthOfLastWord(" World   ");

	return 0;
}