#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int num[256] = { 0 };
		int result = 0;
		num['I'] = 1; num['V'] = 5; num['X'] = 10;
		num['C'] = 100; num['D'] = 500; num['M'] = 1000;
		int i = 0;
		while (i < s.size()){
			if (num[s[i]] < num[s[i+1]])
				result -= num[s[i]];
			else
				result += num[s[i]];
			i++;
		}
		return result;
	}
};


int main()
{
	Solution so;
	string str;
	str = "MMDCXXXV"; cout << str << " " << so.romanToInt(str) << endl;
	str = "MCMXCIX"; cout << str << " " << so.romanToInt(str) << endl;
	str = "MCMIV"; cout << str << " " << so.romanToInt(str) << endl;
	return 1;
}