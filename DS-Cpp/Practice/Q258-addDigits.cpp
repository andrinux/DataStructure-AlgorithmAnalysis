#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//Recursion Method.
	int addDigits_Recurse(int num) {
		if (num < 10)
			return num;
		//General case
		int sum = 0;
		while (num){
			sum += num % 10;
			num = num / 10;
		}
		return addDigits_Recurse(sum);
	}

	//O(1) time 
	int addDigits(int num) {
		/*if (num < 9)
			return num;
		else*/
			return (num % 9) == 0 ? 9 : num % 9;
	}

};

int main()
{
	Solution so;
	int num = 38;
	for (num = 0; num < 10000; num++){
		int res1 = so.addDigits_Recurse(num);
		int res2 = so.addDigits(num);
		if (res1 != res2)
			cout << num << " " << res1 << " " << res2 << endl;
	}
	return 1;
}