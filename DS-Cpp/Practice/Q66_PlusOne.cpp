#include <iostream>
#include <vector>

using namespace std;

// The number is non-negative.
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int N = digits.size(); 
		if (N == 0) return vector<int>({ 1 });
		int carry = 1;
		vector<int> res(N + 1, 0);
		for (int i = N - 1; i >= 0; i--){
			int d_ori = digits[i];
			int d_res = d_ori + carry;
			if (d_res >= 10){
				carry = 1;
				res[i + 1] = d_res - 10;
			}
			else{
				carry = 0;
				res[i + 1] = d_res;
			}
		}
		res[0] = carry;
		if (carry == 0)
			res.erase(res.begin());
		return res;
	}
};

int main()
{
	Solution so; 
	vector<int> digits = { 9,9,9,9 };
	vector<int> res = so.plusOne(digits);
	for (auto n : res)
		cout << n << " ";
	cout << endl;
	return 0;
}