#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		if (x < 0) return INT_MIN;
		//general case: binary search.
		long long int low = 0, mid = 0, up = x;
		while (low <= up){
			mid = (low + up) / 2;
			long long int square = mid*mid;
			if (square == x)
				return (int) mid;
			else if (square < x)
				low = mid + 1;
			else
				up = mid - 1;
		}
		return (int) low - 1;
	}
};

int main()
{
	Solution so;
	int x = 0;
	//x = 0; cout << x << " " << so.mySqrt(x) << endl;
	//x = -10; cout << x << " " << so.mySqrt(x) << endl;
	//x = 100; cout << x << " " << so.mySqrt(x) << endl;
	//x = 102; cout << x << " " << so.mySqrt(x) << endl;
	//x = 82; cout << x << " " << so.mySqrt(x) << endl; 
	x = 2147395599; cout << x << " " << so.mySqrt(x) << endl;
	x = INT_MAX; cout << x << " " << so.mySqrt(x) << endl;
	return 0;
}