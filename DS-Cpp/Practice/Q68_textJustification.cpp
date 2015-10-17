#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

//可以少于20行，https://leetcode.com/discuss/13610/share-my-concise-c-solution-less-than-20-lines

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int N = words.size();
		if (N == 0 || maxWidth < 1){
			res.push_back("");
			return res;
		}
		//general cases:
		bool lastLine = false;
		int i = 0, curWidth = 0, wordCnt = 0, beginIdx = 0;
		string curLine;
		while (i < N){
			//reset
			beginIdx = i; curWidth = 0; wordCnt = 0; curLine.clear();
			//collect the words for curLine:
			while (i < N && curWidth + words[i].size() <= maxWidth){
				curWidth += (words[i].size() + 1);
				i++;
				wordCnt++;
			}
			curWidth--;//The last word in curLine no need an extra ' '
			if (i == N) lastLine = true;
			if (wordCnt == 0)
				return vector<string>();
			if (wordCnt == 1){
				curLine = words[beginIdx];
				curLine += string(maxWidth - words[beginIdx].size(), ' ');
				res.push_back(curLine);
				continue;
			}
			//left justify, but still need to occupy maxWidth.
			if (wordCnt > 1 && lastLine){
				for (int j = beginIdx; j < i; j++){
					curLine = curLine + words[j];
					if (j < i - 1)
						curLine = curLine + ' ';
				}
				curLine = curLine + string(maxWidth - curLine.size(), ' ');
				res.push_back(curLine);
			}
			//need to calculate the extra spaces to insert: from beginIdx to i-1
			if (wordCnt > 1 && lastLine == false){
				int totalSpace = maxWidth - curWidth;
				int extra = totalSpace / (wordCnt - 1);
				int rem = totalSpace % (wordCnt - 1);
				for (int j = beginIdx; j < i; j++){
					curLine = curLine + words[j];
					if (j < i - 1){
						curLine = curLine + string(extra + 1, ' ');
						if (rem > 0){
							curLine = curLine + ' ';
							rem--;
						}	
					}
				}
				res.push_back(curLine);
			}
		}
		return res;
	}
};

int main()
{
	Solution so;
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification."};
	vector<string> res = so.fullJustify(words, 16);
	for (auto str : res)
		cout << str << endl;
	return 0;
}
