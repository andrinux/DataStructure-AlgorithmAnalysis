#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//Note the overflow problem.

class Solution {
public:
	double power(double x, int n){
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		double mid = 0;
		if (n % 2 == 1){
			mid = power(x, n / 2);
			return mid*mid*x;
		}
		else
		{
			mid = pow(x, n / 2);
			return mid*mid;
		}
	}
	double myPow(double x, int n) {
		if (n < 0)
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}
};


int main()
{
	int n = 2147483647;
	double x = 2147483647;
	Solution so;
	cout << so.myPow(x, n) << endl;
	return 0;
}