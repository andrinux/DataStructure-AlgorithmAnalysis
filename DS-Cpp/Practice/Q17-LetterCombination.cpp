#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	//Recursion Core Function.
	void do_LC(string &src, int offset, vector<string> & res, string cur){
		//basic case
		if (offset == src.length()){
			res.push_back(cur);
			return;
		}
		//general cases
		vector<string> dataset(10);
		dataset[0] = ""; dataset[1] = ""; dataset[2] = "abc";
		dataset[3] = "def"; dataset[4] = "ghi"; dataset[5] = "jkl";
		dataset[6] = "mno"; dataset[7] = "pqrs"; dataset[8] = "tuv";
		dataset[9] = "wxyz";

		int curNum = src[offset] - '0';
		
		for (int i = 0; i < dataset[curNum].size(); i++){
			do_LC(src, offset + 1, res, cur + dataset[curNum][i]);
		}
	}
	//main func.
	vector<string> letterCombinations_R(string digits) {
		vector<string> res;
		//exception case.
		if (digits.length() == 0)
			return res;
		for (int i = 0; i < digits.length(); i++){
			if (digits[i]<'2' || digits[i]>'9')
				return res;
		}
		//normal case.
		string cur = "";
		do_LC(digits, 0, res, cur);
		return res;
	}


	vector<string> letterCombinations(string digits) {
		//Src Dataset
		vector<string> dataset(10);
		dataset[0] = ""; dataset[1] = ""; dataset[2] = "abc";
		dataset[3] = "def"; dataset[4] = "ghi"; dataset[5] = "jkl";
		dataset[6] = "mno"; dataset[7] = "pqrs"; dataset[8] = "tuv";
		dataset[9] = "wxyz";

		//exception case.
		if (digits.length() == 0)
			return vector<string>();
		for (auto i = 0; i < digits.length(); i++){
			if (digits[i]<'2' || digits[i]>'9')
				return vector<string>();
		}

		//normal case. Use two Vectors(Queue works as well, but need to convert to vector again).
		vector<string> cur, next;
		cur.push_back("");
		int idx = 0, M = digits.size();
		while (!cur.empty() && idx < M){
			string curStr = cur.back();
			for (int i = 0; i < dataset[digits[idx] - '0'].size(); i++){
				next.push_back(curStr + dataset[digits[idx] - '0'][i]);
			}
			cur.pop_back();
			if (cur.empty()){
				cur.swap(next);
				idx++;
			}				
		}
		return cur;
	}
};


int main()
{
	string input;
	Solution so; 
	vector<string> res;

	input = "23"; res = so.letterCombinations(input);
	for (auto i = 0; i < res.size(); i++)
		cout << i << " - " << res[i] << endl;
	return 1;
}