#include <iostream>
#include <vector>
#include <string>

using namespace std;

//  1 - I
//  5 - V
// 10 - X
class Solution {
public:
	//input is guaranteed with 1-3999.
	string genChar(int idx, int val){
		//idx is the order index from right side.
		//char ONE[10] = {'I', 'X', 'C', 'M', 0};
		//char FIVE[10] = {'V', 'L', 'D', 0};
		string ONE = "IXCM";
		string FIVE = "VLD";
		string str = "";
		//1000-M
		if (idx == 4){
			str = string(val, 'M');
			return str;
		}
		//100-C 500-M
		if (val == 9){
			str = str + ONE[idx-1] + ONE[idx];
		}
		else if (val >= 5 && val < 9){
			str = str + FIVE[idx-1];
			str = str + string(val - 5, ONE[idx - 1]);
		}
		else if (val == 4){
			str = str + ONE[idx-1] + FIVE[idx-1];
		}
		else if (val >= 1 && val < 4){
			str = str + string(val, ONE[idx - 1]);
		}
		else
			str = str + "";
		return str;
	}
	//main function.
	string intToRoman(int num) {
		string res = "";
		int len = 0, mask = 1;
		int tmp = num;
		while (tmp){
			len++;
			mask = mask * 10;
			tmp /= 10;
		}
		mask = mask / 10;
		int curNum = 0;
		while (num){
			curNum = num / mask;
			res = res + genChar(len, curNum);
			len--;
			num = num%mask;
			mask = mask / 10;
		}
		return res;
	}
};

int main()
{
	Solution so;
	int i = 1000;
	i = 1904; cout << i << " " << so.intToRoman(i) << endl;
	i = 2635; cout << i << " " << so.intToRoman(i) << endl;
	i = 888; cout << i << " " << so.intToRoman(i) << endl;
	i = 1234; cout << i << " " << so.intToRoman(i) << endl;
	i = 3999; cout << i << " " << so.intToRoman(i) << endl;
	return 1;
}