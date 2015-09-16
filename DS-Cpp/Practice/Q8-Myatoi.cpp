#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
	int myAtoi(string str) {
		if (str.size() == 0)
			return 0;
		unsigned int i = 0;
		long long flag = 1;
		long long num = 0;
		//Skip blank.
		while (i < str.size() && str[i] == ' ')
			i++;
		//Only one symbol
		if (str[i] == '-' || str[i] == '+'){
			if (str[i] == '-')
				flag = -1;
			if (str[i] == '+')
				flag = 1;
			i++;
		}

		while (i < str.size()){
			if (str[i] <'0' || str[i]>'9')
				break;//Special charater, break.
			num = num * 10 + (str[i] - '0');
			if (num > INT_MAX)
				break;
			i++;
		}
		num = num*flag;
		if (num < INT_MIN)
			return INT_MIN;
		else if (num > INT_MAX)
			return INT_MAX;
		else
			return (int)(num);
	}
};



