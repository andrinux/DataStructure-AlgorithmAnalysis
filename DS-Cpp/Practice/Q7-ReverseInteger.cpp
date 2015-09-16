#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN)
			return 0;
		int flag = (x < 0) ? -1 : 1;
		if (x < 0)
			x = -x;
		int y = 0;
		while (x){
			y = y * 10 + x % 10;
			x = x / 10;
			//Deal with Overflow.
			if (y > INT_MAX / 10 && x > 0)
				return 0;
			if (y == INT_MAX / 10 && x > 1)
				return 0;
		}
		return y*flag;
	}
};


int main()
{
	Solution so;
	int in;
	in = 321; cout << in << " " << so.reverse(in) << endl;
	in = -321; cout << in << " " << so.reverse(in) << endl;
	in = 0; cout << in << " " << so.reverse(in) << endl;
	in = 100; cout << in << " " << so.reverse(in) << endl;
	in = INT_MAX; cout << in << " " << so.reverse(in) << endl;
	in = -1463847412; cout << in << " " << so.reverse(in) << endl;
	in = INT_MIN+1; cout << in << " " << so.reverse(in) << endl;
	in = INT_MIN; cout << in << " " << so.reverse(in) << endl;
	in = 1534236469; cout << in << " " << so.reverse(in) << endl;
	return 1;
}