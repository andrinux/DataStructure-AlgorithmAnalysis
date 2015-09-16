#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	//Brute Force.
	//This is absolutely wrong because of numRows would be 1
	//if ((i + 1) % (numRows-1) == 0)
	//	flag = flag*(-1);
	//Corner case is when numRows == 1;
	string convert(string s, int numRows) {
		//Edge cases.
		if (numRows == 1 || numRows >= s.size())
			return s;
		//general case.
		vector<string> store(numRows);
		int flag = 1;
		int N = s.size();
		int idx = -1;
		for (int i = 0; i < N; i++){
			if (idx == (numRows - 1)) flag = -1;
			if (idx == 0) flag = 1; //this line should be after the first line.
			//cout << flag << " ";
			idx = idx + flag;
			store[idx].push_back(s[i]);
		}
		
		string res;
		for (int i = 0; i < numRows; i++){
			res = res + store[i];
		}
		return res;
	}
};


int main()
{
	Solution so;
	string in = "PAYPALISHIRING";
	cout << endl<< so.convert(in, 3);
	return 1;
}