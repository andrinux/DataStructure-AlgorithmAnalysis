#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int M = a.size(), N = b.size();
		if (M == 0) return b;
		if (N == 0) return a;
		//general case.
		res = string(max(M, N) + 1, '0');
		int S = res.size();
		int i = 0;
		int carry = 0;
		for (i = 0; i < S ; i++){
			int d1 = (i >= M) ? 0 : (a[M - 1 - i] - '0');
			int d2 = (i >= N) ? 0 : (b[N - 1 - i] - '0');
			int d = d1 + d2 + carry;
			if (d > 1){
				res[S-1-i] = d - 2 + '0';
				carry = 1;
			}
			else{
				res[S-1-i] = d + '0';
				carry = 0;
			}
		}
		if (res[0] == '0')
			return res.substr(1);
		else
			return res;
	}
};

int main()
{
	Solution so;
	string a = "10111111";
	string b = "111";
	cout << so.addBinary(a, b) << endl;
	return 0;
}