#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		int maxLen = 0, curLen = 0;
		unordered_map<char,  int> curStr;
		unsigned i = 0, lastPos = 0, curStart=0;
		while (i < s.length()){
			if (curStr.count(s[i]) == 0){
				//no existing
				curStr.insert(pair<char,  int>(s[i], i));
				i++;
			}
			else{
				//existing found
				lastPos = curStr[s[i]];
				curLen = i - curStart;
				curStart = max(lastPos + 1, curStart);
				maxLen = max(maxLen, curLen);
				curStr[s[i]] = i;
				i++;
			}
		}
		curLen = i - curStart;
		return max(maxLen, curLen);
	}
};


int main()
{
	string in = "abccdefggbe";
	Solution so;
	cout << so.lengthOfLongestSubstring(in)<<endl;
	return 1;
}