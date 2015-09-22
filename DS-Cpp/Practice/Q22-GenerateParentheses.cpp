#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
	void do_generate_1(vector<string>& res, string cur, int n, int left, int right){
		//basic case
		if (left == right && left == n){
			res.push_back(cur);
			return;
		}
		//general cases.
		if (left > right){
			if (left < n){
				do_generate_1(res, cur + '(', n, left + 1, right);
				do_generate_1(res, cur + ')', n, left, right + 1);
			}
			else
				do_generate_1(res, cur + ')', n, left, right + 1);
		}
		else if (left == right)
			do_generate_1(res, cur + '(', n, left+1, right);
		else
			return;
	}

	//A much concise solution
	void do_generate(vector<string>& res, string cur, int n, int left, int right){
		//basic case
		if (left == right && left == n){
			res.push_back(cur);
			return;
		}
		//general case
		if (left < n) do_generate(res, cur + '(', n, left + 1, right);
		if (right < left) do_generate(res, cur + ')', n, left, right + 1);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n < 1)
			return res;
		string cur = ""; 
		do_generate(res, cur, n, 0, 0);
		return res;
	}
};


int main()
{
	int n = 3;
	vector<string> res;
	Solution so;
	res = so.generateParenthesis(n);
	for (int i = 0; i < res.size(); i++)
		cout << i << " - " << res[i] << endl;
	return 1;
}